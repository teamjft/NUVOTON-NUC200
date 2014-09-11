/****************************************************************************
 * @file     main.c
 * @version  V1.00
 * $Revision: 2 $
 * $Date: 8/06/12 4:57p $ 
 * @brief    NUC200 Series USB HID Sample Code
 *
 * @note
 * Copyright (C) 2011 Nuvoton Technology Corp. All rights reserved.
 *
 ******************************************************************************/
#include <stdio.h>
#include "NUC200Series.h"

#define DEBUG 1

#define PLLCON_SETTING      SYSCLK_PLLCON_48MHz_XTAL
#define PLL_CLOCK           48000000

extern int32_t HID_MainProcess(void);

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
    SYS_WaitingForClockReady( SYSCLK_CLKSTATUS_XTL12M_STB_Msk);

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
    SYSCLK->APBCLK = SYSCLK_APBCLK_UART0_EN_Msk | SYSCLK_APBCLK_USBD_EN_Msk;

    /* Set clock divder */
    SYSCLK->CLKDIV = SYSCLK_CLKDIV_HCLK(1) | SYSCLK_CLKDIV_USB(1);

    /* IP clock source */
    SYSCLK->CLKSEL1 = SYSCLK_CLKSEL1_UART_PLL | SYSCLK_CLKSEL1_WDT_IRC10K |
                      SYSCLK_CLKSEL1_TMR0_XTAL | SYSCLK_CLKSEL1_TMR1_HCLK | SYSCLK_CLKSEL1_TMR2_IRC22M | SYSCLK_CLKSEL1_TMR3_XTAL;


    /* Update System Core Clock */
    /* User can use SystemCoreClockUpdate() to calculate PllClock, SystemCoreClock and CycylesPerUs automatically. */
    //SystemCoreClockUpdate(); 
    PllClock        = PLL_CLOCK;            // PLL
    SystemCoreClock = PLL_CLOCK / 1;        // HCLK
    CyclesPerUs     = PLL_CLOCK / 1000000;  // For SYS_SysTickDelay()

/*---------------------------------------------------------------------------------------------------------*/
/* Init I/O Multi-function                                                                                 */
/*---------------------------------------------------------------------------------------------------------*/
    /* Set PB multi-function pins for UART0 RXD, TXD */
    SYS->GPB_MFP = SYS_GPB_MFP_PB0_RXD0 | SYS_GPB_MFP_PB1_TXD0;

    /* Lock protected registers */
    //SYS_LockReg();
}


void UART0_Init(void)
{
/*---------------------------------------------------------------------------------------------------------*/
/* Init UART                                                                                               */
/*---------------------------------------------------------------------------------------------------------*/

    /* Configure UART0 and set UART0 Baudrate */
    UART0->BAUD = UART_BAUD_MODE2 | UART_BAUD_DIV_MODE2(PLL_CLOCK, 115200);
    _UART_SET_DATA_FORMAT(UART0, UART_WORD_LEN_8 | UART_PARITY_NONE | UART_STOP_BIT_1);
}


/*---------------------------------------------------------------------------------------------------------*/
/*  Main Function									                                           			   */
/*---------------------------------------------------------------------------------------------------------*/
int32_t main (void)
{
   
    SYS_Init();
    UART0_Init();
   
	printf("NUC200 USB HID\n");
    while( (UART0->FSR & UART_FSR_TE_FLAG_Msk)==0 );

    HID_MainProcess();
    
    return 0;
}




