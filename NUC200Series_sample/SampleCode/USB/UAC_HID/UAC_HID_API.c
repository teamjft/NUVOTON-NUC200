/****************************************************************************
 * @file     UAC_HID_API.c
 * @version  V1.00
 * $Revision: 3 $
 * $Date: 8/07/12 11:34a $ 
 * @brief    NUC200 Series UAC HID API
 *
 * @note
 * Copyright (C) 2011 Nuvoton Technology Corp. All rights reserved.
 *
 ******************************************************************************/
#include <string.h>
#include "NUC200Series.h"
#include "UACHIDSys.h"


#define USB_VID     0x0416  /* Vendor ID */
#define USB_PID     0x1000  /* Product ID */


#define HID_DEFAULT_INT_IN_INTERVAL  20


#if(PLAY_CHANNELS == 1)
#define PLAY_CH_CFG     1
#endif
#if(PLAY_CHANNELS == 2)
#define PLAY_CH_CFG     3
#endif

#if(REC_CHANNELS == 1)
#define REC_CH_CFG     1
#endif
#if(REC_CHANNELS == 2)
#define REC_CH_CFG     3
#endif


#define PLAY_RATE_LO    ( PLAY_RATE        & 0xFF)
#define PLAY_RATE_MD    ((PLAY_RATE >> 8)  & 0xFF)
#define PLAY_RATE_HI    ((PLAY_RATE >> 16) & 0xFF)

#define REC_RATE_LO     ( REC_RATE        & 0xFF)
#define REC_RATE_MD     ((REC_RATE >> 8)  & 0xFF)
#define REC_RATE_HI     ((REC_RATE >> 16) & 0xFF)

#define USB_VID_LO      ( USB_VID       & 0xFF)
#define USB_VID_HI      ((USB_VID >> 8) & 0xFF)

#define USB_PID_LO      ( USB_PID       & 0xFF)
#define USB_PID_HI      ((USB_PID >> 8) & 0xFF)


const uint8_t gau8DeviceDescriptor[] =
{
    LEN_DEVICE,                 /* bLength */
    DESC_DEVICE,                /* bDescriptorType */
    0x10, 0x01,                 /* bcdUSB */
    0x00,                       /* bDeviceClass */
    0x00,                       /* bDeviceSubClass */
    0x00,                       /* bDeviceProtocol */
    UAC_MAX_PACKET_SIZE_EP0,    /* bMaxPacketSize0 */
    USB_VID_LO,     
    USB_VID_HI,                 /* idVendor */
    USB_PID_LO, 
    USB_PID_HI,                 /* idProduct */
    0x00, 0x01,                 /* bcdDevice */
    0x01,                       /* iManufacture */
    0x02,                       /* iProduct */
    0x00,                       /* iSerialNumber */
    0x01                        /* bNumConfigurations */
};

const uint8_t g_HID_au8KeyboardReportDescriptor[] = 
{
      0x05, 0x01,
      0x09, 0x06,
      0xA1, 0x01,
      0x05, 0x07,
      0x19, 0xE0,
      0x29, 0xE7,
      0x15, 0x00,
      0x25, 0x01,
      0x75, 0x01,
      0x95, 0x08,
      0x81, 0x02,
      0x95, 0x01,
      0x75, 0x08,
      0x81, 0x01,
      0x95, 0x05,
      0x75, 0x01,
      0x05, 0x08,
      0x19, 0x01,
      0x29, 0x05,
      0x91, 0x02,             
      0x95, 0x01,             
      0x75, 0x03,             
      0x91, 0x01,
      0x95, 0x06,             
      0x75, 0x08,             
      0x15, 0x00,            
      0x25, 0x65,
      0x05, 0x07,
      0x19, 0x00,
      0x29, 0x65,
      0x81, 0x00,
      0xC0  
};

#define HID_KEYBOARD_REPORT_DESCRIPTOR_SIZE \
    sizeof(g_HID_au8KeyboardReportDescriptor) / sizeof(g_HID_au8KeyboardReportDescriptor[0])
const uint32_t g_HID_u32KeyboardReportDescriptorSize = HID_KEYBOARD_REPORT_DESCRIPTOR_SIZE;

#define HID_REPORT_DESCRIPTOR_SIZE   HID_KEYBOARD_REPORT_DESCRIPTOR_SIZE


