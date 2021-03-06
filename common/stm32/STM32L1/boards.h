/*! \file
 * \brief Definitions of various boards based on the STM32L1
 *
 * Copyright (c) 2018, Archos S.A.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * * Redistributions of source code must retain the above copyright
 *   notice, this list of conditions and the following disclaimer.
 * * Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in the
 *   documentation and/or other materials provided with the distribution.
 * * Neither the name of Archos nor the names of its contributors may be
 *   used to endorse or promote products derived from this software without
 *   specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ``AS IS'' AND
 * AND EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL ARCHOS S.A. BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef _BOARDS_H_
#define _BOARDS_H_

#include <gpio.h>

#ifdef CFG_discovery_stm32l1_board
/* ***********************************************************************************
 *
 * STM32L152 Discovery Kit (32L152CDISCOVERY) + SX1276RF1JAS board from Semtech
 *
 *************************************************************************************/

// RF characteristics
#define MAX_RF_POWER			20 // dBm
#define MIN_RF_POWER			2 // dBm
#define ANTENNA_GAIN			-6 // dBi
#define LNA_GAIN			0 // dB

// GPIOs
#define NSS_PORT			GPIO_PORT_A // NSS: PA4, sx1276
#define NSS_PIN				4

#define TX_PA_PORT			GPIO_PORT_C // TX_PA:  PC6
#define TX_PA_PIN			6

#define RST_PORT			GPIO_PORT_A // RST: PA11
#define RST_PIN				11

#define DIO0_PORT			GPIO_PORT_C // DIO0: PC1, sx1276   (line 1 irq handler)
#define DIO0_PIN			1
#define DIO0_TYPE			GPIO_PUPD_NONE
#define DIO1_PORT			GPIO_PORT_C // DIO1: PC2, sx1276  (line 2 irq handler)
#define DIO1_PIN			2
#define DIO1_TYPE			GPIO_PUPD_NONE
#define DIO2_PORT			GPIO_PORT_C // DIO2: PC3, sx1276  (line 3 irq handler)
#define DIO2_PIN			3
#define DIO2_TYPE			GPIO_PUPD_NONE

#define LED0_PORT			GPIO_PORT_B // Blue LED: PB6
#define LED0_PIN			6
#define LED0_MODE			LED_ACTIVE_HIGH
#define LED1_PORT			GPIO_PORT_B // Green LED: PB7
#define LED1_PIN			7
#define LED1_MODE			LED_ACTIVE_HIGH

#define BUTTON0_PORT			GPIO_PORT_A // PA0
#define BUTTON0_PIN			0
#define BUTTON0_TYPE			GPIO_PUPD_NONE
#define BUTTON0_MODE			BUTTON_ACTIVE_HIGH

#define OUTPUT_PINS			{{NSS_PORT, NSS_PIN}, {TX_PA_PORT, TX_PA_PIN}, {LED0_PORT, LED0_PIN}, {LED1_PORT, LED1_PIN}}
#define INPUT_PINS			{{DIO0_PORT, DIO0_PIN, DIO0_TYPE}, {DIO1_PORT, DIO1_PIN, DIO1_TYPE}, {DIO2_PORT, DIO2_PIN, DIO2_TYPE}, {BUTTON0_PORT, BUTTON0_PIN, BUTTON0_TYPE}}

// SPI
#define SCK_PORT			GPIO_PORT_A // SCK:  PA5
#define SCK_PIN				5
#define MISO_PORT			GPIO_PORT_A // MISO: PA6
#define MISO_PIN			6
#define MOSI_PORT			GPIO_PORT_A // MOSI: PA7
#define MOSI_PIN			7

#define GPIO_AF_SPI1			0x05

// Console USART
#define CONSOLE_USART			USART_PORT_1

#define CONSOLE_USART_TX_PORT		GPIO_PORT_A
#define CONSOLE_USART_TX_PIN		9
#define CONSOLE_USART_RX_PORT		GPIO_PORT_A
#define CONSOLE_USART_RX_PIN		10

#define CONSOLE_USART_AF		0x07

#define LOWPOWER_PINS			{{NSS_PORT, NSS_PIN}, {TX_PA_PORT, TX_PA_PIN}, {RST_PORT, RST_PIN}, \
					 {DIO0_PORT, DIO0_PIN}, {DIO1_PORT, DIO1_PIN}, {DIO2_PORT, DIO2_PIN}, \
					 {LED0_PORT, LED0_PIN}, {LED1_PORT, LED1_PIN}, {BUTTON0_PORT, BUTTON0_PIN}, \
					 {SCK_PORT, SCK_PIN}, {MISO_PORT, MISO_PIN}, {MOSI_PORT, MOSI_PIN}}
