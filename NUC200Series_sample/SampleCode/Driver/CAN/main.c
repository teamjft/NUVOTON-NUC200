/**************************************************************************//**
 * @file     main.c
 * @version  V1.00
 * $Revision: 3 $
 * $Date: 12/08/06 6:49p $ 
 * @brief    NUC200 Series CAN Driver Sample Code
 *
 * @note
 * Copyright (C) 2011 Nuvoton Technology Corp. All rights reserved.
 *
 ******************************************************************************/
#include <stdio.h>
#include "NUC200Series.h"
#include "CAN.h"

#define PLLCON_SETTING      SYSCLK_PLLCON_50MHz_XTAL
#define PLL_CLOCK           50000000

/*----------------------------------------------------------------------------*/
/*  Function Declare                            							  */
/*----------------------------------------------------------------------------*/
extern char GetChar(void);
/*----------------------------------------------------------------------------*/
/*  statistics of all the interrupts           	   							  */
/*----------------------------------------------------------------------------*/
void CAN_ShowMsg(STR_CANMSG_T* Msg);
/*----------------------------------------------------------------------------*/
/*  Callback function 													   	  */
/*----------------------------------------------------------------------------*/
STR_CANMSG_T rrMsg;

void TestFnTxOK()
{
	printf("Test Callback funtion OK\n");
}
void CAN_CallbackFn(uint32_t u32IIDR)
{
    if(u32IIDR==1)
    {
	    printf("Msg-0 INT and Callback\n");
        CAN_ReadMsgObj(0,TRUE,&rrMsg);
        CAN_ShowMsg(&rrMsg);
    }
    if(u32IIDR==5+1)
    {
	    printf("Msg-5 INT and Callback \n");
        CAN_ReadMsgObj(5,TRUE,&rrMsg);
        CAN_ShowMsg(&rrMsg);
    }
    if(u32IIDR==31+1)
    {
	    printf("Msg-31 INT and Callback \n");
        CAN_ReadMsgObj(31,TRUE,&rrMsg);
        CAN_ShowMsg(&rrMsg);
    }
}


/*----------------------------------------------------------------------------*/
/*  Test Function 													   	 	  */
/*----------------------------------------------------------------------------*/
void CAN_ShowMsg(STR_CANMSG_T* Msg)
{
    uint8_t i;
	printf("Read ID=%8X, Type=%s, DLC=%d,Data=",Msg->Id,Msg->IdType?"EXT":"STD",Msg->DLC);
    for(i=0;i<Msg->DLC;i++)    
        printf("%02X,",Msg->Data[i]);
    printf("\n\n");
}