const uint8_t gau8ConfigDescriptor[] =
{
    LEN_CONFIG,     /* bLength */
    DESC_CONFIG,    /* bDescriptorType */
    0xD9,0x00,      /* wTotalLength */
    0x04,           /* bNumInterfaces */
    0x01,           /* bConfigurationValue */
    0x00,           /* iConfiguration */
    0x80,           /* bmAttributes */
    0x20,           /* Max power */

    /* Standard AC inteface */
    0x09,           /* bLength */
    0x04,           /* bDescriptorType */
    0x00,           /* bInterfaceNumber */
    0x00,           /* bAlternateSetting */
    0x00,           /* bNumEndpoints */
    0x01,           /* bInterfaceClass:AUDIO */
    0x01,           /* bInterfaceSubClass:AUDIOCONTROL */
    0x00,           /* bInterfaceProtocol */
    0x00,           /* iInterface */

    /* Class-spec AC interface descriptor */
    0x0A,           /* bLength */
    0x24,           /* bDescriptorType:CS_INTERFACE */
    0x01,           /* bDescriptorSubType:HEADER */
    0x00,0x01,      /* bcdADC:1.0 */
    0x46,0x00,      /* wTotalLength */
    0x02,           /* bInCollection */
    0x01,           /* baInterfaceNr(1) */
    0x02,           /* baInterfaceNr(n) */
    
    /* TID 1: Input for usb streaming */
    0x0C,               /* bLength */
    0x24,               /* bDescriptorType:CS_INTERFACE */
    0x02,               /* bDescriptorSubType:INPUT_TERMINAL */
    0x01,               /* bTerminalID */
    0x01,0x01,          /* wTerminalType: 0x0101 usb streaming */
    0x00,               /* bAssocTerminal */
    PLAY_CHANNELS,      /* bNrChannels */
    PLAY_CH_CFG,0x00,   /* wChannelConfig */
    0x00,               /* iChannelNames */
    0x00,               /* iTerminal */

    /* UNIT ID 5: Feature Unit */
    0x08,               /* bLength */
    0x24,               /* bDescriptorType */
    0x06,               /* bDescriptorSubType */
    REC_FEATURE_UNITID, /* bUnitID */
    0x04,               /* bSourceID */
    0x01,               /* bControlSize */
    0x03,               /* bmaControls(0) */
    0x00,               /* iFeature */


    /* TID 2: Output Terminal for usb streaming */
    0x09,               /* bLength */
    0x24,               /* bDescriptorType:CS_INTERFACE */
    0x03,               /* bDescriptorSubType:OUTPUT_TERMINAL */
    0x02,               /* bTerminalID */
    0x01,0x01,          /* wTerminalType: 0x0101 usb streaming */
    0x00,               /* bAssocTerminal */
    REC_FEATURE_UNITID, /* bSourceID */
    0x00,               /* iTerminal */

    /* UNIT ID 6: Feature Unit */
    0x0A,               /* bLength */
    0x24,               /* bDescriptorType */
    0x06,               /* bDescriptorSubType */
    PLAY_FEATURE_UNITID, /* bUnitID */
    0x01,               /* bSourceID */
    0x01,               /* bControlSize */
    0x01,               /* bmaControls(0) */
    0x02,               /* bmaControls(0) */
    0x02,               /* bmaControls(0) */
    0x00,               /* iFeature */
    
    /* TID 3: Output for speaker */
    0x09,           /* bLength*/
    0x24,           /* bDescriptorType:CS_INTERFACE*/
    0x03,           /* bDescriptorSubType:OUTPUT_TERMINAL*/
    0x03,           /* bTerminalID*/
    0x01,0x03,      /* wTerminalType: 0x0301 speaker*/
    0x00,           /* bAssocTerminal*/
    0x06, /* bSourceID*/
    0x00,           /* iTerminal*/

    /* TID 4: Input Terminal for microphone */
    0x0C,               /* bLength */
    0x24,               /* bDescriptorType:CS_INTERFACE */
    0x02,               /* bDescriptorSubType:INPUT_TERMINAL*/
    0x04,               /* bTerminalID*/
    0x01,0x02,          /* wTerminalType: 0x0201 microphone*/
    0x00,               /* bAssocTerminal*/
    REC_CHANNELS,       /* bNrChannels*/
    REC_CH_CFG, 0x00,   /* wChannelConfig*/
    0x00,               /* iChannelNames*/
    0x00,               /* iTerminal*/

    /* Standard AS interface 1, alternate 0 */
    0x09,           /* bLength */
    0x04,           /* bDescriptorType */
    0x01,           /* bInterfaceNumber */
    0x00,           /* bAlternateSetting */
    0x00,           /* bNumEndpoints */
    0x01,           /* bInterfaceClass:AUDIO */
    0x02,           /* bInterfaceSubClass:AUDIOSTREAMING */
    0x00,           /* bInterfaceProtocol */
    0x00,           /* iInterface */                     
    
    /* Standard AS interface 1, alternate 1 */
    0x09,           /* bLength */
    0x04,           /* bDescriptorType */
    0x01,           /* bInterfaceNumber */
    0x01,           /* bAlternateSetting */
    0x01,           /* bNumEndpoints */
    0x01,           /* bInterfaceClass:AUDIO */
    0x02,           /* bInterfaceSubClass:AUDIOSTREAMING */
    0x00,           /* bInterfaceProtocol */
    0x00,           /* iInterface */
    
    /* Class-spec AS interface, this interface's endpoint connect to TID 0x02 */
    0x07,           /* bLength */
    0x24,           /* bDescriptorType:CS_INTERFACE */
    0x01,           /* bDescriptorSubType:AS_GENERAL */
    0x02,           /* bTernimalLink */
    0x01,           /* bDelay */
    0x01,0x00,      /* wFormatTag:0x0001 PCM */
    
    /* Type I format type Descriptor */
    0x0B,           /* bLength */
    0x24,           /* bDescriptorType:CS_INTERFACE */
    0x02,           /* bDescriptorSubType:FORMAT_TYPE */
    0x01,           /* bFormatType:FORMAT_TYPE_I */
    REC_CHANNELS,   /* bNrChannels */
    0x02,           /* bSubFrameSize */
    0x10,           /* bBitResolution */
    0x01,           /* bSamFreqType : 0 continuous; 1 discrete */
    REC_RATE_LO,
    REC_RATE_MD,
    REC_RATE_HI,    /* Sample Frequency */
    
    /* Standard AS ISO Audio Data Endpoint */
    0x09,                       /* bLength */
    0x05,                       /* bDescriptorType */
    ISO_IN_EP_NUM | EP_INPUT,   /* bEndpointAddress */
    0x05,                       /* bmAttributes */
    ISO_IN_MXPLD,0x00,          /* wMaxPacketSize*/
    0x01,                       /* bInterval*/
    0x00,                       /* bRefresh*/
    0x00,                       /* bSynchAddress*/
    
    /* Class-spec AS ISO Audio Data endpoint Descriptor */
    0x07,           /* bLength */
    0x25,           /* bDescriptorType:CS_ENDPOINT */
    0x01,           /* bDescriptorSubType:EP_GENERAL */
    0x00,           /* bmAttributes */
    0x00,           /* bLockDelayUnits */
    0x00, 0x00,     /* wLockDelay */

    /* Standard AS interface 2, alternate 0 */
    0x09,           /* bLength */
    0x04,           /* bDescriptorType */
    0x02,           /* bInterfaceNumber */
    0x00,           /* bAlternateSetting */
    0x00,           /* bNumEndpoints */
    0x01,           /* bInterfaceClass:AUDIO */
    0x02,           /* bInterfaceSubClass:AUDIOSTREAMING */
    0x00,           /* bInterfaceProtocol */
    0x00,           /* iInterface */

    /* Standard AS interface 2, alternate 1 */
    0x09,           /* bLength */
    0x04,           /* bDescriptorType */
    0x02,           /* bInterfaceNumber */
    0x01,           /* bAlternateSetting */
    0x01,           /* bNumEndpoints */
    0x01,           /* bInterfaceClass:AUDIO */
    0x02,           /* bInterfaceSubClass:AUDIOSTREAMING */
    0x00,           /* bInterfaceProtocol */
    0x00,           /* iInterface */
    
    /* Class-spec AS inf this interface's endpoint connect to TID 0x01 */
    0x07,           /* bLength */
    0x24,           /* bDescriptorType:CS_INTERFACE */
    0x01,           /* bDescriptorSubType:AS_GENERAL */
    0x01,           /* bTernimalLink */
    0x01,           /* bDelay */
    0x01,0x00,      /* wFormatTag:0x0001 PCM */   

    /* Type I format type Descriptor */
    0x0B,           /* bLength */
    0x24,           /* bDescriptorType:CS_INTERFACE */
    0x02,           /* bDescriptorSubType:FORMAT_TYPE */
    0x01,           /* bFormatType:FORMAT_TYPE_I */
    PLAY_CHANNELS,  /* bNrChannels */
    0x02,           /* bSubFrameSize */
    0x10,           /* bBitResolution */
    0x01,           /* bSamFreqType : 0 continuous; 1 discrete */
    PLAY_RATE_LO,
    PLAY_RATE_MD,
    PLAY_RATE_HI,   /* Sample Frequency */
    
    /* Standard AS ISO Audio Data Endpoint, output, addtess 2, Max 0x40 */
    0x09,                       /* bLength */
    0x05,                       /* bDescriptorType */
    ISO_OUT_EP_NUM | EP_OUTPUT, /* bEndpointAddress */
    0x0d,                       /* bmAttributes */
    ISO_OUT_MXPLD, 0x00,        /* wMaxPacketSize */
    0x01,                       /* bInterval */
    0x00,                       /* bRefresh */
    0x00,                       /* bSynchAddress */
       
    /* Class-spec AS ISO Audio Data endpoint Descriptor */
    0x07,           /* bLength */
    0x25,           /* bDescriptorType:CS_ENDPOINT */
    0x01,           /* bDescriptorSubType:EP_GENERAL */
    0x80,           /* bmAttributes */
    0x00,           /* bLockDelayUnits */
    0x00, 0x00,     /* wLockDelay */

    // I/F descr: HID
    LEN_INTERFACE,  // bLength
    DESC_INTERFACE, // bDescriptorType
    0x03,           // bInterfaceNumber
    0x00,           // bAlternateSetting
    0x01,           // bNumEndpoints
    0x03,           // bInterfaceClass
    //HID_FUNCTION,         // bInterfaceSubClass
    //HID_FUNCTION,         // bInterfaceProtocol
    0x01,           // bInterfaceSubClass
    0x01,           // bInterfaceProtocol   
    0x00,           // iInterface

    // HID Descriptor
    LEN_HID,        // Size of this descriptor in UINT8s.
    DESC_HID,       // HID descriptor type.
    0x10, 0x01,     // HID Class Spec. release number.
    0x00,           // H/W target country.
    0x01,           // Number of HID class descriptors to follow.
    DESC_HID_RPT,   // Dscriptor type.
    
    /* Total length of report descriptor */
    HID_REPORT_DESCRIPTOR_SIZE & 0x00FF,
    (HID_REPORT_DESCRIPTOR_SIZE & 0xFF00) >> 8,

    /* EP Descriptor: interrupt in */
    LEN_ENDPOINT,   // bLength
    DESC_ENDPOINT,  // bDescriptorType
    (HID_IN_EP_NUM | EP_INPUT),         // bEndpointAddress
    EP_INT,         // bmAttributes
    // wMaxPacketSize
    HID_IN_MXPLD & 0x00FF,
    (HID_IN_MXPLD & 0xFF00) >> 8,
    HID_DEFAULT_INT_IN_INTERVAL     // bInterval
};