#elif CFG_picotag_board
/* ***********************************************************************************
 *
 * Archos PicoSmartTAG
 *
 *************************************************************************************/

#define HAS_TCXO
#define HAS_LIS2DE12_ACCELEROMETER

// RF characteristics
#define MAX_RF_POWER			20 // dBm
#define MIN_RF_POWER			0 // dBm
#define ANTENNA_GAIN			-6 // dBi
// QORVO LNA with nominal gain of 14dB
#define LNA_GAIN			14 // dB

// GPIOs
#define NSS_PORT			GPIO_PORT_B // NSS: PB0, sx1276
#define NSS_PIN				0

#define RX_PORT				GPIO_PORT_B // RX:  PB6
#define RX_PIN				6
#define TX_RFO_PORT			GPIO_PORT_B // TX_RFO:  PB7
#define TX_RFO_PIN			7
#define TX_PA_PORT			GPIO_PORT_A // TX_PA:  PA4
#define TX_PA_PIN			4
#define TCXO_PORT			GPIO_PORT_H // PH1
#define TCXO_PIN			1

#define RST_PORT			GPIO_PORT_B // RST: PB13
#define RST_PIN				13

#define DIO0_PORT			GPIO_PORT_A // DIO0: PA11, sx1276  (line 1 irq handler)
#define DIO0_PIN			11
#define DIO0_TYPE			GPIO_PUPD_NONE
#define DIO1_PORT			GPIO_PORT_B // DIO1: PB1, sx1276  (line 2 irq handler)
#define DIO1_PIN			1
#define DIO1_TYPE			GPIO_PUPD_NONE
#define DIO2_PORT			GPIO_PORT_A // DIO2: PA3, sx1276  (line 3 irq handler)
#define DIO2_PIN			3
#define DIO2_TYPE			GPIO_PUPD_NONE
#define DIO3_PORT			GPIO_PORT_H // DIO3: PH0, sx1276  (line 4 irq handler)
#define DIO3_PIN			0
#define DIO3_TYPE			GPIO_PUPD_NONE
#define DIO4_PORT			GPIO_PORT_C // DIO4: PC13, sx1276  (line 5 irq handler)
#define DIO4_PIN			13
#define DIO4_TYPE			GPIO_PUPD_NONE

#define LED0_PORT			GPIO_PORT_B // Red LED: PB3
#define LED0_PIN			3
#define LED0_MODE			LED_ACTIVE_HIGH
#define LED1_PORT			GPIO_PORT_A // Blue LED: PA8
#define LED1_PIN			8
#define LED1_MODE			LED_ACTIVE_HIGH

#define BUTTON0_PORT			GPIO_PORT_B // PB5
#define BUTTON0_PIN			5
#define BUTTON0_MODE			BUTTON_ACTIVE_LOW
#define BUTTON0_TYPE			GPIO_PUPD_UP
#define BUTTON1_PORT			GPIO_PORT_B // PB4
#define BUTTON1_PIN			4
#define BUTTON1_MODE			BUTTON_ACTIVE_LOW
#define BUTTON1_TYPE			GPIO_PUPD_UP

#define WIFI_GPIO0_PORT			GPIO_PORT_A // PA0
#define WIFI_GPIO0_PIN			0
#define WIFI_GPIO0_TYPE			GPIO_PUPD_NONE
#define WIFI_ENABLE_PORT		GPIO_PORT_A // PA12
#define WIFI_ENABLE_PIN			12

#define ACC1_PORT			GPIO_PORT_B // PB14
#define ACC1_PIN			14
#define ACC1_TYPE			GPIO_PUPD_NONE
#define ACC2_PORT			GPIO_PORT_B // PB15
#define ACC2_PIN			15
#define ACC2_TYPE			GPIO_PUPD_NONE

#define BATT_ANA_PORT			GPIO_PORT_A // PA2
#define BATT_ANA_PIN			2
#define BATT_ANA_CHAN			ADC_Channel_2
#define BATT_MEAS_PORT			GPIO_PORT_A // PA15
#define BATT_MEAS_PIN			15
#define BATT_CHRG_PORT			GPIO_PORT_B // PB12
#define BATT_CHRG_PIN			12
#define BATT_CHRG_TYPE			GPIO_PUPD_UP
#define BATT_SYNC_PORT			GPIO_PORT_A // PA1
#define BATT_SYNC_PIN			1

