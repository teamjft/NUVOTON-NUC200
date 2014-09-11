/****************************************************************************
 * @file     VCOM_API.c
 * @version  V1.00
 * $Revision: 3 $
 * $Date: 8/07/12 2:01p $ 
 * @brief    NUC200 Series USB VOCM API
 *
 * @note
 * Copyright (C) 2011 Nuvoton Technology Corp. All rights reserved.
 *
 ******************************************************************************/
#include <stdio.h>
#include "NUC200Series.h"
#include "VCOMSys.h"
#include "VCOM_API.h"


#define USB_VID			0x0416  /* Vendor ID */
#define USB_PID			0x5011  /* Product ID */



#define RXBUFSIZE			256 /* RX buffer size */  
#define TXBUFSIZE			256 /* RX buffer size */  
#define TX_FIFO_SIZE		64	/* TX Hardware FIFO size */         


/*---------------------------------------------------------------------------------------------------------*/
/* Global variables                                                                                        */
/*---------------------------------------------------------------------------------------------------------*/
volatile uint8_t comRbuf[RXBUFSIZE];
volatile uint16_t comRbytes = 0;
volatile uint16_t comRhead = 0;
volatile uint16_t comRtail = 0;

volatile uint8_t comTbuf[TXBUFSIZE];
volatile uint16_t comTbytes = 0;
volatile uint16_t comThead = 0;
volatile uint16_t comTtail = 0;

uint8_t gRxBuf[BULK_EP_MXPLD] = {0};


uint8_t *gpu8RxBuf = 0;
uint32_t gu32RxSize = 0;
uint32_t gu32TxSize = 0;

volatile int8_t gi8BulkOutReady = 0;



#define USB_VID_LO      (USB_VID & 0xFF)
#define USB_VID_HI      ((USB_VID >> 8) & 0xFF)

#define USB_PID_LO      (USB_PID & 0xFF)
#define USB_PID_HI      ((USB_PID >> 8) & 0xFF)


const uint8_t gau8DeviceDescriptor[] =
{
	LEN_DEVICE,		/* bLength              */
	DESC_DEVICE,	/* bDescriptorType      */
	0x10, 0x01,		/* bcdUSB               */
	0x02,			/* bDeviceClass         */
	0x00,			/* bDeviceSubClass      */
	0x00,			/* bDeviceProtocol      */
	BULK_EP_MXPLD,	/* bMaxPacketSize0      */
	USB_VID_LO,                             
	USB_VID_HI,     /* Veondor ID           */
	USB_PID_LO,     
	USB_PID_HI,     /* Product ID           */
	0x00, 0x03,		/* bcdDevice            */
	0x01,			/* iManufacture         */
	0x02,			/* iProduct             */
	0x00,			/* iSerialNumber        */
	0x01			/* bNumConfigurations   */
};


const uint8_t gau8ConfigDescriptor[] =
{
	LEN_CONFIG,		/* bLength              */
	DESC_CONFIG,	/* bDescriptorType      */
	0x43, 0x00,		/* wTotalLength         */
	0x02,			/* bNumInterfaces       */
	0x01,			/* bConfigurationValue  */
	0x00,			/* iConfiguration       */
	0xC0,			/* bmAttributes         */
	0x32,			/* MaxPower             */

	/* INTERFACE descriptor */
	LEN_INTERFACE,	/* bLength              */
	DESC_INTERFACE,	/* bDescriptorType      */
	0x00,			/* bInterfaceNumber     */
	0x00,			/* bAlternateSetting    */
	0x01,			/* bNumEndpoints        */
	0x02,			/* bInterfaceClass      */
	0x02,			/* bInterfaceSubClass   */
	0x01,			/* bInterfaceProtocol   */
	0x00,			/* iInterface           */

	/* Communication Class Specified INTERFACE descriptor */
    0x05,           /* Size of the descriptor, in bytes */
    0x24,           /* CS_INTERFACE descriptor type */
    0x00,           /* Header functional descriptor subtype */
    0x10, 0x01,     /* Communication device compliant to the communication spec. ver. 1.10 */
    
	/* Communication Class Specified INTERFACE descriptor */
    0x05,           /* Size of the descriptor, in bytes */
    0x24,           /* CS_INTERFACE descriptor type */
    0x01,           /* Call management functional descriptor */
    0x00,           /* BIT0: Whether device handle call management itself. */
                    /* BIT1: Whether device can send/receive call management information over a Data Class Interface 0 */
    0x01,           /* Interface number of data class interface optionally used for call management */

	/* Communication Class Specified INTERFACE descriptor */
    0x04,           /* Size of the descriptor, in bytes */
    0x24,           /* CS_INTERFACE descriptor type */
    0x02,           /* Abstract control management funcational descriptor subtype */
    0x00,           /* bmCapabilities       */
    
	/* Communication Class Specified INTERFACE descriptor */
    0x05,           /* bLength              */
    0x24,           /* bDescriptorType: CS_INTERFACE descriptor type */
    0x06,           /* bDescriptorSubType   */
    0x00,           /* bMasterInterface     */
    0x01,           /* bSlaveInterface0     */
    
	/* ENDPOINT descriptor */
	LEN_ENDPOINT,	                /* bLength          */
	DESC_ENDPOINT,	                /* bDescriptorType  */
	(EP_INPUT | INT_IN_EP_NUM),     /* bEndpointAddress */
	EP_INT,		                    /* bmAttributes     */
	INT_EP_MXPLD, 0x00,	            /* wMaxPacketSize   */
	0x01,	                        /* bInterval        */
			
	/* INTERFACE descriptor */
	LEN_INTERFACE,	/* bLength              */
	DESC_INTERFACE,	/* bDescriptorType      */
	0x01,			/* bInterfaceNumber     */
	0x00,			/* bAlternateSetting    */
	0x02,			/* bNumEndpoints        */
	0x0A,			/* bInterfaceClass      */
	0x00,			/* bInterfaceSubClass   */
	0x00,			/* bInterfaceProtocol   */
	0x00,			/* iInterface           */
			
	/* ENDPOINT descriptor */
	LEN_ENDPOINT,	                /* bLength          */
	DESC_ENDPOINT,	                /* bDescriptorType  */
	(EP_INPUT | BULK_IN_EP_NUM),	/* bEndpointAddress */
	EP_BULK,		                /* bmAttributes     */
	BULK_EP_MXPLD, 0x00,	        /* wMaxPacketSize   */
	0x00,			                /* bInterval        */

	/* ENDPOINT descriptor */
	LEN_ENDPOINT,	                /* bLength          */
	DESC_ENDPOINT,	                /* bDescriptorType  */
	(EP_OUTPUT | BULK_OUT_EP_NUM),	/* bEndpointAddress */
	EP_BULK,		                /* bmAttributes     */
	BULK_EP_MXPLD, 0x00,	        /* wMaxPacketSize   */
	0x00,			                /* bInterval        */
};