/*----------------------------------------------------------------------------*/
/*  Send Tx Msg by Basic Mode Function (Without Message RAM)         	 	  */
/*----------------------------------------------------------------------------*/
void Test_BasicMode_Tx()
{
    int32_t delaycount;
    STR_CANMSG_T msg1;
    delaycount=1000;
    CAN_EnterTestMode(CAN_TESTR_BASIC);	                                       
    CAN_EnableInt(CAN_CON_IE|CAN_CON_SIE);

    /* Send Message No.1 */
    msg1.FrameType= DATA_FRAME;
    msg1.IdType   = CAN_STD_ID;
	msg1.Id       = 0x001;
    msg1.DLC      = 2;
	msg1.Data[0]  = 0x00;
    msg1.Data[1]  = 0x2;
    CAN_BasicSendMsg(&msg1);
    printf("Send STD_ID:0x1,Data[0,2]\n");
    SYS_SysTickDelay(delaycount);
      
    /* Send Message No.2 */
    msg1.FrameType= DATA_FRAME;
    msg1.IdType   = CAN_STD_ID;
	msg1.Id       = 0x1AC;
    msg1.DLC      = 8;
	msg1.Data[0]  = 0x11;
    msg1.Data[1]  = 0x12;
    msg1.Data[2]  = 0x13;
    msg1.Data[3]  = 0x14;
	msg1.Data[4]  = 0x15;
    msg1.Data[5]  = 0x16;
    msg1.Data[6]  = 0x17;
    msg1.Data[7]  = 0x18;
  
    CAN_BasicSendMsg(&msg1);
    printf("Send STD_ID:0x1AC,Data[11,12,13,14,15,16,17,18]\n");
    SYS_SysTickDelay(delaycount);

    /* Send Message No.3 */
    msg1.FrameType= DATA_FRAME;
    msg1.IdType   = CAN_STD_ID;
	msg1.Id       = 0x310;
    msg1.DLC      = 8;
	msg1.Data[0]  = 0x21;
    msg1.Data[1]  = 0x22;
    msg1.Data[2]  = 0x23;
    msg1.Data[3]  = 0x24;
	msg1.Data[4]  = 0x25;
    msg1.Data[5]  = 0x26;
    msg1.Data[6]  = 0x27;
    msg1.Data[7]  = 0x28;
    CAN_BasicSendMsg(&msg1);
    printf("Send STD_ID:0x310,Data[21,22,23,24,25,26,27,28]\n");
    SYS_SysTickDelay(delaycount);

    /* Send Message No.4 */
    msg1.FrameType= DATA_FRAME;    
    msg1.IdType   = CAN_EXT_ID;
    msg1.Id       = 0x3377;
    msg1.DLC      = 8;
	msg1.Data[0]  = 0x31;
    msg1.Data[1]  = 0x32;
    msg1.Data[2]  = 0x33;
    msg1.Data[3]  = 0x34;
	msg1.Data[4]  = 0x35;
    msg1.Data[5]  = 0x36;
    msg1.Data[6]  = 0x37;
    msg1.Data[7]  = 0x38;   
    CAN_BasicSendMsg(&msg1);
    printf("Send EXT_ID:0x3377,Data[31,32,33,34,35,36,37,38]\n");
    SYS_SysTickDelay(delaycount);

    /* Send Message No.5 */
    msg1.FrameType= DATA_FRAME;    
    msg1.IdType   = CAN_EXT_ID;
    msg1.Id       = 0x7755;
    msg1.DLC      = 8;
	msg1.Data[0]  = 0x41;
    msg1.Data[1]  = 0x42;
    msg1.Data[2]  = 0x43;
    msg1.Data[3]  = 0x44;
	msg1.Data[4]  = 0x45;
    msg1.Data[5]  = 0x46;
    msg1.Data[6]  = 0x47;
    msg1.Data[7]  = 0x48;  
    CAN_BasicSendMsg(&msg1);
    printf("Send EXT_ID:0x7755,Data[41,42,43,44,45,46,47,48]\n");
    SYS_SysTickDelay(delaycount);
    CAN_LeaveTestMode();

}

/*----------------------------------------------------------------------------*/
/*  Read Rx Msg by Basic Mode Function (Without Message RAM)         	 	  */
/*----------------------------------------------------------------------------*/
void Test_BasicMode_Rx()
{
	STR_CANMSG_T rMsg[5];
    int32_t i;
    CAN_EnterTestMode(CAN_TESTR_BASIC);

    /*  Wait status flag changed and with read IF2 */
    printf("\b Total 40 bytes data(using 5 frames)will be receive by CAN0 from CAN BUS\n");


    for(i=0;i<5;i++)
    {
        CAN_ResetIF(1);
        CAN->IF[1].MCON  =0; 
        CAN_WaitMsg();
	    CAN_BasicReceiveMsg(&rMsg[i]);
    }
    for(i=0;i<5;i++)
        CAN_ShowMsg(&rMsg[i]);
    printf("CAN TEST END\n");
    return;
}

