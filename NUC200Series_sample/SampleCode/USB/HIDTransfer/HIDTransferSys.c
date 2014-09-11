/****************************************************************************
 * @file     HIDTransferSys.c
 * @version  V1.00
 * $Revision: 3 $
 * $Date: 8/07/12 11:00a $ 
 * @brief    NUC200 Series USB HID Transfer System API
 *
 * @note
 * Copyright (C) 2011 Nuvoton Technology Corp. All rights reserved.
 *
 ******************************************************************************/
#include <stdio.h>
#include <string.h>
#include "NUC200Series.h"
#include "HIDTransferSys.h"
#include "HIDTransfer_API.h"

#define Maximum(a,b)		((a)>(b) ? (a) : (b))
#define Minimum(a,b)		((a)<(b) ? (a) : (b))

#define DBG_PRINTF(...)
//#define DBG_PRINTF          printf

/* Endpoint description */
S_USBD_EP_CTRL sEpDescription[] = 
{
	{CTRL_EP_NUM    | EP_INPUT,  HID_MAX_PACKET_SIZE_CTRL,    NULL},
	{CTRL_EP_NUM    | EP_OUTPUT, HID_MAX_PACKET_SIZE_CTRL,    NULL},
	{HID_IN_EP_NUM  | EP_INPUT,  HID_MAX_PACKET_SIZE_INT_IN,  NULL},
	{HID_OUT_EP_NUM | EP_OUTPUT, HID_MAX_PACKET_SIZE_INT_OUT, NULL},
    {0, 0, 0}
};

/* Bus event call back functions */
S_USBD_EVENT_PROCESS g_sBusOps[6] = 
{
	{NULL, NULL},                               /* Attach event callback        */
	{NULL, NULL},                               /* Detach event callback        */
	{USBD_BusResetCallback, &g_HID_sDevice}, /* Bus reset event callback     */
	{NULL, NULL},                               /* Bus suspend event callback   */
	{NULL, NULL},                               /* Bus resume event callback    */
	{USBD_CtrlSetupAck, &g_HID_sDevice},     /* Setup event callback         */
};

/* USB event call back functions */
S_USBD_EVENT_PROCESS g_sUsbOps[12] = 
{
	{USBD_CtrlDataInAck, 	 &g_HID_sDevice},	/* ctrl pipe0 */
	{USBD_CtrlDataOutAck,  &g_HID_sDevice},	
	{NULL, NULL},								/* endpoint address 1 */
	{NULL, NULL},								
	{NULL, NULL},                           	/* endpoint address 2 */
	{NULL, NULL},
	{NULL, NULL},								/* endpoint address 3 */
	{NULL, NULL},   
	{HID_IntInCallback,  	 &g_HID_sDevice},	/* endpoint address 4 */
	{NULL, NULL},								
	{NULL, NULL},								/* endpoint address 5 */
	{HID_IntOutCallback, 	 &g_HID_sDevice},	
};


/* ctrl pipe call back.                                                                   */
/* it will be call by USBD_CtrlSetupAck, USBD_CtrlDataInAck and USBD_CtrlDataOutAck */
/* if in ack handler and out ack handler is 0, default handler will be called             */
S_USBD_CTRL_CALLBACK_ENTRY g_asCtrlCallbackEntry[] = {
    //request type,command     ,setup ack handler         , in ack handler      ,out ack handler,  parameter
	{REQ_STANDARD, SET_ADDRESS, USBD_CtrlSetupSetAddress, USBD_CtrlDataInSetAddress, 0, &g_HID_sDevice},
	{REQ_STANDARD, CLEAR_FEATURE, USBD_CtrlSetupClearSetFeature, 0, 0, &g_HID_sDevice},
	{REQ_STANDARD, SET_FEATURE, USBD_CtrlSetupClearSetFeature, 0, 0, &g_HID_sDevice},
	{REQ_STANDARD, GET_CONFIGURATION, USBD_CtrlSetupGetConfiguration, 0, 0, &g_HID_sDevice},
	{REQ_STANDARD, GET_STATUS, USBD_CtrlSetupGetStatus, 0, 0, &g_HID_sDevice},
	{REQ_STANDARD, GET_INTERFACE, USBD_CtrlSetupGetInterface, 0, 0, &g_HID_sDevice},
	{REQ_STANDARD, SET_INTERFACE, USBD_CtrlSetupSetInterface, 0, 0, &g_HID_sDevice},
	{REQ_STANDARD, GET_DESCRIPTOR, HID_CtrlSetupGetDescriptor, HID_CtrlGetDescriptorIn, HID_CtrlGetDescriptorOut, &g_HID_sDevice},
	{REQ_STANDARD, SET_CONFIGURATION, HID_CtrlSetupSetConfiguration, 0, 0, &g_HID_sDevice},
	
	/* HID Class Request */
	{REQ_CLASS, SET_REPORT, HID_CtrlSetupSetReport, 0, 0, 0},
	{REQ_CLASS, SET_IDLE, HID_CtrlSetupSetIdle, 0, 0, 0},
	{REQ_CLASS, SET_PROTOCOL, HID_CtrlSetupSetProtocol, 0, 0, 0},
};

