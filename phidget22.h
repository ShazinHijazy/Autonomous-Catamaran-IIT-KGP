#ifndef PHIDGET22_H 
#define PHIDGET22_H 
#ifdef __cplusplus
extern "C" {
#endif

#if defined(__stdcall)
 #define CCONV __stdcall
 #define PHIDGET22_API __declspec(dllimport)
#else
 #if defined(__BORLANDC__) || defined(_MSC_VER)
  #define CCONV __stdcall
  #define PHIDGET22_API __declspec(dllimport)
 #else
  #define CCONV
  #define PHIDGET22_API
 #endif
#endif

#include <stdint.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
/*
 * This file is part of libphidget22
 *
 * Copyright (c) 2015-2022 Phidgets Inc.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from
 *    this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef _PHIDGET_CONSTANTS_H_
#define _PHIDGET_CONSTANTS_H_

#define PUNK_BOOL	0x02	   /* Unknown Boolean */
#define PUNK_INT8	INT8_MAX   /* Unknown Short   (8-bit) */
#define PUNK_UINT8	UINT8_MAX  /* Unknown Short   (8-bit unsigned) */
#define PUNK_INT16	INT16_MAX  /* Unknown Short   (16-bit) */
#define PUNK_UINT16 UINT16_MAX /* Unknown Short   (16-bit unsigned) */
#define PUNK_INT32	INT32_MAX  /* Unknown Integer (32-bit) */
#define PUNK_UINT32 UINT32_MAX /* Unknown Integer (32-bit unsigned) */
#define PUNK_INT64	INT64_MAX  /* Unknown Integer (64-bit) */
#define PUNK_UINT64 UINT64_MAX /* Unknown Integer (64-bit unsigned) */
#define PUNK_DBL	1e300	   /* Unknown Double */
#define PUNK_FLT	1e30	   /* Unknown Float */
#define PUNK_ENUM	INT32_MAX  /* Unknown Enum */
#define PUNK_SIZE	SIZE_MAX   /* Unknown size_t */

#define PFALSE		0x00 /* False. Used for boolean values. */
#define PTRUE		0x01 /* True. Used for boolean values. */

#define PRIphid		"P" /* mos_printf format string for printing a PhidgetHandle */

#endif /* _PHIDGET_CONSTANTS_H_ */
#ifndef _PHIDGETCONSTANTS_GEN_H_
#define _PHIDGETCONSTANTS_GEN_H_

#define PHIDGET_SERIALNUMBER_ANY -1	// Pass to <code>DeviceSerialNumber</code> to open any serial number.
#define PHIDGET_HUBPORT_ANY -1	// Pass to <code>HubPort</code> to open any hub port.
#define PHIDGET_CHANNEL_ANY -1	// Pass to <code>Channel</code> to open any channel.
#define PHIDGET_LABEL_ANY NULL	// Pass to <code>DeviceLabel</code> to open any label.
#define PHIDGET_TIMEOUT_INFINITE 0x0	// Pass to <code>Phidget_openWaitForAttachment()</code> for an infinite timeout.
#define PHIDGET_TIMEOUT_DEFAULT 0x3e8	// Pass to <code>Phidget_openWaitForAttachment()</code> for the default timeout.
#define PHIDGET_HUBPORTSPEED_AUTO 0x0	// Pass to <code>HubPortSpeed</code> to set the Hub Port speed automatically when supported by both the hub port and the VINT device.
#define PHIDGETSERVER_AUTHREQUIRED 0x1	// PhidgetServer flag indicating that the server requires a password to authenticate
#define IR_RAWDATA_LONGSPACE 0xffffffff	// The value for a long space in raw data
#define IR_MAX_CODE_BIT_COUNT 0x80	// Maximum bit count for sent / received data
#define IR_MAX_CODE_STR_LENGTH 0x21	// Maximum bit count for sent / received data

#endif /* _PHIDGETCONSTANTS_GEN_H_ */

typedef enum
{
  ENCODER_IO_MODE_PUSH_PULL = 0x1,	/* Push-Pull */
  ENCODER_IO_MODE_LINE_DRIVER_2K2 = 0x2,	/* Line Driver 2.2K */
  ENCODER_IO_MODE_LINE_DRIVER_10K = 0x3,	/* Line Driver 10K */
  ENCODER_IO_MODE_OPEN_COLLECTOR_2K2 = 0x4,	/* Open Collector 2.2K */
  ENCODER_IO_MODE_OPEN_COLLECTOR_10K = 0x5,	/* Open Collector 10K */
} Phidget_EncoderIOMode;

typedef enum
{
  EPHIDGET_OK = 0x0,		/* Success */
  EPHIDGET_PERM = 0x1,		/* Not Permitted */
  EPHIDGET_NOENT = 0x2,		/* No Such Entity */
  EPHIDGET_TIMEOUT = 0x3,	/* Timed Out */
  EPHIDGET_KEEPALIVE = 0x3a,	/* Keep Alive Failure */
  EPHIDGET_INTERRUPTED = 0x4,	/* Op Interrupted */
  EPHIDGET_IO = 0x5,		/* IO Issue */
  EPHIDGET_NOMEMORY = 0x6,	/* Memory Issue */
  EPHIDGET_ACCESS = 0x7,	/* Access (Permission) Issue */
  EPHIDGET_FAULT = 0x8,		/* Address Issue */
  EPHIDGET_BUSY = 0x9,		/* Resource Busy */
  EPHIDGET_EXIST = 0xa,		/* Object Exists */
  EPHIDGET_NOTDIR = 0xb,	/* Object is not a directory */
  EPHIDGET_ISDIR = 0xc,		/* Object is a directory */
  EPHIDGET_INVALID = 0xd,	/* Invalid */
  EPHIDGET_NFILE = 0xe,		/* Too many open files in system */
  EPHIDGET_MFILE = 0xf,		/* Too many open files */
  EPHIDGET_NOSPC = 0x10,	/* Not enough space */
  EPHIDGET_FBIG = 0x11,		/* File too Big */
  EPHIDGET_ROFS = 0x12,		/* Read Only Filesystem */
  EPHIDGET_RO = 0x13,		/* Read Only Object */
  EPHIDGET_UNSUPPORTED = 0x14,	/* Operation Not Supported */
  EPHIDGET_INVALIDARG = 0x15,	/* Invalid Argument */
  EPHIDGET_AGAIN = 0x16,	/* Try again */
  EPHIDGET_NOTEMPTY = 0x1a,	/* Not Empty */
  EPHIDGET_UNEXPECTED = 0x1c,	/* Unexpected Error */
  EPHIDGET_DUPLICATE = 0x1b,	/* Duplicate */
  EPHIDGET_BADPASSWORD = 0x25,	/* Bad Credential */
  EPHIDGET_NETUNAVAIL = 0x2d,	/* Network Unavailable */
  EPHIDGET_CONNREF = 0x23,	/* Connection Refused */
  EPHIDGET_CONNRESET = 0x2e,	/* Connection Reset */
  EPHIDGET_HOSTUNREACH = 0x30,	/* No route to host */
  EPHIDGET_NODEV = 0x28,	/* No Such Device */
  EPHIDGET_WRONGDEVICE = 0x32,	/* Wrong Device */
  EPHIDGET_PIPE = 0x29,		/* Broken Pipe */
  EPHIDGET_RESOLV = 0x2c,	/* Name Resolution Failure */
  EPHIDGET_UNKNOWNVAL = 0x33,	/* Unknown or Invalid Value */
  EPHIDGET_NOTATTACHED = 0x34,	/* Device not Attached */
  EPHIDGET_INVALIDPACKET = 0x35,	/* Invalid or Unexpected Packet */
  EPHIDGET_2BIG = 0x36,		/* Argument List Too Long */
  EPHIDGET_BADVERSION = 0x37,	/* Bad Version */
  EPHIDGET_CLOSED = 0x38,	/* Closed */
  EPHIDGET_NOTCONFIGURED = 0x39,	/* Not Configured */
  EPHIDGET_EOF = 0x1f,		/* End of File */
  EPHIDGET_FAILSAFE = 0x3b,	/* Failsafe Triggered */
  EPHIDGET_UNKNOWNVALHIGH = 0x3c,	/* Invalid Value - Too High */
  EPHIDGET_UNKNOWNVALLOW = 0x3d,	/* Invalid Value - Too Low */
  EPHIDGET_BADPOWER = 0x3e,	/* Bad Power Supply */
  EPHIDGET_POWERCYCLE = 0x3f,	/* Power Cycle Required */
  EPHIDGET_HALLSENSOR = 0x40,	/* Hall Sensor Error */
  EPHIDGET_BADCURRENT = 0x41,	/* Bad Current Readings */
  EPHIDGET_BADCONNECTION = 0x42,	/* Bad Connection */
  EPHIDGET_NACK = 0x43,		/* NACK */
} PhidgetReturnCode;

typedef enum
{
  EEPHIDGET_BADVERSION = 0x1,	/* Version Mismatch */
  EEPHIDGET_BUSY = 0x2,		/* Phidget in Use */
  EEPHIDGET_NETWORK = 0x3,	/* Network Error */
  EEPHIDGET_DISPATCH = 0x4,	/* Dispatch Error */
  EEPHIDGET_FAILURE = 0x5,	/* General Failure */
  EEPHIDGET_OK = 0x1000,	/* Error Cleared */
  EEPHIDGET_OVERRUN = 0x1002,	/* Sample Overrun */
  EEPHIDGET_PACKETLOST = 0x1003,	/* Packet Lost */
  EEPHIDGET_WRAP = 0x1004,	/* Wrap-Around */
  EEPHIDGET_OVERTEMP = 0x1005,	/* Over-Temperature */
  EEPHIDGET_OVERCURRENT = 0x1006,	/* Over-Current */
  EEPHIDGET_OUTOFRANGE = 0x1007,	/* Out of Range */
  EEPHIDGET_BADPOWER = 0x1008,	/* Bad Power */
  EEPHIDGET_SATURATION = 0x1009,	/* Saturation */
  EEPHIDGET_OVERVOLTAGE = 0x100b,	/* Over-Voltage */
  EEPHIDGET_FAILSAFE = 0x100c,	/* Failsafe */
  EEPHIDGET_VOLTAGEERROR = 0x100d,	/* Voltage Error */
  EEPHIDGET_ENERGYDUMP = 0x100e,	/* Energy Dump */
  EEPHIDGET_MOTORSTALL = 0x100f,	/* Motor Stall */
  EEPHIDGET_INVALIDSTATE = 0x1010,	/* Invalid State */
  EEPHIDGET_BADCONNECTION = 0x1011,	/* Bad Connection */
  EEPHIDGET_OUTOFRANGEHIGH = 0x1012,	/* Out of Range High */
  EEPHIDGET_OUTOFRANGELOW = 0x1013,	/* Out of Range Low */
  EEPHIDGET_FAULT = 0x1014,	/* Fault Condition */
  EEPHIDGET_ESTOP = 0x1015,	/* External Stop Condition */
} Phidget_ErrorEventCode;

typedef enum
{
  PHIDID_NOTHING = 0x0,		/* Unknown device */
  PHIDID_UNKNOWN = 0x7d,	/* Unknown Device */
  PHIDID_DIGITALINPUT_PORT = 0x5f,	/* Hub Port - Digital Input mode */
  PHIDID_DIGITALOUTPUT_PORT = 0x60,	/* Hub Port - Digital Output mode */
  PHIDID_VOLTAGEINPUT_PORT = 0x61,	/* Hub Port - Voltage Input mode */
  PHIDID_VOLTAGERATIOINPUT_PORT = 0x62,	/* Hub Port - Voltage Ratio Input mode */
  PHIDID_DICTIONARY = 0x6f,	/* Dictionary */
  PHIDID_1000 = 0x2,		/* PhidgetServo 1-Motor (1000) */
  PHIDID_1001 = 0x3,		/* PhidgetServo 4-Motor (1001) */
  PHIDID_1002 = 0x4,		/* PhidgetAnalog 4-Output (1002) */
  PHIDID_1008 = 0x5,		/* PhidgetAccelerometer 2-Axis (1008) */
  PHIDID_1010_1013_1018_1019 = 0x6,	/* PhidgetInterfaceKit 8/8/8 (1010, 1013, 1018, 1019) */
  PHIDID_1011 = 0x7,		/* PhidgetInterfaceKit 2/2/2 (1011) */
  PHIDID_1012 = 0x8,		/* PhidgetInterfaceKit 0/16/16 (1012) */
  PHIDID_1014 = 0x9,		/* PhidgetInterfaceKit 0/0/4 (1014) */
  PHIDID_1015 = 0xa,		/* PhidgetLinearTouch (1015) */
  PHIDID_1016 = 0xb,		/* PhidgetCircularTouch (1016) */
  PHIDID_1017 = 0xc,		/* PhidgetInterfaceKit 0/0/8 (1017) */
  PHIDID_1023 = 0xd,		/* PhidgetRFID (1023) */
  PHIDID_1024 = 0xe,		/* PhidgetRFID Read-Write (1024) */
  PHIDID_1030 = 0xf,		/* PhidgetLED-64 (1030) */
  PHIDID_1031 = 0x10,		/* PhidgetLED-64 Advanced (1031) */
  PHIDID_1032 = 0x11,		/* PhidgetLED-64 Advanced (1032) */
  PHIDID_1040 = 0x12,		/* PhidgetGPS (1040) */
  PHIDID_1041 = 0x13,		/* PhidgetSpatial 0/0/3 Basic (1041) */
  PHIDID_1042 = 0x14,		/* PhidgetSpatial 3/3/3 Basic (1042) */
  PHIDID_1043 = 0x15,		/* PhidgetSpatial Precision 0/0/3 High Resolution (1043) */
  PHIDID_1044 = 0x16,		/* PhidgetSpatial Precision 3/3/3 High Resolution (1044) */
  PHIDID_1045 = 0x17,		/* PhidgetTemperatureSensor IR (1045) */
  PHIDID_1046 = 0x18,		/* PhidgetBridge 4-Input (1046) */
  PHIDID_1047 = 0x19,		/* PhidgetEncoder HighSpeed 4-Input (1047) */
  PHIDID_1048 = 0x1a,		/* PhidgetTemperatureSensor 4-Input (1048) */
  PHIDID_1049 = 0x1b,		/* PhidgetSpatial 0/0/3 (1049) */
  PHIDID_1051 = 0x1c,		/* PhidgetTemperatureSensor 1-Input (1051) */
  PHIDID_1052 = 0x1d,		/* PhidgetEncoder (1052) */
  PHIDID_1053 = 0x1e,		/* PhidgetAccelerometer 2-Axis (1053) */
  PHIDID_1054 = 0x1f,		/* PhidgetFrequencyCounter (1054) */
  PHIDID_1055 = 0x20,		/* PhidgetIR (1055) */
  PHIDID_1056 = 0x21,		/* PhidgetSpatial 3/3/3 (1056) */
  PHIDID_1057 = 0x22,		/* PhidgetEncoder HighSpeed (1057) */
  PHIDID_1058 = 0x23,		/* PhidgetPHSensor (1058) */
  PHIDID_1059 = 0x24,		/* PhidgetAccelerometer 3-Axis (1059) */
  PHIDID_1060 = 0x25,		/* PhidgetMotorControl LV (1060) */
  PHIDID_1061 = 0x26,		/* PhidgetAdvancedServo 8-Motor (1061) */
  PHIDID_1062 = 0x27,		/* PhidgetStepper Unipolar 4-Motor (1062) */
  PHIDID_1063 = 0x28,		/* PhidgetStepper Bipolar 1-Motor (1063) */
  PHIDID_1064 = 0x29,		/* PhidgetMotorControl HC (1064) */
  PHIDID_1065 = 0x2a,		/* PhidgetMotorControl 1-Motor (1065) */
  PHIDID_1066 = 0x2b,		/* PhidgetAdvancedServo 1-Motor (1066) */
  PHIDID_1067 = 0x2c,		/* PhidgetStepper Bipolar HC (1067) */
  PHIDID_1202_1203 = 0x2d,	/* PhidgetTextLCD 20x2 with PhidgetInterfaceKit 8/8/8 (1202, 1203) */
  PHIDID_1204 = 0x2e,		/* PhidgetTextLCD Adapter (1204) */
  PHIDID_1215__1218 = 0x2f,	/* PhidgetTextLCD 20x2 (1215, 1216, 1217, 1218) */
  PHIDID_1219__1222 = 0x30,	/* PhidgetTextLCD 20x2 with PhidgetInterfaceKit 0/8/8 (1219, 1220, 1221,
				   1222) */
  PHIDID_ADP1000 = 0x31,	/* pH Adapter Phidget (ADP1000) */
  PHIDID_DAQ1000 = 0x33,	/* 8x Voltage Input Phidget (DAQ1000) */
  PHIDID_DAQ1200 = 0x34,	/* 4x Digital Input Phidget (DAQ1200) */
  PHIDID_DAQ1300 = 0x35,	/* 4x Isolated Digital Input Phidget (DAQ1300) */
  PHIDID_DAQ1301 = 0x36,	/* 16x Isolated Digital Input Phidget (DAQ1301) */
  PHIDID_DAQ1400 = 0x37,	/* Versatile Input Phidget (DAQ1400) */
  PHIDID_DAQ1500 = 0x38,	/* Wheatstone Bridge Phidget (DAQ1500) */
  PHIDID_DCC1000 = 0x39,	/* DC Motor Phidget (DCC1000) */
  PHIDID_DCC1001 = 0x6e,	/* 2A DC Motor Phidget (DCC1001) */
  PHIDID_DCC1002 = 0x75,	/* 4A DC Motor Phidget (DCC1002) */
  PHIDID_DCC1003 = 0x78,	/* 2x DC Motor Phidget (DCC1003) */
  PHIDID_DCC1020 = 0x80,	/* 30V 50A DC Motor Phidget (DCC1020) */
  PHIDID_DCC1030 = 0x98,	/* 60V 50A DC Motor Phidget (DCC1030) */
  PHIDID_DCC1100 = 0x6c,	/* Brushless DC Motor Phidget (DCC1100) */
  PHIDID_DCC1120 = 0x96,	/* 30V 50A Brushless DC Motor Phidget (DCC1120) */
  PHIDID_DCC1130 = 0x9a,	/* 60V 50A Brushless DC Motor Phidget (DCC1130) */
  PHIDID_DST1000 = 0x3a,	/* Distance Phidget (DST1000) */
  PHIDID_DST1001 = 0x79,	/* Distance Phidget 650mm (DST1001) */
  PHIDID_DST1002 = 0x7e,	/* Distance Phidget 1300mm (DST1002) */
  PHIDID_DST1200 = 0x3b,	/* Sonar Phidget (DST1200) */
  PHIDID_ENC1000 = 0x3c,	/* Quadrature Encoder Phidget (ENC1000) */
  PHIDID_ENC1001 = 0x9b,	/* Quadrature Encoder Phidget (ENC1001) */
  PHIDID_FIRMWARE_UPGRADE_SPI = 0x68,	/* SPI Phidget in firmware upgrade mode */
  PHIDID_FIRMWARE_UPGRADE_STM32F0 = 0x66,	/* VINT Phidget in firmware upgrade mode, STM32F0 Proc. */
  PHIDID_FIRMWARE_UPGRADE_STM32F3 = 0x91,	/* VINT Phidget in firmware upgrade mode, STM32F3 Proc. */
  PHIDID_FIRMWARE_UPGRADE_STM32G0 = 0x8f,	/* VINT Phidget in firmware upgrade mode, STM32G0 Proc. */
  PHIDID_FIRMWARE_UPGRADE_STM8S = 0x67,	/* VINT Phidget in firmware upgrade mode, STM8S Proc. */
  PHIDID_FIRMWARE_UPGRADE_USB = 0x65,	/* USB Phidget in firmware upgrade mode */
  PHIDID_HIN1000 = 0x3d,	/* Touch Keypad Phidget (HIN1000) */
  PHIDID_HIN1001 = 0x3e,	/* Touch Wheel Phidget (HIN1001) */
  PHIDID_HIN1100 = 0x3f,	/* Thumbstick Phidget (HIN1100) */
  PHIDID_HIN1101 = 0x6d,	/* Phidget Dial (HIN1101) */
  PHIDID_HUB0000 = 0x40,	/* 6-Port USB VINT Hub Phidget (HUB0000) */
  PHIDID_HUB0001 = 0x8e,	/* 6-Port USB VINT Hub Phidget (HUB0001) */
  PHIDID_HUB0002 = 0x93,	/* 6-Port USB VINT Hub Phidget (HUB0002) */
  PHIDID_HUB0004 = 0x43,	/* 6-Port PhidgetSBC VINT Hub Phidget (HUB0004) */
  PHIDID_HUB0007 = 0x94,	/* 1-Port USB VINT Hub Phidget (HUB0007) */
  PHIDID_HUB5000 = 0x7b,	/* 6-Port Network VINT Hub Phidget (HUB5000) */
  PHIDID_HUM1000 = 0x45,	/* Humidity Phidget (HUM1000) */
  PHIDID_HUM1001 = 0x7f,	/* Humidity Phidget (HUM1001) */
  PHIDID_HUM1100 = 0x88,	/* Soil Moisture Phidget (HUM1100) */
  PHIDID_INTERFACEKIT_4_8_8 = 0x1,	/* PhidgetInterfaceKit 4/8/8 */
  PHIDID_LCD1100 = 0x46,	/* Graphic LCD Phidget (LCD1100) */
  PHIDID_LED1000 = 0x47,	/* 32x Isolated LED Phidget (LED1000) */
  PHIDID_LUX1000 = 0x48,	/* Light Phidget (LUX1000) */
  PHIDID_MOT0100 = 0x92,	/* PhidgetAccelerometer (MOT0100) */
  PHIDID_MOT0109 = 0x8c,	/* PhidgetSpatial Precision 3/3/3 (MOT0109) */
  PHIDID_MOT0110 = 0x8d,	/* PhidgetSpatial Precision 3/3/3 (MOT0110) */
  PHIDID_MOT1100 = 0x49,	/* Accelerometer Phidget (MOT1100) */
  PHIDID_MOT1101 = 0x4a,	/* Spatial Phidget (MOT1101) */
  PHIDID_MOT1102 = 0x89,	/* Spatial Phidget (MOT1102) */
  PHIDID_OUT1000 = 0x4b,	/* 12-bit Voltage Output Phidget (OUT1000) */
  PHIDID_OUT1001 = 0x4c,	/* Isolated 12-bit Voltage Output Phidget (OUT1001) */
  PHIDID_OUT1002 = 0x4d,	/* Isolated 16-bit Voltage Output Phidget (OUT1002) */
  PHIDID_OUT1100 = 0x4e,	/* 4x Digital Output Phidget (OUT1100) */
  PHIDID_PRE1000 = 0x4f,	/* Barometer Phidget (PRE1000) */
  PHIDID_RCC0004 = 0x7c,	/* PhidgetAdvancedServo 8-Motor (RCC0004) */
  PHIDID_RCC1000 = 0x50,	/* 16x RC Servo Phidget (RCC1000) */
  PHIDID_REL1000 = 0x51,	/* 4x Relay Phidget (REL1000) */
  PHIDID_REL1100 = 0x52,	/* 4x Isolated Solid State Relay Phidget (REL1100) */
  PHIDID_REL1101 = 0x53,	/* 16x Isolated Solid State Relay Phidget (REL1101) */
  PHIDID_SAF1000 = 0x54,	/* Programmable Power Guard Phidget (SAF1000) */
  PHIDID_SND1000 = 0x55,	/* Sound Phidget (SND1000) */
  PHIDID_STC1000 = 0x56,	/* Stepper Phidget (STC1000) */
  PHIDID_STC1001 = 0x73,	/* 2.5A Stepper Phidget (STC1001) */
  PHIDID_STC1002 = 0x76,	/* 8A Stepper Phidget (STC1002) */
  PHIDID_STC1003 = 0x77,	/* 4A Stepper Phidget (STC1003) */
  PHIDID_STC1005 = 0x95,	/* 4A Stepper Phidget (STC1005) */
  PHIDID_TMP1000 = 0x57,	/* Temperature Phidget (TMP1000) */
  PHIDID_TMP1100 = 0x58,	/* Isolated Thermocouple Phidget (TMP1100) */
  PHIDID_TMP1101 = 0x59,	/* 4x Thermocouple Phidget (TMP1101) */
  PHIDID_TMP1200 = 0x5a,	/* RTD Phidget (TMP1200) */
  PHIDID_VCP1000 = 0x5c,	/* 20-bit (+-40V) Voltage Input Phidget (VCP1000) */
  PHIDID_VCP1001 = 0x5d,	/* 10-bit (+-40V) Voltage Input Phidget (VCP1001) */
  PHIDID_VCP1002 = 0x5e,	/* 10-bit (+-1V) Voltage Input Phidget (VCP1002) */
  PHIDID_VCP1100 = 0x69,	/* 30A Current Sensor Phidget (VCP1100) */
} Phidget_DeviceID;

typedef enum
{
  PHIDGET_LOG_CRITICAL = 0x1,	/* Critical */
  PHIDGET_LOG_ERROR = 0x2,	/* Error */
  PHIDGET_LOG_WARNING = 0x3,	/* Warning */
  PHIDGET_LOG_INFO = 0x4,	/* Info */
  PHIDGET_LOG_DEBUG = 0x5,	/* Debug */
  PHIDGET_LOG_VERBOSE = 0x6,	/* Verbose */
} Phidget_LogLevel;

typedef enum
{
  PHIDCLASS_NOTHING = 0x0,	/* PhidgetNone */
  PHIDCLASS_ACCELEROMETER = 0x1,	/* PhidgetAccelerometer */
  PHIDCLASS_ADVANCEDSERVO = 0x2,	/* PhidgetAdvancedServo */
  PHIDCLASS_ANALOG = 0x3,	/* PhidgetAnalog */
  PHIDCLASS_BRIDGE = 0x4,	/* PhidgetBridge */
  PHIDCLASS_DATAADAPTER = 0x19,	/* PhidgetDataAdapter */
  PHIDCLASS_DICTIONARY = 0x18,	/* PhidgetDictionary */
  PHIDCLASS_ENCODER = 0x5,	/* PhidgetEncoder */
  PHIDCLASS_FIRMWAREUPGRADE = 0x17,	/* PhidgetFirmwareUpgrade */
  PHIDCLASS_FREQUENCYCOUNTER = 0x6,	/* PhidgetFrequencyCounter */
  PHIDCLASS_GENERIC = 0x16,	/* PhidgetGeneric */
  PHIDCLASS_GPS = 0x7,		/* PhidgetGPS */
  PHIDCLASS_HUB = 0x8,		/* PhidgetHub */
  PHIDCLASS_INTERFACEKIT = 0x9,	/* PhidgetInterfaceKit */
  PHIDCLASS_IR = 0xa,		/* PhidgetIR */
  PHIDCLASS_LED = 0xb,		/* PhidgetLED */
  PHIDCLASS_LEDARRAY = 0x1a,	/* PhidgetLEDArray */
  PHIDCLASS_MESHDONGLE = 0xc,	/* PhidgetMeshDongle */
  PHIDCLASS_MOTORCONTROL = 0xd,	/* PhidgetMotorControl */
  PHIDCLASS_PHSENSOR = 0xe,	/* PhidgetPHSensor */
  PHIDCLASS_RFID = 0xf,		/* PhidgetRFID */
  PHIDCLASS_SERVO = 0x10,	/* PhidgetServo */
  PHIDCLASS_SPATIAL = 0x11,	/* PhidgetSpatial */
  PHIDCLASS_STEPPER = 0x12,	/* PhidgetStepper */
  PHIDCLASS_TEMPERATURESENSOR = 0x13,	/* PhidgetTemperatureSensor */
  PHIDCLASS_TEXTLCD = 0x14,	/* PhidgetTextLCD */
  PHIDCLASS_VINT = 0x15,	/* PhidgetVINT */
} Phidget_DeviceClass;

typedef enum
{
  PHIDCHCLASS_NOTHING = 0x0,	/* PhidgetNone */
  PHIDCHCLASS_ACCELEROMETER = 0x1,	/* PhidgetAccelerometer */
  PHIDCHCLASS_BLDCMOTOR = 0x23,	/* PhidgetBLDCMotor */
  PHIDCHCLASS_CAPACITIVETOUCH = 0xe,	/* PhidgetCapacitiveTouch */
  PHIDCHCLASS_CURRENTINPUT = 0x2,	/* PhidgetCurrentInput */
  PHIDCHCLASS_CURRENTOUTPUT = 0x26,	/* PhidgetCurrentOutput */
  PHIDCHCLASS_DATAADAPTER = 0x3,	/* PhidgetDataAdapter */
  PHIDCHCLASS_DCMOTOR = 0x4,	/* PhidgetDCMotor */
  PHIDCHCLASS_DICTIONARY = 0x24,	/* PhidgetDictionary */
  PHIDCHCLASS_DIGITALINPUT = 0x5,	/* PhidgetDigitalInput */
  PHIDCHCLASS_DIGITALOUTPUT = 0x6,	/* PhidgetDigitalOutput */
  PHIDCHCLASS_DISTANCESENSOR = 0x7,	/* PhidgetDistanceSensor */
  PHIDCHCLASS_ENCODER = 0x8,	/* PhidgetEncoder */
  PHIDCHCLASS_FIRMWAREUPGRADE = 0x20,	/* PhidgetFirmwareUpgrade */
  PHIDCHCLASS_FREQUENCYCOUNTER = 0x9,	/* PhidgetFrequencyCounter */
  PHIDCHCLASS_GENERIC = 0x21,	/* PhidgetGeneric */
  PHIDCHCLASS_GPS = 0xa,	/* PhidgetGPS */
  PHIDCHCLASS_GYROSCOPE = 0xc,	/* PhidgetGyroscope */
  PHIDCHCLASS_HUB = 0xd,	/* PhidgetHub */
  PHIDCHCLASS_HUMIDITYSENSOR = 0xf,	/* PhidgetHumiditySensor */
  PHIDCHCLASS_IR = 0x10,	/* PhidgetIR */
  PHIDCHCLASS_LCD = 0xb,	/* PhidgetLCD */
  PHIDCHCLASS_LEDARRAY = 0x28,	/* PhidgetLEDArray */
  PHIDCHCLASS_LIGHTSENSOR = 0x11,	/* PhidgetLightSensor */
  PHIDCHCLASS_MAGNETOMETER = 0x12,	/* PhidgetMagnetometer */
  PHIDCHCLASS_MESHDONGLE = 0x13,	/* PhidgetMeshDongle */
  PHIDCHCLASS_MOTORPOSITIONCONTROLLER = 0x22,	/* PhidgetMotorPositionController */
  PHIDCHCLASS_MOTORVELOCITYCONTROLLER = 0x27,	/* PhidgetMotorVelocityController */
  PHIDCHCLASS_PHSENSOR = 0x25,	/* PhidgetPHSensor */
  PHIDCHCLASS_POWERGUARD = 0x14,	/* PhidgetPowerGuard */
  PHIDCHCLASS_PRESSURESENSOR = 0x15,	/* PhidgetPressureSensor */
  PHIDCHCLASS_RCSERVO = 0x16,	/* PhidgetRCServo */
  PHIDCHCLASS_RESISTANCEINPUT = 0x17,	/* PhidgetResistanceInput */
  PHIDCHCLASS_RFID = 0x18,	/* PhidgetRFID */
  PHIDCHCLASS_SOUNDSENSOR = 0x19,	/* PhidgetSoundSensor */
  PHIDCHCLASS_SPATIAL = 0x1a,	/* PhidgetSpatial */
  PHIDCHCLASS_STEPPER = 0x1b,	/* PhidgetStepper */
  PHIDCHCLASS_TEMPERATURESENSOR = 0x1c,	/* PhidgetTemperatureSensor */
  PHIDCHCLASS_VOLTAGEINPUT = 0x1d,	/* PhidgetVoltageInput */
  PHIDCHCLASS_VOLTAGEOUTPUT = 0x1e,	/* PhidgetVoltageOutput */
  PHIDCHCLASS_VOLTAGERATIOINPUT = 0x1f,	/* PhidgetVoltageRatioInput */
} Phidget_ChannelClass;

typedef enum
{
  PHIDCHSUBCLASS_NONE = 0x1,	/* No subclass */
  PHIDCHSUBCLASS_DIGITALOUTPUT_DUTY_CYCLE = 0x10,	/* Digital output duty cycle */
  PHIDCHSUBCLASS_DIGITALOUTPUT_FREQUENCY = 0x12,	/* Digital output frequency */
  PHIDCHSUBCLASS_DIGITALOUTPUT_LED_DRIVER = 0x11,	/* Digital output LED driver */
  PHIDCHSUBCLASS_ENCODER_MODE_SETTABLE = 0x60,	/* Encoder IO mode settable */
  PHIDCHSUBCLASS_LCD_GRAPHIC = 0x50,	/* Graphic LCD */
  PHIDCHSUBCLASS_LCD_TEXT = 0x51,	/* Text LCD */
  PHIDCHSUBCLASS_SPATIAL_AHRS = 0x70,	/* Spatial AHRS/IMU */
  PHIDCHSUBCLASS_TEMPERATURESENSOR_RTD = 0x20,	/* Temperature sensor RTD */
  PHIDCHSUBCLASS_TEMPERATURESENSOR_THERMOCOUPLE = 0x21,	/* Temperature sensor thermocouple */
  PHIDCHSUBCLASS_VOLTAGEINPUT_SENSOR_PORT = 0x30,	/* Voltage sensor port */
  PHIDCHSUBCLASS_VOLTAGERATIOINPUT_BRIDGE = 0x41,	/* Voltage ratio bridge input */
  PHIDCHSUBCLASS_VOLTAGERATIOINPUT_SENSOR_PORT = 0x40,	/* Voltage ratio sensor port */
} Phidget_ChannelSubclass;

typedef enum
{
  MESHMODE_ROUTER = 0x1,	/* Router mode */
  MESHMODE_SLEEPYENDDEVICE = 0x2,	/* Sleepy end device mode */
} Phidget_MeshMode;

typedef enum
{
  POWER_SUPPLY_OFF = 0x1,	/* Off */
  POWER_SUPPLY_12V = 0x2,	/* 12 V */
  POWER_SUPPLY_24V = 0x3,	/* 24 V */
} Phidget_PowerSupply;

typedef enum
{
  DATAADAPTER_VOLTAGE_EXTERN = 0x1,	/* External */
  DATAADAPTER_VOLTAGE_2_5V = 0x3,	/* 2.5V */
  DATAADAPTER_VOLTAGE_3_3V = 0x4,	/* 3.3V */
  DATAADAPTER_VOLTAGE_5_0V = 0x5,	/* 5.0V */
} Phidget_DataAdapterVoltage;

typedef enum
{
  RTD_WIRE_SETUP_2WIRE = 0x1,	/* 2 Wire */
  RTD_WIRE_SETUP_3WIRE = 0x2,	/* 3 Wire */
  RTD_WIRE_SETUP_4WIRE = 0x3,	/* 4 Wire */
} Phidget_RTDWireSetup;

typedef enum
{
  INPUT_MODE_NPN = 0x1,		/* NPN */
  INPUT_MODE_PNP = 0x2,		/* PNP */
  INPUT_MODE_FLOATING = 0x3,	/* Floating */
  INPUT_MODE_PULLUP = 0x4,	/* Pullup */
} Phidget_InputMode;

typedef enum
{
  FAN_MODE_OFF = 0x1,		/* Off */
  FAN_MODE_ON = 0x2,		/* On */
  FAN_MODE_AUTO = 0x3,		/* Automatic */
} Phidget_FanMode;

typedef enum
{
  DRIVE_MODE_COAST = 0x1,	/* Coast */
  DRIVE_MODE_FORCED = 0x2,	/* Forced */
} Phidget_DriveMode;

typedef enum
{
  POSITION_TYPE_ENCODER = 0x1,	/* Encoder */
  POSITION_TYPE_HALL_SENSOR = 0x2,	/* Hall-Effect Sensor */
} Phidget_PositionType;

typedef enum
{
  SPATIAL_PRECISION_HYBRID = 0x0,	/* Hybrid */
  SPATIAL_PRECISION_HIGH = 0x1,	/* High */
  SPATIAL_PRECISION_LOW = 0x2,	/* Low */
} Phidget_SpatialPrecision;

typedef enum
{
  PHIDUNIT_NONE = 0x0,		/* Unitless */
  PHIDUNIT_BOOLEAN = 0x1,	/* Boolean */
  PHIDUNIT_PERCENT = 0x2,	/* Percent */
  PHIDUNIT_DECIBEL = 0x3,	/* Decibel */
  PHIDUNIT_MILLIMETER = 0x4,	/* Millimeter */
  PHIDUNIT_CENTIMETER = 0x5,	/* Centimeter */
  PHIDUNIT_METER = 0x6,		/* Meter */
  PHIDUNIT_GRAM = 0x7,		/* Gram */
  PHIDUNIT_KILOGRAM = 0x8,	/* Kilogram */
  PHIDUNIT_MILLIAMPERE = 0x9,	/* Milliampere */
  PHIDUNIT_AMPERE = 0xa,	/* Ampere */
  PHIDUNIT_KILOPASCAL = 0xb,	/* Kilopascal */
  PHIDUNIT_VOLT = 0xc,		/* Volt */
  PHIDUNIT_DEGREE_CELCIUS = 0xd,	/* Degree Celcius */
  PHIDUNIT_LUX = 0xe,		/* Lux */
  PHIDUNIT_GAUSS = 0xf,		/* Gauss */
  PHIDUNIT_PH = 0x10,		/* pH */
  PHIDUNIT_WATT = 0x11,		/* Watt */
} Phidget_Unit;

typedef struct
{
  Phidget_Unit unit;
  const char *name;
  const char *symbol;
} Phidget_UnitInfo, *Phidget_UnitInfoHandle;

typedef enum
{
  PHIDGETSERVER_NONE = 0x0,	/* Unknown or unspecified server type */
  PHIDGETSERVER_DEVICELISTENER = 0x1,	/* Phidget22 Server listener */
  PHIDGETSERVER_DEVICE = 0x2,	/* Phidget22 Server connection */
  PHIDGETSERVER_DEVICEREMOTE = 0x3,	/* Phidget22 Server */
  PHIDGETSERVER_WWWLISTENER = 0x4,	/* Phidget22 Web Server */
  PHIDGETSERVER_WWW = 0x5,	/* Phidget22 Web Server connection */
  PHIDGETSERVER_WWWREMOTE = 0x6,	/* Phidget22 Web server */
  PHIDGETSERVER_SBC = 0x7,	/* Phidget SBC */
} PhidgetServerType;

typedef struct
{
  const char *name;
  const char *stype;
  PhidgetServerType type;
  int flags;
  const char *addr;
  const char *host;
  int port;
} PhidgetServer, *PhidgetServerHandle;

typedef enum
{
  BRIDGE_GAIN_1 = 0x1,		/* 1x */
  BRIDGE_GAIN_2 = 0x2,		/* 2x */
  BRIDGE_GAIN_4 = 0x3,		/* 4x */
  BRIDGE_GAIN_8 = 0x4,		/* 8x */
  BRIDGE_GAIN_16 = 0x5,		/* 16x */
  BRIDGE_GAIN_32 = 0x6,		/* 32x */
  BRIDGE_GAIN_64 = 0x7,		/* 64x */
  BRIDGE_GAIN_128 = 0x8,	/* 128x */
} PhidgetVoltageRatioInput_BridgeGain;

typedef enum
{
  SENSOR_TYPE_VOLTAGERATIO = 0x0,	/* Generic ratiometric sensor */
  SENSOR_TYPE_1101_SHARP_2D120X = 0x2b03,	/* 1101 - IR Distance Adapter,
						   with Sharp Distance Sensor 2D120X (4-30cm) */
  SENSOR_TYPE_1101_SHARP_2Y0A21 = 0x2b04,	/* 1101 - IR Distance Adapter,
						   with Sharp Distance Sensor 2Y0A21 (10-80cm) */
  SENSOR_TYPE_1101_SHARP_2Y0A02 = 0x2b05,	/* 1101 - IR Distance Adapter,
						   with Sharp Distance Sensor 2Y0A02 (20-150cm) */
  SENSOR_TYPE_1102 = 0x2b0c,	/* 1102 - IR Reflective Sensor 5mm */
  SENSOR_TYPE_1103 = 0x2b16,	/* 1103 - IR Reflective Sensor 10cm */
  SENSOR_TYPE_1104 = 0x2b20,	/* 1104 - Vibration Sensor */
  SENSOR_TYPE_1105 = 0x2b2a,	/* 1105 - Light Sensor */
  SENSOR_TYPE_1106 = 0x2b34,	/* 1106 - Force Sensor */
  SENSOR_TYPE_1107 = 0x2b3e,	/* 1107 - Humidity Sensor */
  SENSOR_TYPE_1108 = 0x2b48,	/* 1108 - Magnetic Sensor */
  SENSOR_TYPE_1109 = 0x2b52,	/* 1109 - Rotation Sensor */
  SENSOR_TYPE_1110 = 0x2b5c,	/* 1110 - Touch Sensor */
  SENSOR_TYPE_1111 = 0x2b66,	/* 1111 - Motion Sensor */
  SENSOR_TYPE_1112 = 0x2b70,	/* 1112 - Slider 60 */
  SENSOR_TYPE_1113 = 0x2b7a,	/* 1113 - Mini Joy Stick Sensor */
  SENSOR_TYPE_1115 = 0x2b8e,	/* 1115 - Pressure Sensor */
  SENSOR_TYPE_1116 = 0x2b98,	/* 1116 - Multi-turn Rotation Sensor */
  SENSOR_TYPE_1118_AC = 0x2bad,	/* 1118 - 50Amp Current Sensor AC */
  SENSOR_TYPE_1118_DC = 0x2bae,	/* 1118 - 50Amp Current Sensor DC */
  SENSOR_TYPE_1119_AC = 0x2bb7,	/* 1119 - 20Amp Current Sensor AC */
  SENSOR_TYPE_1119_DC = 0x2bb8,	/* 1119 - 20Amp Current Sensor DC */
  SENSOR_TYPE_1120 = 0x2bc0,	/* 1120 - FlexiForce Adapter */
  SENSOR_TYPE_1121 = 0x2bca,	/* 1121 - Voltage Divider */
  SENSOR_TYPE_1122_AC = 0x2bd5,	/* 1122 - 30 Amp Current Sensor AC */
  SENSOR_TYPE_1122_DC = 0x2bd6,	/* 1122 - 30 Amp Current Sensor DC */
  SENSOR_TYPE_1124 = 0x2be8,	/* 1124 - Precision Temperature Sensor */
  SENSOR_TYPE_1125_HUMIDITY = 0x2bf3,	/* 1125 - Humidity Sensor */
  SENSOR_TYPE_1125_TEMPERATURE = 0x2bf4,	/* 1125 - Temperature Sensor */
  SENSOR_TYPE_1126 = 0x2bfc,	/* 1126 - Differential Air Pressure Sensor +- 25kPa */
  SENSOR_TYPE_1128 = 0x2c10,	/* 1128 - MaxBotix EZ-1 Sonar Sensor */
  SENSOR_TYPE_1129 = 0x2c1a,	/* 1129 - Touch Sensor */
  SENSOR_TYPE_1131 = 0x2c2e,	/* 1131 - Thin Force Sensor */
  SENSOR_TYPE_1134 = 0x2c4c,	/* 1134 - Switchable Voltage Divider */
  SENSOR_TYPE_1136 = 0x2c60,	/* 1136 - Differential Air Pressure Sensor +-2 kPa */
  SENSOR_TYPE_1137 = 0x2c6a,	/* 1137 - Differential Air Pressure Sensor +-7 kPa */
  SENSOR_TYPE_1138 = 0x2c74,	/* 1138 - Differential Air Pressure Sensor 50 kPa */
  SENSOR_TYPE_1139 = 0x2c7e,	/* 1139 - Differential Air Pressure Sensor 100 kPa */
  SENSOR_TYPE_1140 = 0x2c88,	/* 1140 - Absolute Air Pressure Sensor 20-400 kPa */
  SENSOR_TYPE_1141 = 0x2c92,	/* 1141 - Absolute Air Pressure Sensor 15-115 kPa */
  SENSOR_TYPE_1146 = 0x2cc4,	/* 1146 - IR Reflective Sensor 1-4mm */
  SENSOR_TYPE_3120 = 0x79e0,	/* 3120 - Compression Load Cell (0-4.5 kg) */
  SENSOR_TYPE_3121 = 0x79ea,	/* 3121 - Compression Load Cell (0-11.3 kg) */
  SENSOR_TYPE_3122 = 0x79f4,	/* 3122 - Compression Load Cell (0-22.7 kg) */
  SENSOR_TYPE_3123 = 0x79fe,	/* 3123 - Compression Load Cell (0-45.3 kg) */
  SENSOR_TYPE_3130 = 0x7a44,	/* 3130 - Relative Humidity Sensor */
  SENSOR_TYPE_3520 = 0x8980,	/* 3520 - Sharp Distance Sensor (4-30cm) */
  SENSOR_TYPE_3521 = 0x898a,	/* 3521 - Sharp Distance Sensor (10-80cm) */
  SENSOR_TYPE_3522 = 0x8994,	/* 3522 - Sharp Distance Sensor (20-150cm) */
} PhidgetVoltageRatioInput_SensorType;

typedef enum
{
  LED_FORWARD_VOLTAGE_1_7V = 0x1,	/* 1.7 V */
  LED_FORWARD_VOLTAGE_2_75V = 0x2,	/* 2.75 V */
  LED_FORWARD_VOLTAGE_3_2V = 0x3,	/* 3.2 V */
  LED_FORWARD_VOLTAGE_3_9V = 0x4,	/* 3.9 V */
  LED_FORWARD_VOLTAGE_4_0V = 0x5,	/* 4.0 V */
  LED_FORWARD_VOLTAGE_4_8V = 0x6,	/* 4.8 V */
  LED_FORWARD_VOLTAGE_5_0V = 0x7,	/* 5.0 V */
  LED_FORWARD_VOLTAGE_5_6V = 0x8,	/* 5.6 V */
} PhidgetDigitalOutput_LEDForwardVoltage;

typedef enum
{
  RCSERVO_VOLTAGE_5V = 0x1,	/* 5.0 V */
  RCSERVO_VOLTAGE_6V = 0x2,	/* 6.0 V */
  RCSERVO_VOLTAGE_7_4V = 0x3,	/* 7.4 V */
} PhidgetRCServo_Voltage;

typedef enum
{
  VOLTAGE_OUTPUT_RANGE_10V = 0x1,	/* Â±10V DC */
  VOLTAGE_OUTPUT_RANGE_5V = 0x2,	/* 0-5V DC */
} PhidgetVoltageOutput_VoltageOutputRange;

typedef enum
{
  VOLTAGE_RANGE_10mV = 0x1,	/* 10 mV */
  VOLTAGE_RANGE_40mV = 0x2,	/* 40 mV */
  VOLTAGE_RANGE_200mV = 0x3,	/* 200 mV */
  VOLTAGE_RANGE_312_5mV = 0x4,	/* 312.5 mV */
  VOLTAGE_RANGE_400mV = 0x5,	/* 400 mV */
  VOLTAGE_RANGE_1000mV = 0x6,	/* 1000 mV */
  VOLTAGE_RANGE_2V = 0x7,	/* 2 V */
  VOLTAGE_RANGE_5V = 0x8,	/* 5 V */
  VOLTAGE_RANGE_15V = 0x9,	/* 15 V */
  VOLTAGE_RANGE_40V = 0xa,	/* 40 V */
  VOLTAGE_RANGE_AUTO = 0xb,	/* Auto */
} PhidgetVoltageInput_VoltageRange;

typedef enum
{
  SENSOR_TYPE_VOLTAGE = 0x0,	/* Generic voltage sensor */
  SENSOR_TYPE_1114 = 0x2b84,	/* 1114 - Temperature Sensor */
  SENSOR_TYPE_1117 = 0x2ba2,	/* 1117 - Voltage Sensor */
  SENSOR_TYPE_1123 = 0x2bde,	/* 1123 - Precision Voltage Sensor */
  SENSOR_TYPE_1127 = 0x2c06,	/* 1127 - Precision Light Sensor */
  SENSOR_TYPE_1130_PH = 0x2c25,	/* 1130 - pH Adapter */
  SENSOR_TYPE_1130_ORP = 0x2c26,	/* 1130 - ORP Adapter */
  SENSOR_TYPE_1132 = 0x2c38,	/* 1132 - 4-20mA Adapter */
  SENSOR_TYPE_1133 = 0x2c42,	/* 1133 - Sound Sensor */
  SENSOR_TYPE_1135 = 0x2c56,	/* 1135 - Precision Voltage Sensor */
  SENSOR_TYPE_1142 = 0x2c9c,	/* 1142 - Light Sensor 1000 lux */
  SENSOR_TYPE_1143 = 0x2ca6,	/* 1143 - Light Sensor 70000 lux */
  SENSOR_TYPE_3500 = 0x88b8,	/* 3500 - AC Current Sensor 10Amp */
  SENSOR_TYPE_3501 = 0x88c2,	/* 3501 - AC Current Sensor 25Amp */
  SENSOR_TYPE_3502 = 0x88cc,	/* 3502 - AC Current Sensor 50Amp */
  SENSOR_TYPE_3503 = 0x88d6,	/* 3503 - AC Current Sensor 100Amp */
  SENSOR_TYPE_3507 = 0x88fe,	/* 3507 - AC Voltage Sensor 0-250V (50Hz) */
  SENSOR_TYPE_3508 = 0x8908,	/* 3508 - AC Voltage Sensor 0-250V (60Hz) */
  SENSOR_TYPE_3509 = 0x8912,	/* 3509 - DC Voltage Sensor 0-200V */
  SENSOR_TYPE_3510 = 0x891c,	/* 3510 - DC Voltage Sensor 0-75V */
  SENSOR_TYPE_3511 = 0x8926,	/* 3511 - DC Current Sensor 0-10mA */
  SENSOR_TYPE_3512 = 0x8930,	/* 3512 - DC Current Sensor 0-100mA */
  SENSOR_TYPE_3513 = 0x893a,	/* 3513 - DC Current Sensor 0-1A */
  SENSOR_TYPE_3514 = 0x8944,	/* 3514 - AC Active Power Sensor 0-250V*0-30A (50Hz) */
  SENSOR_TYPE_3515 = 0x894e,	/* 3515 - AC Active Power Sensor 0-250V*0-30A (60Hz) */
  SENSOR_TYPE_3516 = 0x8958,	/* 3516 - AC Active Power Sensor 0-250V*0-5A (50Hz) */
  SENSOR_TYPE_3517 = 0x8962,	/* 3517 - AC Active Power Sensor 0-250V*0-5A (60Hz) */
  SENSOR_TYPE_3518 = 0x896c,	/* 3518 - AC Active Power Sensor 0-110V*0-5A (60Hz) */
  SENSOR_TYPE_3519 = 0x8976,	/* 3519 - AC Active Power Sensor 0-110V*0-15A (60Hz) */
  SENSOR_TYPE_3584 = 0x8c00,	/* 3584 - 0-50A DC Current Transducer */
  SENSOR_TYPE_3585 = 0x8c0a,	/* 3585 - 0-100A DC Current Transducer */
  SENSOR_TYPE_3586 = 0x8c14,	/* 3586 - 0-250A DC Current Transducer */
  SENSOR_TYPE_3587 = 0x8c1e,	/* 3587 - +-50A DC Current Transducer */
  SENSOR_TYPE_3588 = 0x8c28,	/* 3588 - +-100A DC Current Transducer */
  SENSOR_TYPE_3589 = 0x8c32,	/* 3589 - +-250A DC Current Transducer */
  SENSOR_TYPE_MOT2002_LOW = 0x4e34,	/* MOT2002 - Motion Sensor Low Sensitivity */
  SENSOR_TYPE_MOT2002_MED = 0x4e35,	/* MOT2002 - Motion Sensor Medium Sensitivity */
  SENSOR_TYPE_MOT2002_HIGH = 0x4e36,	/* MOT2002 - Motion Sensor High Sensitivity */
  SENSOR_TYPE_VCP4114 = 0xa0b4,	/* VCP4114 - +-25A DC Current Transducer */
  SENSOR_TYPE_VCP4115 = 0xa0be,	/* VCP4115 - +-75A DC Current Transducer */
} PhidgetVoltageInput_SensorType;

typedef enum
{
  PROTOCOL_EM4100 = 0x1,	/* EM4100 Series */
  PROTOCOL_ISO11785_FDX_B = 0x2,	/* ISO11785 FDX B */
  PROTOCOL_PHIDGETS = 0x3,	/* PhidgetTAG */
  PROTOCOL_HID_GENERIC = 0x4,	/* HID Generic */
  PROTOCOL_HID_H10301 = 0x5,	/* HID H10301 */
} PhidgetRFID_Protocol;

typedef enum
{
  CHIPSET_T5577 = 0x1,		/* T5577 */
  CHIPSET_EM4305 = 0x2,		/* EM4305 */
} PhidgetRFID_Chipset;

typedef struct
{
  int16_t tm_ms;
  int16_t tm_sec;
  int16_t tm_min;
  int16_t tm_hour;
} PhidgetGPS_Time, *PhidgetGPS_TimeHandle;

typedef struct
{
  int16_t tm_mday;
  int16_t tm_mon;
  int16_t tm_year;
} PhidgetGPS_Date, *PhidgetGPS_DateHandle;

typedef struct
{
  double latitude;
  double longitude;
  int16_t fixQuality;
  int16_t numSatellites;
  double horizontalDilution;
  double altitude;
  double heightOfGeoid;
} PhidgetGPS_GPGGA, *PhidgetGPS_GPGGAHandle;

typedef struct
{
  char mode;
  int16_t fixType;
  int16_t satUsed[12];
  double posnDilution;
  double horizDilution;
  double vertDilution;
} PhidgetGPS_GPGSA, *PhidgetGPS_GPGSAHandle;

typedef struct
{
  char status;
  double latitude;
  double longitude;
  double speedKnots;
  double heading;
  double magneticVariation;
  char mode;
} PhidgetGPS_GPRMC, *PhidgetGPS_GPRMCHandle;

typedef struct
{
  double trueHeading;
  double magneticHeading;
  double speedKnots;
  double speed;
  char mode;
} PhidgetGPS_GPVTG, *PhidgetGPS_GPVTGHandle;

typedef struct
{
  PhidgetGPS_GPGGA GGA;
  PhidgetGPS_GPGSA GSA;
  PhidgetGPS_GPRMC RMC;
  PhidgetGPS_GPVTG VTG;
} PhidgetGPS_NMEAData, *PhidgetGPS_NMEADataHandle;

typedef enum
{
  SPATIAL_ALGORITHM_NONE = 0x0,	/* None */
  SPATIAL_ALGORITHM_AHRS = 0x1,	/* AHRS */
  SPATIAL_ALGORITHM_IMU = 0x2,	/* IMU */
} Phidget_SpatialAlgorithm;

typedef struct
{
  double x;
  double y;
  double z;
  double w;
} PhidgetSpatial_SpatialQuaternion, *PhidgetSpatial_SpatialQuaternionHandle;

typedef struct
{
  double pitch;
  double roll;
  double heading;
} PhidgetSpatial_SpatialEulerAngles, *PhidgetSpatial_SpatialEulerAnglesHandle;

typedef enum
{
  RTD_TYPE_PT100_3850 = 0x1,	/* PT100 3850 */
  RTD_TYPE_PT1000_3850 = 0x2,	/* PT1000 3850 */
  RTD_TYPE_PT100_3920 = 0x3,	/* PT100 3920 */
  RTD_TYPE_PT1000_3920 = 0x4,	/* PT1000 3920 */
} PhidgetTemperatureSensor_RTDType;

typedef enum
{
  THERMOCOUPLE_TYPE_J = 0x1,	/* J-Type */
  THERMOCOUPLE_TYPE_K = 0x2,	/* K-Type */
  THERMOCOUPLE_TYPE_E = 0x3,	/* E-Type */
  THERMOCOUPLE_TYPE_T = 0x4,	/* T-Type */
} PhidgetTemperatureSensor_ThermocoupleType;

typedef enum
{
  FILTER_TYPE_ZERO_CROSSING = 0x1,	/* Zero Crossing */
  FILTER_TYPE_LOGIC_LEVEL = 0x2,	/* Logic Level */
} PhidgetFrequencyCounter_FilterType;

typedef enum
{
  IR_ENCODING_UNKNOWN = 0x1,	/* Unknown */
  IR_ENCODING_SPACE = 0x2,	/* Space */
  IR_ENCODING_PULSE = 0x3,	/* Pulse */
  IR_ENCODING_BIPHASE = 0x4,	/* BiPhase */
  IR_ENCODING_RC5 = 0x5,	/* RC5 */
  IR_ENCODING_RC6 = 0x6,	/* RC6 */
} PhidgetIR_Encoding;

typedef enum
{
  IR_LENGTH_UNKNOWN = 0x1,	/* Unknown */
  IR_LENGTH_CONSTANT = 0x2,	/* Constant */
  IR_LENGTH_VARIABLE = 0x3,	/* Variable */
} PhidgetIR_Length;

typedef struct
{
  uint32_t bitCount;
  PhidgetIR_Encoding encoding;
  PhidgetIR_Length length;
  uint32_t gap;
  uint32_t trail;
  uint32_t header[2];
  uint32_t one[2];
  uint32_t zero[2];
  uint32_t repeat[26];
  uint32_t minRepeat;
  double dutyCycle;
  uint32_t carrierFrequency;
  char toggleMask[33];
} PhidgetIR_CodeInfo, *PhidgetIR_CodeInfoHandle;

typedef enum
{
  CONTROL_MODE_STEP = 0x0,	/* Step */
  CONTROL_MODE_RUN = 0x1,	/* Run */
} PhidgetStepper_ControlMode;

typedef enum
{
  FONT_User1 = 0x1,		/* User 1 */
  FONT_User2 = 0x2,		/* User 2 */
  FONT_6x10 = 0x3,		/* 6x10 */
  FONT_5x8 = 0x4,		/* 5x8 */
  FONT_6x12 = 0x5,		/* 6x12 */
} PhidgetLCD_Font;

typedef enum
{
  SCREEN_SIZE_NONE = 0x1,	/* No Screen */
  SCREEN_SIZE_1x8 = 0x2,	/* 1x8 */
  SCREEN_SIZE_2x8 = 0x3,	/* 2x8 */
  SCREEN_SIZE_1x16 = 0x4,	/* 1x16 */
  SCREEN_SIZE_2x16 = 0x5,	/* 2x16 */
  SCREEN_SIZE_4x16 = 0x6,	/* 4x16 */
  SCREEN_SIZE_2x20 = 0x7,	/* 2x20 */
  SCREEN_SIZE_4x20 = 0x8,	/* 4x20 */
  SCREEN_SIZE_2x24 = 0x9,	/* 2x24 */
  SCREEN_SIZE_1x40 = 0xa,	/* 1x40 */
  SCREEN_SIZE_2x40 = 0xb,	/* 2x40 */
  SCREEN_SIZE_4x40 = 0xc,	/* 4x40 */
  SCREEN_SIZE_64x128 = 0xd,	/* 64x128 */
} PhidgetLCD_ScreenSize;

typedef enum
{
  PIXEL_STATE_OFF = 0x0,	/* Off */
  PIXEL_STATE_ON = 0x1,		/* On */
  PIXEL_STATE_INVERT = 0x2,	/* Invert */
} PhidgetLCD_PixelState;

typedef enum
{
  SPI_MODE_0 = 0x1,		/* Mode 0 */
  SPI_MODE_1 = 0x2,		/* Mode 1 */
  SPI_MODE_2 = 0x3,		/* Mode 2 */
  SPI_MODE_3 = 0x4,		/* Mode 3 */
} PhidgetDataAdapter_SPIMode;

typedef enum
{
  FREQUENCY_10kHz = 0x1,	/* 10kHz */
  FREQUENCY_100kHz = 0x2,	/* 100kHz */
  FREQUENCY_400kHz = 0x3,	/* 400kHz */
  FREQUENCY_188kHz = 0x4,	/* 188kHz */
  FREQUENCY_375kHz = 0x5,	/* 375kHz */
  FREQUENCY_750kHz = 0x6,	/* 750kHz */
  FREQUENCY_1500kHz = 0x7,	/* 1500kHz */
  FREQUENCY_3MHz = 0x8,		/* 3MHz */
  FREQUENCY_6MHz = 0x9,		/* 6MHz */
} PhidgetDataAdapter_Frequency;

typedef enum
{
  PACKET_ERROR_OK = 0x0,	/* No error */
  PACKET_ERROR_UNKNOWN = 0x1,	/* Unknown Error */
  PACKET_ERROR_TIMEOUT = 0x2,	/* Timeout Error */
  PACKET_ERROR_FORMAT = 0x3,	/* Format Error */
  PACKET_ERROR_INVALID = 0x4,	/* Invalid Error */
  PACKET_ERROR_OVERRUN = 0x5,	/* Overrun Error */
  PACKET_ERROR_CORRUPT = 0x6,	/* Corrupt Error */
  PACKET_ERROR_NACK = 0x7,	/* NACK Error */
} PhidgetDataAdapter_PacketErrorCode;

typedef enum
{
  SPI_CHIP_SELECT_ACTIVE_LOW = 0x1,	/* Active Low */
  SPI_CHIP_SELECT_ACTIVE_HIGH = 0x2,	/* Active High */
  SPI_CHIP_SELECT_LOW = 0x3,	/* Low */
  SPI_CHIP_SELECT_HIGH = 0x4,	/* High */
} PhidgetDataAdapter_SPIChipSelect;

typedef enum
{
  ENDIANNESS_MSB_FIRST = 0x1,	/* MSB First */
  ENDIANNESS_LSB_FIRST = 0x2,	/* LSB First */
} PhidgetDataAdapter_Endianness;

typedef struct
{
  uint8_t r;
  uint8_t g;
  uint8_t b;
  uint8_t w;
} PhidgetLEDArray_RGBW, *PhidgetLEDArray_RGBWHandle;

typedef enum
{
  LED_PROTOCOL_RGB = 0x1,	/* Byte order RGB (WS2811) */
  LED_PROTOCOL_GRB = 0x2,	/* Byte order GRB (WS2812B, SK6812) */
  LED_PROTOCOL_RGBW = 0x3,	/* Byte order RGBW */
  LED_PROTOCOL_GRBW = 0x4,	/* Byte order GRBW (SK6812RGBW) */
} PhidgetLEDArray_Protocol;

typedef enum
{
  ANIMATION_TYPE_FORWARD_SCROLL = 0x1,	/* Forward Scroll */
  ANIMATION_TYPE_REVERSE_SCROLL = 0x2,	/* Reverse Scroll */
  ANIMATION_TYPE_POPCORN = 0x3,	/* Popcorn */
  ANIMATION_TYPE_FORWARD_SCROLL_MIRROR = 0x4,	/* Forward Scroll Mirror */
  ANIMATION_TYPE_REVERSE_SCROLL_MIRROR = 0x5,	/* Reverse Scroll Mirror */
} PhidgetLEDArray_AnimationType;

typedef struct
{
  uint16_t startAddress;
  uint16_t span;
  uint16_t time;
  PhidgetLEDArray_AnimationType animationType;
} PhidgetLEDArray_AnimationDescription, *PhidgetLEDArray_AnimationDescriptionHandle;

typedef enum
{
  SPL_RANGE_102dB = 0x1,	/* 102 dB */
  SPL_RANGE_82dB = 0x2,		/* 82 dB */
} PhidgetSoundSensor_SPLRange;

typedef enum
{
  PORT_MODE_VINT_PORT = 0x0,	/* VINT */
  PORT_MODE_DIGITAL_INPUT = 0x1,	/* Digital Input */
  PORT_MODE_DIGITAL_OUTPUT = 0x2,	/* Digital Output */
  PORT_MODE_VOLTAGE_INPUT = 0x3,	/* Voltage Input */
  PORT_MODE_VOLTAGE_RATIO_INPUT = 0x4,	/* Voltage Ratio Input */
} PhidgetHub_PortMode;

typedef struct _Phidget *PhidgetHandle;

/* Methods */
__declspec (dllimport)
     PhidgetReturnCode __stdcall Phidget_getErrorDescription (PhidgetReturnCode errorCode, const char **errorString);
__declspec (dllimport)
     PhidgetReturnCode __stdcall Phidget_finalize (int flags);
__declspec (dllimport)
     PhidgetReturnCode __stdcall Phidget_getLastError (PhidgetReturnCode * errorCode, const char **errorString, char *errorDetail, size_t * errorDetailLen);
__declspec (dllimport)
     PhidgetReturnCode __stdcall Phidget_release (PhidgetHandle * phid);
__declspec (dllimport)
     PhidgetReturnCode __stdcall Phidget_resetLibrary (void);
__declspec (dllimport)
     PhidgetReturnCode __stdcall Phidget_retain (PhidgetHandle phid);

__declspec (dllimport)
     PhidgetReturnCode __stdcall Phidget_getClientVersion (PhidgetHandle ch, int *major, int *minor);

__declspec (dllimport)
     PhidgetReturnCode __stdcall Phidget_close (PhidgetHandle ch);
__declspec (dllimport)
     PhidgetReturnCode __stdcall Phidget_getDeviceChannelCount (PhidgetHandle ch, Phidget_ChannelClass cls, uint32_t * count);
__declspec (dllimport)
     PhidgetReturnCode __stdcall Phidget_open (PhidgetHandle ch);
__declspec (dllimport)
     PhidgetReturnCode __stdcall Phidget_openWaitForAttachment (PhidgetHandle ch, uint32_t timeout);

__declspec (dllimport)
     PhidgetReturnCode __stdcall Phidget_reboot (PhidgetHandle ch);

__declspec (dllimport)
     PhidgetReturnCode __stdcall Phidget_rebootFirmwareUpgrade (PhidgetHandle ch, uint32_t upgradeTimeout);

__declspec (dllimport)
     PhidgetReturnCode __stdcall Phidget_getServerVersion (PhidgetHandle ch, int *major, int *minor);

__declspec (dllimport)
     PhidgetReturnCode __stdcall Phidget_writeDeviceLabel (PhidgetHandle ch, const char *deviceLabel);

__declspec (dllimport)
     PhidgetReturnCode __stdcall Phidget_writeFlash (PhidgetHandle ch);

/* Properties */
__declspec (dllimport)
     PhidgetReturnCode __stdcall Phidget_getLibraryVersion (const char **libraryVersion);
__declspec (dllimport)
     PhidgetReturnCode __stdcall Phidget_getLibraryVersionNumber (const char **libraryVersionNumber);
__declspec (dllimport)
     PhidgetReturnCode __stdcall Phidget_getAttached (PhidgetHandle ch, int *attached);
__declspec (dllimport)
     PhidgetReturnCode __stdcall Phidget_setChannel (PhidgetHandle ch, int channel);
__declspec (dllimport)
     PhidgetReturnCode __stdcall Phidget_getChannel (PhidgetHandle ch, int *channel);
__declspec (dllimport)
     PhidgetReturnCode __stdcall Phidget_getIsChannel (PhidgetHandle ch, int *isChannel);
__declspec (dllimport)
     PhidgetReturnCode __stdcall Phidget_getChannelClass (PhidgetHandle ch, Phidget_ChannelClass * channelClass);
__declspec (dllimport)
     PhidgetReturnCode __stdcall Phidget_getChannelClassName (PhidgetHandle ch, const char **channelClassName);
__declspec (dllimport)
     PhidgetReturnCode __stdcall Phidget_getChannelName (PhidgetHandle ch, const char **channelName);
__declspec (dllimport)
     PhidgetReturnCode __stdcall Phidget_getChannelSubclass (PhidgetHandle ch, Phidget_ChannelSubclass * channelSubclass);
__declspec (dllimport)
     PhidgetReturnCode __stdcall Phidget_setDataInterval (PhidgetHandle ch, uint32_t dataInterval);
__declspec (dllimport)
     PhidgetReturnCode __stdcall Phidget_getDataInterval (PhidgetHandle ch, uint32_t * dataInterval);
__declspec (dllimport)
     PhidgetReturnCode __stdcall Phidget_getMinDataInterval (PhidgetHandle ch, uint32_t * minDataInterval);
__declspec (dllimport)
     PhidgetReturnCode __stdcall Phidget_getMaxDataInterval (PhidgetHandle ch, uint32_t * maxDataInterval);
__declspec (dllimport)
     PhidgetReturnCode __stdcall Phidget_setDataRate (PhidgetHandle ch, double dataRate);
__declspec (dllimport)
     PhidgetReturnCode __stdcall Phidget_getDataRate (PhidgetHandle ch, double *dataRate);
__declspec (dllimport)
     PhidgetReturnCode __stdcall Phidget_getMinDataRate (PhidgetHandle ch, double *minDataRate);
__declspec (dllimport)
     PhidgetReturnCode __stdcall Phidget_getMaxDataRate (PhidgetHandle ch, double *maxDataRate);
__declspec (dllimport)
     PhidgetReturnCode __stdcall Phidget_getDeviceClass (PhidgetHandle ch, Phidget_DeviceClass * deviceClass);
__declspec (dllimport)
     PhidgetReturnCode __stdcall Phidget_getDeviceClassName (PhidgetHandle ch, const char **deviceClassName);

__declspec (dllimport)
     PhidgetReturnCode __stdcall Phidget_getDeviceFirmwareUpgradeString (PhidgetHandle ch, const char **deviceFirmwareUpgradeString);

__declspec (dllimport)
     PhidgetReturnCode __stdcall Phidget_getDeviceID (PhidgetHandle ch, Phidget_DeviceID * deviceID);
__declspec (dllimport)
     PhidgetReturnCode __stdcall Phidget_setDeviceLabel (PhidgetHandle ch, const char *deviceLabel);
__declspec (dllimport)
     PhidgetReturnCode __stdcall Phidget_getDeviceLabel (PhidgetHandle ch, const char **deviceLabel);
__declspec (dllimport)
     PhidgetReturnCode __stdcall Phidget_getDeviceName (PhidgetHandle ch, const char **deviceName);
__declspec (dllimport)
     PhidgetReturnCode __stdcall Phidget_setDeviceSerialNumber (PhidgetHandle ch, int32_t deviceSerialNumber);
__declspec (dllimport)
     PhidgetReturnCode __stdcall Phidget_getDeviceSerialNumber (PhidgetHandle ch, int32_t * deviceSerialNumber);
__declspec (dllimport)
     PhidgetReturnCode __stdcall Phidget_getDeviceSKU (PhidgetHandle ch, const char **deviceSKU);
__declspec (dllimport)
     PhidgetReturnCode __stdcall Phidget_getDeviceVersion (PhidgetHandle ch, int *deviceVersion);

__declspec (dllimport)
     PhidgetReturnCode __stdcall Phidget_getDeviceVINTID (PhidgetHandle ch, uint32_t * deviceVINTID);

__declspec (dllimport)
     PhidgetReturnCode __stdcall Phidget_getHub (PhidgetHandle ch, PhidgetHandle * hub);
__declspec (dllimport)
     PhidgetReturnCode __stdcall Phidget_setHubPort (PhidgetHandle ch, int hubPort);
__declspec (dllimport)
     PhidgetReturnCode __stdcall Phidget_getHubPort (PhidgetHandle ch, int *hubPort);
__declspec (dllimport)
     PhidgetReturnCode __stdcall Phidget_getHubPortCount (PhidgetHandle ch, int *hubPortCount);
__declspec (dllimport)
     PhidgetReturnCode __stdcall Phidget_setIsHubPortDevice (PhidgetHandle ch, int isHubPortDevice);
__declspec (dllimport)
     PhidgetReturnCode __stdcall Phidget_getIsHubPortDevice (PhidgetHandle ch, int *isHubPortDevice);
__declspec (dllimport)
     PhidgetReturnCode __stdcall Phidget_setHubPortSpeed (PhidgetHandle ch, uint32_t hubPortSpeed);
__declspec (dllimport)
     PhidgetReturnCode __stdcall Phidget_getHubPortSpeed (PhidgetHandle ch, uint32_t * hubPortSpeed);
__declspec (dllimport)
     PhidgetReturnCode __stdcall Phidget_getMaxHubPortSpeed (PhidgetHandle ch, uint32_t * maxHubPortSpeed);
__declspec (dllimport)
     PhidgetReturnCode __stdcall Phidget_getHubPortSupportsAutoSetSpeed (PhidgetHandle ch, int *hubPortSupportsAutoSetSpeed);
__declspec (dllimport)
     PhidgetReturnCode __stdcall Phidget_getHubPortSupportsSetSpeed (PhidgetHandle ch, int *hubPortSupportsSetSpeed);
__declspec (dllimport)
     PhidgetReturnCode __stdcall Phidget_setIsLocal (PhidgetHandle ch, int isLocal);
__declspec (dllimport)
     PhidgetReturnCode __stdcall Phidget_getIsLocal (PhidgetHandle ch, int *isLocal);

__declspec (dllimport)
     PhidgetReturnCode __stdcall Phidget_setMeshMode (PhidgetHandle ch, Phidget_MeshMode meshMode);
__declspec (dllimport)
     PhidgetReturnCode __stdcall Phidget_getMeshMode (PhidgetHandle ch, Phidget_MeshMode * meshMode);

__declspec (dllimport)
     PhidgetReturnCode __stdcall Phidget_getIsOpen (PhidgetHandle ch, int *isOpen);
__declspec (dllimport)
     PhidgetReturnCode __stdcall Phidget_getParent (PhidgetHandle ch, PhidgetHandle * parent);
__declspec (dllimport)
     PhidgetReturnCode __stdcall Phidget_setIsRemote (PhidgetHandle ch, int isRemote);
__declspec (dllimport)
     PhidgetReturnCode __stdcall Phidget_getIsRemote (PhidgetHandle ch, int *isRemote);
__declspec (dllimport)
     PhidgetReturnCode __stdcall Phidget_getServerHostname (PhidgetHandle ch, const char **serverHostname);
__declspec (dllimport)
     PhidgetReturnCode __stdcall Phidget_setServerName (PhidgetHandle ch, const char *serverName);
__declspec (dllimport)
     PhidgetReturnCode __stdcall Phidget_getServerName (PhidgetHandle ch, const char **serverName);
__declspec (dllimport)
     PhidgetReturnCode __stdcall Phidget_getServerPeerName (PhidgetHandle ch, const char **serverPeerName);
__declspec (dllimport)
     PhidgetReturnCode __stdcall Phidget_getServerUniqueName (PhidgetHandle ch, const char **serverUniqueName);
__declspec (dllimport)
     PhidgetReturnCode __stdcall Phidget_getMaxVINTDeviceSpeed (PhidgetHandle ch, uint32_t * maxVINTDeviceSpeed);
__declspec (dllimport)
     PhidgetReturnCode __stdcall Phidget_getVINTDeviceSupportsAutoSetSpeed (PhidgetHandle ch, int *VINTDeviceSupportsAutoSetSpeed);
__declspec (dllimport)
     PhidgetReturnCode __stdcall Phidget_getVINTDeviceSupportsSetSpeed (PhidgetHandle ch, int *VINTDeviceSupportsSetSpeed);

/* Events */
     typedef void (__stdcall * Phidget_OnAttachCallback) (PhidgetHandle ch, void *ctx);

__declspec (dllimport)
     PhidgetReturnCode __stdcall Phidget_setOnAttachHandler (PhidgetHandle ch, Phidget_OnAttachCallback fptr, void *ctx);
     typedef void (__stdcall * Phidget_OnDetachCallback) (PhidgetHandle ch, void *ctx);

__declspec (dllimport)
     PhidgetReturnCode __stdcall Phidget_setOnDetachHandler (PhidgetHandle ch, Phidget_OnDetachCallback fptr, void *ctx);
     typedef void (__stdcall * Phidget_OnErrorCallback) (PhidgetHandle ch, void *ctx, Phidget_ErrorEventCode code, const char *description);

__declspec (dllimport)
     PhidgetReturnCode __stdcall Phidget_setOnErrorHandler (PhidgetHandle ch, Phidget_OnErrorCallback fptr, void *ctx);
     typedef void (__stdcall * Phidget_OnPropertyChangeCallback) (PhidgetHandle ch, void *ctx, const char *propertyName);

__declspec (dllimport)
     PhidgetReturnCode __stdcall Phidget_setOnPropertyChangeHandler (PhidgetHandle ch, Phidget_OnPropertyChangeCallback fptr, void *ctx);

     typedef void (__stdcall * Phidget_AsyncCallback) (PhidgetHandle phid, void *ctx, PhidgetReturnCode returnCode);

/* Channel agnostic delete */
__declspec (dllimport)
     PhidgetReturnCode __stdcall Phidget_delete (PhidgetHandle * phid);

/* Returns VINT devices attached to a VINT hub */
__declspec (dllimport)
     PhidgetReturnCode __stdcall Phidget_getChildDevices (PhidgetHandle phid, PhidgetHandle * arr, size_t * arrCnt);
__declspec (dllimport)
     PhidgetReturnCode __stdcall Phidget_releaseDevices (PhidgetHandle * arr, size_t arrCnt);

/* Used by the network server */
__declspec (dllimport)
     int __stdcall Phidget_validDictionaryKey (const char *);
     typedef void (__stdcall * PhidgetDictionary_OnChangeCallback) (int, const char *, void *, int, const char *, const char *);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDictionary_setOnChangeCallbackHandler (PhidgetDictionary_OnChangeCallback, void *);

     typedef struct _PhidgetManager *PhidgetManagerHandle;

/* Methods */
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetManager_create (PhidgetManagerHandle * man);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetManager_delete (PhidgetManagerHandle * man);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetManager_close (PhidgetManagerHandle man);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetManager_open (PhidgetManagerHandle man);

/* Properties */

/* Events */
     typedef void (__stdcall * PhidgetManager_OnAttachCallback) (PhidgetManagerHandle man, void *ctx, PhidgetHandle channel);

__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetManager_setOnAttachHandler (PhidgetManagerHandle man, PhidgetManager_OnAttachCallback fptr, void *ctx);
     typedef void (__stdcall * PhidgetManager_OnDetachCallback) (PhidgetManagerHandle man, void *ctx, PhidgetHandle channel);

__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetManager_setOnDetachHandler (PhidgetManagerHandle man, PhidgetManager_OnDetachCallback fptr, void *ctx);

/* Methods */
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetLog_disable (void);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetLog_enable (Phidget_LogLevel level, const char *destination);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetLog_getLevel (Phidget_LogLevel * level);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetLog_setLevel (Phidget_LogLevel level);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetLog_log (Phidget_LogLevel level, const char *message, ...);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetLog_loge (const char *file, int line, const char *function, const char *source, Phidget_LogLevel level, const char *message, ...);

__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetLog_loges (Phidget_LogLevel level, const char *source, const char *message);

__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetLog_logs (Phidget_LogLevel level, const char *message);

__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetLog_rotate (void);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetLog_isRotating (int *isrotating);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetLog_getRotating (uint64_t * size, int *keepCount);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetLog_setRotating (uint64_t size, int keepCount);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetLog_enableRotating (void);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetLog_disableRotating (void);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetLog_addSource (const char *source, Phidget_LogLevel level);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetLog_getSourceLevel (const char *source, Phidget_LogLevel * level);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetLog_setSourceLevel (const char *source, Phidget_LogLevel level);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetLog_getSources (const char **sources, uint32_t * count);

/* Properties */

/* Events */

__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetLog_enableNetwork (const char *address, int port);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetLog_disableNetwork (void);

/* Methods */

__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetNet_removeAllServers (void);

__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetNet_freeServerAddressList (const char **addressList, uint32_t count);

__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetNet_setProperty (const char *key, const char *property, ...);

__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetNet_addServer (const char *serverName, const char *address, int port, const char *password, int flags);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetNet_removeServer (const char *serverName);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetNet_enableServer (const char *serverName);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetNet_disableServer (const char *serverName, int flags);

__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetNet_getServerAddressList (const char *hostname, int addressFamily, const char **addressList, uint32_t * count);

__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetNet_enableServerDiscovery (PhidgetServerType serverType);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetNet_disableServerDiscovery (PhidgetServerType serverType);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetNet_setServerPassword (const char *serverName, const char *password);

__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetNet_startServer (int flags, int addressFamily, const char *serverName, const char *address, int port, const char *password, PhidgetServer ** server);

__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetNet_stopServer (PhidgetServer ** server);

/* Properties */

/* Events */
     typedef void (__stdcall * PhidgetNet_OnServerAddedCallback) (void *ctx, PhidgetServer * server, void *kv);

__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetNet_setOnServerAddedHandler (PhidgetNet_OnServerAddedCallback fptr, void *ctx);
     typedef void (__stdcall * PhidgetNet_OnServerRemovedCallback) (void *ctx, PhidgetServer * server);

__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetNet_setOnServerRemovedHandler (PhidgetNet_OnServerRemovedCallback fptr, void *ctx);

__declspec (dllimport)
     const char *__stdcall Phidget_enumString (const char *, int);
__declspec (dllimport)
     int __stdcall Phidget_enumFromString (const char *);

     typedef struct _PhidgetAccelerometer *PhidgetAccelerometerHandle;

/* Methods */
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetAccelerometer_create (PhidgetAccelerometerHandle * ch);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetAccelerometer_delete (PhidgetAccelerometerHandle * ch);

/* Properties */
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetAccelerometer_getAcceleration (PhidgetAccelerometerHandle ch, double (*acceleration)[3]);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetAccelerometer_getMinAcceleration (PhidgetAccelerometerHandle ch, double (*minAcceleration)[3]);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetAccelerometer_getMaxAcceleration (PhidgetAccelerometerHandle ch, double (*maxAcceleration)[3]);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetAccelerometer_setAccelerationChangeTrigger (PhidgetAccelerometerHandle ch, double accelerationChangeTrigger);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetAccelerometer_getAccelerationChangeTrigger (PhidgetAccelerometerHandle ch, double *accelerationChangeTrigger);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetAccelerometer_getMinAccelerationChangeTrigger (PhidgetAccelerometerHandle ch, double *minAccelerationChangeTrigger);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetAccelerometer_getMaxAccelerationChangeTrigger (PhidgetAccelerometerHandle ch, double *maxAccelerationChangeTrigger);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetAccelerometer_getAxisCount (PhidgetAccelerometerHandle ch, int *axisCount);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetAccelerometer_setDataInterval (PhidgetAccelerometerHandle ch, uint32_t dataInterval);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetAccelerometer_getDataInterval (PhidgetAccelerometerHandle ch, uint32_t * dataInterval);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetAccelerometer_getMinDataInterval (PhidgetAccelerometerHandle ch, uint32_t * minDataInterval);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetAccelerometer_getMaxDataInterval (PhidgetAccelerometerHandle ch, uint32_t * maxDataInterval);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetAccelerometer_setDataRate (PhidgetAccelerometerHandle ch, double dataRate);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetAccelerometer_getDataRate (PhidgetAccelerometerHandle ch, double *dataRate);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetAccelerometer_getMinDataRate (PhidgetAccelerometerHandle ch, double *minDataRate);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetAccelerometer_getMaxDataRate (PhidgetAccelerometerHandle ch, double *maxDataRate);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetAccelerometer_setHeatingEnabled (PhidgetAccelerometerHandle ch, int heatingEnabled);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetAccelerometer_getHeatingEnabled (PhidgetAccelerometerHandle ch, int *heatingEnabled);

__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetAccelerometer_setPrecision (PhidgetAccelerometerHandle ch, Phidget_SpatialPrecision precision);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetAccelerometer_getPrecision (PhidgetAccelerometerHandle ch, Phidget_SpatialPrecision * precision);

__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetAccelerometer_getTimestamp (PhidgetAccelerometerHandle ch, double *timestamp);

/* Events */
     typedef void (__stdcall * PhidgetAccelerometer_OnAccelerationChangeCallback) (PhidgetAccelerometerHandle ch, void *ctx, const double acceleration[3], double timestamp);

__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetAccelerometer_setOnAccelerationChangeHandler (PhidgetAccelerometerHandle ch, PhidgetAccelerometer_OnAccelerationChangeCallback fptr, void *ctx);

     typedef struct _PhidgetBLDCMotor *PhidgetBLDCMotorHandle;

/* Methods */
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetBLDCMotor_create (PhidgetBLDCMotorHandle * ch);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetBLDCMotor_delete (PhidgetBLDCMotorHandle * ch);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetBLDCMotor_enableFailsafe (PhidgetBLDCMotorHandle ch, uint32_t failsafeTime);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetBLDCMotor_addPositionOffset (PhidgetBLDCMotorHandle ch, double positionOffset);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetBLDCMotor_resetFailsafe (PhidgetBLDCMotorHandle ch);

/* Properties */
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetBLDCMotor_setAcceleration (PhidgetBLDCMotorHandle ch, double acceleration);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetBLDCMotor_getAcceleration (PhidgetBLDCMotorHandle ch, double *acceleration);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetBLDCMotor_getMinAcceleration (PhidgetBLDCMotorHandle ch, double *minAcceleration);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetBLDCMotor_getMaxAcceleration (PhidgetBLDCMotorHandle ch, double *maxAcceleration);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetBLDCMotor_getActiveCurrentLimit (PhidgetBLDCMotorHandle ch, double *activeCurrentLimit);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetBLDCMotor_setBrakingEnabled (PhidgetBLDCMotorHandle ch, int brakingEnabled);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetBLDCMotor_getBrakingEnabled (PhidgetBLDCMotorHandle ch, int *brakingEnabled);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetBLDCMotor_getBrakingStrength (PhidgetBLDCMotorHandle ch, double *brakingStrength);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetBLDCMotor_getMinBrakingStrength (PhidgetBLDCMotorHandle ch, double *minBrakingStrength);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetBLDCMotor_getMaxBrakingStrength (PhidgetBLDCMotorHandle ch, double *maxBrakingStrength);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetBLDCMotor_setCurrentLimit (PhidgetBLDCMotorHandle ch, double currentLimit);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetBLDCMotor_getCurrentLimit (PhidgetBLDCMotorHandle ch, double *currentLimit);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetBLDCMotor_getMinCurrentLimit (PhidgetBLDCMotorHandle ch, double *minCurrentLimit);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetBLDCMotor_getMaxCurrentLimit (PhidgetBLDCMotorHandle ch, double *maxCurrentLimit);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetBLDCMotor_setDataInterval (PhidgetBLDCMotorHandle ch, uint32_t dataInterval);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetBLDCMotor_getDataInterval (PhidgetBLDCMotorHandle ch, uint32_t * dataInterval);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetBLDCMotor_getMinDataInterval (PhidgetBLDCMotorHandle ch, uint32_t * minDataInterval);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetBLDCMotor_getMaxDataInterval (PhidgetBLDCMotorHandle ch, uint32_t * maxDataInterval);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetBLDCMotor_setDataRate (PhidgetBLDCMotorHandle ch, double dataRate);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetBLDCMotor_getDataRate (PhidgetBLDCMotorHandle ch, double *dataRate);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetBLDCMotor_getMinDataRate (PhidgetBLDCMotorHandle ch, double *minDataRate);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetBLDCMotor_getMaxDataRate (PhidgetBLDCMotorHandle ch, double *maxDataRate);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetBLDCMotor_setDriveMode (PhidgetBLDCMotorHandle ch, Phidget_DriveMode driveMode);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetBLDCMotor_getDriveMode (PhidgetBLDCMotorHandle ch, Phidget_DriveMode * driveMode);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetBLDCMotor_setFailsafeBrakingEnabled (PhidgetBLDCMotorHandle ch, int failsafeBrakingEnabled);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetBLDCMotor_getFailsafeBrakingEnabled (PhidgetBLDCMotorHandle ch, int *failsafeBrakingEnabled);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetBLDCMotor_setFailsafeCurrentLimit (PhidgetBLDCMotorHandle ch, double failsafeCurrentLimit);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetBLDCMotor_getFailsafeCurrentLimit (PhidgetBLDCMotorHandle ch, double *failsafeCurrentLimit);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetBLDCMotor_getMinFailsafeTime (PhidgetBLDCMotorHandle ch, uint32_t * minFailsafeTime);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetBLDCMotor_getMaxFailsafeTime (PhidgetBLDCMotorHandle ch, uint32_t * maxFailsafeTime);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetBLDCMotor_setInductance (PhidgetBLDCMotorHandle ch, double inductance);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetBLDCMotor_getInductance (PhidgetBLDCMotorHandle ch, double *inductance);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetBLDCMotor_getMinInductance (PhidgetBLDCMotorHandle ch, double *minInductance);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetBLDCMotor_getMaxInductance (PhidgetBLDCMotorHandle ch, double *maxInductance);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetBLDCMotor_getPosition (PhidgetBLDCMotorHandle ch, double *position);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetBLDCMotor_getMinPosition (PhidgetBLDCMotorHandle ch, double *minPosition);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetBLDCMotor_getMaxPosition (PhidgetBLDCMotorHandle ch, double *maxPosition);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetBLDCMotor_setRescaleFactor (PhidgetBLDCMotorHandle ch, double rescaleFactor);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetBLDCMotor_getRescaleFactor (PhidgetBLDCMotorHandle ch, double *rescaleFactor);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetBLDCMotor_setStallVelocity (PhidgetBLDCMotorHandle ch, double stallVelocity);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetBLDCMotor_getStallVelocity (PhidgetBLDCMotorHandle ch, double *stallVelocity);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetBLDCMotor_getMinStallVelocity (PhidgetBLDCMotorHandle ch, double *minStallVelocity);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetBLDCMotor_getMaxStallVelocity (PhidgetBLDCMotorHandle ch, double *maxStallVelocity);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetBLDCMotor_setSurgeCurrentLimit (PhidgetBLDCMotorHandle ch, double surgeCurrentLimit);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetBLDCMotor_getSurgeCurrentLimit (PhidgetBLDCMotorHandle ch, double *surgeCurrentLimit);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetBLDCMotor_getMinSurgeCurrentLimit (PhidgetBLDCMotorHandle ch, double *minSurgeCurrentLimit);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetBLDCMotor_getMaxSurgeCurrentLimit (PhidgetBLDCMotorHandle ch, double *maxSurgeCurrentLimit);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetBLDCMotor_setTargetBrakingStrength (PhidgetBLDCMotorHandle ch, double targetBrakingStrength);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetBLDCMotor_getTargetBrakingStrength (PhidgetBLDCMotorHandle ch, double *targetBrakingStrength);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetBLDCMotor_setTargetVelocity (PhidgetBLDCMotorHandle ch, double targetVelocity);
__declspec (dllimport)
     void __stdcall PhidgetBLDCMotor_setTargetVelocity_async (PhidgetBLDCMotorHandle ch, double targetVelocity, Phidget_AsyncCallback fptr, void *ctx);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetBLDCMotor_getTargetVelocity (PhidgetBLDCMotorHandle ch, double *targetVelocity);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetBLDCMotor_getVelocity (PhidgetBLDCMotorHandle ch, double *velocity);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetBLDCMotor_getMinVelocity (PhidgetBLDCMotorHandle ch, double *minVelocity);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetBLDCMotor_getMaxVelocity (PhidgetBLDCMotorHandle ch, double *maxVelocity);

/* Events */
     typedef void (__stdcall * PhidgetBLDCMotor_OnBrakingStrengthChangeCallback) (PhidgetBLDCMotorHandle ch, void *ctx, double brakingStrength);

__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetBLDCMotor_setOnBrakingStrengthChangeHandler (PhidgetBLDCMotorHandle ch, PhidgetBLDCMotor_OnBrakingStrengthChangeCallback fptr, void *ctx);
     typedef void (__stdcall * PhidgetBLDCMotor_OnPositionChangeCallback) (PhidgetBLDCMotorHandle ch, void *ctx, double position);

__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetBLDCMotor_setOnPositionChangeHandler (PhidgetBLDCMotorHandle ch, PhidgetBLDCMotor_OnPositionChangeCallback fptr, void *ctx);
     typedef void (__stdcall * PhidgetBLDCMotor_OnVelocityUpdateCallback) (PhidgetBLDCMotorHandle ch, void *ctx, double velocity);

__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetBLDCMotor_setOnVelocityUpdateHandler (PhidgetBLDCMotorHandle ch, PhidgetBLDCMotor_OnVelocityUpdateCallback fptr, void *ctx);

     typedef struct _PhidgetCapacitiveTouch *PhidgetCapacitiveTouchHandle;

/* Methods */
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetCapacitiveTouch_create (PhidgetCapacitiveTouchHandle * ch);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetCapacitiveTouch_delete (PhidgetCapacitiveTouchHandle * ch);

/* Properties */
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetCapacitiveTouch_setDataInterval (PhidgetCapacitiveTouchHandle ch, uint32_t dataInterval);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetCapacitiveTouch_getDataInterval (PhidgetCapacitiveTouchHandle ch, uint32_t * dataInterval);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetCapacitiveTouch_getMinDataInterval (PhidgetCapacitiveTouchHandle ch, uint32_t * minDataInterval);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetCapacitiveTouch_getMaxDataInterval (PhidgetCapacitiveTouchHandle ch, uint32_t * maxDataInterval);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetCapacitiveTouch_setDataRate (PhidgetCapacitiveTouchHandle ch, double dataRate);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetCapacitiveTouch_getDataRate (PhidgetCapacitiveTouchHandle ch, double *dataRate);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetCapacitiveTouch_getMinDataRate (PhidgetCapacitiveTouchHandle ch, double *minDataRate);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetCapacitiveTouch_getMaxDataRate (PhidgetCapacitiveTouchHandle ch, double *maxDataRate);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetCapacitiveTouch_setSensitivity (PhidgetCapacitiveTouchHandle ch, double sensitivity);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetCapacitiveTouch_getSensitivity (PhidgetCapacitiveTouchHandle ch, double *sensitivity);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetCapacitiveTouch_getMinSensitivity (PhidgetCapacitiveTouchHandle ch, double *minSensitivity);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetCapacitiveTouch_getMaxSensitivity (PhidgetCapacitiveTouchHandle ch, double *maxSensitivity);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetCapacitiveTouch_getIsTouched (PhidgetCapacitiveTouchHandle ch, int *isTouched);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetCapacitiveTouch_getTouchValue (PhidgetCapacitiveTouchHandle ch, double *touchValue);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetCapacitiveTouch_getMinTouchValue (PhidgetCapacitiveTouchHandle ch, double *minTouchValue);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetCapacitiveTouch_getMaxTouchValue (PhidgetCapacitiveTouchHandle ch, double *maxTouchValue);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetCapacitiveTouch_setTouchValueChangeTrigger (PhidgetCapacitiveTouchHandle ch, double touchValueChangeTrigger);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetCapacitiveTouch_getTouchValueChangeTrigger (PhidgetCapacitiveTouchHandle ch, double *touchValueChangeTrigger);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetCapacitiveTouch_getMinTouchValueChangeTrigger (PhidgetCapacitiveTouchHandle ch, double *minTouchValueChangeTrigger);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetCapacitiveTouch_getMaxTouchValueChangeTrigger (PhidgetCapacitiveTouchHandle ch, double *maxTouchValueChangeTrigger);

/* Events */
     typedef void (__stdcall * PhidgetCapacitiveTouch_OnTouchCallback) (PhidgetCapacitiveTouchHandle ch, void *ctx, double touchValue);

__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetCapacitiveTouch_setOnTouchHandler (PhidgetCapacitiveTouchHandle ch, PhidgetCapacitiveTouch_OnTouchCallback fptr, void *ctx);
     typedef void (__stdcall * PhidgetCapacitiveTouch_OnTouchEndCallback) (PhidgetCapacitiveTouchHandle ch, void *ctx);

__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetCapacitiveTouch_setOnTouchEndHandler (PhidgetCapacitiveTouchHandle ch, PhidgetCapacitiveTouch_OnTouchEndCallback fptr, void *ctx);

     typedef struct _PhidgetCurrentInput *PhidgetCurrentInputHandle;

/* Methods */
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetCurrentInput_create (PhidgetCurrentInputHandle * ch);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetCurrentInput_delete (PhidgetCurrentInputHandle * ch);

/* Properties */
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetCurrentInput_getCurrent (PhidgetCurrentInputHandle ch, double *current);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetCurrentInput_getMinCurrent (PhidgetCurrentInputHandle ch, double *minCurrent);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetCurrentInput_getMaxCurrent (PhidgetCurrentInputHandle ch, double *maxCurrent);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetCurrentInput_setCurrentChangeTrigger (PhidgetCurrentInputHandle ch, double currentChangeTrigger);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetCurrentInput_getCurrentChangeTrigger (PhidgetCurrentInputHandle ch, double *currentChangeTrigger);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetCurrentInput_getMinCurrentChangeTrigger (PhidgetCurrentInputHandle ch, double *minCurrentChangeTrigger);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetCurrentInput_getMaxCurrentChangeTrigger (PhidgetCurrentInputHandle ch, double *maxCurrentChangeTrigger);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetCurrentInput_setDataInterval (PhidgetCurrentInputHandle ch, uint32_t dataInterval);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetCurrentInput_getDataInterval (PhidgetCurrentInputHandle ch, uint32_t * dataInterval);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetCurrentInput_getMinDataInterval (PhidgetCurrentInputHandle ch, uint32_t * minDataInterval);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetCurrentInput_getMaxDataInterval (PhidgetCurrentInputHandle ch, uint32_t * maxDataInterval);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetCurrentInput_setDataRate (PhidgetCurrentInputHandle ch, double dataRate);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetCurrentInput_getDataRate (PhidgetCurrentInputHandle ch, double *dataRate);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetCurrentInput_getMinDataRate (PhidgetCurrentInputHandle ch, double *minDataRate);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetCurrentInput_getMaxDataRate (PhidgetCurrentInputHandle ch, double *maxDataRate);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetCurrentInput_setPowerSupply (PhidgetCurrentInputHandle ch, Phidget_PowerSupply powerSupply);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetCurrentInput_getPowerSupply (PhidgetCurrentInputHandle ch, Phidget_PowerSupply * powerSupply);

/* Events */
     typedef void (__stdcall * PhidgetCurrentInput_OnCurrentChangeCallback) (PhidgetCurrentInputHandle ch, void *ctx, double current);

__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetCurrentInput_setOnCurrentChangeHandler (PhidgetCurrentInputHandle ch, PhidgetCurrentInput_OnCurrentChangeCallback fptr, void *ctx);

     typedef struct _PhidgetCurrentOutput *PhidgetCurrentOutputHandle;

/* Methods */
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetCurrentOutput_create (PhidgetCurrentOutputHandle * ch);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetCurrentOutput_delete (PhidgetCurrentOutputHandle * ch);

/* Properties */
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetCurrentOutput_setCurrent (PhidgetCurrentOutputHandle ch, double current);
__declspec (dllimport)
     void __stdcall PhidgetCurrentOutput_setCurrent_async (PhidgetCurrentOutputHandle ch, double current, Phidget_AsyncCallback fptr, void *ctx);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetCurrentOutput_getCurrent (PhidgetCurrentOutputHandle ch, double *current);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetCurrentOutput_getMinCurrent (PhidgetCurrentOutputHandle ch, double *minCurrent);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetCurrentOutput_getMaxCurrent (PhidgetCurrentOutputHandle ch, double *maxCurrent);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetCurrentOutput_setEnabled (PhidgetCurrentOutputHandle ch, int enabled);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetCurrentOutput_getEnabled (PhidgetCurrentOutputHandle ch, int *enabled);

/* Events */

     typedef struct _PhidgetDCMotor *PhidgetDCMotorHandle;

/* Methods */
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDCMotor_create (PhidgetDCMotorHandle * ch);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDCMotor_delete (PhidgetDCMotorHandle * ch);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDCMotor_enableFailsafe (PhidgetDCMotorHandle ch, uint32_t failsafeTime);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDCMotor_resetFailsafe (PhidgetDCMotorHandle ch);

/* Properties */
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDCMotor_setAcceleration (PhidgetDCMotorHandle ch, double acceleration);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDCMotor_getAcceleration (PhidgetDCMotorHandle ch, double *acceleration);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDCMotor_getMinAcceleration (PhidgetDCMotorHandle ch, double *minAcceleration);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDCMotor_getMaxAcceleration (PhidgetDCMotorHandle ch, double *maxAcceleration);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDCMotor_getActiveCurrentLimit (PhidgetDCMotorHandle ch, double *activeCurrentLimit);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDCMotor_getBackEMF (PhidgetDCMotorHandle ch, double *backEMF);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDCMotor_setBackEMFSensingState (PhidgetDCMotorHandle ch, int backEMFSensingState);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDCMotor_getBackEMFSensingState (PhidgetDCMotorHandle ch, int *backEMFSensingState);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDCMotor_setBrakingEnabled (PhidgetDCMotorHandle ch, int brakingEnabled);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDCMotor_getBrakingEnabled (PhidgetDCMotorHandle ch, int *brakingEnabled);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDCMotor_getBrakingStrength (PhidgetDCMotorHandle ch, double *brakingStrength);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDCMotor_getMinBrakingStrength (PhidgetDCMotorHandle ch, double *minBrakingStrength);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDCMotor_getMaxBrakingStrength (PhidgetDCMotorHandle ch, double *maxBrakingStrength);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDCMotor_setCurrentLimit (PhidgetDCMotorHandle ch, double currentLimit);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDCMotor_getCurrentLimit (PhidgetDCMotorHandle ch, double *currentLimit);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDCMotor_getMinCurrentLimit (PhidgetDCMotorHandle ch, double *minCurrentLimit);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDCMotor_getMaxCurrentLimit (PhidgetDCMotorHandle ch, double *maxCurrentLimit);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDCMotor_setCurrentRegulatorGain (PhidgetDCMotorHandle ch, double currentRegulatorGain);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDCMotor_getCurrentRegulatorGain (PhidgetDCMotorHandle ch, double *currentRegulatorGain);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDCMotor_getMinCurrentRegulatorGain (PhidgetDCMotorHandle ch, double *minCurrentRegulatorGain);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDCMotor_getMaxCurrentRegulatorGain (PhidgetDCMotorHandle ch, double *maxCurrentRegulatorGain);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDCMotor_setDataInterval (PhidgetDCMotorHandle ch, uint32_t dataInterval);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDCMotor_getDataInterval (PhidgetDCMotorHandle ch, uint32_t * dataInterval);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDCMotor_getMinDataInterval (PhidgetDCMotorHandle ch, uint32_t * minDataInterval);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDCMotor_getMaxDataInterval (PhidgetDCMotorHandle ch, uint32_t * maxDataInterval);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDCMotor_setDataRate (PhidgetDCMotorHandle ch, double dataRate);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDCMotor_getDataRate (PhidgetDCMotorHandle ch, double *dataRate);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDCMotor_getMinDataRate (PhidgetDCMotorHandle ch, double *minDataRate);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDCMotor_getMaxDataRate (PhidgetDCMotorHandle ch, double *maxDataRate);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDCMotor_setDriveMode (PhidgetDCMotorHandle ch, Phidget_DriveMode driveMode);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDCMotor_getDriveMode (PhidgetDCMotorHandle ch, Phidget_DriveMode * driveMode);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDCMotor_setFailsafeBrakingEnabled (PhidgetDCMotorHandle ch, int failsafeBrakingEnabled);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDCMotor_getFailsafeBrakingEnabled (PhidgetDCMotorHandle ch, int *failsafeBrakingEnabled);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDCMotor_setFailsafeCurrentLimit (PhidgetDCMotorHandle ch, double failsafeCurrentLimit);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDCMotor_getFailsafeCurrentLimit (PhidgetDCMotorHandle ch, double *failsafeCurrentLimit);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDCMotor_getMinFailsafeTime (PhidgetDCMotorHandle ch, uint32_t * minFailsafeTime);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDCMotor_getMaxFailsafeTime (PhidgetDCMotorHandle ch, uint32_t * maxFailsafeTime);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDCMotor_setFanMode (PhidgetDCMotorHandle ch, Phidget_FanMode fanMode);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDCMotor_getFanMode (PhidgetDCMotorHandle ch, Phidget_FanMode * fanMode);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDCMotor_setInductance (PhidgetDCMotorHandle ch, double inductance);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDCMotor_getInductance (PhidgetDCMotorHandle ch, double *inductance);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDCMotor_getMinInductance (PhidgetDCMotorHandle ch, double *minInductance);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDCMotor_getMaxInductance (PhidgetDCMotorHandle ch, double *maxInductance);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDCMotor_setSurgeCurrentLimit (PhidgetDCMotorHandle ch, double surgeCurrentLimit);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDCMotor_getSurgeCurrentLimit (PhidgetDCMotorHandle ch, double *surgeCurrentLimit);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDCMotor_getMinSurgeCurrentLimit (PhidgetDCMotorHandle ch, double *minSurgeCurrentLimit);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDCMotor_getMaxSurgeCurrentLimit (PhidgetDCMotorHandle ch, double *maxSurgeCurrentLimit);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDCMotor_setTargetBrakingStrength (PhidgetDCMotorHandle ch, double targetBrakingStrength);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDCMotor_getTargetBrakingStrength (PhidgetDCMotorHandle ch, double *targetBrakingStrength);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDCMotor_setTargetVelocity (PhidgetDCMotorHandle ch, double targetVelocity);
__declspec (dllimport)
     void __stdcall PhidgetDCMotor_setTargetVelocity_async (PhidgetDCMotorHandle ch, double targetVelocity, Phidget_AsyncCallback fptr, void *ctx);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDCMotor_getTargetVelocity (PhidgetDCMotorHandle ch, double *targetVelocity);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDCMotor_getVelocity (PhidgetDCMotorHandle ch, double *velocity);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDCMotor_getMinVelocity (PhidgetDCMotorHandle ch, double *minVelocity);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDCMotor_getMaxVelocity (PhidgetDCMotorHandle ch, double *maxVelocity);

/* Events */
     typedef void (__stdcall * PhidgetDCMotor_OnBackEMFChangeCallback) (PhidgetDCMotorHandle ch, void *ctx, double backEMF);

__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDCMotor_setOnBackEMFChangeHandler (PhidgetDCMotorHandle ch, PhidgetDCMotor_OnBackEMFChangeCallback fptr, void *ctx);
     typedef void (__stdcall * PhidgetDCMotor_OnBrakingStrengthChangeCallback) (PhidgetDCMotorHandle ch, void *ctx, double brakingStrength);

__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDCMotor_setOnBrakingStrengthChangeHandler (PhidgetDCMotorHandle ch, PhidgetDCMotor_OnBrakingStrengthChangeCallback fptr, void *ctx);
     typedef void (__stdcall * PhidgetDCMotor_OnVelocityUpdateCallback) (PhidgetDCMotorHandle ch, void *ctx, double velocity);

__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDCMotor_setOnVelocityUpdateHandler (PhidgetDCMotorHandle ch, PhidgetDCMotor_OnVelocityUpdateCallback fptr, void *ctx);

     typedef struct _PhidgetDataAdapter *PhidgetDataAdapterHandle;

/* Methods */
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDataAdapter_create (PhidgetDataAdapterHandle * ch);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDataAdapter_delete (PhidgetDataAdapterHandle * ch);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDataAdapter_i2cComplexTransaction (PhidgetDataAdapterHandle ch, int32_t address, char *I2CPacketString, const uint8_t * data, size_t sendDataLen, uint8_t * recvData, size_t * recvDataLen);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDataAdapter_i2cSendReceive (PhidgetDataAdapterHandle ch, int32_t address, const uint8_t * data, size_t sendDataLen, uint8_t * recvData, size_t recvDataLen);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDataAdapter_sendPacket (PhidgetDataAdapterHandle ch, const uint8_t * data, size_t dataLen);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDataAdapter_sendPacketWaitResponse (PhidgetDataAdapterHandle ch, const uint8_t * data, size_t sendDataLen, uint8_t * recvData, size_t * recvDataLen);

/* Properties */
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDataAdapter_setDataAdapterVoltage (PhidgetDataAdapterHandle ch, Phidget_DataAdapterVoltage dataAdapterVoltage);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDataAdapter_getDataAdapterVoltage (PhidgetDataAdapterHandle ch, Phidget_DataAdapterVoltage * dataAdapterVoltage);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDataAdapter_setDataBits (PhidgetDataAdapterHandle ch, uint32_t dataBits);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDataAdapter_getDataBits (PhidgetDataAdapterHandle ch, uint32_t * dataBits);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDataAdapter_getMinDataBits (PhidgetDataAdapterHandle ch, uint32_t * minDataBits);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDataAdapter_getMaxDataBits (PhidgetDataAdapterHandle ch, uint32_t * maxDataBits);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDataAdapter_setFrequency (PhidgetDataAdapterHandle ch, PhidgetDataAdapter_Frequency frequency);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDataAdapter_getFrequency (PhidgetDataAdapterHandle ch, PhidgetDataAdapter_Frequency * frequency);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDataAdapter_setEndianness (PhidgetDataAdapterHandle ch, PhidgetDataAdapter_Endianness endianness);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDataAdapter_getEndianness (PhidgetDataAdapterHandle ch, PhidgetDataAdapter_Endianness * endianness);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDataAdapter_getMaxReceivePacketLength (PhidgetDataAdapterHandle ch, uint32_t * maxReceivePacketLength);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDataAdapter_getMaxSendPacketLength (PhidgetDataAdapterHandle ch, uint32_t * maxSendPacketLength);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDataAdapter_setSPIChipSelect (PhidgetDataAdapterHandle ch, PhidgetDataAdapter_SPIChipSelect SPIChipSelect);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDataAdapter_getSPIChipSelect (PhidgetDataAdapterHandle ch, PhidgetDataAdapter_SPIChipSelect * SPIChipSelect);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDataAdapter_setSPIMode (PhidgetDataAdapterHandle ch, PhidgetDataAdapter_SPIMode SPIMode);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDataAdapter_getSPIMode (PhidgetDataAdapterHandle ch, PhidgetDataAdapter_SPIMode * SPIMode);

/* Events */

     typedef struct _PhidgetDictionary *PhidgetDictionaryHandle;

/* Methods */

__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDictionary_enableControlDictionary (void);

__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDictionary_addDictionary (int deviceSerialNumber, const char *label);

__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDictionary_removeDictionary (int deviceSerialNumber);

__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDictionary_loadDictionary (int dictionarySerialNumber, const char *file);

__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDictionary_enableStatsDictionary (void);

__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDictionary_create (PhidgetDictionaryHandle * ch);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDictionary_delete (PhidgetDictionaryHandle * ch);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDictionary_add (PhidgetDictionaryHandle ch, const char *key, const char *value);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDictionary_removeAll (PhidgetDictionaryHandle ch);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDictionary_get (PhidgetDictionaryHandle ch, const char *key, char *value, size_t valueLen);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDictionary_remove (PhidgetDictionaryHandle ch, const char *key);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDictionary_scan (PhidgetDictionaryHandle ch, const char *start, char *keyList, size_t keyListLen);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDictionary_set (PhidgetDictionaryHandle ch, const char *key, const char *value);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDictionary_update (PhidgetDictionaryHandle ch, const char *key, const char *value);

/* Properties */

/* Events */
     typedef void (__stdcall * PhidgetDictionary_OnAddCallback) (PhidgetDictionaryHandle ch, void *ctx, const char *key, const char *value);

__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDictionary_setOnAddHandler (PhidgetDictionaryHandle ch, PhidgetDictionary_OnAddCallback fptr, void *ctx);
     typedef void (__stdcall * PhidgetDictionary_OnRemoveCallback) (PhidgetDictionaryHandle ch, void *ctx, const char *key);

__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDictionary_setOnRemoveHandler (PhidgetDictionaryHandle ch, PhidgetDictionary_OnRemoveCallback fptr, void *ctx);
     typedef void (__stdcall * PhidgetDictionary_OnUpdateCallback) (PhidgetDictionaryHandle ch, void *ctx, const char *key, const char *value);

__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDictionary_setOnUpdateHandler (PhidgetDictionaryHandle ch, PhidgetDictionary_OnUpdateCallback fptr, void *ctx);

     typedef struct _PhidgetDigitalInput *PhidgetDigitalInputHandle;

/* Methods */
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDigitalInput_create (PhidgetDigitalInputHandle * ch);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDigitalInput_delete (PhidgetDigitalInputHandle * ch);

/* Properties */
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDigitalInput_setInputMode (PhidgetDigitalInputHandle ch, Phidget_InputMode inputMode);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDigitalInput_getInputMode (PhidgetDigitalInputHandle ch, Phidget_InputMode * inputMode);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDigitalInput_setPowerSupply (PhidgetDigitalInputHandle ch, Phidget_PowerSupply powerSupply);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDigitalInput_getPowerSupply (PhidgetDigitalInputHandle ch, Phidget_PowerSupply * powerSupply);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDigitalInput_getState (PhidgetDigitalInputHandle ch, int *state);

/* Events */
     typedef void (__stdcall * PhidgetDigitalInput_OnStateChangeCallback) (PhidgetDigitalInputHandle ch, void *ctx, int state);

__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDigitalInput_setOnStateChangeHandler (PhidgetDigitalInputHandle ch, PhidgetDigitalInput_OnStateChangeCallback fptr, void *ctx);

     typedef struct _PhidgetDigitalOutput *PhidgetDigitalOutputHandle;

/* Methods */
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDigitalOutput_create (PhidgetDigitalOutputHandle * ch);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDigitalOutput_delete (PhidgetDigitalOutputHandle * ch);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDigitalOutput_enableFailsafe (PhidgetDigitalOutputHandle ch, uint32_t failsafeTime);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDigitalOutput_resetFailsafe (PhidgetDigitalOutputHandle ch);

/* Properties */
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDigitalOutput_setDutyCycle (PhidgetDigitalOutputHandle ch, double dutyCycle);
__declspec (dllimport)
     void __stdcall PhidgetDigitalOutput_setDutyCycle_async (PhidgetDigitalOutputHandle ch, double dutyCycle, Phidget_AsyncCallback fptr, void *ctx);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDigitalOutput_getDutyCycle (PhidgetDigitalOutputHandle ch, double *dutyCycle);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDigitalOutput_getMinDutyCycle (PhidgetDigitalOutputHandle ch, double *minDutyCycle);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDigitalOutput_getMaxDutyCycle (PhidgetDigitalOutputHandle ch, double *maxDutyCycle);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDigitalOutput_getMinFailsafeTime (PhidgetDigitalOutputHandle ch, uint32_t * minFailsafeTime);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDigitalOutput_getMaxFailsafeTime (PhidgetDigitalOutputHandle ch, uint32_t * maxFailsafeTime);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDigitalOutput_setFrequency (PhidgetDigitalOutputHandle ch, double frequency);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDigitalOutput_getFrequency (PhidgetDigitalOutputHandle ch, double *frequency);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDigitalOutput_getMinFrequency (PhidgetDigitalOutputHandle ch, double *minFrequency);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDigitalOutput_getMaxFrequency (PhidgetDigitalOutputHandle ch, double *maxFrequency);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDigitalOutput_setLEDCurrentLimit (PhidgetDigitalOutputHandle ch, double LEDCurrentLimit);
__declspec (dllimport)
     void __stdcall PhidgetDigitalOutput_setLEDCurrentLimit_async (PhidgetDigitalOutputHandle ch, double LEDCurrentLimit, Phidget_AsyncCallback fptr, void *ctx);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDigitalOutput_getLEDCurrentLimit (PhidgetDigitalOutputHandle ch, double *LEDCurrentLimit);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDigitalOutput_getMinLEDCurrentLimit (PhidgetDigitalOutputHandle ch, double *minLEDCurrentLimit);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDigitalOutput_getMaxLEDCurrentLimit (PhidgetDigitalOutputHandle ch, double *maxLEDCurrentLimit);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDigitalOutput_setLEDForwardVoltage (PhidgetDigitalOutputHandle ch, PhidgetDigitalOutput_LEDForwardVoltage LEDForwardVoltage);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDigitalOutput_getLEDForwardVoltage (PhidgetDigitalOutputHandle ch, PhidgetDigitalOutput_LEDForwardVoltage * LEDForwardVoltage);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDigitalOutput_setState (PhidgetDigitalOutputHandle ch, int state);
__declspec (dllimport)
     void __stdcall PhidgetDigitalOutput_setState_async (PhidgetDigitalOutputHandle ch, int state, Phidget_AsyncCallback fptr, void *ctx);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDigitalOutput_getState (PhidgetDigitalOutputHandle ch, int *state);

/* Events */

     typedef struct _PhidgetDistanceSensor *PhidgetDistanceSensorHandle;

/* Methods */
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDistanceSensor_create (PhidgetDistanceSensorHandle * ch);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDistanceSensor_delete (PhidgetDistanceSensorHandle * ch);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDistanceSensor_getSonarReflections (PhidgetDistanceSensorHandle ch, uint32_t (*distances)[8], uint32_t (*amplitudes)[8], uint32_t * count);

/* Properties */
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDistanceSensor_setDataInterval (PhidgetDistanceSensorHandle ch, uint32_t dataInterval);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDistanceSensor_getDataInterval (PhidgetDistanceSensorHandle ch, uint32_t * dataInterval);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDistanceSensor_getMinDataInterval (PhidgetDistanceSensorHandle ch, uint32_t * minDataInterval);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDistanceSensor_getMaxDataInterval (PhidgetDistanceSensorHandle ch, uint32_t * maxDataInterval);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDistanceSensor_setDataRate (PhidgetDistanceSensorHandle ch, double dataRate);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDistanceSensor_getDataRate (PhidgetDistanceSensorHandle ch, double *dataRate);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDistanceSensor_getMinDataRate (PhidgetDistanceSensorHandle ch, double *minDataRate);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDistanceSensor_getMaxDataRate (PhidgetDistanceSensorHandle ch, double *maxDataRate);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDistanceSensor_getDistance (PhidgetDistanceSensorHandle ch, uint32_t * distance);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDistanceSensor_getMinDistance (PhidgetDistanceSensorHandle ch, uint32_t * minDistance);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDistanceSensor_getMaxDistance (PhidgetDistanceSensorHandle ch, uint32_t * maxDistance);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDistanceSensor_setDistanceChangeTrigger (PhidgetDistanceSensorHandle ch, uint32_t distanceChangeTrigger);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDistanceSensor_getDistanceChangeTrigger (PhidgetDistanceSensorHandle ch, uint32_t * distanceChangeTrigger);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDistanceSensor_getMinDistanceChangeTrigger (PhidgetDistanceSensorHandle ch, uint32_t * minDistanceChangeTrigger);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDistanceSensor_getMaxDistanceChangeTrigger (PhidgetDistanceSensorHandle ch, uint32_t * maxDistanceChangeTrigger);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDistanceSensor_setSonarQuietMode (PhidgetDistanceSensorHandle ch, int sonarQuietMode);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDistanceSensor_getSonarQuietMode (PhidgetDistanceSensorHandle ch, int *sonarQuietMode);

/* Events */
     typedef void (__stdcall * PhidgetDistanceSensor_OnDistanceChangeCallback) (PhidgetDistanceSensorHandle ch, void *ctx, uint32_t distance);

__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDistanceSensor_setOnDistanceChangeHandler (PhidgetDistanceSensorHandle ch, PhidgetDistanceSensor_OnDistanceChangeCallback fptr, void *ctx);
     typedef void (__stdcall * PhidgetDistanceSensor_OnSonarReflectionsUpdateCallback) (PhidgetDistanceSensorHandle ch, void *ctx, const uint32_t distances[8], const uint32_t amplitudes[8], uint32_t count);

__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetDistanceSensor_setOnSonarReflectionsUpdateHandler (PhidgetDistanceSensorHandle ch, PhidgetDistanceSensor_OnSonarReflectionsUpdateCallback fptr, void *ctx);

     typedef struct _PhidgetEncoder *PhidgetEncoderHandle;

/* Methods */
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetEncoder_create (PhidgetEncoderHandle * ch);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetEncoder_delete (PhidgetEncoderHandle * ch);

/* Properties */
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetEncoder_setEnabled (PhidgetEncoderHandle ch, int enabled);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetEncoder_getEnabled (PhidgetEncoderHandle ch, int *enabled);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetEncoder_setDataInterval (PhidgetEncoderHandle ch, uint32_t dataInterval);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetEncoder_getDataInterval (PhidgetEncoderHandle ch, uint32_t * dataInterval);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetEncoder_getMinDataInterval (PhidgetEncoderHandle ch, uint32_t * minDataInterval);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetEncoder_getMaxDataInterval (PhidgetEncoderHandle ch, uint32_t * maxDataInterval);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetEncoder_setDataRate (PhidgetEncoderHandle ch, double dataRate);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetEncoder_getDataRate (PhidgetEncoderHandle ch, double *dataRate);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetEncoder_getMinDataRate (PhidgetEncoderHandle ch, double *minDataRate);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetEncoder_getMaxDataRate (PhidgetEncoderHandle ch, double *maxDataRate);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetEncoder_getIndexPosition (PhidgetEncoderHandle ch, int64_t * indexPosition);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetEncoder_setIOMode (PhidgetEncoderHandle ch, Phidget_EncoderIOMode IOMode);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetEncoder_getIOMode (PhidgetEncoderHandle ch, Phidget_EncoderIOMode * IOMode);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetEncoder_setPosition (PhidgetEncoderHandle ch, int64_t position);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetEncoder_getPosition (PhidgetEncoderHandle ch, int64_t * position);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetEncoder_setPositionChangeTrigger (PhidgetEncoderHandle ch, uint32_t positionChangeTrigger);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetEncoder_getPositionChangeTrigger (PhidgetEncoderHandle ch, uint32_t * positionChangeTrigger);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetEncoder_getMinPositionChangeTrigger (PhidgetEncoderHandle ch, uint32_t * minPositionChangeTrigger);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetEncoder_getMaxPositionChangeTrigger (PhidgetEncoderHandle ch, uint32_t * maxPositionChangeTrigger);

/* Events */
     typedef void (__stdcall * PhidgetEncoder_OnPositionChangeCallback) (PhidgetEncoderHandle ch, void *ctx, int positionChange, double timeChange, int indexTriggered);

__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetEncoder_setOnPositionChangeHandler (PhidgetEncoderHandle ch, PhidgetEncoder_OnPositionChangeCallback fptr, void *ctx);

     typedef struct _PhidgetFirmwareUpgrade *PhidgetFirmwareUpgradeHandle;

/* Methods */
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetFirmwareUpgrade_create (PhidgetFirmwareUpgradeHandle * ch);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetFirmwareUpgrade_delete (PhidgetFirmwareUpgradeHandle * ch);

__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetFirmwareUpgrade_sendFirmware (PhidgetFirmwareUpgradeHandle ch, const uint8_t * data, size_t dataLen);

/* Properties */

__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetFirmwareUpgrade_getActualDeviceID (PhidgetFirmwareUpgradeHandle ch, Phidget_DeviceID * actualDeviceID);

__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetFirmwareUpgrade_getActualDeviceName (PhidgetFirmwareUpgradeHandle ch, const char **actualDeviceName);

__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetFirmwareUpgrade_getActualDeviceSKU (PhidgetFirmwareUpgradeHandle ch, const char **actualDeviceSKU);

__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetFirmwareUpgrade_getActualDeviceVersion (PhidgetFirmwareUpgradeHandle ch, int *actualDeviceVersion);

__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetFirmwareUpgrade_getActualDeviceVINTID (PhidgetFirmwareUpgradeHandle ch, uint32_t * actualDeviceVINTID);

__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetFirmwareUpgrade_getProgress (PhidgetFirmwareUpgradeHandle ch, double *progress);

/* Events */

     typedef void (__stdcall * PhidgetFirmwareUpgrade_OnProgressChangeCallback) (PhidgetFirmwareUpgradeHandle ch, void *ctx, double progress);

__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetFirmwareUpgrade_setOnProgressChangeHandler (PhidgetFirmwareUpgradeHandle ch, PhidgetFirmwareUpgrade_OnProgressChangeCallback fptr, void *ctx);

     typedef struct _PhidgetFrequencyCounter *PhidgetFrequencyCounterHandle;

/* Methods */
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetFrequencyCounter_create (PhidgetFrequencyCounterHandle * ch);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetFrequencyCounter_delete (PhidgetFrequencyCounterHandle * ch);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetFrequencyCounter_reset (PhidgetFrequencyCounterHandle ch);

/* Properties */
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetFrequencyCounter_getCount (PhidgetFrequencyCounterHandle ch, uint64_t * count);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetFrequencyCounter_setEnabled (PhidgetFrequencyCounterHandle ch, int enabled);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetFrequencyCounter_getEnabled (PhidgetFrequencyCounterHandle ch, int *enabled);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetFrequencyCounter_setDataInterval (PhidgetFrequencyCounterHandle ch, uint32_t dataInterval);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetFrequencyCounter_getDataInterval (PhidgetFrequencyCounterHandle ch, uint32_t * dataInterval);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetFrequencyCounter_getMinDataInterval (PhidgetFrequencyCounterHandle ch, uint32_t * minDataInterval);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetFrequencyCounter_getMaxDataInterval (PhidgetFrequencyCounterHandle ch, uint32_t * maxDataInterval);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetFrequencyCounter_setDataRate (PhidgetFrequencyCounterHandle ch, double dataRate);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetFrequencyCounter_getDataRate (PhidgetFrequencyCounterHandle ch, double *dataRate);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetFrequencyCounter_getMinDataRate (PhidgetFrequencyCounterHandle ch, double *minDataRate);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetFrequencyCounter_getMaxDataRate (PhidgetFrequencyCounterHandle ch, double *maxDataRate);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetFrequencyCounter_setFilterType (PhidgetFrequencyCounterHandle ch, PhidgetFrequencyCounter_FilterType filterType);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetFrequencyCounter_getFilterType (PhidgetFrequencyCounterHandle ch, PhidgetFrequencyCounter_FilterType * filterType);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetFrequencyCounter_getFrequency (PhidgetFrequencyCounterHandle ch, double *frequency);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetFrequencyCounter_getMaxFrequency (PhidgetFrequencyCounterHandle ch, double *maxFrequency);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetFrequencyCounter_setFrequencyCutoff (PhidgetFrequencyCounterHandle ch, double frequencyCutoff);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetFrequencyCounter_getFrequencyCutoff (PhidgetFrequencyCounterHandle ch, double *frequencyCutoff);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetFrequencyCounter_getMinFrequencyCutoff (PhidgetFrequencyCounterHandle ch, double *minFrequencyCutoff);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetFrequencyCounter_getMaxFrequencyCutoff (PhidgetFrequencyCounterHandle ch, double *maxFrequencyCutoff);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetFrequencyCounter_setInputMode (PhidgetFrequencyCounterHandle ch, Phidget_InputMode inputMode);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetFrequencyCounter_getInputMode (PhidgetFrequencyCounterHandle ch, Phidget_InputMode * inputMode);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetFrequencyCounter_setPowerSupply (PhidgetFrequencyCounterHandle ch, Phidget_PowerSupply powerSupply);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetFrequencyCounter_getPowerSupply (PhidgetFrequencyCounterHandle ch, Phidget_PowerSupply * powerSupply);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetFrequencyCounter_getTimeElapsed (PhidgetFrequencyCounterHandle ch, double *timeElapsed);

/* Events */
     typedef void (__stdcall * PhidgetFrequencyCounter_OnCountChangeCallback) (PhidgetFrequencyCounterHandle ch, void *ctx, uint64_t counts, double timeChange);

__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetFrequencyCounter_setOnCountChangeHandler (PhidgetFrequencyCounterHandle ch, PhidgetFrequencyCounter_OnCountChangeCallback fptr, void *ctx);
     typedef void (__stdcall * PhidgetFrequencyCounter_OnFrequencyChangeCallback) (PhidgetFrequencyCounterHandle ch, void *ctx, double frequency);

__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetFrequencyCounter_setOnFrequencyChangeHandler (PhidgetFrequencyCounterHandle ch, PhidgetFrequencyCounter_OnFrequencyChangeCallback fptr, void *ctx);

     typedef struct _PhidgetGPS *PhidgetGPSHandle;

/* Methods */
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetGPS_create (PhidgetGPSHandle * ch);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetGPS_delete (PhidgetGPSHandle * ch);

/* Properties */
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetGPS_getAltitude (PhidgetGPSHandle ch, double *altitude);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetGPS_getDate (PhidgetGPSHandle ch, PhidgetGPS_Date * date);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetGPS_getHeading (PhidgetGPSHandle ch, double *heading);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetGPS_getLatitude (PhidgetGPSHandle ch, double *latitude);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetGPS_getLongitude (PhidgetGPSHandle ch, double *longitude);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetGPS_getNMEAData (PhidgetGPSHandle ch, PhidgetGPS_NMEAData * NMEAData);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetGPS_getPositionFixState (PhidgetGPSHandle ch, int *positionFixState);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetGPS_getTime (PhidgetGPSHandle ch, PhidgetGPS_Time * time);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetGPS_getVelocity (PhidgetGPSHandle ch, double *velocity);

/* Events */
     typedef void (__stdcall * PhidgetGPS_OnHeadingChangeCallback) (PhidgetGPSHandle ch, void *ctx, double heading, double velocity);

__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetGPS_setOnHeadingChangeHandler (PhidgetGPSHandle ch, PhidgetGPS_OnHeadingChangeCallback fptr, void *ctx);
     typedef void (__stdcall * PhidgetGPS_OnPositionChangeCallback) (PhidgetGPSHandle ch, void *ctx, double latitude, double longitude, double altitude);

__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetGPS_setOnPositionChangeHandler (PhidgetGPSHandle ch, PhidgetGPS_OnPositionChangeCallback fptr, void *ctx);
     typedef void (__stdcall * PhidgetGPS_OnPositionFixStateChangeCallback) (PhidgetGPSHandle ch, void *ctx, int positionFixState);

__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetGPS_setOnPositionFixStateChangeHandler (PhidgetGPSHandle ch, PhidgetGPS_OnPositionFixStateChangeCallback fptr, void *ctx);

     typedef struct _PhidgetGeneric *PhidgetGenericHandle;

/* Methods */
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetGeneric_create (PhidgetGenericHandle * ch);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetGeneric_delete (PhidgetGenericHandle * ch);

/* Properties */

/* Events */

     typedef struct _PhidgetGyroscope *PhidgetGyroscopeHandle;

/* Methods */
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetGyroscope_create (PhidgetGyroscopeHandle * ch);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetGyroscope_delete (PhidgetGyroscopeHandle * ch);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetGyroscope_zero (PhidgetGyroscopeHandle ch);

/* Properties */
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetGyroscope_getAngularRate (PhidgetGyroscopeHandle ch, double (*angularRate)[3]);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetGyroscope_getMinAngularRate (PhidgetGyroscopeHandle ch, double (*minAngularRate)[3]);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetGyroscope_getMaxAngularRate (PhidgetGyroscopeHandle ch, double (*maxAngularRate)[3]);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetGyroscope_getAxisCount (PhidgetGyroscopeHandle ch, int *axisCount);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetGyroscope_setDataInterval (PhidgetGyroscopeHandle ch, uint32_t dataInterval);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetGyroscope_getDataInterval (PhidgetGyroscopeHandle ch, uint32_t * dataInterval);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetGyroscope_getMinDataInterval (PhidgetGyroscopeHandle ch, uint32_t * minDataInterval);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetGyroscope_getMaxDataInterval (PhidgetGyroscopeHandle ch, uint32_t * maxDataInterval);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetGyroscope_setDataRate (PhidgetGyroscopeHandle ch, double dataRate);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetGyroscope_getDataRate (PhidgetGyroscopeHandle ch, double *dataRate);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetGyroscope_getMinDataRate (PhidgetGyroscopeHandle ch, double *minDataRate);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetGyroscope_getMaxDataRate (PhidgetGyroscopeHandle ch, double *maxDataRate);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetGyroscope_setHeatingEnabled (PhidgetGyroscopeHandle ch, int heatingEnabled);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetGyroscope_getHeatingEnabled (PhidgetGyroscopeHandle ch, int *heatingEnabled);

__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetGyroscope_setPrecision (PhidgetGyroscopeHandle ch, Phidget_SpatialPrecision precision);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetGyroscope_getPrecision (PhidgetGyroscopeHandle ch, Phidget_SpatialPrecision * precision);

__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetGyroscope_getTimestamp (PhidgetGyroscopeHandle ch, double *timestamp);

/* Events */
     typedef void (__stdcall * PhidgetGyroscope_OnAngularRateUpdateCallback) (PhidgetGyroscopeHandle ch, void *ctx, const double angularRate[3], double timestamp);

__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetGyroscope_setOnAngularRateUpdateHandler (PhidgetGyroscopeHandle ch, PhidgetGyroscope_OnAngularRateUpdateCallback fptr, void *ctx);

     typedef struct _PhidgetHub *PhidgetHubHandle;

/* Methods */
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetHub_create (PhidgetHubHandle * ch);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetHub_delete (PhidgetHubHandle * ch);

__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetHub_setADCCalibrationValues (PhidgetHubHandle ch, double voltageInputGain[6], double voltageRatioGain[6]);

__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetHub_setADCCalibrationValues2 (PhidgetHubHandle ch, const double *voltageInputOffset, size_t voltageInputOffsetLen, const double *voltageInputGain, size_t voltageInputGainLen, const double *voltageRatioOffset, size_t voltageRatioOffsetLen, const double *voltageRatioGain, size_t voltageRatioGainLen);

__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetHub_setFirmwareUpgradeFlag (PhidgetHubHandle ch, int port, uint32_t timeout);

__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetHub_setPortAutoSetSpeed (PhidgetHubHandle ch, int port, int state);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetHub_getPortMaxSpeed (PhidgetHubHandle ch, int port, uint32_t * state);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetHub_getPortMode (PhidgetHubHandle ch, int port, PhidgetHub_PortMode * mode);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetHub_setPortMode (PhidgetHubHandle ch, int port, PhidgetHub_PortMode mode);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetHub_getPortPower (PhidgetHubHandle ch, int port, int *state);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetHub_setPortPower (PhidgetHubHandle ch, int port, int state);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetHub_getPortSupportsAutoSetSpeed (PhidgetHubHandle ch, int port, int *state);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetHub_getPortSupportsSetSpeed (PhidgetHubHandle ch, int port, int *state);

/* Properties */

/* Events */

     typedef struct _PhidgetHumiditySensor *PhidgetHumiditySensorHandle;

/* Methods */
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetHumiditySensor_create (PhidgetHumiditySensorHandle * ch);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetHumiditySensor_delete (PhidgetHumiditySensorHandle * ch);

/* Properties */
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetHumiditySensor_setDataInterval (PhidgetHumiditySensorHandle ch, uint32_t dataInterval);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetHumiditySensor_getDataInterval (PhidgetHumiditySensorHandle ch, uint32_t * dataInterval);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetHumiditySensor_getMinDataInterval (PhidgetHumiditySensorHandle ch, uint32_t * minDataInterval);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetHumiditySensor_getMaxDataInterval (PhidgetHumiditySensorHandle ch, uint32_t * maxDataInterval);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetHumiditySensor_setDataRate (PhidgetHumiditySensorHandle ch, double dataRate);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetHumiditySensor_getDataRate (PhidgetHumiditySensorHandle ch, double *dataRate);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetHumiditySensor_getMinDataRate (PhidgetHumiditySensorHandle ch, double *minDataRate);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetHumiditySensor_getMaxDataRate (PhidgetHumiditySensorHandle ch, double *maxDataRate);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetHumiditySensor_getHumidity (PhidgetHumiditySensorHandle ch, double *humidity);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetHumiditySensor_getMinHumidity (PhidgetHumiditySensorHandle ch, double *minHumidity);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetHumiditySensor_getMaxHumidity (PhidgetHumiditySensorHandle ch, double *maxHumidity);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetHumiditySensor_setHumidityChangeTrigger (PhidgetHumiditySensorHandle ch, double humidityChangeTrigger);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetHumiditySensor_getHumidityChangeTrigger (PhidgetHumiditySensorHandle ch, double *humidityChangeTrigger);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetHumiditySensor_getMinHumidityChangeTrigger (PhidgetHumiditySensorHandle ch, double *minHumidityChangeTrigger);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetHumiditySensor_getMaxHumidityChangeTrigger (PhidgetHumiditySensorHandle ch, double *maxHumidityChangeTrigger);

/* Events */
     typedef void (__stdcall * PhidgetHumiditySensor_OnHumidityChangeCallback) (PhidgetHumiditySensorHandle ch, void *ctx, double humidity);

__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetHumiditySensor_setOnHumidityChangeHandler (PhidgetHumiditySensorHandle ch, PhidgetHumiditySensor_OnHumidityChangeCallback fptr, void *ctx);

     typedef struct _PhidgetIR *PhidgetIRHandle;

/* Methods */
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetIR_create (PhidgetIRHandle * ch);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetIR_delete (PhidgetIRHandle * ch);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetIR_getLastCode (PhidgetIRHandle ch, char *code, size_t codeLen, uint32_t * bitCount);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetIR_getLastLearnedCode (PhidgetIRHandle ch, char *code, size_t codeLen, PhidgetIR_CodeInfo * codeInfo);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetIR_transmit (PhidgetIRHandle ch, const char *code, PhidgetIR_CodeInfo * codeInfo);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetIR_transmitRaw (PhidgetIRHandle ch, const uint32_t * data, size_t dataLen, uint32_t carrierFrequency, double dutyCycle, uint32_t gap);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetIR_transmitRepeat (PhidgetIRHandle ch);

/* Properties */

/* Events */
     typedef void (__stdcall * PhidgetIR_OnCodeCallback) (PhidgetIRHandle ch, void *ctx, const char *code, uint32_t bitCount, int isRepeat);

__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetIR_setOnCodeHandler (PhidgetIRHandle ch, PhidgetIR_OnCodeCallback fptr, void *ctx);
     typedef void (__stdcall * PhidgetIR_OnLearnCallback) (PhidgetIRHandle ch, void *ctx, const char *code, PhidgetIR_CodeInfo * codeInfo);

__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetIR_setOnLearnHandler (PhidgetIRHandle ch, PhidgetIR_OnLearnCallback fptr, void *ctx);
     typedef void (__stdcall * PhidgetIR_OnRawDataCallback) (PhidgetIRHandle ch, void *ctx, const uint32_t * data, size_t dataLen);

__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetIR_setOnRawDataHandler (PhidgetIRHandle ch, PhidgetIR_OnRawDataCallback fptr, void *ctx);

     typedef struct _PhidgetLCD *PhidgetLCDHandle;

/* Methods */
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetLCD_create (PhidgetLCDHandle * ch);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetLCD_delete (PhidgetLCDHandle * ch);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetLCD_setCharacterBitmap (PhidgetLCDHandle ch, PhidgetLCD_Font font, const char *character, const uint8_t * bitmap);
__declspec (dllimport)
     void __stdcall PhidgetLCD_setCharacterBitmap_async (PhidgetLCDHandle ch, PhidgetLCD_Font font, const char *character, const uint8_t * bitmap, Phidget_AsyncCallback fptr, void *ctx);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetLCD_getMaxCharacters (PhidgetLCDHandle ch, PhidgetLCD_Font font, int *maxCharacters);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetLCD_clear (PhidgetLCDHandle ch);
__declspec (dllimport)
     void __stdcall PhidgetLCD_clear_async (PhidgetLCDHandle ch, Phidget_AsyncCallback fptr, void *ctx);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetLCD_copy (PhidgetLCDHandle ch, int sourceFramebuffer, int destFramebuffer, int sourceX1, int sourceY1, int sourceX2, int sourceY2, int destX, int destY, int inverted);
__declspec (dllimport)
     void __stdcall PhidgetLCD_copy_async (PhidgetLCDHandle ch, int sourceFramebuffer, int destFramebuffer, int sourceX1, int sourceY1, int sourceX2, int sourceY2, int destX, int destY, int inverted, Phidget_AsyncCallback fptr, void *ctx);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetLCD_drawLine (PhidgetLCDHandle ch, int x1, int y1, int x2, int y2);
__declspec (dllimport)
     void __stdcall PhidgetLCD_drawLine_async (PhidgetLCDHandle ch, int x1, int y1, int x2, int y2, Phidget_AsyncCallback fptr, void *ctx);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetLCD_drawPixel (PhidgetLCDHandle ch, int x, int y, PhidgetLCD_PixelState pixelState);
__declspec (dllimport)
     void __stdcall PhidgetLCD_drawPixel_async (PhidgetLCDHandle ch, int x, int y, PhidgetLCD_PixelState pixelState, Phidget_AsyncCallback fptr, void *ctx);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetLCD_drawRect (PhidgetLCDHandle ch, int x1, int y1, int x2, int y2, int filled, int inverted);
__declspec (dllimport)
     void __stdcall PhidgetLCD_drawRect_async (PhidgetLCDHandle ch, int x1, int y1, int x2, int y2, int filled, int inverted, Phidget_AsyncCallback fptr, void *ctx);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetLCD_flush (PhidgetLCDHandle ch);
__declspec (dllimport)
     void __stdcall PhidgetLCD_flush_async (PhidgetLCDHandle ch, Phidget_AsyncCallback fptr, void *ctx);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetLCD_getFontSize (PhidgetLCDHandle ch, PhidgetLCD_Font font, int *width, int *height);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetLCD_setFontSize (PhidgetLCDHandle ch, PhidgetLCD_Font font, int width, int height);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetLCD_initialize (PhidgetLCDHandle ch);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetLCD_saveFrameBuffer (PhidgetLCDHandle ch, int frameBuffer);
__declspec (dllimport)
     void __stdcall PhidgetLCD_saveFrameBuffer_async (PhidgetLCDHandle ch, int frameBuffer, Phidget_AsyncCallback fptr, void *ctx);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetLCD_writeBitmap (PhidgetLCDHandle ch, int xPosition, int yPosition, int xSize, int ySize, const uint8_t * bitmap);
__declspec (dllimport)
     void __stdcall PhidgetLCD_writeBitmap_async (PhidgetLCDHandle ch, int xPosition, int yPosition, int xSize, int ySize, const uint8_t * bitmap, Phidget_AsyncCallback fptr, void *ctx);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetLCD_writeText (PhidgetLCDHandle ch, PhidgetLCD_Font font, int xPosition, int yPosition, const char *text);
__declspec (dllimport)
     void __stdcall PhidgetLCD_writeText_async (PhidgetLCDHandle ch, PhidgetLCD_Font font, int xPosition, int yPosition, const char *text, Phidget_AsyncCallback fptr, void *ctx);

/* Properties */
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetLCD_setAutoFlush (PhidgetLCDHandle ch, int autoFlush);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetLCD_getAutoFlush (PhidgetLCDHandle ch, int *autoFlush);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetLCD_setBacklight (PhidgetLCDHandle ch, double backlight);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetLCD_getBacklight (PhidgetLCDHandle ch, double *backlight);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetLCD_getMinBacklight (PhidgetLCDHandle ch, double *minBacklight);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetLCD_getMaxBacklight (PhidgetLCDHandle ch, double *maxBacklight);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetLCD_setContrast (PhidgetLCDHandle ch, double contrast);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetLCD_getContrast (PhidgetLCDHandle ch, double *contrast);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetLCD_getMinContrast (PhidgetLCDHandle ch, double *minContrast);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetLCD_getMaxContrast (PhidgetLCDHandle ch, double *maxContrast);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetLCD_setCursorBlink (PhidgetLCDHandle ch, int cursorBlink);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetLCD_getCursorBlink (PhidgetLCDHandle ch, int *cursorBlink);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetLCD_setCursorOn (PhidgetLCDHandle ch, int cursorOn);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetLCD_getCursorOn (PhidgetLCDHandle ch, int *cursorOn);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetLCD_setFrameBuffer (PhidgetLCDHandle ch, int frameBuffer);
__declspec (dllimport)
     void __stdcall PhidgetLCD_setFrameBuffer_async (PhidgetLCDHandle ch, int frameBuffer, Phidget_AsyncCallback fptr, void *ctx);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetLCD_getFrameBuffer (PhidgetLCDHandle ch, int *frameBuffer);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetLCD_getHeight (PhidgetLCDHandle ch, int *height);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetLCD_setScreenSize (PhidgetLCDHandle ch, PhidgetLCD_ScreenSize screenSize);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetLCD_getScreenSize (PhidgetLCDHandle ch, PhidgetLCD_ScreenSize * screenSize);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetLCD_setSleeping (PhidgetLCDHandle ch, int sleeping);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetLCD_getSleeping (PhidgetLCDHandle ch, int *sleeping);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetLCD_getWidth (PhidgetLCDHandle ch, int *width);

/* Events */

     typedef struct _PhidgetLEDArray *PhidgetLEDArrayHandle;

/* Methods */
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetLEDArray_create (PhidgetLEDArrayHandle * ch);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetLEDArray_delete (PhidgetLEDArrayHandle * ch);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetLEDArray_setAnimation (PhidgetLEDArrayHandle ch, int32_t animationID, const PhidgetLEDArray_RGBW * pattern, size_t patternCount, PhidgetLEDArray_AnimationDescription * animationDescription);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetLEDArray_clearLEDs (PhidgetLEDArrayHandle ch);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetLEDArray_setLEDs (PhidgetLEDArrayHandle ch, uint32_t offset, const PhidgetLEDArray_RGBW * leds, size_t ledCount, uint32_t fadeTime);
__declspec (dllimport)
     void __stdcall PhidgetLEDArray_setLEDs_async (PhidgetLEDArrayHandle ch, uint32_t offset, const PhidgetLEDArray_RGBW * leds, size_t ledCount, uint32_t fadeTime, Phidget_AsyncCallback fptr, void *ctx);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetLEDArray_stopAnimation (PhidgetLEDArrayHandle ch, int32_t animationID);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetLEDArray_synchronizeAnimations (PhidgetLEDArrayHandle ch);

/* Properties */
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetLEDArray_getMinAnimationID (PhidgetLEDArrayHandle ch, int32_t * minAnimationID);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetLEDArray_getMaxAnimationID (PhidgetLEDArrayHandle ch, int32_t * maxAnimationID);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetLEDArray_getMinAnimationPatternCount (PhidgetLEDArrayHandle ch, uint32_t * minAnimationPatternCount);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetLEDArray_getMaxAnimationPatternCount (PhidgetLEDArrayHandle ch, uint32_t * maxAnimationPatternCount);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetLEDArray_setBrightness (PhidgetLEDArrayHandle ch, double brightness);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetLEDArray_getBrightness (PhidgetLEDArrayHandle ch, double *brightness);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetLEDArray_getMinBrightness (PhidgetLEDArrayHandle ch, double *minBrightness);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetLEDArray_getMaxBrightness (PhidgetLEDArrayHandle ch, double *maxBrightness);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetLEDArray_getMinFadeTime (PhidgetLEDArrayHandle ch, uint32_t * minFadeTime);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetLEDArray_getMaxFadeTime (PhidgetLEDArrayHandle ch, uint32_t * maxFadeTime);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetLEDArray_setGamma (PhidgetLEDArrayHandle ch, double gamma);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetLEDArray_getGamma (PhidgetLEDArrayHandle ch, double *gamma);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetLEDArray_getMinLEDCount (PhidgetLEDArrayHandle ch, uint32_t * minLEDCount);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetLEDArray_getMaxLEDCount (PhidgetLEDArrayHandle ch, uint32_t * maxLEDCount);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetLEDArray_setPowerEnabled (PhidgetLEDArrayHandle ch, int powerEnabled);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetLEDArray_getPowerEnabled (PhidgetLEDArrayHandle ch, int *powerEnabled);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetLEDArray_setProtocol (PhidgetLEDArrayHandle ch, PhidgetLEDArray_Protocol protocol);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetLEDArray_getProtocol (PhidgetLEDArrayHandle ch, PhidgetLEDArray_Protocol * protocol);

/* Events */

     typedef struct _PhidgetLightSensor *PhidgetLightSensorHandle;

/* Methods */
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetLightSensor_create (PhidgetLightSensorHandle * ch);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetLightSensor_delete (PhidgetLightSensorHandle * ch);

/* Properties */
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetLightSensor_setDataInterval (PhidgetLightSensorHandle ch, uint32_t dataInterval);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetLightSensor_getDataInterval (PhidgetLightSensorHandle ch, uint32_t * dataInterval);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetLightSensor_getMinDataInterval (PhidgetLightSensorHandle ch, uint32_t * minDataInterval);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetLightSensor_getMaxDataInterval (PhidgetLightSensorHandle ch, uint32_t * maxDataInterval);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetLightSensor_setDataRate (PhidgetLightSensorHandle ch, double dataRate);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetLightSensor_getDataRate (PhidgetLightSensorHandle ch, double *dataRate);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetLightSensor_getMinDataRate (PhidgetLightSensorHandle ch, double *minDataRate);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetLightSensor_getMaxDataRate (PhidgetLightSensorHandle ch, double *maxDataRate);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetLightSensor_getIlluminance (PhidgetLightSensorHandle ch, double *illuminance);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetLightSensor_getMinIlluminance (PhidgetLightSensorHandle ch, double *minIlluminance);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetLightSensor_getMaxIlluminance (PhidgetLightSensorHandle ch, double *maxIlluminance);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetLightSensor_setIlluminanceChangeTrigger (PhidgetLightSensorHandle ch, double illuminanceChangeTrigger);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetLightSensor_getIlluminanceChangeTrigger (PhidgetLightSensorHandle ch, double *illuminanceChangeTrigger);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetLightSensor_getMinIlluminanceChangeTrigger (PhidgetLightSensorHandle ch, double *minIlluminanceChangeTrigger);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetLightSensor_getMaxIlluminanceChangeTrigger (PhidgetLightSensorHandle ch, double *maxIlluminanceChangeTrigger);

/* Events */
     typedef void (__stdcall * PhidgetLightSensor_OnIlluminanceChangeCallback) (PhidgetLightSensorHandle ch, void *ctx, double illuminance);

__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetLightSensor_setOnIlluminanceChangeHandler (PhidgetLightSensorHandle ch, PhidgetLightSensor_OnIlluminanceChangeCallback fptr, void *ctx);

     typedef struct _PhidgetMagnetometer *PhidgetMagnetometerHandle;

/* Methods */
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMagnetometer_create (PhidgetMagnetometerHandle * ch);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMagnetometer_delete (PhidgetMagnetometerHandle * ch);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMagnetometer_setCorrectionParameters (PhidgetMagnetometerHandle ch, double magneticField, double offset0, double offset1, double offset2, double gain0, double gain1, double gain2, double T0, double T1, double T2, double T3, double T4, double T5);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMagnetometer_resetCorrectionParameters (PhidgetMagnetometerHandle ch);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMagnetometer_saveCorrectionParameters (PhidgetMagnetometerHandle ch);

/* Properties */
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMagnetometer_getAxisCount (PhidgetMagnetometerHandle ch, int *axisCount);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMagnetometer_setDataInterval (PhidgetMagnetometerHandle ch, uint32_t dataInterval);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMagnetometer_getDataInterval (PhidgetMagnetometerHandle ch, uint32_t * dataInterval);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMagnetometer_getMinDataInterval (PhidgetMagnetometerHandle ch, uint32_t * minDataInterval);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMagnetometer_getMaxDataInterval (PhidgetMagnetometerHandle ch, uint32_t * maxDataInterval);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMagnetometer_setDataRate (PhidgetMagnetometerHandle ch, double dataRate);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMagnetometer_getDataRate (PhidgetMagnetometerHandle ch, double *dataRate);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMagnetometer_getMinDataRate (PhidgetMagnetometerHandle ch, double *minDataRate);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMagnetometer_getMaxDataRate (PhidgetMagnetometerHandle ch, double *maxDataRate);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMagnetometer_setHeatingEnabled (PhidgetMagnetometerHandle ch, int heatingEnabled);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMagnetometer_getHeatingEnabled (PhidgetMagnetometerHandle ch, int *heatingEnabled);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMagnetometer_getMagneticField (PhidgetMagnetometerHandle ch, double (*magneticField)[3]);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMagnetometer_getMinMagneticField (PhidgetMagnetometerHandle ch, double (*minMagneticField)[3]);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMagnetometer_getMaxMagneticField (PhidgetMagnetometerHandle ch, double (*maxMagneticField)[3]);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMagnetometer_setMagneticFieldChangeTrigger (PhidgetMagnetometerHandle ch, double magneticFieldChangeTrigger);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMagnetometer_getMagneticFieldChangeTrigger (PhidgetMagnetometerHandle ch, double *magneticFieldChangeTrigger);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMagnetometer_getMinMagneticFieldChangeTrigger (PhidgetMagnetometerHandle ch, double *minMagneticFieldChangeTrigger);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMagnetometer_getMaxMagneticFieldChangeTrigger (PhidgetMagnetometerHandle ch, double *maxMagneticFieldChangeTrigger);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMagnetometer_getTimestamp (PhidgetMagnetometerHandle ch, double *timestamp);

/* Events */
     typedef void (__stdcall * PhidgetMagnetometer_OnMagneticFieldChangeCallback) (PhidgetMagnetometerHandle ch, void *ctx, const double magneticField[3], double timestamp);

__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMagnetometer_setOnMagneticFieldChangeHandler (PhidgetMagnetometerHandle ch, PhidgetMagnetometer_OnMagneticFieldChangeCallback fptr, void *ctx);

     typedef struct _PhidgetMeshDongle *PhidgetMeshDongleHandle;

/* Methods */
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMeshDongle_create (PhidgetMeshDongleHandle * ch);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMeshDongle_delete (PhidgetMeshDongleHandle * ch);

/* Properties */

/* Events */

     typedef struct _PhidgetMotorPositionController *PhidgetMotorPositionControllerHandle;

/* Methods */
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorPositionController_create (PhidgetMotorPositionControllerHandle * ch);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorPositionController_delete (PhidgetMotorPositionControllerHandle * ch);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorPositionController_enableFailsafe (PhidgetMotorPositionControllerHandle ch, uint32_t failsafeTime);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorPositionController_addPositionOffset (PhidgetMotorPositionControllerHandle ch, double positionOffset);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorPositionController_resetFailsafe (PhidgetMotorPositionControllerHandle ch);

/* Properties */
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorPositionController_setAcceleration (PhidgetMotorPositionControllerHandle ch, double acceleration);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorPositionController_getAcceleration (PhidgetMotorPositionControllerHandle ch, double *acceleration);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorPositionController_getMinAcceleration (PhidgetMotorPositionControllerHandle ch, double *minAcceleration);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorPositionController_getMaxAcceleration (PhidgetMotorPositionControllerHandle ch, double *maxAcceleration);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorPositionController_getActiveCurrentLimit (PhidgetMotorPositionControllerHandle ch, double *activeCurrentLimit);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorPositionController_setCurrentLimit (PhidgetMotorPositionControllerHandle ch, double currentLimit);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorPositionController_getCurrentLimit (PhidgetMotorPositionControllerHandle ch, double *currentLimit);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorPositionController_getMinCurrentLimit (PhidgetMotorPositionControllerHandle ch, double *minCurrentLimit);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorPositionController_getMaxCurrentLimit (PhidgetMotorPositionControllerHandle ch, double *maxCurrentLimit);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorPositionController_setCurrentRegulatorGain (PhidgetMotorPositionControllerHandle ch, double currentRegulatorGain);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorPositionController_getCurrentRegulatorGain (PhidgetMotorPositionControllerHandle ch, double *currentRegulatorGain);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorPositionController_getMinCurrentRegulatorGain (PhidgetMotorPositionControllerHandle ch, double *minCurrentRegulatorGain);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorPositionController_getMaxCurrentRegulatorGain (PhidgetMotorPositionControllerHandle ch, double *maxCurrentRegulatorGain);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorPositionController_setDataInterval (PhidgetMotorPositionControllerHandle ch, uint32_t dataInterval);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorPositionController_getDataInterval (PhidgetMotorPositionControllerHandle ch, uint32_t * dataInterval);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorPositionController_getMinDataInterval (PhidgetMotorPositionControllerHandle ch, uint32_t * minDataInterval);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorPositionController_getMaxDataInterval (PhidgetMotorPositionControllerHandle ch, uint32_t * maxDataInterval);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorPositionController_setDataRate (PhidgetMotorPositionControllerHandle ch, double dataRate);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorPositionController_getDataRate (PhidgetMotorPositionControllerHandle ch, double *dataRate);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorPositionController_getMinDataRate (PhidgetMotorPositionControllerHandle ch, double *minDataRate);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorPositionController_getMaxDataRate (PhidgetMotorPositionControllerHandle ch, double *maxDataRate);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorPositionController_setDeadBand (PhidgetMotorPositionControllerHandle ch, double deadBand);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorPositionController_getDeadBand (PhidgetMotorPositionControllerHandle ch, double *deadBand);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorPositionController_getDutyCycle (PhidgetMotorPositionControllerHandle ch, double *dutyCycle);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorPositionController_setEngaged (PhidgetMotorPositionControllerHandle ch, int engaged);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorPositionController_getEngaged (PhidgetMotorPositionControllerHandle ch, int *engaged);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorPositionController_getExpectedPosition (PhidgetMotorPositionControllerHandle ch, double *expectedPosition);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorPositionController_setEnableExpectedPosition (PhidgetMotorPositionControllerHandle ch, int enableExpectedPosition);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorPositionController_getEnableExpectedPosition (PhidgetMotorPositionControllerHandle ch, int *enableExpectedPosition);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorPositionController_setFailsafeBrakingEnabled (PhidgetMotorPositionControllerHandle ch, int failsafeBrakingEnabled);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorPositionController_getFailsafeBrakingEnabled (PhidgetMotorPositionControllerHandle ch, int *failsafeBrakingEnabled);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorPositionController_setFailsafeCurrentLimit (PhidgetMotorPositionControllerHandle ch, double failsafeCurrentLimit);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorPositionController_getFailsafeCurrentLimit (PhidgetMotorPositionControllerHandle ch, double *failsafeCurrentLimit);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorPositionController_getMinFailsafeTime (PhidgetMotorPositionControllerHandle ch, uint32_t * minFailsafeTime);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorPositionController_getMaxFailsafeTime (PhidgetMotorPositionControllerHandle ch, uint32_t * maxFailsafeTime);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorPositionController_setFanMode (PhidgetMotorPositionControllerHandle ch, Phidget_FanMode fanMode);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorPositionController_getFanMode (PhidgetMotorPositionControllerHandle ch, Phidget_FanMode * fanMode);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorPositionController_setInductance (PhidgetMotorPositionControllerHandle ch, double inductance);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorPositionController_getInductance (PhidgetMotorPositionControllerHandle ch, double *inductance);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorPositionController_getMinInductance (PhidgetMotorPositionControllerHandle ch, double *minInductance);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorPositionController_getMaxInductance (PhidgetMotorPositionControllerHandle ch, double *maxInductance);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorPositionController_setIOMode (PhidgetMotorPositionControllerHandle ch, Phidget_EncoderIOMode IOMode);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorPositionController_getIOMode (PhidgetMotorPositionControllerHandle ch, Phidget_EncoderIOMode * IOMode);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorPositionController_setKd (PhidgetMotorPositionControllerHandle ch, double kd);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorPositionController_getKd (PhidgetMotorPositionControllerHandle ch, double *kd);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorPositionController_setKi (PhidgetMotorPositionControllerHandle ch, double ki);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorPositionController_getKi (PhidgetMotorPositionControllerHandle ch, double *ki);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorPositionController_setKp (PhidgetMotorPositionControllerHandle ch, double kp);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorPositionController_getKp (PhidgetMotorPositionControllerHandle ch, double *kp);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorPositionController_setNormalizePID (PhidgetMotorPositionControllerHandle ch, int normalizePID);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorPositionController_getNormalizePID (PhidgetMotorPositionControllerHandle ch, int *normalizePID);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorPositionController_getPosition (PhidgetMotorPositionControllerHandle ch, double *position);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorPositionController_getMinPosition (PhidgetMotorPositionControllerHandle ch, double *minPosition);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorPositionController_getMaxPosition (PhidgetMotorPositionControllerHandle ch, double *maxPosition);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorPositionController_setPositionType (PhidgetMotorPositionControllerHandle ch, Phidget_PositionType positionType);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorPositionController_getPositionType (PhidgetMotorPositionControllerHandle ch, Phidget_PositionType * positionType);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorPositionController_setRescaleFactor (PhidgetMotorPositionControllerHandle ch, double rescaleFactor);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorPositionController_getRescaleFactor (PhidgetMotorPositionControllerHandle ch, double *rescaleFactor);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorPositionController_setStallVelocity (PhidgetMotorPositionControllerHandle ch, double stallVelocity);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorPositionController_getStallVelocity (PhidgetMotorPositionControllerHandle ch, double *stallVelocity);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorPositionController_getMinStallVelocity (PhidgetMotorPositionControllerHandle ch, double *minStallVelocity);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorPositionController_getMaxStallVelocity (PhidgetMotorPositionControllerHandle ch, double *maxStallVelocity);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorPositionController_setSurgeCurrentLimit (PhidgetMotorPositionControllerHandle ch, double surgeCurrentLimit);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorPositionController_getSurgeCurrentLimit (PhidgetMotorPositionControllerHandle ch, double *surgeCurrentLimit);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorPositionController_getMinSurgeCurrentLimit (PhidgetMotorPositionControllerHandle ch, double *minSurgeCurrentLimit);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorPositionController_getMaxSurgeCurrentLimit (PhidgetMotorPositionControllerHandle ch, double *maxSurgeCurrentLimit);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorPositionController_setTargetPosition (PhidgetMotorPositionControllerHandle ch, double targetPosition);
__declspec (dllimport)
     void __stdcall PhidgetMotorPositionController_setTargetPosition_async (PhidgetMotorPositionControllerHandle ch, double targetPosition, Phidget_AsyncCallback fptr, void *ctx);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorPositionController_getTargetPosition (PhidgetMotorPositionControllerHandle ch, double *targetPosition);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorPositionController_setVelocityLimit (PhidgetMotorPositionControllerHandle ch, double velocityLimit);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorPositionController_getVelocityLimit (PhidgetMotorPositionControllerHandle ch, double *velocityLimit);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorPositionController_getMinVelocityLimit (PhidgetMotorPositionControllerHandle ch, double *minVelocityLimit);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorPositionController_getMaxVelocityLimit (PhidgetMotorPositionControllerHandle ch, double *maxVelocityLimit);

/* Events */
     typedef void (__stdcall * PhidgetMotorPositionController_OnDutyCycleUpdateCallback) (PhidgetMotorPositionControllerHandle ch, void *ctx, double dutyCycle);

__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorPositionController_setOnDutyCycleUpdateHandler (PhidgetMotorPositionControllerHandle ch, PhidgetMotorPositionController_OnDutyCycleUpdateCallback fptr, void *ctx);
     typedef void (__stdcall * PhidgetMotorPositionController_OnExpectedPositionChangeCallback) (PhidgetMotorPositionControllerHandle ch, void *ctx, double expectedPosition);

__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorPositionController_setOnExpectedPositionChangeHandler (PhidgetMotorPositionControllerHandle ch, PhidgetMotorPositionController_OnExpectedPositionChangeCallback fptr, void *ctx);
     typedef void (__stdcall * PhidgetMotorPositionController_OnPositionChangeCallback) (PhidgetMotorPositionControllerHandle ch, void *ctx, double position);

__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorPositionController_setOnPositionChangeHandler (PhidgetMotorPositionControllerHandle ch, PhidgetMotorPositionController_OnPositionChangeCallback fptr, void *ctx);

     typedef struct _PhidgetMotorVelocityController *PhidgetMotorVelocityControllerHandle;

/* Methods */
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorVelocityController_create (PhidgetMotorVelocityControllerHandle * ch);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorVelocityController_delete (PhidgetMotorVelocityControllerHandle * ch);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorVelocityController_enableFailsafe (PhidgetMotorVelocityControllerHandle ch, uint32_t failsafeTime);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorVelocityController_resetFailsafe (PhidgetMotorVelocityControllerHandle ch);

/* Properties */
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorVelocityController_setAcceleration (PhidgetMotorVelocityControllerHandle ch, double acceleration);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorVelocityController_getAcceleration (PhidgetMotorVelocityControllerHandle ch, double *acceleration);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorVelocityController_getMinAcceleration (PhidgetMotorVelocityControllerHandle ch, double *minAcceleration);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorVelocityController_getMaxAcceleration (PhidgetMotorVelocityControllerHandle ch, double *maxAcceleration);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorVelocityController_getActiveCurrentLimit (PhidgetMotorVelocityControllerHandle ch, double *activeCurrentLimit);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorVelocityController_setCurrentLimit (PhidgetMotorVelocityControllerHandle ch, double currentLimit);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorVelocityController_getCurrentLimit (PhidgetMotorVelocityControllerHandle ch, double *currentLimit);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorVelocityController_getMinCurrentLimit (PhidgetMotorVelocityControllerHandle ch, double *minCurrentLimit);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorVelocityController_getMaxCurrentLimit (PhidgetMotorVelocityControllerHandle ch, double *maxCurrentLimit);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorVelocityController_setDataInterval (PhidgetMotorVelocityControllerHandle ch, uint32_t dataInterval);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorVelocityController_getDataInterval (PhidgetMotorVelocityControllerHandle ch, uint32_t * dataInterval);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorVelocityController_getMinDataInterval (PhidgetMotorVelocityControllerHandle ch, uint32_t * minDataInterval);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorVelocityController_getMaxDataInterval (PhidgetMotorVelocityControllerHandle ch, uint32_t * maxDataInterval);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorVelocityController_setDataRate (PhidgetMotorVelocityControllerHandle ch, double dataRate);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorVelocityController_getDataRate (PhidgetMotorVelocityControllerHandle ch, double *dataRate);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorVelocityController_getMinDataRate (PhidgetMotorVelocityControllerHandle ch, double *minDataRate);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorVelocityController_getMaxDataRate (PhidgetMotorVelocityControllerHandle ch, double *maxDataRate);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorVelocityController_setDeadBand (PhidgetMotorVelocityControllerHandle ch, double deadBand);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorVelocityController_getDeadBand (PhidgetMotorVelocityControllerHandle ch, double *deadBand);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorVelocityController_getDutyCycle (PhidgetMotorVelocityControllerHandle ch, double *dutyCycle);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorVelocityController_setEngaged (PhidgetMotorVelocityControllerHandle ch, int engaged);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorVelocityController_getEngaged (PhidgetMotorVelocityControllerHandle ch, int *engaged);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorVelocityController_getExpectedVelocity (PhidgetMotorVelocityControllerHandle ch, double *expectedVelocity);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorVelocityController_setEnableExpectedVelocity (PhidgetMotorVelocityControllerHandle ch, int enableExpectedVelocity);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorVelocityController_getEnableExpectedVelocity (PhidgetMotorVelocityControllerHandle ch, int *enableExpectedVelocity);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorVelocityController_setFailsafeBrakingEnabled (PhidgetMotorVelocityControllerHandle ch, int failsafeBrakingEnabled);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorVelocityController_getFailsafeBrakingEnabled (PhidgetMotorVelocityControllerHandle ch, int *failsafeBrakingEnabled);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorVelocityController_setFailsafeCurrentLimit (PhidgetMotorVelocityControllerHandle ch, double failsafeCurrentLimit);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorVelocityController_getFailsafeCurrentLimit (PhidgetMotorVelocityControllerHandle ch, double *failsafeCurrentLimit);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorVelocityController_getMinFailsafeTime (PhidgetMotorVelocityControllerHandle ch, uint32_t * minFailsafeTime);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorVelocityController_getMaxFailsafeTime (PhidgetMotorVelocityControllerHandle ch, uint32_t * maxFailsafeTime);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorVelocityController_setInductance (PhidgetMotorVelocityControllerHandle ch, double inductance);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorVelocityController_getInductance (PhidgetMotorVelocityControllerHandle ch, double *inductance);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorVelocityController_getMinInductance (PhidgetMotorVelocityControllerHandle ch, double *minInductance);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorVelocityController_getMaxInductance (PhidgetMotorVelocityControllerHandle ch, double *maxInductance);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorVelocityController_setKd (PhidgetMotorVelocityControllerHandle ch, double kd);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorVelocityController_getKd (PhidgetMotorVelocityControllerHandle ch, double *kd);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorVelocityController_setKi (PhidgetMotorVelocityControllerHandle ch, double ki);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorVelocityController_getKi (PhidgetMotorVelocityControllerHandle ch, double *ki);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorVelocityController_setKp (PhidgetMotorVelocityControllerHandle ch, double kp);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorVelocityController_getKp (PhidgetMotorVelocityControllerHandle ch, double *kp);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorVelocityController_setPositionType (PhidgetMotorVelocityControllerHandle ch, Phidget_PositionType positionType);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorVelocityController_getPositionType (PhidgetMotorVelocityControllerHandle ch, Phidget_PositionType * positionType);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorVelocityController_setRescaleFactor (PhidgetMotorVelocityControllerHandle ch, double rescaleFactor);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorVelocityController_getRescaleFactor (PhidgetMotorVelocityControllerHandle ch, double *rescaleFactor);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorVelocityController_setStallVelocity (PhidgetMotorVelocityControllerHandle ch, double stallVelocity);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorVelocityController_getStallVelocity (PhidgetMotorVelocityControllerHandle ch, double *stallVelocity);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorVelocityController_getMinStallVelocity (PhidgetMotorVelocityControllerHandle ch, double *minStallVelocity);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorVelocityController_getMaxStallVelocity (PhidgetMotorVelocityControllerHandle ch, double *maxStallVelocity);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorVelocityController_setSurgeCurrentLimit (PhidgetMotorVelocityControllerHandle ch, double surgeCurrentLimit);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorVelocityController_getSurgeCurrentLimit (PhidgetMotorVelocityControllerHandle ch, double *surgeCurrentLimit);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorVelocityController_getMinSurgeCurrentLimit (PhidgetMotorVelocityControllerHandle ch, double *minSurgeCurrentLimit);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorVelocityController_getMaxSurgeCurrentLimit (PhidgetMotorVelocityControllerHandle ch, double *maxSurgeCurrentLimit);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorVelocityController_setTargetVelocity (PhidgetMotorVelocityControllerHandle ch, double targetVelocity);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorVelocityController_getTargetVelocity (PhidgetMotorVelocityControllerHandle ch, double *targetVelocity);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorVelocityController_getMinTargetVelocity (PhidgetMotorVelocityControllerHandle ch, double *minTargetVelocity);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorVelocityController_getMaxTargetVelocity (PhidgetMotorVelocityControllerHandle ch, double *maxTargetVelocity);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorVelocityController_getVelocity (PhidgetMotorVelocityControllerHandle ch, double *velocity);

/* Events */
     typedef void (__stdcall * PhidgetMotorVelocityController_OnDutyCycleUpdateCallback) (PhidgetMotorVelocityControllerHandle ch, void *ctx, double dutyCycle);

__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorVelocityController_setOnDutyCycleUpdateHandler (PhidgetMotorVelocityControllerHandle ch, PhidgetMotorVelocityController_OnDutyCycleUpdateCallback fptr, void *ctx);
     typedef void (__stdcall * PhidgetMotorVelocityController_OnExpectedVelocityChangeCallback) (PhidgetMotorVelocityControllerHandle ch, void *ctx, double expectedVelocity);

__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorVelocityController_setOnExpectedVelocityChangeHandler (PhidgetMotorVelocityControllerHandle ch, PhidgetMotorVelocityController_OnExpectedVelocityChangeCallback fptr, void *ctx);
     typedef void (__stdcall * PhidgetMotorVelocityController_OnVelocityChangeCallback) (PhidgetMotorVelocityControllerHandle ch, void *ctx, double velocity);

__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetMotorVelocityController_setOnVelocityChangeHandler (PhidgetMotorVelocityControllerHandle ch, PhidgetMotorVelocityController_OnVelocityChangeCallback fptr, void *ctx);

     typedef struct _PhidgetPHSensor *PhidgetPHSensorHandle;

/* Methods */
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetPHSensor_create (PhidgetPHSensorHandle * ch);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetPHSensor_delete (PhidgetPHSensorHandle * ch);

/* Properties */
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetPHSensor_setCorrectionTemperature (PhidgetPHSensorHandle ch, double correctionTemperature);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetPHSensor_getCorrectionTemperature (PhidgetPHSensorHandle ch, double *correctionTemperature);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetPHSensor_getMinCorrectionTemperature (PhidgetPHSensorHandle ch, double *minCorrectionTemperature);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetPHSensor_getMaxCorrectionTemperature (PhidgetPHSensorHandle ch, double *maxCorrectionTemperature);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetPHSensor_setDataInterval (PhidgetPHSensorHandle ch, uint32_t dataInterval);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetPHSensor_getDataInterval (PhidgetPHSensorHandle ch, uint32_t * dataInterval);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetPHSensor_getMinDataInterval (PhidgetPHSensorHandle ch, uint32_t * minDataInterval);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetPHSensor_getMaxDataInterval (PhidgetPHSensorHandle ch, uint32_t * maxDataInterval);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetPHSensor_setDataRate (PhidgetPHSensorHandle ch, double dataRate);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetPHSensor_getDataRate (PhidgetPHSensorHandle ch, double *dataRate);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetPHSensor_getMinDataRate (PhidgetPHSensorHandle ch, double *minDataRate);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetPHSensor_getMaxDataRate (PhidgetPHSensorHandle ch, double *maxDataRate);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetPHSensor_getPH (PhidgetPHSensorHandle ch, double *PH);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetPHSensor_getMinPH (PhidgetPHSensorHandle ch, double *minPH);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetPHSensor_getMaxPH (PhidgetPHSensorHandle ch, double *maxPH);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetPHSensor_setPHChangeTrigger (PhidgetPHSensorHandle ch, double PHChangeTrigger);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetPHSensor_getPHChangeTrigger (PhidgetPHSensorHandle ch, double *PHChangeTrigger);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetPHSensor_getMinPHChangeTrigger (PhidgetPHSensorHandle ch, double *minPHChangeTrigger);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetPHSensor_getMaxPHChangeTrigger (PhidgetPHSensorHandle ch, double *maxPHChangeTrigger);

/* Events */
     typedef void (__stdcall * PhidgetPHSensor_OnPHChangeCallback) (PhidgetPHSensorHandle ch, void *ctx, double PH);

__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetPHSensor_setOnPHChangeHandler (PhidgetPHSensorHandle ch, PhidgetPHSensor_OnPHChangeCallback fptr, void *ctx);

     typedef struct _PhidgetPowerGuard *PhidgetPowerGuardHandle;

/* Methods */
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetPowerGuard_create (PhidgetPowerGuardHandle * ch);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetPowerGuard_delete (PhidgetPowerGuardHandle * ch);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetPowerGuard_enableFailsafe (PhidgetPowerGuardHandle ch, uint32_t failsafeTime);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetPowerGuard_resetFailsafe (PhidgetPowerGuardHandle ch);

/* Properties */
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetPowerGuard_getMinFailsafeTime (PhidgetPowerGuardHandle ch, uint32_t * minFailsafeTime);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetPowerGuard_getMaxFailsafeTime (PhidgetPowerGuardHandle ch, uint32_t * maxFailsafeTime);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetPowerGuard_setFanMode (PhidgetPowerGuardHandle ch, Phidget_FanMode fanMode);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetPowerGuard_getFanMode (PhidgetPowerGuardHandle ch, Phidget_FanMode * fanMode);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetPowerGuard_setOverVoltage (PhidgetPowerGuardHandle ch, double overVoltage);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetPowerGuard_getOverVoltage (PhidgetPowerGuardHandle ch, double *overVoltage);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetPowerGuard_getMinOverVoltage (PhidgetPowerGuardHandle ch, double *minOverVoltage);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetPowerGuard_getMaxOverVoltage (PhidgetPowerGuardHandle ch, double *maxOverVoltage);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetPowerGuard_setPowerEnabled (PhidgetPowerGuardHandle ch, int powerEnabled);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetPowerGuard_getPowerEnabled (PhidgetPowerGuardHandle ch, int *powerEnabled);

/* Events */

     typedef struct _PhidgetPressureSensor *PhidgetPressureSensorHandle;

/* Methods */
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetPressureSensor_create (PhidgetPressureSensorHandle * ch);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetPressureSensor_delete (PhidgetPressureSensorHandle * ch);

/* Properties */
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetPressureSensor_setDataInterval (PhidgetPressureSensorHandle ch, uint32_t dataInterval);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetPressureSensor_getDataInterval (PhidgetPressureSensorHandle ch, uint32_t * dataInterval);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetPressureSensor_getMinDataInterval (PhidgetPressureSensorHandle ch, uint32_t * minDataInterval);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetPressureSensor_getMaxDataInterval (PhidgetPressureSensorHandle ch, uint32_t * maxDataInterval);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetPressureSensor_setDataRate (PhidgetPressureSensorHandle ch, double dataRate);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetPressureSensor_getDataRate (PhidgetPressureSensorHandle ch, double *dataRate);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetPressureSensor_getMinDataRate (PhidgetPressureSensorHandle ch, double *minDataRate);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetPressureSensor_getMaxDataRate (PhidgetPressureSensorHandle ch, double *maxDataRate);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetPressureSensor_getPressure (PhidgetPressureSensorHandle ch, double *pressure);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetPressureSensor_getMinPressure (PhidgetPressureSensorHandle ch, double *minPressure);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetPressureSensor_getMaxPressure (PhidgetPressureSensorHandle ch, double *maxPressure);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetPressureSensor_setPressureChangeTrigger (PhidgetPressureSensorHandle ch, double pressureChangeTrigger);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetPressureSensor_getPressureChangeTrigger (PhidgetPressureSensorHandle ch, double *pressureChangeTrigger);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetPressureSensor_getMinPressureChangeTrigger (PhidgetPressureSensorHandle ch, double *minPressureChangeTrigger);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetPressureSensor_getMaxPressureChangeTrigger (PhidgetPressureSensorHandle ch, double *maxPressureChangeTrigger);

/* Events */
     typedef void (__stdcall * PhidgetPressureSensor_OnPressureChangeCallback) (PhidgetPressureSensorHandle ch, void *ctx, double pressure);

__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetPressureSensor_setOnPressureChangeHandler (PhidgetPressureSensorHandle ch, PhidgetPressureSensor_OnPressureChangeCallback fptr, void *ctx);

     typedef struct _PhidgetRCServo *PhidgetRCServoHandle;

/* Methods */
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetRCServo_create (PhidgetRCServoHandle * ch);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetRCServo_delete (PhidgetRCServoHandle * ch);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetRCServo_enableFailsafe (PhidgetRCServoHandle ch, uint32_t failsafeTime);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetRCServo_resetFailsafe (PhidgetRCServoHandle ch);

/* Properties */
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetRCServo_setAcceleration (PhidgetRCServoHandle ch, double acceleration);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetRCServo_getAcceleration (PhidgetRCServoHandle ch, double *acceleration);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetRCServo_getMinAcceleration (PhidgetRCServoHandle ch, double *minAcceleration);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetRCServo_getMaxAcceleration (PhidgetRCServoHandle ch, double *maxAcceleration);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetRCServo_setDataInterval (PhidgetRCServoHandle ch, uint32_t dataInterval);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetRCServo_getDataInterval (PhidgetRCServoHandle ch, uint32_t * dataInterval);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetRCServo_getMinDataInterval (PhidgetRCServoHandle ch, uint32_t * minDataInterval);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetRCServo_getMaxDataInterval (PhidgetRCServoHandle ch, uint32_t * maxDataInterval);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetRCServo_setDataRate (PhidgetRCServoHandle ch, double dataRate);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetRCServo_getDataRate (PhidgetRCServoHandle ch, double *dataRate);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetRCServo_getMinDataRate (PhidgetRCServoHandle ch, double *minDataRate);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetRCServo_getMaxDataRate (PhidgetRCServoHandle ch, double *maxDataRate);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetRCServo_setEngaged (PhidgetRCServoHandle ch, int engaged);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetRCServo_getEngaged (PhidgetRCServoHandle ch, int *engaged);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetRCServo_getMinFailsafeTime (PhidgetRCServoHandle ch, uint32_t * minFailsafeTime);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetRCServo_getMaxFailsafeTime (PhidgetRCServoHandle ch, uint32_t * maxFailsafeTime);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetRCServo_getIsMoving (PhidgetRCServoHandle ch, int *isMoving);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetRCServo_getPosition (PhidgetRCServoHandle ch, double *position);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetRCServo_setMinPosition (PhidgetRCServoHandle ch, double minPosition);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetRCServo_getMinPosition (PhidgetRCServoHandle ch, double *minPosition);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetRCServo_setMaxPosition (PhidgetRCServoHandle ch, double maxPosition);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetRCServo_getMaxPosition (PhidgetRCServoHandle ch, double *maxPosition);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetRCServo_setMinPulseWidth (PhidgetRCServoHandle ch, double minPulseWidth);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetRCServo_getMinPulseWidth (PhidgetRCServoHandle ch, double *minPulseWidth);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetRCServo_setMaxPulseWidth (PhidgetRCServoHandle ch, double maxPulseWidth);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetRCServo_getMaxPulseWidth (PhidgetRCServoHandle ch, double *maxPulseWidth);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetRCServo_getMinPulseWidthLimit (PhidgetRCServoHandle ch, double *minPulseWidthLimit);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetRCServo_getMaxPulseWidthLimit (PhidgetRCServoHandle ch, double *maxPulseWidthLimit);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetRCServo_setSpeedRampingState (PhidgetRCServoHandle ch, int speedRampingState);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetRCServo_getSpeedRampingState (PhidgetRCServoHandle ch, int *speedRampingState);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetRCServo_setTargetPosition (PhidgetRCServoHandle ch, double targetPosition);
__declspec (dllimport)
     void __stdcall PhidgetRCServo_setTargetPosition_async (PhidgetRCServoHandle ch, double targetPosition, Phidget_AsyncCallback fptr, void *ctx);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetRCServo_getTargetPosition (PhidgetRCServoHandle ch, double *targetPosition);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetRCServo_setTorque (PhidgetRCServoHandle ch, double torque);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetRCServo_getTorque (PhidgetRCServoHandle ch, double *torque);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetRCServo_getMinTorque (PhidgetRCServoHandle ch, double *minTorque);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetRCServo_getMaxTorque (PhidgetRCServoHandle ch, double *maxTorque);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetRCServo_getVelocity (PhidgetRCServoHandle ch, double *velocity);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetRCServo_setVelocityLimit (PhidgetRCServoHandle ch, double velocityLimit);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetRCServo_getVelocityLimit (PhidgetRCServoHandle ch, double *velocityLimit);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetRCServo_getMinVelocityLimit (PhidgetRCServoHandle ch, double *minVelocityLimit);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetRCServo_getMaxVelocityLimit (PhidgetRCServoHandle ch, double *maxVelocityLimit);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetRCServo_setVoltage (PhidgetRCServoHandle ch, PhidgetRCServo_Voltage voltage);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetRCServo_getVoltage (PhidgetRCServoHandle ch, PhidgetRCServo_Voltage * voltage);

/* Events */
     typedef void (__stdcall * PhidgetRCServo_OnPositionChangeCallback) (PhidgetRCServoHandle ch, void *ctx, double position);

__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetRCServo_setOnPositionChangeHandler (PhidgetRCServoHandle ch, PhidgetRCServo_OnPositionChangeCallback fptr, void *ctx);
     typedef void (__stdcall * PhidgetRCServo_OnTargetPositionReachedCallback) (PhidgetRCServoHandle ch, void *ctx, double position);

__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetRCServo_setOnTargetPositionReachedHandler (PhidgetRCServoHandle ch, PhidgetRCServo_OnTargetPositionReachedCallback fptr, void *ctx);
     typedef void (__stdcall * PhidgetRCServo_OnVelocityChangeCallback) (PhidgetRCServoHandle ch, void *ctx, double velocity);

__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetRCServo_setOnVelocityChangeHandler (PhidgetRCServoHandle ch, PhidgetRCServo_OnVelocityChangeCallback fptr, void *ctx);

     typedef struct _PhidgetRFID *PhidgetRFIDHandle;

/* Methods */
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetRFID_create (PhidgetRFIDHandle * ch);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetRFID_delete (PhidgetRFIDHandle * ch);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetRFID_getLastTag (PhidgetRFIDHandle ch, char *tagString, size_t tagStringLen, PhidgetRFID_Protocol * protocol);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetRFID_write (PhidgetRFIDHandle ch, const char *tagString, PhidgetRFID_Protocol protocol, int lockTag);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetRFID_writeWithChipset (PhidgetRFIDHandle ch, const char *tagString, PhidgetRFID_Protocol protocol, int lockTag, PhidgetRFID_Chipset chipset);

/* Properties */
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetRFID_setAntennaEnabled (PhidgetRFIDHandle ch, int antennaEnabled);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetRFID_getAntennaEnabled (PhidgetRFIDHandle ch, int *antennaEnabled);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetRFID_getTagPresent (PhidgetRFIDHandle ch, int *tagPresent);

/* Events */
     typedef void (__stdcall * PhidgetRFID_OnTagCallback) (PhidgetRFIDHandle ch, void *ctx, const char *tag, PhidgetRFID_Protocol protocol);

__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetRFID_setOnTagHandler (PhidgetRFIDHandle ch, PhidgetRFID_OnTagCallback fptr, void *ctx);
     typedef void (__stdcall * PhidgetRFID_OnTagLostCallback) (PhidgetRFIDHandle ch, void *ctx, const char *tag, PhidgetRFID_Protocol protocol);

__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetRFID_setOnTagLostHandler (PhidgetRFIDHandle ch, PhidgetRFID_OnTagLostCallback fptr, void *ctx);

     typedef struct _PhidgetResistanceInput *PhidgetResistanceInputHandle;

/* Methods */
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetResistanceInput_create (PhidgetResistanceInputHandle * ch);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetResistanceInput_delete (PhidgetResistanceInputHandle * ch);

/* Properties */
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetResistanceInput_setDataInterval (PhidgetResistanceInputHandle ch, uint32_t dataInterval);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetResistanceInput_getDataInterval (PhidgetResistanceInputHandle ch, uint32_t * dataInterval);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetResistanceInput_getMinDataInterval (PhidgetResistanceInputHandle ch, uint32_t * minDataInterval);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetResistanceInput_getMaxDataInterval (PhidgetResistanceInputHandle ch, uint32_t * maxDataInterval);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetResistanceInput_setDataRate (PhidgetResistanceInputHandle ch, double dataRate);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetResistanceInput_getDataRate (PhidgetResistanceInputHandle ch, double *dataRate);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetResistanceInput_getMinDataRate (PhidgetResistanceInputHandle ch, double *minDataRate);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetResistanceInput_getMaxDataRate (PhidgetResistanceInputHandle ch, double *maxDataRate);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetResistanceInput_getResistance (PhidgetResistanceInputHandle ch, double *resistance);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetResistanceInput_getMinResistance (PhidgetResistanceInputHandle ch, double *minResistance);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetResistanceInput_getMaxResistance (PhidgetResistanceInputHandle ch, double *maxResistance);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetResistanceInput_setResistanceChangeTrigger (PhidgetResistanceInputHandle ch, double resistanceChangeTrigger);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetResistanceInput_getResistanceChangeTrigger (PhidgetResistanceInputHandle ch, double *resistanceChangeTrigger);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetResistanceInput_getMinResistanceChangeTrigger (PhidgetResistanceInputHandle ch, double *minResistanceChangeTrigger);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetResistanceInput_getMaxResistanceChangeTrigger (PhidgetResistanceInputHandle ch, double *maxResistanceChangeTrigger);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetResistanceInput_setRTDWireSetup (PhidgetResistanceInputHandle ch, Phidget_RTDWireSetup RTDWireSetup);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetResistanceInput_getRTDWireSetup (PhidgetResistanceInputHandle ch, Phidget_RTDWireSetup * RTDWireSetup);

/* Events */
     typedef void (__stdcall * PhidgetResistanceInput_OnResistanceChangeCallback) (PhidgetResistanceInputHandle ch, void *ctx, double resistance);

__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetResistanceInput_setOnResistanceChangeHandler (PhidgetResistanceInputHandle ch, PhidgetResistanceInput_OnResistanceChangeCallback fptr, void *ctx);

     typedef struct _PhidgetSoundSensor *PhidgetSoundSensorHandle;

/* Methods */
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetSoundSensor_create (PhidgetSoundSensorHandle * ch);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetSoundSensor_delete (PhidgetSoundSensorHandle * ch);

/* Properties */
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetSoundSensor_setDataInterval (PhidgetSoundSensorHandle ch, uint32_t dataInterval);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetSoundSensor_getDataInterval (PhidgetSoundSensorHandle ch, uint32_t * dataInterval);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetSoundSensor_getMinDataInterval (PhidgetSoundSensorHandle ch, uint32_t * minDataInterval);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetSoundSensor_getMaxDataInterval (PhidgetSoundSensorHandle ch, uint32_t * maxDataInterval);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetSoundSensor_setDataRate (PhidgetSoundSensorHandle ch, double dataRate);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetSoundSensor_getDataRate (PhidgetSoundSensorHandle ch, double *dataRate);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetSoundSensor_getMinDataRate (PhidgetSoundSensorHandle ch, double *minDataRate);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetSoundSensor_getMaxDataRate (PhidgetSoundSensorHandle ch, double *maxDataRate);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetSoundSensor_getdB (PhidgetSoundSensorHandle ch, double *dB);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetSoundSensor_getMaxdB (PhidgetSoundSensorHandle ch, double *maxdB);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetSoundSensor_getdBA (PhidgetSoundSensorHandle ch, double *dBA);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetSoundSensor_getdBC (PhidgetSoundSensorHandle ch, double *dBC);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetSoundSensor_getNoiseFloor (PhidgetSoundSensorHandle ch, double *noiseFloor);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetSoundSensor_getOctaves (PhidgetSoundSensorHandle ch, double (*octaves)[10]);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetSoundSensor_setSPLChangeTrigger (PhidgetSoundSensorHandle ch, double SPLChangeTrigger);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetSoundSensor_getSPLChangeTrigger (PhidgetSoundSensorHandle ch, double *SPLChangeTrigger);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetSoundSensor_getMinSPLChangeTrigger (PhidgetSoundSensorHandle ch, double *minSPLChangeTrigger);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetSoundSensor_getMaxSPLChangeTrigger (PhidgetSoundSensorHandle ch, double *maxSPLChangeTrigger);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetSoundSensor_setSPLRange (PhidgetSoundSensorHandle ch, PhidgetSoundSensor_SPLRange SPLRange);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetSoundSensor_getSPLRange (PhidgetSoundSensorHandle ch, PhidgetSoundSensor_SPLRange * SPLRange);

/* Events */
     typedef void (__stdcall * PhidgetSoundSensor_OnSPLChangeCallback) (PhidgetSoundSensorHandle ch, void *ctx, double dB, double dBA, double dBC, const double octaves[10]);

__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetSoundSensor_setOnSPLChangeHandler (PhidgetSoundSensorHandle ch, PhidgetSoundSensor_OnSPLChangeCallback fptr, void *ctx);

     typedef struct _PhidgetSpatial *PhidgetSpatialHandle;

/* Methods */
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetSpatial_create (PhidgetSpatialHandle * ch);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetSpatial_delete (PhidgetSpatialHandle * ch);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetSpatial_setAHRSParameters (PhidgetSpatialHandle ch, double angularVelocityThreshold, double angularVelocityDeltaThreshold, double accelerationThreshold, double magTime, double accelTime, double biasTime);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetSpatial_setMagnetometerCorrectionParameters (PhidgetSpatialHandle ch, double magneticField, double offset0, double offset1, double offset2, double gain0, double gain1, double gain2, double T0, double T1, double T2, double T3, double T4, double T5);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetSpatial_resetMagnetometerCorrectionParameters (PhidgetSpatialHandle ch);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetSpatial_saveMagnetometerCorrectionParameters (PhidgetSpatialHandle ch);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetSpatial_zeroAlgorithm (PhidgetSpatialHandle ch);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetSpatial_zeroGyro (PhidgetSpatialHandle ch);

/* Properties */
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetSpatial_getMinAcceleration (PhidgetSpatialHandle ch, double (*minAcceleration)[3]);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetSpatial_getMaxAcceleration (PhidgetSpatialHandle ch, double (*maxAcceleration)[3]);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetSpatial_setAlgorithm (PhidgetSpatialHandle ch, Phidget_SpatialAlgorithm algorithm);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetSpatial_getAlgorithm (PhidgetSpatialHandle ch, Phidget_SpatialAlgorithm * algorithm);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetSpatial_setAlgorithmMagnetometerGain (PhidgetSpatialHandle ch, double algorithmMagnetometerGain);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetSpatial_getAlgorithmMagnetometerGain (PhidgetSpatialHandle ch, double *algorithmMagnetometerGain);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetSpatial_getMinAngularRate (PhidgetSpatialHandle ch, double (*minAngularRate)[3]);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetSpatial_getMaxAngularRate (PhidgetSpatialHandle ch, double (*maxAngularRate)[3]);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetSpatial_setDataInterval (PhidgetSpatialHandle ch, uint32_t dataInterval);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetSpatial_getDataInterval (PhidgetSpatialHandle ch, uint32_t * dataInterval);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetSpatial_getMinDataInterval (PhidgetSpatialHandle ch, uint32_t * minDataInterval);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetSpatial_getMaxDataInterval (PhidgetSpatialHandle ch, uint32_t * maxDataInterval);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetSpatial_setDataRate (PhidgetSpatialHandle ch, double dataRate);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetSpatial_getDataRate (PhidgetSpatialHandle ch, double *dataRate);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetSpatial_getMinDataRate (PhidgetSpatialHandle ch, double *minDataRate);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetSpatial_getMaxDataRate (PhidgetSpatialHandle ch, double *maxDataRate);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetSpatial_getEulerAngles (PhidgetSpatialHandle ch, PhidgetSpatial_SpatialEulerAngles * eulerAngles);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetSpatial_setHeatingEnabled (PhidgetSpatialHandle ch, int heatingEnabled);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetSpatial_getHeatingEnabled (PhidgetSpatialHandle ch, int *heatingEnabled);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetSpatial_getMinMagneticField (PhidgetSpatialHandle ch, double (*minMagneticField)[3]);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetSpatial_getMaxMagneticField (PhidgetSpatialHandle ch, double (*maxMagneticField)[3]);

__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetSpatial_setPrecision (PhidgetSpatialHandle ch, Phidget_SpatialPrecision precision);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetSpatial_getPrecision (PhidgetSpatialHandle ch, Phidget_SpatialPrecision * precision);

__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetSpatial_getQuaternion (PhidgetSpatialHandle ch, PhidgetSpatial_SpatialQuaternion * quaternion);

/* Events */
     typedef void (__stdcall * PhidgetSpatial_OnAlgorithmDataCallback) (PhidgetSpatialHandle ch, void *ctx, const double quaternion[4], double timestamp);

__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetSpatial_setOnAlgorithmDataHandler (PhidgetSpatialHandle ch, PhidgetSpatial_OnAlgorithmDataCallback fptr, void *ctx);
     typedef void (__stdcall * PhidgetSpatial_OnSpatialDataCallback) (PhidgetSpatialHandle ch, void *ctx, const double acceleration[3], const double angularRate[3], const double magneticField[3], double timestamp);

__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetSpatial_setOnSpatialDataHandler (PhidgetSpatialHandle ch, PhidgetSpatial_OnSpatialDataCallback fptr, void *ctx);

     typedef struct _PhidgetStepper *PhidgetStepperHandle;

/* Methods */
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetStepper_create (PhidgetStepperHandle * ch);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetStepper_delete (PhidgetStepperHandle * ch);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetStepper_enableFailsafe (PhidgetStepperHandle ch, uint32_t failsafeTime);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetStepper_addPositionOffset (PhidgetStepperHandle ch, double positionOffset);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetStepper_resetFailsafe (PhidgetStepperHandle ch);

/* Properties */
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetStepper_setAcceleration (PhidgetStepperHandle ch, double acceleration);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetStepper_getAcceleration (PhidgetStepperHandle ch, double *acceleration);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetStepper_getMinAcceleration (PhidgetStepperHandle ch, double *minAcceleration);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetStepper_getMaxAcceleration (PhidgetStepperHandle ch, double *maxAcceleration);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetStepper_setControlMode (PhidgetStepperHandle ch, PhidgetStepper_ControlMode controlMode);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetStepper_getControlMode (PhidgetStepperHandle ch, PhidgetStepper_ControlMode * controlMode);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetStepper_setCurrentLimit (PhidgetStepperHandle ch, double currentLimit);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetStepper_getCurrentLimit (PhidgetStepperHandle ch, double *currentLimit);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetStepper_getMinCurrentLimit (PhidgetStepperHandle ch, double *minCurrentLimit);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetStepper_getMaxCurrentLimit (PhidgetStepperHandle ch, double *maxCurrentLimit);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetStepper_setDataInterval (PhidgetStepperHandle ch, uint32_t dataInterval);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetStepper_getDataInterval (PhidgetStepperHandle ch, uint32_t * dataInterval);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetStepper_getMinDataInterval (PhidgetStepperHandle ch, uint32_t * minDataInterval);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetStepper_getMaxDataInterval (PhidgetStepperHandle ch, uint32_t * maxDataInterval);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetStepper_setDataRate (PhidgetStepperHandle ch, double dataRate);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetStepper_getDataRate (PhidgetStepperHandle ch, double *dataRate);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetStepper_getMinDataRate (PhidgetStepperHandle ch, double *minDataRate);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetStepper_getMaxDataRate (PhidgetStepperHandle ch, double *maxDataRate);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetStepper_setEngaged (PhidgetStepperHandle ch, int engaged);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetStepper_getEngaged (PhidgetStepperHandle ch, int *engaged);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetStepper_getMinFailsafeTime (PhidgetStepperHandle ch, uint32_t * minFailsafeTime);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetStepper_getMaxFailsafeTime (PhidgetStepperHandle ch, uint32_t * maxFailsafeTime);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetStepper_setHoldingCurrentLimit (PhidgetStepperHandle ch, double holdingCurrentLimit);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetStepper_getHoldingCurrentLimit (PhidgetStepperHandle ch, double *holdingCurrentLimit);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetStepper_getIsMoving (PhidgetStepperHandle ch, int *isMoving);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetStepper_getPosition (PhidgetStepperHandle ch, double *position);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetStepper_getMinPosition (PhidgetStepperHandle ch, double *minPosition);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetStepper_getMaxPosition (PhidgetStepperHandle ch, double *maxPosition);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetStepper_setRescaleFactor (PhidgetStepperHandle ch, double rescaleFactor);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetStepper_getRescaleFactor (PhidgetStepperHandle ch, double *rescaleFactor);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetStepper_setTargetPosition (PhidgetStepperHandle ch, double targetPosition);
__declspec (dllimport)
     void __stdcall PhidgetStepper_setTargetPosition_async (PhidgetStepperHandle ch, double targetPosition, Phidget_AsyncCallback fptr, void *ctx);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetStepper_getTargetPosition (PhidgetStepperHandle ch, double *targetPosition);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetStepper_getVelocity (PhidgetStepperHandle ch, double *velocity);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetStepper_setVelocityLimit (PhidgetStepperHandle ch, double velocityLimit);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetStepper_getVelocityLimit (PhidgetStepperHandle ch, double *velocityLimit);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetStepper_getMinVelocityLimit (PhidgetStepperHandle ch, double *minVelocityLimit);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetStepper_getMaxVelocityLimit (PhidgetStepperHandle ch, double *maxVelocityLimit);

/* Events */
     typedef void (__stdcall * PhidgetStepper_OnPositionChangeCallback) (PhidgetStepperHandle ch, void *ctx, double position);

__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetStepper_setOnPositionChangeHandler (PhidgetStepperHandle ch, PhidgetStepper_OnPositionChangeCallback fptr, void *ctx);
     typedef void (__stdcall * PhidgetStepper_OnStoppedCallback) (PhidgetStepperHandle ch, void *ctx);

__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetStepper_setOnStoppedHandler (PhidgetStepperHandle ch, PhidgetStepper_OnStoppedCallback fptr, void *ctx);
     typedef void (__stdcall * PhidgetStepper_OnVelocityChangeCallback) (PhidgetStepperHandle ch, void *ctx, double velocity);

__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetStepper_setOnVelocityChangeHandler (PhidgetStepperHandle ch, PhidgetStepper_OnVelocityChangeCallback fptr, void *ctx);

     typedef struct _PhidgetTemperatureSensor *PhidgetTemperatureSensorHandle;

/* Methods */
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetTemperatureSensor_create (PhidgetTemperatureSensorHandle * ch);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetTemperatureSensor_delete (PhidgetTemperatureSensorHandle * ch);

/* Properties */
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetTemperatureSensor_setDataInterval (PhidgetTemperatureSensorHandle ch, uint32_t dataInterval);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetTemperatureSensor_getDataInterval (PhidgetTemperatureSensorHandle ch, uint32_t * dataInterval);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetTemperatureSensor_getMinDataInterval (PhidgetTemperatureSensorHandle ch, uint32_t * minDataInterval);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetTemperatureSensor_getMaxDataInterval (PhidgetTemperatureSensorHandle ch, uint32_t * maxDataInterval);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetTemperatureSensor_setDataRate (PhidgetTemperatureSensorHandle ch, double dataRate);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetTemperatureSensor_getDataRate (PhidgetTemperatureSensorHandle ch, double *dataRate);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetTemperatureSensor_getMinDataRate (PhidgetTemperatureSensorHandle ch, double *minDataRate);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetTemperatureSensor_getMaxDataRate (PhidgetTemperatureSensorHandle ch, double *maxDataRate);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetTemperatureSensor_setRTDType (PhidgetTemperatureSensorHandle ch, PhidgetTemperatureSensor_RTDType RTDType);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetTemperatureSensor_getRTDType (PhidgetTemperatureSensorHandle ch, PhidgetTemperatureSensor_RTDType * RTDType);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetTemperatureSensor_setRTDWireSetup (PhidgetTemperatureSensorHandle ch, Phidget_RTDWireSetup RTDWireSetup);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetTemperatureSensor_getRTDWireSetup (PhidgetTemperatureSensorHandle ch, Phidget_RTDWireSetup * RTDWireSetup);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetTemperatureSensor_getTemperature (PhidgetTemperatureSensorHandle ch, double *temperature);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetTemperatureSensor_getMinTemperature (PhidgetTemperatureSensorHandle ch, double *minTemperature);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetTemperatureSensor_getMaxTemperature (PhidgetTemperatureSensorHandle ch, double *maxTemperature);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetTemperatureSensor_setTemperatureChangeTrigger (PhidgetTemperatureSensorHandle ch, double temperatureChangeTrigger);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetTemperatureSensor_getTemperatureChangeTrigger (PhidgetTemperatureSensorHandle ch, double *temperatureChangeTrigger);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetTemperatureSensor_getMinTemperatureChangeTrigger (PhidgetTemperatureSensorHandle ch, double *minTemperatureChangeTrigger);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetTemperatureSensor_getMaxTemperatureChangeTrigger (PhidgetTemperatureSensorHandle ch, double *maxTemperatureChangeTrigger);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetTemperatureSensor_setThermocoupleType (PhidgetTemperatureSensorHandle ch, PhidgetTemperatureSensor_ThermocoupleType thermocoupleType);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetTemperatureSensor_getThermocoupleType (PhidgetTemperatureSensorHandle ch, PhidgetTemperatureSensor_ThermocoupleType * thermocoupleType);

/* Events */
     typedef void (__stdcall * PhidgetTemperatureSensor_OnTemperatureChangeCallback) (PhidgetTemperatureSensorHandle ch, void *ctx, double temperature);

__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetTemperatureSensor_setOnTemperatureChangeHandler (PhidgetTemperatureSensorHandle ch, PhidgetTemperatureSensor_OnTemperatureChangeCallback fptr, void *ctx);

     typedef struct _PhidgetVoltageInput *PhidgetVoltageInputHandle;

/* Methods */
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetVoltageInput_create (PhidgetVoltageInputHandle * ch);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetVoltageInput_delete (PhidgetVoltageInputHandle * ch);

/* Properties */
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetVoltageInput_setDataInterval (PhidgetVoltageInputHandle ch, uint32_t dataInterval);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetVoltageInput_getDataInterval (PhidgetVoltageInputHandle ch, uint32_t * dataInterval);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetVoltageInput_getMinDataInterval (PhidgetVoltageInputHandle ch, uint32_t * minDataInterval);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetVoltageInput_getMaxDataInterval (PhidgetVoltageInputHandle ch, uint32_t * maxDataInterval);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetVoltageInput_setDataRate (PhidgetVoltageInputHandle ch, double dataRate);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetVoltageInput_getDataRate (PhidgetVoltageInputHandle ch, double *dataRate);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetVoltageInput_getMinDataRate (PhidgetVoltageInputHandle ch, double *minDataRate);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetVoltageInput_getMaxDataRate (PhidgetVoltageInputHandle ch, double *maxDataRate);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetVoltageInput_setPowerSupply (PhidgetVoltageInputHandle ch, Phidget_PowerSupply powerSupply);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetVoltageInput_getPowerSupply (PhidgetVoltageInputHandle ch, Phidget_PowerSupply * powerSupply);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetVoltageInput_setSensorType (PhidgetVoltageInputHandle ch, PhidgetVoltageInput_SensorType sensorType);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetVoltageInput_getSensorType (PhidgetVoltageInputHandle ch, PhidgetVoltageInput_SensorType * sensorType);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetVoltageInput_getSensorUnit (PhidgetVoltageInputHandle ch, Phidget_UnitInfo * sensorUnit);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetVoltageInput_getSensorValue (PhidgetVoltageInputHandle ch, double *sensorValue);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetVoltageInput_setSensorValueChangeTrigger (PhidgetVoltageInputHandle ch, double sensorValueChangeTrigger);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetVoltageInput_getSensorValueChangeTrigger (PhidgetVoltageInputHandle ch, double *sensorValueChangeTrigger);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetVoltageInput_getVoltage (PhidgetVoltageInputHandle ch, double *voltage);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetVoltageInput_getMinVoltage (PhidgetVoltageInputHandle ch, double *minVoltage);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetVoltageInput_getMaxVoltage (PhidgetVoltageInputHandle ch, double *maxVoltage);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetVoltageInput_setVoltageChangeTrigger (PhidgetVoltageInputHandle ch, double voltageChangeTrigger);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetVoltageInput_getVoltageChangeTrigger (PhidgetVoltageInputHandle ch, double *voltageChangeTrigger);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetVoltageInput_getMinVoltageChangeTrigger (PhidgetVoltageInputHandle ch, double *minVoltageChangeTrigger);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetVoltageInput_getMaxVoltageChangeTrigger (PhidgetVoltageInputHandle ch, double *maxVoltageChangeTrigger);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetVoltageInput_setVoltageRange (PhidgetVoltageInputHandle ch, PhidgetVoltageInput_VoltageRange voltageRange);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetVoltageInput_getVoltageRange (PhidgetVoltageInputHandle ch, PhidgetVoltageInput_VoltageRange * voltageRange);

/* Events */
     typedef void (__stdcall * PhidgetVoltageInput_OnSensorChangeCallback) (PhidgetVoltageInputHandle ch, void *ctx, double sensorValue, Phidget_UnitInfo * sensorUnit);

__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetVoltageInput_setOnSensorChangeHandler (PhidgetVoltageInputHandle ch, PhidgetVoltageInput_OnSensorChangeCallback fptr, void *ctx);
     typedef void (__stdcall * PhidgetVoltageInput_OnVoltageChangeCallback) (PhidgetVoltageInputHandle ch, void *ctx, double voltage);

__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetVoltageInput_setOnVoltageChangeHandler (PhidgetVoltageInputHandle ch, PhidgetVoltageInput_OnVoltageChangeCallback fptr, void *ctx);

     typedef struct _PhidgetVoltageOutput *PhidgetVoltageOutputHandle;

/* Methods */
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetVoltageOutput_create (PhidgetVoltageOutputHandle * ch);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetVoltageOutput_delete (PhidgetVoltageOutputHandle * ch);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetVoltageOutput_enableFailsafe (PhidgetVoltageOutputHandle ch, uint32_t failsafeTime);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetVoltageOutput_resetFailsafe (PhidgetVoltageOutputHandle ch);

/* Properties */
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetVoltageOutput_setEnabled (PhidgetVoltageOutputHandle ch, int enabled);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetVoltageOutput_getEnabled (PhidgetVoltageOutputHandle ch, int *enabled);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetVoltageOutput_getMinFailsafeTime (PhidgetVoltageOutputHandle ch, uint32_t * minFailsafeTime);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetVoltageOutput_getMaxFailsafeTime (PhidgetVoltageOutputHandle ch, uint32_t * maxFailsafeTime);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetVoltageOutput_setVoltage (PhidgetVoltageOutputHandle ch, double voltage);
__declspec (dllimport)
     void __stdcall PhidgetVoltageOutput_setVoltage_async (PhidgetVoltageOutputHandle ch, double voltage, Phidget_AsyncCallback fptr, void *ctx);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetVoltageOutput_getVoltage (PhidgetVoltageOutputHandle ch, double *voltage);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetVoltageOutput_getMinVoltage (PhidgetVoltageOutputHandle ch, double *minVoltage);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetVoltageOutput_getMaxVoltage (PhidgetVoltageOutputHandle ch, double *maxVoltage);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetVoltageOutput_setVoltageOutputRange (PhidgetVoltageOutputHandle ch, PhidgetVoltageOutput_VoltageOutputRange voltageOutputRange);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetVoltageOutput_getVoltageOutputRange (PhidgetVoltageOutputHandle ch, PhidgetVoltageOutput_VoltageOutputRange * voltageOutputRange);

/* Events */

     typedef struct _PhidgetVoltageRatioInput *PhidgetVoltageRatioInputHandle;

/* Methods */
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetVoltageRatioInput_create (PhidgetVoltageRatioInputHandle * ch);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetVoltageRatioInput_delete (PhidgetVoltageRatioInputHandle * ch);

/* Properties */
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetVoltageRatioInput_setBridgeEnabled (PhidgetVoltageRatioInputHandle ch, int bridgeEnabled);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetVoltageRatioInput_getBridgeEnabled (PhidgetVoltageRatioInputHandle ch, int *bridgeEnabled);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetVoltageRatioInput_setBridgeGain (PhidgetVoltageRatioInputHandle ch, PhidgetVoltageRatioInput_BridgeGain bridgeGain);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetVoltageRatioInput_getBridgeGain (PhidgetVoltageRatioInputHandle ch, PhidgetVoltageRatioInput_BridgeGain * bridgeGain);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetVoltageRatioInput_setDataInterval (PhidgetVoltageRatioInputHandle ch, uint32_t dataInterval);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetVoltageRatioInput_getDataInterval (PhidgetVoltageRatioInputHandle ch, uint32_t * dataInterval);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetVoltageRatioInput_getMinDataInterval (PhidgetVoltageRatioInputHandle ch, uint32_t * minDataInterval);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetVoltageRatioInput_getMaxDataInterval (PhidgetVoltageRatioInputHandle ch, uint32_t * maxDataInterval);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetVoltageRatioInput_setDataRate (PhidgetVoltageRatioInputHandle ch, double dataRate);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetVoltageRatioInput_getDataRate (PhidgetVoltageRatioInputHandle ch, double *dataRate);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetVoltageRatioInput_getMinDataRate (PhidgetVoltageRatioInputHandle ch, double *minDataRate);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetVoltageRatioInput_getMaxDataRate (PhidgetVoltageRatioInputHandle ch, double *maxDataRate);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetVoltageRatioInput_setSensorType (PhidgetVoltageRatioInputHandle ch, PhidgetVoltageRatioInput_SensorType sensorType);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetVoltageRatioInput_getSensorType (PhidgetVoltageRatioInputHandle ch, PhidgetVoltageRatioInput_SensorType * sensorType);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetVoltageRatioInput_getSensorUnit (PhidgetVoltageRatioInputHandle ch, Phidget_UnitInfo * sensorUnit);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetVoltageRatioInput_getSensorValue (PhidgetVoltageRatioInputHandle ch, double *sensorValue);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetVoltageRatioInput_setSensorValueChangeTrigger (PhidgetVoltageRatioInputHandle ch, double sensorValueChangeTrigger);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetVoltageRatioInput_getSensorValueChangeTrigger (PhidgetVoltageRatioInputHandle ch, double *sensorValueChangeTrigger);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetVoltageRatioInput_getVoltageRatio (PhidgetVoltageRatioInputHandle ch, double *voltageRatio);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetVoltageRatioInput_getMinVoltageRatio (PhidgetVoltageRatioInputHandle ch, double *minVoltageRatio);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetVoltageRatioInput_getMaxVoltageRatio (PhidgetVoltageRatioInputHandle ch, double *maxVoltageRatio);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetVoltageRatioInput_setVoltageRatioChangeTrigger (PhidgetVoltageRatioInputHandle ch, double voltageRatioChangeTrigger);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetVoltageRatioInput_getVoltageRatioChangeTrigger (PhidgetVoltageRatioInputHandle ch, double *voltageRatioChangeTrigger);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetVoltageRatioInput_getMinVoltageRatioChangeTrigger (PhidgetVoltageRatioInputHandle ch, double *minVoltageRatioChangeTrigger);
__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetVoltageRatioInput_getMaxVoltageRatioChangeTrigger (PhidgetVoltageRatioInputHandle ch, double *maxVoltageRatioChangeTrigger);

/* Events */
     typedef void (__stdcall * PhidgetVoltageRatioInput_OnSensorChangeCallback) (PhidgetVoltageRatioInputHandle ch, void *ctx, double sensorValue, Phidget_UnitInfo * sensorUnit);

__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetVoltageRatioInput_setOnSensorChangeHandler (PhidgetVoltageRatioInputHandle ch, PhidgetVoltageRatioInput_OnSensorChangeCallback fptr, void *ctx);
     typedef void (__stdcall * PhidgetVoltageRatioInput_OnVoltageRatioChangeCallback) (PhidgetVoltageRatioInputHandle ch, void *ctx, double voltageRatio);

__declspec (dllimport)
     PhidgetReturnCode __stdcall PhidgetVoltageRatioInput_setOnVoltageRatioChangeHandler (PhidgetVoltageRatioInputHandle ch, PhidgetVoltageRatioInput_OnVoltageRatioChangeCallback fptr, void *ctx);
#ifdef __cplusplus
}
#endif
#endif 