/*----------------------------------------------------------------------------*/
/*  Send Tx Msg by Normal Mode Function (With Message RAM)         	 	      */
/*----------------------------------------------------------------------------*/
void Test_NormalMode_Tx()
{
    STR_CANMSG_T tMsg;

	/* Send a 11-bits message */
    tMsg.FrameType= DATA_FRAME;
    tMsg.IdType   = CAN_STD_ID;
    tMsg.Id       = 0x7FF;
    tMsg.DLC      = 2;
    tMsg.Data[0]  = 7;
    tMsg.Data[1]  = 0xFF;    

    if(CAN_SetTxMsgObj(MSG(0),&tMsg) < 0)     /* Call CAN_SetTxMsgObj() only Confiugre Msg RAM */
    {
        printf("Set Tx Msg Object failed\n");
        return;
    }
	CAN_SetTxRqst(MSG(0));                    /* Call CAN_SetTxRqst() requeset to send the Msg in the RAM */
    printf("MSG(0).Send STD_ID:0x7FF, Data[07,FF]done\n");

    if(CAN_SetTxMsgObj(MSG(1),&tMsg) < 0)    
    {
        printf("Set Tx Msg Object failed\n");
        return;
    }
	/* Send a 29-bits message */
    tMsg.FrameType= DATA_FRAME;
    tMsg.IdType   = CAN_EXT_ID;
    tMsg.Id       = 0x12345;
    tMsg.DLC      = 3;
    tMsg.Data[0]  = 1;
    tMsg.Data[1]  = 0x23;
    tMsg.Data[2]  = 0x45;        

    if(CAN_SetTxMsgObj(MSG(1),&tMsg) < 0)    
    {
        printf("Set Tx Msg Object failed\n");
        return;
    }
	CAN_SetTxRqst(MSG(1));              
    printf("MSG(1).Send EXT:0x12345 ,Data[01,23,45]done\n");  
 
	/* Send a data message */
    tMsg.FrameType= DATA_FRAME;
    tMsg.IdType   = CAN_EXT_ID;
    tMsg.Id       = 0x7FF01;
    tMsg.DLC      = 4;
    tMsg.Data[0]  = 0xA1;
    tMsg.Data[1]  = 0xB2;
    tMsg.Data[2]  = 0xC3;        
    tMsg.Data[3]  = 0xD4;        

    if(CAN_SetTxMsgObj(MSG(3),&tMsg) < 0)    
    {
        printf("Set Tx Msg Object failed\n");
        return;
    }
	CAN_SetTxRqst(MSG(3));                
    printf("MSG(3).Send EXT:0x7FF01 ,Data[A1,B2,C3,D4]done\n");  
	SYS_SysTickDelay(1000000); //Delay one second to wait INT
	printf("Trasmit Done!\nCheck the receive host received data\n");

}

/*----------------------------------------------------------------------------*/
/*  Send Rx Msg by Normal Mode Function (With Message RAM)         	 	      */
/*----------------------------------------------------------------------------*/

void Test_NormalMode_Rx()
{
    if(CAN_SetRxMsgObj(MSG(0),CAN_STD_ID, 0x7FF,TRUE) < 0)
    {
        printf("Set Rx Msg Object failed\n");
        return;
    }

    if(CAN_SetRxMsgObj(MSG(5),CAN_EXT_ID, 0x12345,TRUE) < 0)
    {
        printf("Set Rx Msg Object failed\n");
        return;
    }

    if(CAN_SetRxMsgObj(MSG(31),CAN_EXT_ID, 0x7FF01,TRUE) < 0)
    {
        printf("Set Rx Msg Object failed\n");
        return;
    }
	/*Choose one mode to test*/
#if 1
    /* Polling Mode */
    while(1)
    {
        while(CAN->IIDR ==0);            /* Wait IDR is changed */
        printf("IDR = %x\n",CAN->IIDR);
        CAN_ReadMsgObj(CAN->IIDR -1,TRUE,&rrMsg);
        CAN_ShowMsg(&rrMsg);
    }
#else
	/* INT Mode */
	CAN_EnableInt(CAN_CON_IE);
 	CAN_InstallCallback(CALLBACK_MSG, (CAN_CALLBACK)CAN_CallbackFn);
	printf("Wait Msg\n");
	printf("Enter any key to exit\n");
	GetChar();
#endif
}


