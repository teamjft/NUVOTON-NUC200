/****************************************************************************
 * @file     HID_API.c
 * @version  V1.00
 * $Revision: 4 $
 * $Date: 12/08/08 7:09p $ 
 * @brief    NUC200 Series USB HID API
 *
 * @note
 * Copyright (C) 2012 Nuvoton Technology Corp. All rights reserved.
 *
 ******************************************************************************/
#include "NUC200Series.h"
#include "HIDTouchSys.h"
#include "HID_API.h"

#define HID_DIGITIZER   3
#define HID_FUNCTION    HID_DIGITIZER

/* Define the vendor id and product id */
#define USB_VID			0x0416
#define USB_PID			(0xC143 + HID_FUNCTION)

#define HID_DEFAULT_INT_IN_INTERVAL	10
#define HID_IS_SELF_POWERED         0
#define HID_IS_REMOTE_WAKEUP        0
#define HID_MAX_POWER               50  	/* The unit is in 2mA. ex: 50 * 2mA = 100mA */

#define HID_REPORT_SIZE             64		/* set maximum packet size */

#define LEN_CONFIG_AND_SUBORDINATE (LEN_CONFIG+LEN_INTERFACE+LEN_HID+LEN_ENDPOINT*2)

extern S_HID_DEVICE g_HID_sDevice;

