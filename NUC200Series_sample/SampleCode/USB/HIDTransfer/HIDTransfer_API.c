/****************************************************************************
 * @file     HIDTransfer_API.c
 * @version  V1.00
 * $Revision: 3 $
 * $Date: 8/07/12 11:00a $ 
 * @brief    NUC200 Series USB HID Transfer API
 *
 * @note
 * Copyright (C) 2011 Nuvoton Technology Corp. All rights reserved.
 *
 ******************************************************************************/
#include <stdio.h>
#include "NUC200Series.h"
#include "HIDTransferSys.h"
#include "HIDTransfer_API.h"

//#define DBG_PRINTF(...)
#define DBG_PRINTF  printf

#define USB_VID			0x0416  /* Vendor ID */
#define USB_PID			0x5020  /* Product ID */

#define USB_VID_LO      (USB_VID & 0xFF)
#define USB_VID_HI      ((USB_VID >> 8) & 0xFF)

#define USB_PID_LO      (USB_PID & 0xFF)
#define USB_PID_HI      ((USB_PID >> 8) & 0xFF)

#define HID_DEFAULT_INT_IN_INTERVAL		1
#define HID_IS_SELF_POWERED         	0
#define HID_IS_REMOTE_WAKEUP        	0
#define HID_MAX_POWER               	50  /* The unit is in 2mA. ex: 50 * 2mA = 100mA */

#define LEN_CONFIG_AND_SUBORDINATE (LEN_CONFIG+LEN_INTERFACE+LEN_HID+LEN_ENDPOINT*2)

#define HID_CMD_SIGNATURE   0x43444948

/* HID Transfer Commands */
#define HID_CMD_NONE     0x00
#define HID_CMD_ERASE    0x71
#define HID_CMD_READ     0xD2
#define HID_CMD_WRITE    0xC3
#define HID_CMD_TEST     0xB4

#define PAGE_SIZE		 256

typedef __packed struct {
    uint8_t u8Cmd;
    uint8_t u8Size;
    uint32_t u32Arg1;
    uint32_t u32Arg2;
    uint32_t u32Signature;
    uint32_t u32Checksum;
}CMD_T;

CMD_T gCmd;    


uint8_t g_au8DeviceReport[HID_MAX_PACKET_SIZE_INT_IN];
const uint32_t g_u32DeviceReportSize = sizeof(g_au8DeviceReport) / sizeof(g_au8DeviceReport[0]);

const uint8_t gau8DeviceReportDescriptor[] =
{

 	0x05, 0x01, // USAGE_PAGE (Generic Desktop)
 	0x09, 0x00, // USAGE (0)
 	0xA1, 0x01, // COLLECTION (Application)
 	0x15, 0x00, //     LOGICAL_MINIMUM (0)
 	0x25, 0xFF, //     LOGICAL_MAXIMUM (255)
 	0x19, 0x01, //     USAGE_MINIMUM (1)
 	0x29, 0x08, //     USAGE_MAXIMUM (8) 
 	0x95, HID_MAX_PACKET_SIZE_INT_OUT, //     REPORT_COUNT (8)
 	0x75, 0x08, //     REPORT_SIZE (8)
 	0x81, 0x02, //     INPUT (Data,Var,Abs)
 	0x19, 0x01, //     USAGE_MINIMUM (1)
 	0x29, 0x08, //     USAGE_MAXIMUM (8) 
 	0x91, 0x02, //   OUTPUT (Data,Var,Abs)
 	0xC0        // END_COLLECTION
};

#define HID_DEVICE_REPORT_DESCRIPTOR_SIZE \
	sizeof (gau8DeviceReportDescriptor) / sizeof(gau8DeviceReportDescriptor[0])

const uint32_t gu32DeviceReportDescriptorSize = HID_DEVICE_REPORT_DESCRIPTOR_SIZE;

#define HID_REPORT_DESCRIPTOR_SIZE 		HID_DEVICE_REPORT_DESCRIPTOR_SIZE

extern int8_t imageBegin0, imageEnd;

const uint8_t gau8DeviceDescriptor[LEN_DEVICE] =
{
	LEN_DEVICE,		    		/* bLength 				*/
	DESC_DEVICE,	    		/* bDescriptorType 		*/
	0x10, 0x01,		    		/* bcdUSB 				*/
	0x00,			    		/* bDeviceClass 		*/
	0x00,			    		/* bDeviceSubClass 		*/
	0x00,			    		/* bDeviceProtocol 		*/
	HID_MAX_PACKET_SIZE_CTRL,/* bMaxPacketSize0 	*/
	USB_VID & 0x00FF,			/* Vendor ID 			*/
	(USB_VID & 0xFF00) >> 8, 
	USB_PID & 0x00FF,			/* Product ID 			*/
	(USB_PID & 0xFF00) >> 8, 
	0x00, 0x00,		    		/* bcdDevice 			*/
	0x01,			    		/* iManufacture 		*/
	0x02,			    		/* iProduct				*/
	0x00,			    		/* iSerialNumber 		*/
	0x01			    		/* bNumConfigurations 	*/
};

