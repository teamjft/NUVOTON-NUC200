/**************************************************************************//**
 * @file     main.c
 * @version  V1.00
 * $Revision: 2 $
 * $Date: 12/08/03 5:46p $ 
 * @brief    NUC200 Series CRC Sample Code
 *
 * @note
 * Copyright (C) 2011 Nuvoton Technology Corp. All rights reserved.
 *
 ******************************************************************************/
#include <stdio.h>
#include <string.h>
#include "NUC200Series.h"

#define PLLCON_SETTING      SYSCLK_PLLCON_50MHz_XTAL
#define PLL_CLOCK           50000000


/*---------------------------------------------------------------------------------------------------------*/
/* Global Interface Variables Declarations                                                                 */                                                                            
/*---------------------------------------------------------------------------------------------------------*/
extern int IsDebugFifoEmpty(void);
volatile uint8_t g_u8IsTargetAbortINTFlag = 0, g_u8IsBlockTransferDoneINTFlag = 0;
                         

/**
 * @brief       PDMA Handler for PDMA and CRC Interrupt
 *
 * @param       None
 *
 * @return      None
 *
 * @details     The PDMA_IRQHandler is default IRQ of PDMA and CRC, declared in startup_NUC200Series.s.
 */
void PDMA_IRQHandler(void)
{
    if (_CRC_GET_BLKD_INT_FLAG() == 1)
    {
        /* Clear Block Transfer Done Interrupt Flag */
        _CRC_CLEAR_BLKD_INT_FLAG();

        g_u8IsBlockTransferDoneINTFlag++;
    }else
    if (_CRC_GET_TABORT_INT_FLAG() == 1)
    {
        /* Clear Target Abort Interrupt Flag */
        _CRC_GET_TABORT_INT_FLAG();
        
        g_u8IsTargetAbortINTFlag++;
    }else
    {
        printf("Un-expected interrupts. \n");
    }
}


/*---------------------------------------------------------------------------------------------------------*/
/*  CRC-CCITT Polynomial Mode Test                                                                         */
/*---------------------------------------------------------------------------------------------------------*/
void CRC_CCITTPolyModeTest(uint32_t u32SrcAddr, uint32_t u32TransByteCount)
{
    uint32_t u32TargetChecksum = 0x29B1, u32CalChecksum = 0;

    printf("# Calculate string \"123456789\" CRC-CCITT checksum value by CRC DMA mode. \n");
    printf("    - Seed value is 0xFFFF          \n");
    printf("    - Checksum Complement disable   \n");
    printf("    - Checksum Reverse disable      \n");
    printf("    - Write Data Complement disable \n");
    printf("    - Write Data Reverse disable    \n");
    printf("    - Checksum should be 0x%X       \n", u32TargetChecksum);
    printf("Press any key to start test ... \n\n");
    getchar();

    g_u8IsTargetAbortINTFlag = g_u8IsBlockTransferDoneINTFlag = 0;

    /* Enable CRC channel clock */
    PDMA_GCR->GCRCSR |= PDMA_GCRCSR_CRC_CLK_EN_Msk;

    /* Enable PDMA and CRC NVIC */
    NVIC_EnableIRQ(PDMA_IRQn);

    /* Disable CRC Function */
    _CRC_DISABLE();

    /* Configure CRC Operation Settings for CRC DMA mode */
    _CRC_SET_SEED(0xFFFF);
    _CRC_SET_DMA_SRC_ADDRESS(u32SrcAddr);
    _CRC_SET_DMA_TRANS_BYTE_COUNT(u32TransByteCount);
    CRC->CTL = CRC_CTL_CRC_MODE_CCITT | CRC_CTL_CRCCEN_EN;

    /* Enable DMA Target Abort and Block Transfer Done Interrupt */
    _CRC_TABORT_INT_ENABLE();
    _CRC_BLKD_INT_ENABLE();

    /* Reset CRC State Machine and Internal Buffer */
    _CRC_RESET();

    /* Trigger CRC DMA transfer */
    _CRC_TRIG_DMA();

    /* Wait CRC Interrupt Flag occurred */
    while (1)
    {
        if (g_u8IsTargetAbortINTFlag == 1)
        {
            printf("DMA Target Abort Interrupt occurred. \n");
            break;
        }
        if (g_u8IsBlockTransferDoneINTFlag == 1)
        {
            break;
        }
    }

    /* Disable PDMA and CRC NVIC */
    NVIC_DisableIRQ(PDMA_IRQn);

    /* Disable CRC Function */
    _CRC_DISABLE();

    /* Get CRC Checksum value */
    u32CalChecksum = _CRC_GET_POLY_CCITT_CHECKSUM();        
    if (g_u8IsBlockTransferDoneINTFlag == 1)
    {
        printf("CRC checksum is 0x%X ... %s.\n", u32CalChecksum, (u32CalChecksum==u32TargetChecksum)?"PASS":"FAIL");
    }

    printf("\n");
}