static void HID_UsbStartCallBack(void * pVoid);
S_HID_DEVICE g_HID_sDevice;

/* The callback is called when Host issues the interrupt IN transfer to get report */
void (*pfHID_GetInReport)(uint8_t *buf) = NULL;

/* The callback is called when Host issues the interrupt OUT transfer to set report */
void (*pfHID_SetOutReport)(uint8_t *buf, uint32_t u32Size) = NULL;


/* The structure registered to USB driver */
S_USBD_CLASS sHIDClass = 
{
	(void *)&g_HID_sDevice, 
	HID_UsbStartCallBack,
	NULL
};


int8_t g_bCBWInvalid;
int8_t volatile bFirstCMD = 0xFF;
int8_t volatile bIsDeviceReady = FALSE;

uint8_t g_u8Size;
uint8_t g_u8BulkState;
uint8_t g_au8SenseKey[3];
uint8_t volatile MassLUN=0;
uint8_t volatile F_SPI_LUN=0;
uint8_t preventflag=0;

//int32_t gTotalSectors = 44;
uint32_t g_u32Length;
uint32_t g_u32Address;
uint32_t g_u32LbaAddress;
uint32_t g_u32BytesInStorageBuf;


static const uint8_t * gpu8UsbBuf = 0;
static uint32_t gu32BytesInUsbBuf = 0;
static int8_t gIsOverRequest = 0;



void HID_PrepareDescriptors(const uint8_t *pu8Descriptor, uint32_t u32DescriptorSize, uint32_t u32RequestSize, uint32_t u32MaxPacketSize)
{
    
    gu32BytesInUsbBuf = u32RequestSize;
    if(u32RequestSize > u32DescriptorSize)
    {
        gIsOverRequest = 1;
        gu32BytesInUsbBuf = u32DescriptorSize; 
    }
    gpu8UsbBuf = pu8Descriptor;

    DBG_PRINTF("Get descriptor 0x%08x %d size.\n", pu8Descriptor, gu32BytesInUsbBuf);

	if(gu32BytesInUsbBuf < u32MaxPacketSize)
	{
	    USBD_DataIn(0, gpu8UsbBuf, gu32BytesInUsbBuf); 
	    gpu8UsbBuf = 0;
	    gu32BytesInUsbBuf = 0;
        gIsOverRequest = 0;   
	}
	else
	{
		USBD_DataIn(0, gpu8UsbBuf, u32MaxPacketSize);
		gpu8UsbBuf += u32MaxPacketSize;
		gu32BytesInUsbBuf -= u32MaxPacketSize;
    }

}


void HID_CtrlGetDescriptorOut(void * pVoid)
{
	USBD_ClrCtrlReady();
    gu32BytesInUsbBuf = 0;
    gpu8UsbBuf = 0;
    gIsOverRequest = 0;
}

