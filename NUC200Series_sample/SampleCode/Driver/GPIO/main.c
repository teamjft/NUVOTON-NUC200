/**************************************************************************//**
 * @file     main.c
 * @version  V1.00
 * $Revision: 4 $
 * $Date: 12/08/03 5:46p $ 
 * @brief    NUC200 Series General Purpose I/O Driver Sample Code
 *
 * @note
 * Copyright (C) 2011 Nuvoton Technology Corp. All rights reserved.
 *
 ******************************************************************************/
#include <stdio.h>
#include "NUC200Series.h"

#define PLLCON_SETTING      SYSCLK_PLLCON_50MHz_XTAL
#define PLL_CLOCK           50000000


/**
 * @brief       GPIO PA/PB IRQ
 *
 * @param       None
 *
 * @return      None
 *
 * @details     The GPIO PA/PB default IRQ, declared in startup_NUC200Series.s.
 */
void GPAB_IRQHandler(void)
{	
    /* To check if PB.5 interrupt occurred */
    if (PB->ISRC & GPIO_ISRC_ISRC5)
    {
	    PB->ISRC = GPIO_ISRC_ISRC5;
        printf("PB.5 INT occurred. \n");
    }else
    {
        /* Un-expected interrupt. Just clear all PA, PB interrupts */
        PA->ISRC = PA->ISRC;
        PB->ISRC = PB->ISRC;
        printf("Un-expected interrupts. \n");
    }
}


/**
 * @brief       GPIO PC/PD/PE/PF IRQ
 *
 * @param       None
 *
 * @return      None
 *
 * @details     The GPIO PC/PD/PE/PF default IRQ, declared in startup_NUC200Series.s.
 */
void GPCDEF_IRQHandler(void)
{
    /* To check if PE.3 interrupt occurred */
    if (PE->ISRC & GPIO_ISRC_ISRC3)
    {
	    PE->ISRC = GPIO_ISRC_ISRC3;
        printf("PE.3 INT occurred. \n");
    }else
    {
        /* Un-expected interrupt. Just clear all PC, PD, PE and PF interrupts */
    	PC->ISRC = PC->ISRC;
    	PD->ISRC = PD->ISRC;
    	PE->ISRC = PE->ISRC;
    	PF->ISRC = PF->ISRC;
        printf("Un-expected interrupts. \n");
    }
}


/**
 * @brief       External INT0 IRQ
 *
 * @param       None
 *
 * @return      None
 *
 * @details     The External INT0(PB.14) default IRQ, declared in startup_NUC200Series.s.
 */
void EINT0_IRQHandler(void)
{
	/* For PB.14, clear the INT flag */
    PB->ISRC = GPIO_ISRC_ISRC14;

    printf("PB.14 EINT0 occurred. \n");
}


/**
 * @brief       External INT1 IRQ
 *
 * @param       None
 *
 * @return      None
 *
 * @details     The External INT1(PB.15) default IRQ, declared in startup_NUC200Series.s.
 */
void EINT1_IRQHandler(void)
{	
	/* For PB.15, clear the INT flag */
    PB->ISRC = GPIO_ISRC_ISRC15;
	
    printf("PB.15 EINT1 occurred. \n");
}


void SYS_Init(void)
{
/*---------------------------------------------------------------------------------------------------------*/
/* Init System Clock                                                                                       */
/*---------------------------------------------------------------------------------------------------------*/
    /* Unlock protected registers */
    SYS_UnlockReg();

    /* Enable External XTAL (4~24 MHz) */
    SYSCLK->PWRCON |= SYSCLK_PWRCON_XTL12M_EN_Msk;

    /* Waiting for 12MHz clock ready */
    SYS_WaitingForClockReady(SYSCLK_CLKSTATUS_XTL12M_STB_Msk);

    /* Switch HCLK clock source to XTAL */
    SYSCLK->CLKSEL0 = SYSCLK_CLKSEL0_HCLK_XTAL;

    /* Set PLL to power down mode and PLL_STB bit in CLKSTATUS register will be cleared by hardware.*/
    SYSCLK->PLLCON |= SYSCLK_PLLCON_PD_Msk;

    /* Set PLL frequency */        
    SYSCLK->PLLCON = PLLCON_SETTING;

    /* Waiting for clock ready */
    SYS_WaitingForClockReady(SYSCLK_CLKSTATUS_PLL_STB_Msk);

    /* Switch HCLK clock source to PLL */
    SYSCLK->CLKSEL0 = SYSCLK_CLKSEL0_HCLK_PLL;

    /* Enable IP clock */        
    SYSCLK->APBCLK = SYSCLK_APBCLK_UART0_EN_Msk;

    /* IP clock source */
    SYSCLK->CLKSEL1 = SYSCLK_CLKSEL1_UART_PLL;

    /* Update System Core Clock */
    /* User can use SystemCoreClockUpdate() to calculate PllClock, SystemCoreClock and CycylesPerUs automatically. */
    //SystemCoreClockUpdate(); 
    PllClock        = PLL_CLOCK;            // PLL
    SystemCoreClock = PLL_CLOCK / 1;        // HCLK
    CyclesPerUs     = PLL_CLOCK / 1000000;  // For SYS_SysTickDelay()

/*---------------------------------------------------------------------------------------------------------*/
/* Init I/O Multi-function                                                                                 */
/*---------------------------------------------------------------------------------------------------------*/
    /* Set PB multi-function pins for UART0 RXD, UART0 TXD, EINT0 and EINT1 */
    SYS->GPB_MFP = SYS_GPB_MFP_PB0_RXD0 | SYS_GPB_MFP_PB1_TXD0 | SYS_GPB_MFP_PB14_INT0 | SYS_GPB_MFP_PB15_INT1;

    /* Lock protected registers */
    SYS_LockReg();
}