const uint8_t gau8StringLang[] = {
	4,				/* bLength                  */
	DESC_STRING,	/* bDescriptorType          */
	0x09, 0x04      /* Language ID: USA(0x0409) */
};


const uint8_t gau8VendorStringDescriptor[] = {
	16,             /* bLength          */
	DESC_STRING,    /* bDescriptorType  */
	'N', 0, 
	'u', 0, 
	'v', 0, 
	'o', 0, 
	't', 0, 
	'o', 0, 
	'n', 0
};

const uint8_t gau8ProductStringDescriptor[] = {
	32,             /* bLength          */
	DESC_STRING,    /* bDescriptorType  */
	'U', 0, 
	'S', 0,
	'B', 0,
	' ', 0,
	'V', 0,
	'i', 0,
	'r', 0,
	't', 0,
	'u', 0,
	'a', 0,
	'l', 0,
	' ', 0,
	'C', 0,
	'O', 0,
	'M', 0
};

const uint8_t gau8StringSerial[26] =
{
	26,				/* bLength          */
	DESC_STRING,	/* bDescriptorType  */
	'N', 0, 
	'T', 0, 
	'2', 0, 
	'0', 0, 
	'0', 0, 
	'9', 0, 
	'1', 0, 
	'0', 0, 
	'1', 0, 
	'4', 0, 
	'0', 0, 
	'0', 0
};



void VCOM_BulkOutAckCallback(void* pVoid)
{	
	gpu8RxBuf = USBD_GetOutData(BULK_OUT_EP_NUM,&gu32RxSize);
    
    /* Set a flag to indicate builk out ready */
    gi8BulkOutReady = 1;
}


void VCOM_BulkInAckCallback(void* pVoid)
{
	/* Reserved for user define */
	gu32TxSize = 0;
}


void VCOM_IntInAckCallback(void* pVoid)
{
    uint8_t au8Buf[8] = {0};
    /* Reserved for user define */
    USBD_DataIn(INT_IN_EP_NUM, au8Buf, INT_EP_MXPLD);
}


static void RoughDelay(uint32_t t)
{
    volatile int32_t delay;
    delay = t;
    while(delay-- >= 0);
}

