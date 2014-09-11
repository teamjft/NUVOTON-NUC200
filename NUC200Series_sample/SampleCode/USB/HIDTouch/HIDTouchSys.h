/****************************************************************************
 * @file     HIDTouchSys.h
 * @version  V1.00
 * $Revision: 4 $
 * $Date: 12/08/08 7:04p $ 
 * @brief    NUC200 Series USB HID Touch System Header File
 *
 * @note
 * Copyright (C) 2011 Nuvoton Technology Corp. All rights reserved.
 *
 ******************************************************************************/
#ifndef __HIDTOUCH_SYS_H__
#define __HIDTOUCH_SYS_H__

#ifdef  __cplusplus
extern "C"
{
#endif


#define HID_MAJOR_NUM	1
#define HID_MINOR_NUM	00
#define HID_BUILD_NUM	1
  
// E_HID_BUFFER_OVERRUN                 Allocated buffer is not enough.
// E_HID_CTRL_REG_TAB_FULL              Control register table is full.
// E_HID_EXCEED_INT_IN_PACKET_SIZE      Report size must be less than packet size of interrupt.
// E_HID_INVALID_EP_NUM                 Invalid EP number.
// E_HID_MUST_LESS_THAN_PACKET0_SIZE    Data size in control must be less than packet0 size.
// E_HID_NULL_POINTER                   NULL pointer.
// E_HID_UNDEFINE                       Undefined error.
// E_HID_INVALID_REG_NUM				  			Invaild register unmber


#define E_HID_NULL_POINTER                   -1
#define E_HID_BUFFER_OVERRUN                 -2
#define E_HID_INVALID_EP_NUM                 -3
#define E_HID_MUST_LESS_THAN_PACKET0_SIZE    -4
#define E_HID_EXCEED_INT_IN_PACKET_SIZE      -5
#define E_HID_CTRL_REG_TAB_FULL              -6
#define E_HID_INVALID_REG_NUM                -7
#define E_HID_UNDEFINE                       -100

#define HID_VERSION_NUM    _SYSINFRA_VERSION(HID_MAJOR_NUM, HID_MINOR_NUM, HID_BUILD_NUM)

#define CTRL_EP_NUM      0x00
#define HID_IN_EP_NUM    0x01
#define HID_OUT_EP_NUM   0x02

// Max packet size of EP0
#define	HID_MAX_PACKET_SIZE_EP0		64

// Max packet size of EP1
#define HID_MAX_PACKET_SIZE_EP1		64
#define HID_MAX_PACKET_SIZE_EP2		64


//***************************************************
// 		HID Class REQUEST
//***************************************************
#define GET_REPORT          0x01
#define GET_IDLE            0x02
#define GET_PROTOCOL        0x03
#define SET_REPORT          0x09
#define SET_IDLE            0x0A
#define SET_PROTOCOL        0x0B

#define HID_RPT_TYPE_INPUT		0x01
#define HID_RPT_TYPE_OUTPUT		0x02
#define HID_RPT_TYPE_FEATURE	0x03

typedef struct
{

	const uint8_t *au8DeviceDescriptor;
	const uint8_t *au8ConfigDescriptor;

	const uint8_t *pu8IntInEPDescriptor;

	const uint8_t *pu8ReportDescriptor;
	uint32_t u32ReportDescriptorSize;

	const uint8_t *pu8HIDDescriptor;

	uint8_t *pu8Report;
	uint32_t u32ReportSize;
	uint8_t *pu8SetReportData;

	void * *device;
	
} S_HID_DEVICE;

extern S_HID_DEVICE g_HID_sDevice;

static __INLINE void _HID_CLR_CTRL_READY_AND_TRIG_STALL()
{
	_USBD_CLEAR_EP_READY_AND_TRIG_STALL(0);
	_USBD_CLEAR_EP_READY_AND_TRIG_STALL(1);
}

static __INLINE void _HID_CLR_CTRL_READY()
{
	_USBD_CLEAR_EP_READY(0);
	_USBD_CLEAR_EP_READY(1);
}

int32_t	HID_Open(uint32_t inReportSize, void *pfGetInReport, void *pfSetOutReport);
void HID_Close(void);
void HID_IntInCallback(void * pVoid);
void HID_IntOutCallback(void * pVoid);
int32_t	HID_SetReportDescriptor(const uint8_t* pu8ReportDescriptor, uint32_t u32ReportDescriptorSize);
int32_t	HID_SetReportBuf(uint8_t* pu8Report, uint32_t u32ReportSize);
void HID_CtrlSetupSetReport(void * pVoid);
void HID_CtrlSetupDataOutReport(void * pVoid);
void HID_CtrlSetupGetReport(void * pVoid);
void HID_CtrlSetupSetIdle(void * pVoid);
void HID_CtrlSetupSetProtocol(void * pVoid);
void HID_CtrlSetupGetDescriptor(void * pVoid);
void HID_CtrlGetDescriptorIn(void * pVoid);
void HID_CtrlGetDescriptorOut(void * pVoid);
void HID_Start(S_HID_DEVICE *psDevice);
static void HID_UsbStartCallBack(void * pVoid);
static int32_t HID_IsConfigureValue(uint8_t u8ConfigureValue);
static void HID_Reset(S_HID_DEVICE *psDevice);
#ifdef  __cplusplus
}
#endif

#endif