const uint8_t gau8StringLang[4] =
{
    4,              /* bLength */
    DESC_STRING,    /* bDescriptorType */
    0x09, 0x04
};

const uint8_t gau8StringSerial[26] =
{
    26,             /* bLength */
    DESC_STRING,    /* bDescriptorType */
    'B', 0, 
    '0', 0, 
    '2', 0, 
    '0', 0, 
    '0', 0, 
    '8', 0, 
    '0', 0, 
    '3', 0, 
    '2', 0, 
    '1', 0, 
    '1', 0, 
    '5', 0
};

const uint8_t gau8StringAudio[] =
{
    0x1E,           /* bLength */
    DESC_STRING,    /* bDescriptorType */
    'U', 0, 
    'S', 0, 
    'B', 0, 
    ' ', 0, 
    'M', 0, 
    'i', 0, 
    'c', 0, 
    'r', 0, 
    'o', 0, 
    'p', 0, 
    'h', 0, 
    'o', 0, 
    'n', 0, 
    'e', 0
};

const uint8_t gau8VendorStringDescriptor[] = 
{
    16,
    DESC_STRING,
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
    42,
    DESC_STRING,
    'U', 0, 
    'S', 0, 
    'B', 0, 
    ' ', 0, 
    'A', 0, 
    'u', 0, 
    'd', 0, 
    'i', 0, 
    'o', 0,
    '&', 0,
    'H', 0,
    'I', 0,
    'D', 0,
    ' ', 0,
    'D', 0,
    'e', 0,
    'v', 0,
    'i', 0,
    'c', 0,
    'e', 0
};