void Test_TestMaskFilter()
{
    int32_t i32id=0;
    STR_CANMSG_T tMsg;

    printf("Use Messge Object No.1 to send ID=0x700 ~0x70F\n");
    printf("Enter any key to send\n ");

    GetChar();
    while(1)
    {
    	/* Send a 11-bits message */
	    tMsg.FrameType= DATA_FRAME;
	    tMsg.IdType   = CAN_STD_ID;
	    tMsg.Id 	  = 0x700 + i32id;
	    tMsg.DLC	  = 0;

    	if(CAN_SetTxMsgObj(MSG(1),&tMsg) < 0)	 /* Call CAN_SetTxMsgObj() only Confiugre Msg RAM */
	    {
		    printf("Set Tx Msg Object failed\n");
		    return;
	    }
	    CAN_SetTxRqst(MSG(1));
        i32id++;
        if(i32id>=0x10)
            break;
        SYS_SysTickDelay(100000);
    }
    printf("Transfer Done\n");
}


void Test_SetMaskFilter()
{
    STR_CANMASK_T MaskMsg;

	CAN_EnableInt(CAN_CON_IE);
 	CAN_InstallCallback(CALLBACK_MSG, (CAN_CALLBACK)CAN_CallbackFn);
	
	/* Set b'0' means don't care*/
	/* Set Messge Object No.0 mask ID */
	MaskMsg.u8Xtd    = 1;
	MaskMsg.u8Dir    = 1;
	MaskMsg.u8IdType = 0;     /* 1:EXT or 0:STD */
	MaskMsg.u32Id 	 = 0x707;
	CAN_SetMsgObjMask(MSG(0),&MaskMsg);
	CAN_SetRxMsgObj(MSG(0), CAN_STD_ID, 0x7FF , TRUE);

    printf("The sample code should be with Item[4]\n\n");

    printf("Set Receive Message Object Contect\n");
    printf("===================================\n");
    printf("Message Object No.0 :Receive STD_ID:0x7FF\n\n\n");
    printf("Set Mask Content\n");
    printf("==========================\n");
    printf("Compare Xtd: %s\n",MaskMsg.u8Xtd?"YES":"NO");
    printf("Compare Dir: %s\n",MaskMsg.u8Dir?"YES":"NO");
    printf("Compare MaskID:%s 0x%x\n\n\n",MaskMsg.u8IdType? "EXT":"STD",MaskMsg.u32Id);
    printf("If there is a message-ID 0x700~0x70F,\n ONLY 0x707/0x70F can pass acceptance filter.\n");

    printf("Waiting Message\n");
	SYS_SysTickDelay(100000);
	GetChar();

	CAN_UninstallCallback(CALLBACK_MSG);
   	CAN_DisableInt(CAN_CON_IE);
	
}



/*----------------------------------------------------------------------------*/
/*  Some description about how to create test environment         	 	      */
/*----------------------------------------------------------------------------*/
void Note_Configure()
{
    printf("\n\n");
    printf("+------------------------------------------------------------------------+\n");
    printf("|  About CAN sample code configure                                       |\n");
    printf("+------------------------------------------------------------------------+\n");
    printf("|   The sample code provide a simple sample code for you study CAN       |\n");
    printf("|   Before execute it, please check description as below                 |\n");
    printf("|                                                                        |\n");
    printf("|   1.CAN_TX and CAN_RX should be connected to your CAN transceiver      |\n");
    printf("|   2.Using two module board and connect to the same CAN BUS             |\n");
    printf("|   3.Check the terminal resistor of bus is connected                    |\n");
    printf("|   4.Using UART0 as print message port(Both of NUC1xx module boards)    |\n");
    printf("|                                                                        |\n"); 
    printf("|  |--------|       |----------|   CANBUS  |----------|       |--------| |\n");     
    printf("|  |        |------>|          |<--------->|          |<------|        | |\n"); 
    printf("|  |        |CAN_TX |   CAN    |   CAN_H   |   CAN    |CAN_TX |        | |\n");     
    printf("|  | NUC1XX |       |Tranceiver|           |Tranceiver|       | NUC1XX | |\n"); 
    printf("|  |        |<------|          |<--------->|          |------>|        | |\n"); 
    printf("|  |        |CAN_RX |          |   CAN_L   |          |CAN_RX |        | |\n");    
    printf("|  |--------|       |----------|           |----------|       |--------| |\n");     
    printf("|   |                                                           |        |\n");
    printf("|   |                                                           |        |\n");
    printf("|   V                                                           V        |\n");
    printf("| UART0                                                         UART0    |\n");
    printf("|(print message)                                          (print message)|\n");
    printf("+------------------------------------------------------------------------+\n");
}