/*---------------------------------------------------------------------------------------------------------*/
/*  CRC-8 Polynomial Mode Test                                                                             */
/*---------------------------------------------------------------------------------------------------------*/
void CRC_CRC8PolyModeTest(uint32_t u32SrcAddr, uint32_t u32TransByteCount)
{
    uint32_t i = 0;
    uint32_t u32TargetChecksum = 0x58, u32CalChecksum = 0;
    uint8_t *p8SrcAddr;

    printf("# Calculate string \"123456789\" CRC-8 checksum value by CRC CPU mode. \n");
    printf("    - Seed value is 0x5A            \n");
    printf("    - CPU Write Length is 8-bit     \n");
    printf("    - Checksum Complement disable   \n");
    printf("    - Checksum Reverse disable      \n");
    printf("    - Write Data Complement disable \n");
    printf("    - Write Data Reverse disable    \n");
    printf("    - Checksum should be 0x%X       \n", u32TargetChecksum);
    printf("Press any key to start test ... \n\n");
    getchar();

    p8SrcAddr = (uint8_t *)u32SrcAddr;

    /* Enable CRC channel clock */
    PDMA_GCR->GCRCSR |= PDMA_GCRCSR_CRC_CLK_EN_Msk;

    /* Disable CRC Function */
    _CRC_DISABLE();

    /* Configure CRC Operation Settings for CRC CPU mode */
    _CRC_SET_SEED(0x5A);
    CRC->CTL = CRC_CTL_CRC_MODE_CRC8 | CRC_CTL_CPU_WDLEN_8 | CRC_CTL_CRCCEN_EN;

    /* Reset CRC State Machine and Internal Buffer */
    _CRC_RESET();

    for (i=0; i<u32TransByteCount; i++)
    {
        _CRC_CPU_WRITE_DATA((p8SrcAddr[i]&0xFF));
    }


    /* Disable CRC Function */
    _CRC_DISABLE();

    /* Get CRC Checksum value */
    u32CalChecksum = _CRC_GET_POLY_8_CHECKSUM();        
    printf("CRC checksum is 0x%X ... %s.\n", u32CalChecksum, (u32CalChecksum==u32TargetChecksum)?"PASS":"FAIL");

    printf("\n");
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
    SYSCLK->AHBCLK |= SYSCLK_AHBCLK_PDMA_EN_Msk;
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
    /* Set PB multi-function pins for UART0 RXD, UART0 TXD */
    SYS->GPB_MFP = SYS_GPB_MFP_PB0_RXD0 | SYS_GPB_MFP_PB1_TXD0;

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
/*  MAIN function                                                                                          */
/*---------------------------------------------------------------------------------------------------------*/
int main (void)
{
	uint8_t	u8Item = 0x0;
    const uint8_t acCRCSrcPattern[] = "123456789";

    /* Init System, IP clock and multi-function I/O */
    SYS_Init();     

    /* Init UART0 for printf */
    UART0_Init();

    printf("\n\nCPU @ %dHz\n", SystemCoreClock);
    printf("+------------------------------------+\n");
    printf("|    NUC200 CRC Driver Sample Code   |\n");
    printf("+------------------------------------+\n");
	printf("\n");
    
    do
    {
        printf("+-------------------------------------------+ \n");
        printf("| Select an item to test                    | \n");
        printf("+-------------------------------------------+ \n");
        printf("| [0] CRC-CCITT Polynomial mode test        | \n");
        printf("| [1] CRC-8 Polynomial mode test            | \n");
        printf("+-------------------------------------------+ \n");
        printf("\n");
        u8Item = getchar();

        switch (u8Item)
        {
            case '0':
                CRC_CCITTPolyModeTest((uint32_t )acCRCSrcPattern, strlen((char *)acCRCSrcPattern)); break;    

            case '1':
                CRC_CRC8PolyModeTest((uint32_t )acCRCSrcPattern, strlen((char *)acCRCSrcPattern));  break;    
        }
    } while (u8Item != 27);
  
    printf("\nExit CRC Sample Code. \n");

    return 0;
}