/* Multi-touch digitizer */
#if defined(__ICCARM__)
  #define pragma data_alignment = 4
  const uint8_t gau8DigitizerReportDescriptor[] = {
#else
const __align(4) uint8_t gau8DigitizerReportDescriptor[] = {
#endif
	0x05, 0x0D,			// USAGE_PAGE (Digitizers)
	0x09, 0x04,			// USAGE (Touch Screen)
	0xA1, 0x01 ,		// COLLECTION (Application)
	0x85, 0x01 ,		//   REPORT_ID (1)
	0x09, 0x22 ,		//   USAGE (Finger)
	0xA1, 0x02 ,		//   COLLECTION (Logical)
	0x09, 0x42 ,		//     USAGE (Tip Switch)
	0x15, 0x00 ,		//     LOGICAL_MINIMUM (0)
	0x25, 0x01 ,		//     LOGICAL_MAXIMUM (1)
	0x75, 0x01 ,		//     REPORT_SIZE (1)
	0x95, 0x01 ,		//     REPORT_COUNT (1)
	0x81, 0x02 ,		//     INPUT (Data,Var,Abs)
	0x09, 0x32 ,		//     USAGE (In Range)
	0x81, 0x02 ,		//     INPUT (Data,Var,Abs)
	0x09, 0x47 ,		//     USAGE (Touch Valid)
	0x81, 0x02 ,		//     INPUT (Data,Var,Abs)
	0x95, 0x05 ,		//     REPORT_COUNT (5)
	0x81, 0x03 ,		//     INPUT (Cnst,Ary,Abs)
	0x75, 0x08 ,		//     REPORT_SIZE (8)
	0x09, 0x51 ,		//     USAGE (Contact Identifier)
	0x95, 0x01 ,		//     REPORT_COUNT (1)
	0x81, 0x02 ,		//     INPUT (Data,Var,Abs)
	0x05, 0x01 ,		//     USAGE_PAGE (Generic Desktop)
	0x75, 0x10 ,		//     REPORT_SIZE (16)
	0x55, 0x0E ,		//     UNIT_EXPONENT (-2)
	0x65, 0x11 ,		//     UNIT (Centimeter)
	0x09, 0x30 ,		//     USAGE (X)
	0x35, 0x00 ,		//     PHYSICAL_MINIMUM (0)
	0x46, 0xE3, 0x13 ,	//     PHYSICAL_MAXIMUM (0x13E3)
	0x26, 0x7F, 0x07 ,	//     LOGICAL_MAXIMUM (0x77F)
	0x81, 0x02 ,		//     INPUT (Data,Var,Abs)
	0x09, 0x31 ,		//     USAGE (Y)
	0x46, 0x2F, 0x0B ,	//     PHYSICAL_MAXIMUM (0xB2F)
	0x26, 0x37, 0x04 ,	//     LOGICAL_MAXIMUM (0x437)
	0x81, 0x02 ,		//     INPUT (Data,Var,Abs)
	0xC0 ,				//   END_COLLECTION
	0xA1, 0x02 ,		//   COLLECTION (Logical)
	0x05, 0x0D ,		//    USAGE_PAGE (Digitizers)
	0x09, 0x42 ,		//     USAGE (Tip Switch)
	0x15, 0x00 ,		//     LOGICAL_MINIMUM (0)
	0x25, 0x01 ,		//     LOGICAL_MAXIMUM (1)
	0x75, 0x01 ,		//     REPORT_SIZE (1)
	0x95, 0x01 ,		//     REPORT_COUNT (1)
	0x81, 0x02 ,		//     INPUT (Data,Var,Abs)
	0x09, 0x32 ,		//     USAGE (In Range)
	0x81, 0x02 ,		//     INPUT (Data,Var,Abs)
	0x09, 0x47 ,		//     USAGE (Touch Valid)
	0x81, 0x02 ,		//     INPUT (Data,Var,Abs)
	0x95, 0x05 ,		//     REPORT_COUNT (5)
	0x81, 0x03 ,		//     INPUT (Cnst,Ary,Abs)
	0x75, 0x08 ,		//     REPORT_SIZE (8)
	0x09, 0x51 ,		//     USAGE (Contact Identifier)
	0x95, 0x01 ,		//     REPORT_COUNT (1)
	0x81, 0x02 ,		//     INPUT (Data,Var,Abs)
	0x05, 0x01 ,		//     USAGE_PAGE (Generic Desktop)
	0x75, 0x10 ,		//     REPORT_SIZE (16)
	0x55, 0x0E ,		//     UNIT_EXPONENT (-2)
	0x65, 0x11 ,		//     UNIT (Centimeter)
	0x09, 0x30 ,		//     USAGE (X)
	0x35, 0x00 ,		//     PHYSICAL_MINIMUM (0)
	0x46, 0xE3, 0x13 ,	//     PHYSICAL_MAXIMUM (0x13E3)
	0x26, 0x7F, 0x07 ,	//     LOGICAL_MAXIMUM (0x77F)
	0x81, 0x02 ,		//     INPUT (Data,Var,Abs)
	0x46, 0x2F, 0x0B ,	//     PHYSICAL_MAXIMUM (0xB2F)
	0x26, 0x37, 0x04 ,	//     LOGICAL_MAXIMUM (0x437)
	0x09, 0x31 ,		//     USAGE (Y)
	0x81, 0x02 ,		//     INPUT (Data,Var,Abs)
	0xC0 ,				//   END_COLLECTION
	0x05, 0x0D ,		//   USAGE_PAGE (Digitizers)
	0x09, 0x54 ,		//   USAGE (Contact Count)
	0x15, 0x00 ,		//   LOGICAL_MINIMUM (0)
	0x26, 0xFF, 0x00 ,	//   LOGICAL_MAXIMUM (0x00FF)
	0x95, 0x01 ,		//   REPORT_COUNT (1)
	0x75, 0x08 ,		//   REPORT_SIZE (8)
	0x81, 0x02 ,		//   INPUT (Data,Var,Abs)
	0x09, 0x55 ,		//   USAGE (Contact Count Maximum)
	0x25, 0x02 ,		//   LOGICAL_MAXIMUM (2)
	0x95, 0x01 ,		//   REPORT_COUNT (1)
	0x85, 0x02 ,		//   REPORT_ID (2)
	0xB1, 0x02 ,		//   FEATURE (Data,Var,Abs)
	0xC0 				// END_COLLECTION
};

#define HID_DIGITIZER_REPORT_DESCRIPTOR_SIZE \
    sizeof(gau8DigitizerReportDescriptor) / sizeof(gau8DigitizerReportDescriptor[0])
const uint32_t gu32DigitizerReportDescriptorSize = HID_DIGITIZER_REPORT_DESCRIPTOR_SIZE;

#define HID_REPORT_DESCRIPTOR_SIZE HID_DIGITIZER_REPORT_DESCRIPTOR_SIZE

#if defined(__ICCARM__)
  #define pragma data_alignment = 4
  uint8_t gau8DigitizerReport[HID_REPORT_SIZE];
#else
__align(4) uint8_t gau8DigitizerReport[HID_REPORT_SIZE];
#endif
const uint32_t gu32DigitizerReportSize = sizeof(gau8DigitizerReport) / sizeof(gau8DigitizerReport[0]);

#define gSerialIndex	0x00	// no serial number
//#define gSerialIndex	0x03	// has unique serial number

#if defined(__ICCARM__)
  #define pragma data_alignment = 4
  const uint8_t gau8DeviceDescriptor[] = 
#else
const __align(4) uint8_t gau8DeviceDescriptor[] =
#endif
{
	LEN_DEVICE,		// bLength
	DESC_DEVICE,	// bDescriptorType
	0x10, 0x01,		// bcdUSB
	0x00,			// bDeviceClass
	0x00,			// bDeviceSubClass
	0x00,			// bDeviceProtocol
	HID_MAX_PACKET_SIZE_EP0,	// bMaxPacketSize0
	// idVendor
	USB_VID & 0x00FF,
	(USB_VID & 0xFF00) >> 8,
	// idProduct
	USB_PID & 0x00FF,
	(USB_PID & 0xFF00) >> 8,
	0x00, 0x00,		// bcdDevice
	0x01,			// iManufacture
	0x02,			// iProduct
	gSerialIndex,	// iSerialNumber
	0x01			// bNumConfigurations
};

#if defined(__ICCARM__)
  #define pragma data_alignment = 4
  const uint8_t gau8ConfigDescriptor[] =
#else
const __align(4) uint8_t gau8ConfigDescriptor[] =
#endif
{
	LEN_CONFIG,		// bLength
	DESC_CONFIG,	// bDescriptorType
	// wTotalLength
	LEN_CONFIG_AND_SUBORDINATE & 0x00FF,
	(LEN_CONFIG_AND_SUBORDINATE & 0xFF00) >> 8,
	0x01,			// bNumInterfaces
	0x01,			// bConfigurationValue
	0x00,			// iConfiguration
	(HID_IS_SELF_POWERED << 6) | (HID_IS_REMOTE_WAKEUP << 5),// bmAttributes
	HID_MAX_POWER,			// MaxPower

	// I/F descr: HID
	LEN_INTERFACE,	// bLength
	DESC_INTERFACE,	// bDescriptorType
	0x00,			// bInterfaceNumber
	0x00,			// bAlternateSetting
	0x02,			// bNumEndpoints
	0x03,			// bInterfaceClass
	0x00,			// bInterfaceSubClass
	0x00,			// bInterfaceProtocol
	0x00,			// iInterface

	// HID Descriptor
	LEN_HID,		// Size of this descriptor in UINT8s.
	DESC_HID,		// HID descriptor type.
	0x10, 0x01, 	// HID Class Spec. release number.
	0x00,			// H/W target country.
	0x01,			// Number of HID class descriptors to follow.
	DESC_HID_RPT,	// Dscriptor type.
	// Total length of report descriptor.
	HID_REPORT_DESCRIPTOR_SIZE & 0x00FF,
	(HID_REPORT_DESCRIPTOR_SIZE & 0xFF00) >> 8,

	// EP Descriptor: interrupt in.
	LEN_ENDPOINT,	// bLength
	DESC_ENDPOINT,	// bDescriptorType
	HID_IN_EP_NUM | EP_INPUT,   // bEndpointAddress
	EP_INT, // bmAttributes
	// wMaxPacketSize
	HID_MAX_PACKET_SIZE_EP1 & 0x00FF,
	(HID_MAX_PACKET_SIZE_EP1 & 0xFF00) >> 8,
	HID_DEFAULT_INT_IN_INTERVAL,		// bInterval

	// EP Descriptor: interrupt out.
	LEN_ENDPOINT,	// bLength
	DESC_ENDPOINT,	// bDescriptorType
	HID_OUT_EP_NUM | EP_OUTPUT,   // bEndpointAddress
	EP_INT, // bmAttributes
	// wMaxPacketSize
	HID_MAX_PACKET_SIZE_EP2 & 0x00FF,
	(HID_MAX_PACKET_SIZE_EP2 & 0xFF00) >> 8,
	HID_DEFAULT_INT_IN_INTERVAL		// bInterval

};

#if defined(__ICCARM__)
  #define pragma data_alignment = 4
  const uint8_t gau8StringLang[4] =
#else
const __align(4) uint8_t gau8StringLang[4] =
#endif
{
	4,				// bLength
	DESC_STRING,	// bDescriptorType
	0x09, 0x04
};

#if defined(__ICCARM__)
  #define pragma data_alignment = 4
  const uint8_t gau8VendorStringDescriptor[] =
#else
const __align(4) uint8_t gau8VendorStringDescriptor[] =
#endif
{
	16,
	DESC_STRING,
	'N', 0,
    'U', 0,
    'V', 0,
    'O', 0,
    'T', 0,
    'O', 0,
    'N', 0
};
#if defined(__ICCARM__)
  #define pragma data_alignment = 4
  const uint8_t gau8ProductStringDescriptor[] =
#else
const __align(4) uint8_t gau8ProductStringDescriptor[] =
#endif
{
	22,
	DESC_STRING,
	'M', 0,
    'u', 0,
    'l', 0,
    't', 0,
    'i', 0,
    'T', 0,
    'o', 0,
    'u', 0,
    'c', 0,
    'h', 0
};

#if defined(__ICCARM__)
  #define pragma data_alignment = 4
  const uint8_t gau8StringSerial[26] =
#else
const __align(4) uint8_t gau8StringSerial[26] =
#endif
{
	26,				// bLength
	DESC_STRING,	// bDescriptorType
	'B', 0, 
	'0', 0, 
	'2', 0, 
	'0', 0, 
	'0', 0, 
	'6', 0, 
	'0', 0, 
	'9', 0, 
	'2', 0, 
	'1', 0, 
	'1', 0, 
	'4', 0
};

void HID_Init(void *pfGetInReport, void *pfSetOutReport)
{
	/* Open HID to initial the descriptors and control handlers */
	HID_Open(HID_REPORT_SIZE, pfGetInReport, pfSetOutReport);
	
    /* Set the HID report descriptor */
	HID_SetReportDescriptor(gau8DigitizerReportDescriptor, gu32DigitizerReportDescriptorSize);

    /* Set the HID report buffer */
	HID_SetReportBuf(gau8DigitizerReport, 0);
}

/* This callback will be executed whenever the interrupt IN transaction is received from HOST to get
   report. */
#if 0
/* one line demo in Paint */
unsigned char bIsSend04 = 0;
void HID_GetInReport(uint8_t *buf)
{
    static unsigned short posX = 0x0180, posY = 0x0100;
    
    if(g_HID_sDevice.u32ReportSize)
        return;

    buf = g_HID_sDevice.pu8Report;

    /* Report ID 1 */
	buf[0] = 1;
	buf[2] = 0;
	buf[3] = posX & 0xff;
	buf[4] = (posX >> 8) & 0xff;
	buf[5] = posY & 0xff;
	buf[6] = (posY >> 8) & 0xff;
	buf[7] = 0x00;
	buf[8] = 0x01;
	buf[9] = 0x00;
	buf[10] = 0x00;
	buf[11] = 0x00;
	buf[12] = 0x00;

	if ((posX >= 0x0200) && (posX <= 0x0400))
	{
		buf[1] = 0x7;
		buf[13] = 1;
		bIsSend04 = 1;
	}
	else if (bIsSend04)
	{
		buf[1] = 0x4;
		buf[3] = 0x00;
		buf[4] = 0x04;
		if (posY == 0x0100)
		{
			buf[5] = 0xE0;
			buf[6] = 0x02;
		}
		else
		{
			buf[5] = (posY-0x30) & 0xff;
			buf[6] = ((posY-0x30) >> 8) & 0xff;
		}
		buf[13] = 1;
		bIsSend04 = 0;
	}
	else
	{
		buf[1] = 0;
		buf[13] = 0;
	}

	posX += 0x3;
	if (posX > 0x0400)
	{
		posX = 0x0180;
		posY += 0x30;
		if (posY > 0x0300)
			posY = 0x0100;
	}

	g_HID_sDevice.u32ReportSize = 14;
	USBD_DataIn(HID_IN_EP_NUM, buf, g_HID_sDevice.u32ReportSize);
}
#else
/* two lines demo in Paint */
unsigned int ReportCount = 0;
unsigned char bIsX1Send04 = 0, bIsX2Send04 = 0;
void HID_GetInReport(uint8_t *buf)
{
    static unsigned short X1 = 0x01f0, Y1 = 0x0100;

    if(g_HID_sDevice.u32ReportSize)
        return;

    buf = g_HID_sDevice.pu8Report;

	ReportCount++;
    /* Report ID 1 */
	buf[0] = 1;
	buf[2] = 0;
	buf[8] = 1;

	if ((X1 >= 0x0200) && (X1 <= 0x0400))
	{
		bIsX1Send04 = 1;
		buf[1] = 0x07;
		buf[3] = X1 & 0xff;
		buf[4] = (X1 >> 8) & 0xff;
		buf[5] = Y1 & 0xff;
		buf[6] = (Y1 >> 8) & 0xff;
		buf[7] = 0x07;
		buf[9] = X1 & 0xff;
		buf[10] = (X1 >> 8) & 0xff;
		buf[11] = (Y1+30) & 0xff;
		buf[12] = ((Y1+30) >> 8) & 0xff;
		buf[13] = 2;
	}
	else if (bIsX1Send04)
	{
		bIsX1Send04 = 0;
		buf[1] = 0x04;
		buf[3] = 0x00;
		buf[4] = 0x04;
		buf[5] = Y1 & 0xff;
		buf[6] = (Y1 >> 8) & 0xff;
		buf[7] = 0x04;
		buf[9] = 0x00;
		buf[10] = 0x04;
		buf[11] = (Y1+0x20) & 0xff;
		buf[12] = ((Y1+0x20) >> 8) & 0xff;
		buf[13] = 2;

		if (Y1 == 0x0100)
		{
			buf[5] = 0xE0;
			buf[6] = 0x02;
			buf[11] = 0x00;
			buf[12] = 0x03;
		}
		else
		{
			buf[5] = (Y1-0x50) & 0xff;
			buf[6] = ((Y1-0x50) >> 8) & 0xff;
			buf[11] = ((Y1+0x20)-0x50) & 0xff;
			buf[12] = (((Y1+0x20)-0x50) >> 8) & 0xff;
		}
	}
	else
	{
		buf[1] = 0;
		buf[3] = 0;
		buf[4] = 0;
		buf[5] = 0;
		buf[6] = 0;
		buf[7] = 0;
		buf[9] = 0;
		buf[10] = 0;
		buf[11] = 0;
		buf[12] = 0;
		buf[13] = 0;
	}

	if ((ReportCount % 6) == 0)
		X1 += 0x3;

	if (X1 > 0x0400)
	{
		X1 = 0x01f0;
		Y1 += 0x50;
		if (Y1 > 0x0300)
			Y1 = 0x0100;
	}

	g_HID_sDevice.u32ReportSize = 14;
	USBD_DataIn(HID_IN_EP_NUM, buf, g_HID_sDevice.u32ReportSize);
}
#endif

/* This callback will be executed whenever the interrupt OUT transaction is received from HOST to set
   report. */
void HID_SetOutReport(uint8_t *buf, uint32_t size)
{
	/* The OUT length is size */
	/* The OUT data is put at *buf */

}

int32_t HID_MainProcess(void)
{
    int32_t i32Ret = E_SUCCESS;
	E_USBD_STATE eUsbState;
	int volatile i;
	    
    i32Ret = USBD_Open((void *)USBD_DispatchEvent);
    if(i32Ret != E_SUCCESS)
        return i32Ret;

	while(1)
	{
		/* Disable USB-related interrupts. */
		_USBD_ENABLE_MISC_INT(0);

		/* Enable float-detection interrupt. */
		_USBD_ENABLE_FLDET_INT();

		// Wait for USB connected.
		while (TRUE)
		{
			// Order here is significant.
			// Give a chance to handle remaining events before exiting this loop.
			eUsbState = USBD_GetUsbState();

			//USBD_DispatchEvent();

			if (eUsbState >= eUSBD_ATTACHED &&
			        eUsbState != eUSBD_SUSPENDED)
			{
				break;
			}
		}
		
		/* Start HID and install the callback functions to handle in/out report */
		HID_Init((void *)HID_GetInReport, (void *)HID_SetOutReport);

		// Enable USB-related interrupts.
		_USBD_ENABLE_MISC_INT(INTEN_WAKEUP | INTEN_WAKEUPEN | INTEN_FLDET | INTEN_USB | INTEN_BUS);

		// Poll and handle USB events.
		while(1)
		{
			eUsbState = USBD_GetUsbState();

			//USBD_DispatchEvent();
			
			HID_GetInReport(0);

			if (eUsbState == eUSBD_DETACHED)
			{
				break;
			}
		}

		// Disable USB-related interrupts.
		_USBD_ENABLE_MISC_INT(0);
    }
}