const uint8_t gau8ConfigDescriptor[] =
{
	LEN_CONFIG,		// bLength
	DESC_CONFIG,	// bDescriptorType
	// wTotalLength
	LEN_CONFIG_AND_SUBORDINATE & 0x00FF,
	(LEN_CONFIG_AND_SUBORDINATE & 0xFF00) >> 8,
	0x01,			// bNumInterfaces
	0x01,			// bConfigurationValue
	0x00,			// iConfiguration
	0xC0,			// bmAttributes
	0x32,			// MaxPower

    
 	LEN_INTERFACE,
 	DESC_INTERFACE,
 	0x00,           // bInterfaceNumber
 	0x00,           // bAlternateSetting
 	0x02,           // bNumEndpoints
 	0x03,           // bInterfaceClass
 	0x00,           // bInterfaceSubClass
 	HID_FUNCTION,   // bInterfaceProtocol
 	0x00,           // iInterface
 

 	LEN_HID,        // bLength
 	DESC_HID,       // bDescriptorType
 	0x10, 0x01,     // bcdHID
 	0x00,           // bCountryCode
 	0x01,           // bNumDescriptor
 	DESC_HID_RPT,   // bDescriptorType
	HID_REPORT_DESCRIPTOR_SIZE & 0x00FF,            // wDescriptorLen
	(HID_REPORT_DESCRIPTOR_SIZE & 0xFF00) >> 8,
	
 	LEN_ENDPOINT,                                   // bLength
 	DESC_ENDPOINT,                                  // bDescriptorType
 	HID_IN_EP_NUM | 0x80,                           // bEndpointAddress
 	EP_INT,                                         // bmAttributes
 	HID_MAX_PACKET_SIZE_INT_IN & 0x00FF,                // wMaxPacketSize
	(HID_MAX_PACKET_SIZE_INT_IN & 0xFF00) >> 8,         
 	HID_DEFAULT_INT_IN_INTERVAL,                    // bInterval

 	LEN_ENDPOINT,                                   // bLength
 	DESC_ENDPOINT,                                  // bDescriptorType
 	HID_OUT_EP_NUM,                                 // bEndpointAddress
 	EP_INT,                                         // bmAttributes
	HID_MAX_PACKET_SIZE_INT_IN & 0x00FF,                // wMaxPacketSize
	(HID_MAX_PACKET_SIZE_INT_IN & 0xFF00) >> 8,
 	HID_DEFAULT_INT_IN_INTERVAL                     // bInterval
};

const uint8_t gau8StringLang[] = 
{
	4,				/* bLength                  */
	DESC_STRING,	/* bDescriptorType          */
	0x09, 0x04      /* Language ID: USA(0x0409) */
};