void HID_CtrlGetDescriptorIn(void * pVoid)
{
    uint32_t u32Len;


    DBG_PRINTF(" >>> 0x%08x %d size.\n", gpu8UsbBuf, gu32BytesInUsbBuf);
	
    if(gpu8UsbBuf)
    {

        if(gu32BytesInUsbBuf == 0)
        {
            /* Zero packet */
    		USBD_DataIn(0, gpu8UsbBuf, 0);
    		gpu8UsbBuf = 0;
        }
        else
        {
            u32Len = Minimum(gu32BytesInUsbBuf, HID_MAX_PACKET_SIZE_CTRL);
    		USBD_DataIn(0, gpu8UsbBuf, u32Len);
    		gpu8UsbBuf += u32Len;
    		gu32BytesInUsbBuf -= u32Len;
    		
    		
    		if(gu32BytesInUsbBuf == 0)
    		{
                if(u32Len < HID_MAX_PACKET_SIZE_CTRL)
                {
    		        /* This should be last IN packet due to it is less than HID_MAX_PACKET_SIZE_EP0 */
    		        gpu8UsbBuf = 0;
                }
                else
                {
                    if(!gIsOverRequest)
                    {
                        gpu8UsbBuf = 0;
                    }
                }
    		}
    		
        }
    }
    else
    {
  	    /* The EP id 1 should always be used as control (OUT) endpoint */
		_USBD_TRIG_EP(1,0x00);
    }
}


/*************************************************************************/
/*                                                                       */
/* DESCRIPTION                                                           */
/*      setup ACK handler for Get descriptor command                     */
/*                                                                       */
/* INPUTS                                                                */
/*      pVoid     parameter passed by USBD_RegisterCtrl                */
/*                                                                       */
/* OUTPUTS                                                               */
/*      None                                                             */
/*                                                                       */
/* RETURN                                                                */
/*      0           Success                                              */
/*		Otherwise	error												 */
/*                                                                       */
/*************************************************************************/
void HID_CtrlSetupGetDescriptor(void * pVoid)
{
	S_HID_DEVICE *psDevice = (S_HID_DEVICE *) pVoid;
	S_USBD_DEVICE *pUsbDevice = (S_USBD_DEVICE *)psDevice->device;
	uint16_t u16Len;

	u16Len = 0;
	u16Len = pUsbDevice->au8Setup[7];
	u16Len <<= 8;
	u16Len += pUsbDevice->au8Setup[6];
	
	gIsOverRequest = 0;
	gu32BytesInUsbBuf = 0;
	gpu8UsbBuf = 0;
	switch (pUsbDevice->au8Setup[3])
	{
		// Get Device Descriptor
	case DESC_DEVICE:
	{
        HID_PrepareDescriptors(g_HID_sDevice.au8DeviceDescriptor, LEN_DEVICE, u16Len, HID_MAX_PACKET_SIZE_CTRL);
		break;
	}

	// Get Configuration Descriptor
	case DESC_CONFIG:
	{	
        HID_PrepareDescriptors(g_HID_sDevice.au8ConfigDescriptor, gau8ConfigDescriptor[2], u16Len, HID_MAX_PACKET_SIZE_CTRL);
		break;
    }
		// Get HID Descriptor
	case DESC_HID:
    {
        HID_PrepareDescriptors(g_HID_sDevice.pu8HIDDescriptor, LEN_HID, u16Len, HID_MAX_PACKET_SIZE_CTRL);
		break;
    }
		// Get Report Descriptor
	case DESC_HID_RPT:
	{
        HID_PrepareDescriptors(g_HID_sDevice.pu8ReportDescriptor, g_HID_sDevice.u32ReportDescriptorSize, u16Len, HID_MAX_PACKET_SIZE_CTRL);
		break;
    }
		// Get String Descriptor
	case DESC_STRING:
	{
		// Get Language
		if (pUsbDevice->au8Setup[2] == 0)
		{
            HID_PrepareDescriptors(gau8StringLang, 4, u16Len, HID_MAX_PACKET_SIZE_CTRL);
		}
		else
		{
			// Get String Descriptor
			switch (pUsbDevice->au8Setup[2])
			{
			case 1:
                HID_PrepareDescriptors((const uint8_t *)gau8VendorStringDescriptor, gau8VendorStringDescriptor[0], u16Len, HID_MAX_PACKET_SIZE_CTRL);
				break;

			case 2:
                HID_PrepareDescriptors((const uint8_t *)gau8ProductStringDescriptor, gau8ProductStringDescriptor[0], u16Len, HID_MAX_PACKET_SIZE_CTRL);
               
 				break;

			case 3:
                HID_PrepareDescriptors(gau8StringSerial, gau8StringSerial[0], u16Len, HID_MAX_PACKET_SIZE_CTRL);
				break;

			default:
				/* Not support. Reply STALL. */
				USBD_ClrCtrlReadyAndTrigStall();
			}
		}

		break;
	}
	default:
		/* Not support. Reply STALL. */
		USBD_ClrCtrlReadyAndTrigStall();
        return;
	}

    /* Prepare the OUT to avoid HOST stop data phase without all data transfered. */
	_USBD_TRIG_EP(1,0x00);
}