uint8_t g_au8KeyboardReport[8];
const uint32_t g_u32KeyboardReportSize = sizeof(g_au8KeyboardReport) / sizeof(g_au8KeyboardReport[0]);

void HID_GetInReport(uint8_t *buf);


/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* FUNCTION                                                                                                */
/*      SendRecData()                                                                                      */
/*                                                                                                         */
/* DESCRIPTION                                                                                             */
/*      The callback function when ISO IN ack. It could be used to prepare the record data for next ISO IN */
/*      transfer.                                                                                          */
/*                                                                                                         */
/* INPUTS                                                                                                  */
/*      None                                                                                               */
/*                                                                                                         */
/* OUTPUTS                                                                                                 */
/*      None                                                                                               */
/*                                                                                                         */
/* RETURN                                                                                                  */
/*      None                                                                                               */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/
void SendRecData(void)
{
    static int32_t i32Cnt = 0;
    int32_t i;
    int32_t i32Samples = REC_RATE / 1000;
    int16_t ai16PcmBuf[REC_RATE/1000];
    
    /* Generate record data */
    for(i = 0;i < i32Samples; i++)
    {
        ai16PcmBuf[i] = i32Cnt++;
        if(i32Cnt >= 16384)
            i32Cnt = -16384;
    }
    
    UAC_SendOneAudioPacket((uint8_t *)ai16PcmBuf, i32Samples);

}