#define OUTPUT_PINS			{{NSS_PORT, NSS_PIN}, {RX_PORT, RX_PIN}, {TX_RFO_PORT, TX_RFO_PIN}, \
					 {TX_PA_PORT, TX_PA_PIN}, {LED0_PORT, LED0_PIN}, {LED1_PORT, LED1_PIN}, \
					 {WIFI_ENABLE_PORT, WIFI_ENABLE_PIN}, \
					 {BATT_MEAS_PORT, BATT_MEAS_PIN}, {BATT_SYNC_PORT, BATT_SYNC_PIN}, \
					 {TCXO_PORT, TCXO_PIN}}
#define INPUT_PINS			{{DIO0_PORT, DIO0_PIN, DIO0_TYPE}, {DIO1_PORT, DIO1_PIN, DIO1_TYPE}, {DIO2_PORT, DIO2_PIN, DIO2_TYPE}, \
					 {DIO3_PORT, DIO3_PIN, DIO3_TYPE}, {DIO4_PORT, DIO4_PIN, DIO4_TYPE}, \
					 {BUTTON0_PORT, BUTTON0_PIN, BUTTON0_TYPE}, {BUTTON1_PORT, BUTTON1_PIN, BUTTON1_TYPE}, \
					 {ACC1_PORT, ACC1_PIN, ACC1_TYPE}, {ACC2_PORT, ACC2_PIN, ACC2_TYPE}, \
					 {BATT_CHRG_PORT, BATT_CHRG_PIN, BATT_CHRG_TYPE}}

// SPI
#define SCK_PORT			GPIO_PORT_A // SCK:  PA5
#define SCK_PIN				5
#define MISO_PORT			GPIO_PORT_A // MISO: PA6
#define MISO_PIN			6
#define MOSI_PORT			GPIO_PORT_A // MOSI: PA7
#define MOSI_PIN			7

#define GPIO_AF_SPI1			0x05

// I2C
#define SCL_PORT			GPIO_PORT_B // SCL:  PB8
#define SCL_PIN				8
#define SDA_PORT			GPIO_PORT_B // SDA:  PB9
#define SDA_PIN				9

#define GPIO_AF_I2C1			0x04

#define ACC_I2C_PORT			I2C_PORT_1

// Console USART
#define CONSOLE_USART			USART_PORT_1

#define CONSOLE_USART_TX_PORT		GPIO_PORT_A
#define CONSOLE_USART_TX_PIN		9
#define CONSOLE_USART_RX_PORT		GPIO_PORT_A
#define CONSOLE_USART_RX_PIN		10

#define CONSOLE_USART_AF		0x07

// Wifi USART
#define WIFI_USART			USART_PORT_3

#define WIFI_USART_TX_PORT		GPIO_PORT_B
#define WIFI_USART_TX_PIN		10
#define WIFI_USART_RX_PORT		GPIO_PORT_B
#define WIFI_USART_RX_PIN		11

#define WIFI_USART_AF			0x07

#define LOWPOWER_PINS			{{NSS_PORT, NSS_PIN}, {TX_RFO_PORT, TX_RFO_PIN}, {RX_PORT, RX_PIN}, \
					 {TX_PA_PORT, TX_PA_PIN}, {RST_PORT, RST_PIN}, \
					 {DIO0_PORT, DIO0_PIN}, {DIO1_PORT, DIO1_PIN}, {DIO2_PORT, DIO2_PIN}, \
					 {DIO3_PORT, DIO3_PIN}, {DIO4_PORT, DIO4_PIN}, \
					 {SCK_PORT, SCK_PIN}, {MISO_PORT, MISO_PIN}, {MOSI_PORT, MOSI_PIN}, \
					 {LED0_PORT, LED0_PIN}, {LED1_PORT, LED1_PIN}, \
					 {BUTTON0_PORT, BUTTON0_PIN}, {BUTTON1_PORT, BUTTON1_PIN}, \
					 {SCL_PORT, SCL_PIN}, {SDA_PORT, SDA_PIN}, \
					 {ACC1_PORT, ACC1_PIN}, {ACC2_PORT, ACC2_PIN}, \
					 {WIFI_ENABLE_PORT, WIFI_ENABLE_PIN}, \
					 {WIFI_USART_TX_PORT, WIFI_USART_TX_PIN}, {WIFI_USART_RX_PORT, WIFI_USART_RX_PIN}, \
					 {BATT_MEAS_PORT, BATT_MEAS_PIN}, {BATT_CHRG_PORT, BATT_CHRG_PIN}, {BATT_SYNC_PORT, BATT_SYNC_PIN}, \
					 {TCXO_PORT, TCXO_PIN}}
#else
#error Missing board configuration !
#endif


#endif /* _BOARDS_H_ */