/*---------------------------------------------------------------------------------------------------------*/
/* Function: UDC_CtrlSetupSetConfiguration                                                                */
/*                                                                                                         */
/* Parameters:                                                                                             */
/*      pVoid - [in],   A pointer to USB class device structure (gsUDCDevice).                            */
/*                                                                                                         */
/* Returns:                                                                                                */
/*      None                                                                                               */
/*                                                                                                         */
/* Description:                                                                                            */
/*      The callback function when get SET_CONFIGURATION request.                                          */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/
void HID_CtrlSetupSetConfiguration(void * pVoid)
{
	S_USBD_DEVICE *pDrvDevice = &gsUsbDevice;
	S_USBD_CLASS *psUsbClass = pDrvDevice->psUsbClass;
	int8_t bIsDeviceConfigure;
	
	bIsDeviceConfigure = psUsbClass->pfnCompare ? psUsbClass->pfnCompare(pDrvDevice->au8Setup[2]) : 1;
	
	if (pDrvDevice->au8Setup[2] == 0)
	{
		// USB address state.
		USBD_SetUsbState(eUSBD_ADDRESS);
		pDrvDevice->u8UsbConfiguration = pDrvDevice->au8Setup[2];
		USBD_DataIn(0, NULL, 0);
		
	}
	else if (bIsDeviceConfigure)
	{
		// USB configured state.
		USBD_SetUsbState(eUSBD_CONFIGURED);

		//call USB class's start function
		if(psUsbClass->pfnStart)
			psUsbClass->pfnStart(pVoid);

		pDrvDevice->u8UsbConfiguration = pDrvDevice->au8Setup[2];

		USBD_DataIn(0, NULL, 0);
		
	}
	else
	{
		// Not support. Reply STALL.
		USBD_ClrCtrlReadyAndTrigStall();
	}
}


/*---------------------------------------------------------------------------------------------------------*/
/* Function: UDC_GetVersion                                                                               */
/*                                                                                                         */
/* Parameters:                                                                                             */
/*      None                                                                                               */
/*                                                                                                         */
/* Returns:                                                                                                */
/*      The virtual com driver version number                                                              */
/*                                                                                                         */
/* Description:                                                                                            */
/*      To return the virtual com drvier version number.                                                   */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/
//uint32_t UDC_GetVersion()
//{
//	return UDC_VERSION_NUM;
//}


/*---------------------------------------------------------------------------------------------------------*/
/* Function: UDCHID_Open                                                                                   */
/*                                                                                                         */
/* Parameters:                                                                                             */
/*      None                                                                                               */
/*                                                                                                         */
/* Returns:                                                                                                */
/*      E_SUCCESS                                                                                          */
/*                                                                                                         */
/* Description:                                                                                            */
/*      To install the virtual com to USB device driver and install the relative descriptors.              */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/
int32_t HID_Open(void *pfGetInReport, void *pfSetOutReport)
{
    S_HID_DEVICE *psDevice = &g_HID_sDevice;
	
	if ((uint32_t)pfGetInReport != NULL)
        pfHID_GetInReport = (void(*)(uint8_t *))pfGetInReport;

    if ((uint32_t)pfSetOutReport != NULL)
        pfHID_SetOutReport = (void(*)(uint8_t *, uint32_t))pfSetOutReport;
	
	/* Install the virtual com to USB device */
	psDevice->device = (void *)USBD_InstallClassDevice(&sHIDClass);
	
	/* Configure the descritors */
	psDevice->au8DeviceDescriptor = gau8DeviceDescriptor;
	psDevice->au8ConfigDescriptor = gau8ConfigDescriptor;			
	
	psDevice->pu8ReportDescriptor = gau8DeviceReportDescriptor;
	psDevice->u32ReportDescriptorSize = gu32DeviceReportDescriptorSize;

	psDevice->pu8Report = g_au8DeviceReport;
	psDevice->u32ReportSize = g_u32DeviceReportSize;
	
	/* Install the USB event callbacks */
	USBD_InstallCtrlHandler(psDevice->device, g_asCtrlCallbackEntry, 
	    sizeof(g_asCtrlCallbackEntry) / sizeof(g_asCtrlCallbackEntry[0]));

	return E_SUCCESS;
}