const uint8_t gau8VendorStringDescriptor[] = 
{
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


const uint8_t gau8ProductStringDescriptor[] = 
{
	26,             /* bLength          */
	DESC_STRING,    /* bDescriptorType  */
	'H', 0, 
	'I', 0, 
	'D', 0, 
	' ', 0, 
	'T', 0, 
	'r', 0, 
	'a', 0, 
	'n', 0, 
	's', 0, 
	'f', 0, 
	'e', 0, 
	'r', 0
};


const uint8_t gau8StringSerial[26] =
{
	26,				// bLength
	DESC_STRING,	// bDescriptorType
	'B', 0, 
	'0', 0, 
	'2', 0, 
	'0', 0, 
	'1', 0, 
	'0', 0, 
	'0', 0, 
	'4', 0, 
	'1', 0, 
	'3', 0, 
	'0', 0, 
	'2', 0
};


static uint8_t  g_u8PageBuff[PAGE_SIZE] = {0};    /* Page buffer to upload/download through HID report */
static uint32_t g_u32BytesInPageBuf = 0;                         /* The bytes of data in g_u8PageBuff */



int32_t HID_CmdEraseSectors(CMD_T *pCmd)
{
    uint32_t u32StartSector;
    uint32_t u32Sectors;
    uint32_t i;
    
    u32StartSector = pCmd->u32Arg1;
    u32Sectors = pCmd->u32Arg2;

	DBG_PRINTF("Erase command - Sector: %d   Sector Cnt: %d\n", u32StartSector, u32Sectors);
	
	for(i=0;i<u32Sectors;i++)
	{
	    DBG_PRINTF("Erase sector - %d\n",u32StartSector + i);
		/* TODO: To erase the sector of storage */
	
	}
	/* To note the command has been done */
	pCmd->u8Cmd = HID_CMD_NONE;
	
	return 0;
}


int32_t HID_CmdReadPages(CMD_T *pCmd)
{
    uint32_t u32StartPage;
    uint32_t u32Pages;
    int32_t i;

    
    u32StartPage = pCmd->u32Arg1;
    u32Pages     = pCmd->u32Arg2;

	DBG_PRINTF("Read command - Start page: %d    Pages Numbers: %d\n", u32StartPage, u32Pages);

    if(u32Pages)
    {
        /* Update data to page buffer to upload */
		/* TODO: We need to update the page data if got a page read command. (0xFF is used in this sample code) */
        for(i=0;i<PAGE_SIZE;i++)
            g_u8PageBuff[i] = 0xFF;
        g_u32BytesInPageBuf = PAGE_SIZE;
        
        /* The signature word is used as page counter */
        pCmd->u32Signature = 1;
        
	    /* Trigger HID IN */
		USBD_DataIn(HID_IN_EP_NUM, g_u8PageBuff, HID_MAX_PACKET_SIZE_INT_IN);
		g_u32BytesInPageBuf-= HID_MAX_PACKET_SIZE_INT_IN;
		
    }

	return 0;
}


int32_t HID_CmdWritePages(CMD_T *pCmd)
{
    uint32_t u32StartPage;
    uint32_t u32Pages;
    
    u32StartPage = pCmd->u32Arg1;
    u32Pages     = pCmd->u32Arg2;

	DBG_PRINTF("Write command - Start page: %d    Pages Numbers: %d\n", u32StartPage, u32Pages);
    g_u32BytesInPageBuf = 0;
    
    /* The signature is used to page counter */
    pCmd->u32Signature = 0;

	return 0;
}




int32_t gi32CmdTestCnt = 0;
int32_t HID_CmdTest(CMD_T *pCmd)
{
    int32_t i;
    uint8_t *pu8;
    
    pu8 = (uint8_t *)pCmd;
    DBG_PRINTF("Get test command #%d (%d bytes)\n", gi32CmdTestCnt++, pCmd->u8Size);
    for(i=0;i<pCmd->u8Size;i++)
    {
        if((i&0xF) == 0)
        {
            DBG_PRINTF("\n");
        }
        DBG_PRINTF(" %02x", pu8[i]);
    }
    
    DBG_PRINTF("\n");
    
    
	/* To note the command has been done */
	pCmd->u8Cmd = HID_CMD_NONE;
	
	return 0;
}


uint32_t CalCheckSum(uint8_t *buf, uint32_t size)
{
    uint32_t sum;
    int32_t i;

    i = 0;
    sum = 0;
    while(size--)
    {
        sum+=buf[i++];
    }

    return sum;

}


int32_t ProcessCommand(uint8_t *pu8Buffer, uint32_t u32BufferLen)
{
	uint32_t u32sum;

	
    USBD_memcpy((uint8_t *)&gCmd, pu8Buffer, u32BufferLen);
    
    /* Check size */
    if((gCmd.u8Size > sizeof(gCmd)) || (gCmd.u8Size > u32BufferLen))    
        return -1;

    /* Check signature */
    if(gCmd.u32Signature != HID_CMD_SIGNATURE)
        return -1;
        
    /* Calculate checksum & check it*/        
    u32sum = CalCheckSum((uint8_t *)&gCmd, gCmd.u8Size);
    if(u32sum != gCmd.u32Checksum)
        return -1;
    
	switch(gCmd.u8Cmd)
	{
		case HID_CMD_ERASE:
		{
			HID_CmdEraseSectors(&gCmd);
			break;
		}		
		case HID_CMD_READ:
		{
			HID_CmdReadPages(&gCmd);
			break;
		}		
		case HID_CMD_WRITE:
		{
			HID_CmdWritePages(&gCmd);
			break;		
		}
		case HID_CMD_TEST:
		{
		    HID_CmdTest(&gCmd);
		    break;
		}
		default:
			return -1;
	}	
	
	return 0;
}


void HID_SetOutReport(uint8_t *pu8EpBuf, uint32_t u32Size)
{
    uint8_t  u8Cmd;
    uint32_t u32StartPage;
    uint32_t u32Pages;
    uint32_t u32PageCnt;

    /* Get command information */
    u8Cmd        = gCmd.u8Cmd;
    u32StartPage = gCmd.u32Arg1;
    u32Pages     = gCmd.u32Arg2;
    u32PageCnt   = gCmd.u32Signature; /* The signature word is used to count pages */
    

    /* Check if it is in the data phase of write command */
    if((u8Cmd == HID_CMD_WRITE) &&  (u32PageCnt < u32Pages))
    {
        /* Process the data phase of write command */


        /* Get data from HID OUT */
		USBD_memcpy(&g_u8PageBuff[g_u32BytesInPageBuf], pu8EpBuf, HID_MAX_PACKET_SIZE_INT_IN);
		g_u32BytesInPageBuf += HID_MAX_PACKET_SIZE_INT_IN;

        /* The HOST must make sure the data is PAGE_SIZE alignment */
		if(g_u32BytesInPageBuf >= PAGE_SIZE)
		{
		    DBG_PRINTF("Writing page %d\n", u32StartPage + u32PageCnt);
			/* TODO: We should program received data to storage here */
			u32PageCnt++;
		
		    /* Write command complete! */
			if(u32PageCnt >= u32Pages)
			{
				u8Cmd = HID_CMD_NONE;	
		        
		        DBG_PRINTF("Write command complete.\n");
		    }

  			g_u32BytesInPageBuf = 0;

		}

		/* Update command status */
		gCmd.u8Cmd        = u8Cmd;
		gCmd.u32Signature = u32PageCnt;
    }
    else
    {
        /* Check and process the command packet */
        if(ProcessCommand(pu8EpBuf, u32Size))
        {
            DBG_PRINTF("Unknown HID command!\n");
        }        
    }
}

void HID_GetInReport(uint8_t *buf)
{
    uint32_t u32StartPage;
    uint32_t u32TotalPages;
    uint32_t u32PageCnt;
    uint8_t u8Cmd;
	int32_t i;
    
    u8Cmd        = gCmd.u8Cmd;
    u32StartPage = gCmd.u32Arg1;
    u32TotalPages= gCmd.u32Arg2;
    u32PageCnt   = gCmd.u32Signature;

    /* Check if it is in data phase of read command */
	if(u8Cmd == HID_CMD_READ)
	{
	    /* Process the data phase of read command */
        if((u32PageCnt >= u32TotalPages) && (g_u32BytesInPageBuf == 0))
        {
    		/* The data transfer is complete. */
            u8Cmd = HID_CMD_NONE;
            DBG_PRINTF("Read command complete!\n");
        }    
	    else
	    {
	        if(g_u32BytesInPageBuf == 0)
	        {
	            /* The previous page has sent out. Read new page to page buffer */
				/* TODO: We should update new page data here. (0xFF is used in this sample code) */
				DBG_PRINTF("Reading page %d\n", u32StartPage + u32PageCnt);
		        for(i=0;i<PAGE_SIZE;i++)
		            g_u8PageBuff[i] = 0xFF;
					
	            g_u32BytesInPageBuf = PAGE_SIZE;
	        
	            /* Update the page counter */
	            u32PageCnt++;
	        }
	    
            /* Prepare the data for next HID IN transfer */	    
    		USBD_DataIn(HID_IN_EP_NUM, &g_u8PageBuff[PAGE_SIZE - g_u32BytesInPageBuf], HID_MAX_PACKET_SIZE_INT_IN);
    		g_u32BytesInPageBuf -= HID_MAX_PACKET_SIZE_INT_IN;
		}
	}
	
	gCmd.u8Cmd        = u8Cmd;
	gCmd.u32Signature = u32PageCnt; 
	
}


void HID_MainProcess(void)
{
	E_USBD_STATE eUsbState;

    USBD_Open((void *)USBD_DispatchEvent);
    
    HID_Open((void *)HID_GetInReport, (void *)HID_SetOutReport); 
        
    eUsbState = USBD_GetUsbState();
    
    if (eUsbState >= eUSBD_ATTACHED)
    {
        _USBD_ENABLE_SE0();
        SYS_SysTickDelay(10000); /* 10ms */
        _USBD_DISABLE_SE0();
    }
    
	
	/* Disable USB-related interrupts */
	_USBD_ENABLE_MISC_INT(0);

	/* Enable float-detection interrupt */
	_USBD_ENABLE_FLDET_INT();
	
    /* Enable USB relative interrupt */    
	_USBD_ENABLE_MISC_INT(INTEN_WAKEUP | INTEN_WAKEUPEN | INTEN_FLDET | INTEN_USB | INTEN_BUS);
 
    while(1)
    {
        eUsbState = USBD_GetUsbState();
        
        if ( eUsbState == eUSBD_DETACHED )
        {
            DBG_PRINTF("USB Detached.\n");
            /* Just waiting for USB attach */
            while (eUsbState == eUSBD_DETACHED)
            {
                eUsbState = USBD_GetUsbState();
            }
        }
    }
}