/*----------------------------------------------------------------------------*/
/*  Test Menu    													   	 	  */
/*----------------------------------------------------------------------------*/
void TestItem(void)
{
    printf("\n");
    printf("+------------------------------------------------------------------ +\n");
    printf("|  Nuvoton CAN BUS DRIVER DEMO                                      |\n");
    printf("+-------------------------------------------------------------------+\n");
    printf("|  [0] Transmit a message by basic mode                             |\n");
    printf("|  [1] Receive a message by basic mode                              |\n");
    printf("|  [2] Transmit a message by normal mode                            |\n");
    printf("|  [3] Receive a message by normal mode                             |\n");
	printf("|  [4] Test Mask Filter                                             |\n");
    printf("|  [5] Set Mask Filter                                              |\n");
    printf("+-------------------------------------------------------------------+\n");
}


void TestFnMsg_RXOK(uint32_t u32Parameter)
{
    STR_CANMSG_T rMsg;
    CAN_ResetIF(1);
    CAN->IF[1].MCON  =0; 

	CAN_BasicReceiveMsg(&rMsg);
    CAN_ShowMsg(&rMsg);
}

void SelectCANSpeed()
{
    uint32_t unItem;
    int32_t i32Err =0;

    printf("Please select CAN speed you desired\n");
    printf("[0] 1000Kbps\n");
    printf("[1]  500Kbps\n");
    printf("[2]  250Kbps\n");
    printf("[3]  125Kbps\n");
    printf("[4]  100Kbps\n");
    printf("[5]   50Kbps\n");

    unItem = GetChar();
    printf("%c\n",unItem) ;
    if(unItem=='1')
        i32Err = CAN_Open(500);
    else if(unItem=='2')
        i32Err = CAN_Open(250);
    else if(unItem=='3')
        i32Err = CAN_Open(125);
    else if(unItem=='4')
        i32Err = CAN_Open(100);
    else if(unItem=='5')
        i32Err = CAN_Open(50);
    else
        i32Err = CAN_Open(1000);

    if(i32Err<0)
        printf("Set CAN bit rate is fail\n");
}