void UART0_Init(void)
{
/*---------------------------------------------------------------------------------------------------------*/
/* Init UART                                                                                               */
/*---------------------------------------------------------------------------------------------------------*/
    /* Reset IP */
    SYS->IPRSTC2 |=  SYS_IPRSTC2_UART0_RST_Msk;
    SYS->IPRSTC2 &= ~SYS_IPRSTC2_UART0_RST_Msk;

    /* Configure UART0 and set UART0 Baudrate */
    UART0->BAUD = UART_BAUD_MODE2 | UART_BAUD_DIV_MODE2(PLL_CLOCK, 115200);
    _UART_SET_DATA_FORMAT(UART0, UART_WORD_LEN_8 | UART_PARITY_NONE | UART_STOP_BIT_1);
}


/*---------------------------------------------------------------------------------------------------------*/
/* MAIN function                                                                                           */
/*---------------------------------------------------------------------------------------------------------*/
int main (void)
{
    int32_t i32Err;

    /* Init System, IP clock and multi-function I/O */
    SYS_Init();     

    /* Init UART0 for printf */
    UART0_Init();

    printf("\n\nCPU @ %dHz\n", SystemCoreClock);
                                
    printf("+-------------------------------------+ \n");
    printf("|    NUC200 GPIO Driver Sample Code   | \n");
    printf("+-------------------------------------+ \n");

    /*-----------------------------------------------------------------------------------------------------*/
    /* GPIO Basic Mode Test --- Use Pin Data Input/Output to control GPIO pin                              */
    /*-----------------------------------------------------------------------------------------------------*/    
    printf("  >> Please connect PA.2 and PD.1 first << \n");
    printf("     Press any key to start test by using [Pin Data Input/Output Control] \n\n");
	getchar();
	
    /* Configure PA.2 as Output mode and PD.1 as Input mode then close it */
    _GPIO_SET_PIN_MODE(PA, 2, GPIO_PMD_OUTPUT);
    _GPIO_SET_PIN_MODE(PD, 1, GPIO_PMD_INPUT);
	
    i32Err = 0;
    printf("  GPIO Output/Input test ...... \n");

    /* Use Pin Data Input/Output Control to pull specified I/O or get I/O pin status */
    PA2 = 0;
    if (PD1 != 0)
	{
		i32Err = 1;
	}

    PA2 = 1;
    if (PD1 != 1)
	{
		i32Err = 1;
	}

    if ( i32Err )
    { 
	    printf("  [FAIL] --- Please make sure PA.2 and PD.1 are connected. \n");
    }else
    {
        printf("  [OK] \n");
    }
    
    /* Configure PA.2 amd PD.1 to default Quasi-bidirectional mode */
    _GPIO_SET_PIN_MODE(PA, 2, GPIO_PMD_QUASI);
    _GPIO_SET_PIN_MODE(PD, 1, GPIO_PMD_QUASI);


    /*-----------------------------------------------------------------------------------------------------*/
    /* GPIO Interrupt Function Test                                                                        */
    /*-----------------------------------------------------------------------------------------------------*/    
    printf("\n  PB.5, PE.3, PB.14(INT0) and PB.15(INT1) are used to test interrupt \n");    

    /* Configure PB.5 as Input mode and enable interrupt by rising edge trigger */
    _GPIO_SET_PIN_MODE(PB, 5, GPIO_PMD_INPUT);
    GPIO_EnableInt(PB, 5, GPIO_INT_RISING);
    NVIC_EnableIRQ(GPAB_IRQn);

    /*  Configure PE.3 as Quasi-bidirection mode and enable interrupt by falling edge trigger */
    _GPIO_SET_PIN_MODE(PE, 3, GPIO_PMD_QUASI);
    GPIO_EnableInt(PE, 3, GPIO_INT_FALLING);
    NVIC_EnableIRQ(GPCDEF_IRQn);

    /* Configure PB.14 as EINT0 pin and enable interrupt by falling edge trigger */
    _GPIO_SET_PIN_MODE(PB, 14, GPIO_PMD_INPUT);
    GPIO_EnableInt(PB, 14, GPIO_INT_FALLING);
    NVIC_EnableIRQ(EINT0_IRQn);

    /* Configure PB.15 as EINT1 pin and enable interrupt by rising and falling edge trigger */
    _GPIO_SET_PIN_MODE(PB, 15, GPIO_PMD_INPUT);
    GPIO_EnableInt(PB, 15, GPIO_INT_BOTH_EDGE);
    NVIC_EnableIRQ(EINT1_IRQn);

    /* Enable interrupt de-bounce function and select de-bounce sampling cycle time is 1024 * 10 KHz clock */
    _GPIO_SET_DEBOUNCE_TIME(GPIO_DBNCECON_DBCLKSRC_IRC10K, GPIO_DBNCECON_DBCLKSEL_1024);
    _GPIO_ENABLE_DEBOUNCE(PB, 5);
    _GPIO_ENABLE_DEBOUNCE(PE, 3);
    _GPIO_ENABLE_DEBOUNCE(PB, 14);
    _GPIO_ENABLE_DEBOUNCE(PB, 15);

    /* Waiting for interrupts */
    while (1);
}