void VCOM_MainProcess(void)
{
	E_USBD_STATE eUsbState;
	int32_t i, i32Len;
	
	
	/* Enable Interrupt and install the call back function */
	///DrvUART_EnableInt(UART_PORT0, (DRVUART_RLSINT | DRVUART_RDAINT | DRVUART_TOUTINT),UartIntHandler);

    USBD_Open((void*)USBD_DispatchEvent);
    
	VCOM_Open();
        
    /* Enable Interrupt and install the call back function */
	///DrvUART_EnableInt(UART_PORT0, DRVUART_RDAINT, UartIntHandler);

	
	eUsbState = USBD_GetUsbState();
    
	if (eUsbState >= eUSBD_ATTACHED)
    {
        /* Force Bus Reset for 150 ms*/
        _USBD_ENABLE_SE0();
        RoughDelay(150000);
        _USBD_DISABLE_SE0();
    }
    		
	/* Disable USB-related interrupts. */
	_USBD_ENABLE_MISC_INT(0);

	/* Enable float-detection interrupt. */
	_USBD_ENABLE_FLDET_INT();
        
	_USBD_ENABLE_MISC_INT(INTEN_WAKEUP | INTEN_WAKEUPEN | INTEN_FLDET | INTEN_USB | INTEN_BUS);
 
    while(1)
    {
        eUsbState = USBD_GetUsbState();
        if (eUsbState == eUSBD_DETACHED)
        {
            //printf("USB Detached.\n");
            /* Just waiting for USB attach */
            while(eUsbState == eUSBD_DETACHED)
            {
                eUsbState = USBD_GetUsbState();
            }
            //printf("USB Attached.\n");
        }

        /* Check if any data to send to USB & USB is ready to send them out */
        if(comRbytes && (gu32TxSize == 0))
        {
        	i32Len = comRbytes;
        	if(i32Len > BULK_EP_MXPLD)
        		i32Len = BULK_EP_MXPLD;
        
		    for(i=0;i<i32Len;i++)
		    {
		    	gRxBuf[i] = comRbuf[comRhead++];
		    	if(comRhead >= RXBUFSIZE)
		    		comRhead = 0;
		    }
		    
			NVIC_DisableIRQ(UART02_IRQn);
		    comRbytes -= i32Len;
			NVIC_EnableIRQ(UART02_IRQn);
		    
		    gu32TxSize = i32Len;
		    USBD_DataIn(BULK_IN_EP_NUM, gRxBuf, i32Len);
        }


		/* Process the Bulk out data when bulk out data is ready. */
		if(gi8BulkOutReady && (gu32RxSize <= TXBUFSIZE - comTbytes))
		{
			for(i=0;i<gu32RxSize;i++)
			{
			    comTbuf[comTtail++] = gpu8RxBuf[i];
			    if(comTtail >= TXBUFSIZE)
			    	comTtail = 0;
			}
			
			NVIC_DisableIRQ(UART02_IRQn);
			comTbytes += gu32RxSize;
			NVIC_EnableIRQ(UART02_IRQn);

			gu32RxSize = 0;
            gi8BulkOutReady = 0; /* Clear bulk out ready flag */

			/* Ready to get next BULK out */
		    USBD_DataOutTrigger(BULK_OUT_EP_NUM, BULK_EP_MXPLD);
		}
        

		/* Process the software Tx FIFO */
	    if(comTbytes)
	    {
	        /* Check if Tx is working */		    
		    if((UART0->IER & UART_IER_THRE_IEN_Msk) == 0)
            {
		        /* Send one bytes out */
                UART0->DATA = comTbuf[comThead++];
		        if(comThead >= TXBUFSIZE)
		            comThead = 0;

				NVIC_DisableIRQ(UART02_IRQn);
		        comTbytes--;    
				NVIC_EnableIRQ(UART02_IRQn);
		        
		        /* Enable Tx Empty Interrupt. (Trigger first one) */  
                UART0->IER |= UART_IER_THRE_IEN_Msk;
		    }
	    }


    }
}


/*---------------------------------------------------------------------------------------------------------*/
/* UART Callback function                                                                           	   */
/*---------------------------------------------------------------------------------------------------------*/
void UART02_IRQHandler(void)
{
    uint32_t u32IntStatus;
	uint8_t bInChar;
	int32_t size;

    u32IntStatus = UART0->ISR;
    
	if((u32IntStatus & 0x1 /* RDAIF */) || (u32IntStatus & 0x10 /* TOUT_IF */))
	{
        /* Receiver FIFO threashold level is reached or Rx time out */

		/* Get all the input characters */
		while((UART0->FSR & UART_FSR_RX_EMPTY_Msk) == 0)
        {
			/* Get the character from UART Buffer */
            bInChar = UART0->DATA;

			/* Check if buffer full */
			if(comRbytes < RXBUFSIZE)
			{
				/* Enqueue the character */
				comRbuf[comRtail++] = bInChar;
				if(comRtail >= RXBUFSIZE)
				    comRtail = 0;
				comRbytes++;
			}
			else
			{
			    /* FIFO over run */
			}			
		}
	}
	
	if(u32IntStatus & 0x2 /* THRE_IF */)
	{   
				   
		if(comTbytes)
		{
			/* Fill the Tx FIFO */
			size = comTbytes;
			if(size >= TX_FIFO_SIZE)
			{
				size = TX_FIFO_SIZE;   
			}
			
			while(size)
			{
				bInChar = comTbuf[comThead++];
				UART0->DATA = bInChar;
                if(comThead >= TXBUFSIZE)
				    comThead = 0;
				comTbytes--;
				size--;
			}
		}
		else
		{
		    /* No more data, just stop Tx (Stop work) */
            UART0->IER &= (~UART_IER_THRE_IEN_Msk);
		}
	}
	
}