/*---------------------------------------------------------------------------------------------------------*/
/* Function: UDCHID_Close                                                                                  */
/*                                                                                                         */
/* Parameters:                                                                                             */
/*      None                                                                                               */
/*                                                                                                         */
/* Returns:                                                                                                */
/*      None                                                                                               */
/*                                                                                                         */
/* Description:                                                                                            */
/*      To close UDC and HID.                                                                              */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/
void HID_Close(void)
{

}

static void HID_Reset(S_HID_DEVICE *psDevice)
{	
	USBD_Reset(HID_IN_EP_NUM);
}

static void HID_Start(S_HID_DEVICE *psDevice)
{
	USBD_DataOutTrigger(HID_OUT_EP_NUM, HID_MAX_PACKET_SIZE_INT_OUT);
}


void HID_IntInCallback(void * pVoid)
{
	S_HID_DEVICE* psDevice = (S_HID_DEVICE*) pVoid;
	
	if ((uint32_t)pfHID_GetInReport)
	    pfHID_GetInReport(psDevice->pu8Report);
	
}

void HID_IntOutCallback(void * pVoid)
{
	uint8_t *pu8EpBuf;
	uint32_t u32Size;

	pu8EpBuf = USBD_GetOutData(HID_OUT_EP_NUM, &u32Size);

    if ((uint32_t)pfHID_SetOutReport)
	    pfHID_SetOutReport(pu8EpBuf, u32Size);
    
	USBD_DataOutTrigger(HID_OUT_EP_NUM, HID_MAX_PACKET_SIZE_INT_OUT);
}

void HID_CtrlSetupSetReport(void * pVoid)
{
	S_USBD_DEVICE *psDevice = (S_USBD_DEVICE *)((S_HID_DEVICE *)pVoid)->device;

	if(psDevice->au8Setup[3] == 1)
	{
        /* Report Type = input */

		// Trigger next Control Out DATA1 Transaction.
		_USBD_SET_EP_TOG_BIT(1, FALSE);
		_USBD_TRIG_EP(1, 0);

	}
	else if (psDevice->au8Setup[3] == 2)
	{
		_USBD_SET_EP_TOG_BIT(1, FALSE);
		_USBD_TRIG_EP(1, 0x00);

	}
	else if (psDevice->au8Setup[3] == 3)
	{
        /* Request Type = Feature */
		_USBD_SET_EP_TOG_BIT(1, FALSE);
		_USBD_TRIG_EP(1, 0x00);
	}
	else
	{
		// Not support. Reply STALL.                
		_HID_CLR_CTRL_READY_AND_TRIG_STALL();
	}
}

void HID_CtrlSetupSetIdle(void * pVoid)
{    
	_USBD_SET_EP_TOG_BIT(0, FALSE);
	_USBD_TRIG_EP(0, 0x00);
}

void HID_CtrlSetupSetProtocol(void * pVoid)
{
	_USBD_SET_EP_TOG_BIT(0, FALSE);
	_USBD_TRIG_EP(0, 0x00);
}


static void HID_UsbStartCallBack(void * pVoid)
{
	HID_Reset((S_HID_DEVICE *)pVoid);
	HID_Start((S_HID_DEVICE *)pVoid);
}