void SYS_Init(void)
{
/*---------------------------------------------------------------------------------------------------------*/
/* Init System Clock                                                                                       */
/*---------------------------------------------------------------------------------------------------------*/
    /* Unlock protected registers */
    SYS_UnlockReg();

    /* Enable external 12MHz XTAL */
    SYSCLK->PWRCON |= SYSCLK_PWRCON_XTL12M_EN_Msk;

    /* Enable internal 22.1184 MHz Oscillator */
    SYSCLK->PWRCON |= SYSCLK_PWRCON_IRC22M_EN_Msk;

    /* Waiting for clock ready */
    SYS_WaitingForClockReady(SYSCLK_CLKSTATUS_XTL12M_STB_Msk | SYSCLK_CLKSTATUS_IRC22M_STB_Msk);
    
    /* Force system to use other clock source before PLL setting */
    SYSCLK->CLKSEL0 = SYSCLK_CLKSEL0_HCLK_IRC22M;

    /* Disable PLL before changing PLL setting */
    SYSCLK->PLLCON |= SYSCLK_PLLCON_PD_Msk;
    
    /* Enable PLL and update new PLL setting */
    SYSCLK->PLLCON = PLLCON_SETTING;
    
    /* Waiting for PLL ready */
    SYS_WaitingForClockReady(SYSCLK_CLKSTATUS_PLL_STB_Msk);

    /* Switch HCLK clock source to PLL */
    SYSCLK->CLKSEL0 = SYSCLK_CLKSEL0_HCLK_PLL;

    /* Enable IP clock */        
    SYSCLK->APBCLK = SYSCLK_APBCLK_UART0_EN_Msk | SYSCLK_APBCLK_TMR0_EN_Msk | 
                     SYSCLK_APBCLK_CAN0_EN_Msk | SYSCLK_APBCLK_CAN1_EN_Msk;

    /* IP clock source */
    SYSCLK->CLKSEL1 = SYSCLK_CLKSEL1_UART_PLL | SYSCLK_CLKSEL1_TMR0_XTAL;

    /* Update System Core Clock */
    /* User can use SystemCoreClockUpdate() to calculate PllClock, SystemCoreClock and CycylesPerUs automatically. */
    //SystemCoreClockUpdate(); 
    PllClock        = PLL_CLOCK;            // PLL
    SystemCoreClock = PLL_CLOCK / 1;        // HCLK
    CyclesPerUs     = PLL_CLOCK / 1000000;  // For SYS_SysTickDelay()

/*---------------------------------------------------------------------------------------------------------*/
/* Init I/O Multi-function                                                                                 */
/*---------------------------------------------------------------------------------------------------------*/
    
    /* Set PA multi-function pins for CANTX1, CANRX1 */
    SYS->GPA_MFP = SYS_GPA_MFP_PA10_CANTX1 | SYS_GPA_MFP_PA11_CANRX1;
    
    /* Set PB multi-function pins for UART0 RXD, UART0 TXD */
    SYS->GPB_MFP = SYS_GPB_MFP_PB0_RXD0 | SYS_GPB_MFP_PB1_TXD0;

    /* Set PD multi-function pins for CANTX0, CANRX0 */
    SYS->GPD_MFP = SYS_GPD_MFP_PD6_CAN0RX | SYS_GPD_MFP_PD7_CAN0TX;

    /* Alt setting for CANTX1, CANRX1 */
    SYS->ALT_MFP = SYS_ALT_MFP_PA10_CANTX1 | SYS_ALT_MFP_PA11_CANRX1;


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


/*----------------------------------------------------------------------------*/
/*  MAIN function													   	 	  */
/*----------------------------------------------------------------------------*/
int main (void)
{
	uint8_t item;
    UNLOCKREG();

    SYS_Init();
    UART0_Init();
    
    /* Set GPD14 to control CAN transceiver for Nuvoton board */
    PD14 = 0;

	/* Select CAN Multi-Function */
    CAN_Init();
    Note_Configure();
    SelectCANSpeed();
    do
    {
        TestItem();
        item = GetChar();    
        printf("\n");
        switch (item)
        {
            case '0':
            {
                printf("[0] Transmit a message by basic mode\n\n");
                printf("Please confirm receiver is ready.\n");
                printf("Press any key to continue ...\n\n");
                GetChar();
                Test_BasicMode_Tx();
                break;     
            }
            case '1': 
            {
                printf("[1] Receive a message by basic mode\n\n");
                Test_BasicMode_Rx();
                break;     
            }
            case '2':
            {
                printf("[2] Transmit a message by normal mode\n\n");
                printf("Please confirm receiver is ready.\n");
                printf("Press any key to continue ...\n\n");
                GetChar();
                Test_NormalMode_Tx();
                break;     
            }
            case '3': 
            {
                printf("[3] Receive a message by normal mode\n\n");
                Test_NormalMode_Rx();
                break;     
            }
            case '4':
            {
                printf("[4] Test Mask Filter\n\n");
                printf("Please confirm [Set Mask Filter] of receiver is selected.\n");
                printf("Press any key to continue ...\n\n");
                GetChar();
                Test_TestMaskFilter();
                break;      
            }
            case '5':
            {
                printf("[5] Set Mask Filter\n\n");
                Test_SetMaskFilter();
                break;
            }
            default:
            {
                printf("Unknown command!\n\n");
            }
              
        }
    }while(item != 27);
	
	CAN_Close(); 
}







