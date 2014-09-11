/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* Copyright(c) 2010 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/
#include <stdio.h>
#include "NUC200Series.h"
#include "initialization.h"

#define DBG_PRINTF      printf

/*---------------------------------------------------------------------------------------------------------*/
/* MAIN function                                                                                           */
/*---------------------------------------------------------------------------------------------------------*/
int main(void)
{
    SYS_Init();
    UART0_Init();
    UART1_Init();
    GPIO_Init();
    TMR0_Init();
    TMR1_Init();
    PWMA_Init();
    PWMB_Init();
    CKO_Init();

_GPIO_SET_PIN_MODE(PC, 12, GPIO_PMD_OUTPUT);	
_GPIO_SET_PIN_MODE(PE, 0, GPIO_PMD_OUTPUT);
_GPIO_SET_PIN_MODE(PE, 2, GPIO_PMD_OUTPUT);	
_GPIO_SET_PIN_MODE(PE, 4, GPIO_PMD_OUTPUT);
_GPIO_SET_PIN_MODE(PA, 10, GPIO_PMD_OUTPUT);	
_GPIO_SET_PIN_MODE(PA, 8, GPIO_PMD_OUTPUT);	
_GPIO_SET_PIN_MODE(PD, 9, GPIO_PMD_OUTPUT);
_GPIO_SET_PIN_MODE(PD, 11, GPIO_PMD_OUTPUT);	
_GPIO_SET_PIN_MODE(PD, 13, GPIO_PMD_OUTPUT);
_GPIO_SET_PIN_MODE(PB, 5, GPIO_PMD_OUTPUT);	
_GPIO_SET_PIN_MODE(PB, 7, GPIO_PMD_OUTPUT);	
_GPIO_SET_PIN_MODE(PE, 8, GPIO_PMD_OUTPUT);
_GPIO_SET_PIN_MODE(PB, 0, GPIO_PMD_OUTPUT);	
_GPIO_SET_PIN_MODE(PB, 2, GPIO_PMD_OUTPUT);
_GPIO_SET_PIN_MODE(PD, 6, GPIO_PMD_OUTPUT);	
_GPIO_SET_PIN_MODE(PD, 14, GPIO_PMD_OUTPUT);	
_GPIO_SET_PIN_MODE(PC, 5, GPIO_PMD_OUTPUT);
_GPIO_SET_PIN_MODE(PC, 3, GPIO_PMD_OUTPUT);	
_GPIO_SET_PIN_MODE(PC, 1, GPIO_PMD_OUTPUT);
_GPIO_SET_PIN_MODE(PE, 6, GPIO_PMD_OUTPUT);	
_GPIO_SET_PIN_MODE(PB, 11, GPIO_PMD_OUTPUT);	
/*_GPIO_SET_PIN_MODE(PA, 1, GPIO_PMD_OUTPUT);
_GPIO_SET_PIN_MODE(PA, 2, GPIO_PMD_OUTPUT);	
_GPIO_SET_PIN_MODE(PA, 3, GPIO_PMD_OUTPUT);
_GPIO_SET_PIN_MODE(PA, 4, GPIO_PMD_OUTPUT);*/	



	
while (1)
{


}


    __WFI();

}