/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* FUNCTION                                                                                                */
/*      DeviceEnable()                                                                                     */
/*                                                                                                         */
/* DESCRIPTION                                                                                             */
/*      To enable the device to play or record audio data.                                                 */
/*                                                                                                         */
/* INPUTS                                                                                                  */
/*      u8Object    To select the device. It could be UAC_MICROPHONE or UAC_SPEAKER.                       */
/*                                                                                                         */
/*      u8State     To indicate the calling stage. 0 = Call by set interface. 1 = Call by first ISO IN ack.*/
/*                                                                                                         */
/* OUTPUTS                                                                                                 */
/*      None                                                                                               */
/*                                                                                                         */
/* RETURN                                                                                                  */
/*                                                                                                         */
/*      None                                                                                               */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/
void DeviceEnable(uint8_t u8Object, uint8_t u8State)
{

    if (u8Object == UAC_MICROPHONE)
    {
        /* Enable record hardware */
    }
    else
    {
        /* Eanble play hardware */
    }
}


/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* FUNCTION                                                                                                */
/*      DeviceDisable()                                                                                    */
/*                                                                                                         */
/* DESCRIPTION                                                                                             */
/*      To disable the device to play or record audio data.                                                */
/*                                                                                                         */
/* INPUTS                                                                                                  */
/*      u8Object    To select the device. It could be UAC_MICROPHONE or UAC_SPEAKER.                       */
/*                                                                                                         */
/*                                                                                                         */
/* OUTPUTS                                                                                                 */
/*      None                                                                                               */
/*                                                                                                         */
/* RETURN                                                                                                  */
/*                                                                                                         */
/*      None                                                                                               */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/
void DeviceDisable(uint8_t u8Object)
{
    if (u8Object ==  UAC_MICROPHONE )
    {
    }
    else
    {
    }   
}


/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* FUNCTION                                                                                                */
/*      GetPlayData()                                                                                      */
/*                                                                                                         */
/* DESCRIPTION                                                                                             */
/*      To get data from ISO OUT.                                                                          */
/*                                                                                                         */
/* INPUTS                                                                                                  */
/*      pi16src    The data buffer of ISO OUT.                                                             */
/*      i16Samples The sample number in data buffer.                                                       */
/*                                                                                                         */
/* OUTPUTS                                                                                                 */
/*      None                                                                                               */
/*                                                                                                         */
/* RETURN                                                                                                  */
/*                                                                                                         */
/*      None                                                                                               */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/
void GetPlayData(int16_t *pi16src, int16_t i16Samples)
{
    /* Get play data from ISO out packets */
    
    /* Toggle GPIO to show it is playing */
    static int32_t i32DelayCnt = 0;
    if(i32DelayCnt++ > PLAY_RATE/100)
    {
        PC15 ^= 1;
        i32DelayCnt = 0;
    }
}


/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* FUNCTION                                                                                                */
/*      UAC_MainProcess()                                                                                  */
/*                                                                                                         */
/* DESCRIPTION                                                                                             */
/*      The main loop of UAC funciton.                                                                     */
/*                                                                                                         */
/* INPUTS                                                                                                  */
/*      None                                                                                               */
/*                                                                                                         */
/* OUTPUTS                                                                                                 */
/*      None                                                                                               */
/*                                                                                                         */
/* RETURN                                                                                                  */
/*                                                                                                         */
/*      None                                                                                               */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/
int32_t UACHID_MainProcess(void)
{
    E_USBD_STATE eUsbState;
    int32_t i32Ret = E_SUCCESS;


    /* Install the UAC control callbacks */
    UAC_Init(DeviceEnable, DeviceDisable, SendRecData, GetPlayData);

    if (i32Ret == E_SUCCESS)
    {
        /* Install the USB event handler to USB event callback */       
        i32Ret = USBD_Open((void *)USBD_DispatchEvent);
        HID_SetReportDescriptor(g_HID_au8KeyboardReportDescriptor, g_HID_u32KeyboardReportDescriptorSize);
        
        /* Set the HID report buffer */
        HID_SetReportBuf(g_au8KeyboardReport, g_u32KeyboardReportSize);
        UAC_Open((void *)HID_GetInReport);
        
               
        /* If the USB has been attached already, we should force the bus reset. */
        eUsbState = USBD_GetUsbState();
        if (eUsbState >= eUSBD_ATTACHED)
        {
            /* Force Bus Reset for 150 ms*/
            _USBD_ENABLE_SE0();
            SYS_SysTickDelay(150000);
            _USBD_DISABLE_SE0();
        }
                    
        // Disable USB-related interrupts.
        _USBD_ENABLE_MISC_INT(0);

        // Enable float-detection interrupt.
        _USBD_ENABLE_FLDET_INT();
        
        _USBD_ENABLE_MISC_INT(INTEN_WAKEUP | INTEN_WAKEUPEN | INTEN_FLDET | INTEN_USB | INTEN_BUS);
 
        while(1)
        {      

            eUsbState = USBD_GetUsbState();
            
            if (eUsbState == eUSBD_DETACHED)
            {
                /* Just waiting for USB attach */
                while (eUsbState == eUSBD_DETACHED)
                {
                    eUsbState = USBD_GetUsbState();
                }
            }
        }
    }
    
    return 0;
}

void HID_GetInReport(uint8_t *buf)
{
    int32_t i;
    uint32_t key;
    
    key = PA->PIN;
    {
        /* No any key pressed */
        if (((key >> 3) & 0xF) == 0xF)
        {
            for(i=0;i<8;i++)
            {
                buf[i] = 0;
            }
        }
        
        /* Key A (GPIOA3) Pressed */
        if ((key & (1<<3)) == 0)
        {
            buf[2] = 0x04; /* a */
        }
        
        /* Key B (GPIOA4) Pressed */
        if ((key & (1<<4)) == 0)
        {
            buf[2] = 0x05; /* b */   
        }
        
        /* Key C (GPIOA5) Pressed */
        if ((key & (1<<5)) == 0)
        {
            buf[2] = 0x06; /* c */ 
        }
        
        /* Key D (GPIOA6) Pressed */
        if ((key & (1<<6)) == 0)
        {
            /* abc */
            buf[2] = 0x04;
            buf[3] = 0x05;
            buf[4] = 0x06;
        }
    }
}

