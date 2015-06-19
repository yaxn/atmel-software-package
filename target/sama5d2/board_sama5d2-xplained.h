/**
 * \page sama5d2_xult_board_desc sama5d2-XULT - Board Description
 *
 * \section Purpose
 *
 * This file is dedicated to describe the sama5d2-XULT board.
 *
 * \section Contents
 *
 *  - sama5d2-XULT
 *  - For sama5d2-XULT information, see \subpage sama5d2_xult_board_info.
 *  - For operating frequency information, see \subpage sama5d2_xult_opfreq.
 *  - For using portable PIO definitions, see \subpage sama5d2_xult_piodef.
 *  - For on-board memories, see \subpage sama5d2_xult_mem.
 *  - Several USB definitions are included here, see \subpage sama5d2_xult_usb.
 *  - For External components, see \subpage sama5d2_xult_extcomp.
 *  - For Individual chip definition, see \subpage sama5d2_xult_chipdef.
 *
 * To get more software details and the full list of parameters related to the
 * sama5d2-XULT board configuration, please have a look at the source file:
 * \ref board.h\n
 *
 * \section Usage
 *
 *  - The code for booting the board is provided by board_cstartup_xxx.c and
 *    board_lowlevel.c.
 *  - For using board PIOs, board characteristics (clock, etc.) and external
 *    components, see board.h.
 *  - For manipulating memories, see board_memories.h.
 *
 * This file can be used as a template and modified to fit a custom board, with
 * specific PIOs usage or memory connections.
 */

/**
 *  \file board.h
 *
 *  Definition of sama5d2-XULT
 *  characteristics, sama5d4-dependant PIOs and external components interfacing.
 */

#ifndef _BOARD_D2_H
#define _BOARD_D2_H

/*----------------------------------------------------------------------------
 *        Headers
 *----------------------------------------------------------------------------*/

#include "chip.h"

#include "board_lowlevel.h"
#include "board_memories.h"

/*----------------------------------------------------------------------------
 *        HW BOARD Definitions
 *----------------------------------------------------------------------------*/

/**
 * \page sama5d2_xult_board_info "sama5d2-XULT - Board informations"
 * This page lists several definition related to the board description.
 *
 * \section Definitions
 * - \ref BOARD_NAME
 */

/** Name of the board */
#define BOARD_NAME "sama5d2-xult"

/** Family definition */
#if !defined sama5d2
  #define sama5d2
#endif

/** Board definition */
#define sama5d2xult

/** Core definition */
#define cortexa5

#define BOARD_REV_A_XULT

/*----------------------------------------------------------------------------*/
/**
 *  \page sama5d2_xult_opfreq "sama5d2-XULT - Operating frequencies"
 *  This page lists several definition related to the board operating frequency
 *  (when using the initialization done by board_lowlevel.c).
 */

/** Frequency of the board slow clock oscillator */
#define BOARD_SLOW_CLOCK_EXT_OSC 32768

/** Frequency of the board main clock oscillator */
#define BOARD_MAIN_CLOCK_EXT_OSC 12000000

/** /def Definition of DDRAM's type */
#define BOARD_DDRAM_TYPE         MT41K128M16

/** \def Board DDR memory size in bytes */
#define BOARD_DDR_MEMORY_SIZE    512*1024*1024

/* =================== PIN CONSOLE definition ================== */

/** CONSOLE pin definition, Use only UART */
#define PINS_CONSOLE            PINS_UART1_IOS1
#define CONSOLE_PER_ADD         UART1
#define CONSOLE_ID              ID_UART1
#define CONSOLE_BAUDRATE        57600
#define CONSOLE_DRIVER          DRV_UART

/* =================== PIN LED definition ====================== */

/* RGB LED index */
#define LED_RED   0    /* led red shared with SDHC0 (eMMC) card detect used only by RomBoot */
#define LED_GREEN 1
#define LED_BLUE  2

/** LED #0 pin definition (Red). */
#define PIN_LED_0 { PIO_GROUP_A, PIO_PA13, PIO_OUTPUT_0, PIO_OPENDRAIN }

/** LED #1 pin definition (Green). */
#define PIN_LED_1 { PIO_GROUP_B, PIO_PB5, PIO_OUTPUT_1, PIO_OPENDRAIN }

/** LED #2 pin definition (Blue). */
#define PIN_LED_2 { PIO_GROUP_B, PIO_PB0, PIO_OUTPUT_1, PIO_OPENDRAIN }

/** List of all LEDs definitions. */
#define PINS_LEDS { PIN_LED_0, PIN_LED_1, PIN_LED_2 }

/* =================== PIN PUSH BUTTON definition ============== */

#define PIO_CFG_PB  (PIO_PULLUP | PIO_DEBOUNCE)

#define PIN_PUSHBUTTON_1 { PIO_GROUP_B, PIO_PB6, PIO_INPUT, PIO_CFG_PB }

/** List of all push button definitions. */
#define PINS_PUSHBUTTONS { PIN_PUSHBUTTON_1 }

/** Push button index. */
#define PUSHBUTTON_BP1 0

/* ================== PIN PMIC definition ====================== */

#define PIN_ACT8945A_CHGLEV  {\
	{ PIO_GROUP_A, PIO_PA12, PIO_OUTPUT_0, PIO_PULLUP },\
}

#define PIO_CFG_ACT8945A_IRQ  (PIO_PULLUP | PIO_IT_FALL_EDGE)
#define PIN_ACT8945A_IRQ {\
	{ PIO_GROUP_B, PIO_PB13, PIO_INPUT, PIO_CFG_ACT8945A_IRQ },\
}

#define PIN_ACT8945A_LBO {\
	{ PIO_GROUP_A, PIO_PB13, PIO_INPUT, PIO_PULLUP },\
}

/* ================== PIN USB definition ======================= */

/** USB VBus pin */
#define PIN_USB_VBUS      {\
	{ PIO_GROUP_A, PIO_PA31, PIO_INPUT, PIO_DEFAULT },\
}
/** USB OverCurrent detection*/
#define PIN_USB_OVCUR     {\
	{ PIO_GROUP_A, PIO_PA29, PIO_INPUT, PIO_DEFAULT },\
}
/** USB Power Enable A, Active high */
#define PIN_USB_POWER_ENA {\
	{ PIO_GROUP_B, PIO_PB9, PIO_OUTPUT_0, PIO_DEFAULT },\
}
/** USB Power Enable B, Active high  */
#define PIN_USB_POWER_ENB {\
	{ PIO_GROUP_B, PIO_PB10, PIO_OUTPUT_0, PIO_DEFAULT },\
}

/* ================= PIN GMAC IRQ definition ==================== */

#define PIO_CFG_GMAC_IRQ  (PIO_PULLUP | PIO_IT_FALL_EDGE)
#define PIN_GMAC_IRQ	{\
	{ PIO_GROUP_C, PIO_PC9, PIO_INPUT, PIO_CFG_GMAC_IRQ },\
}

/* ================= PIN LCD IRQ definition ===================== */

#define PIO_CFG_LCD_IRQ  (PIO_PULLUP | PIO_IT_FALL_EDGE)

#define PIN_QT1070_IRQ {\
	{ PIO_GROUP_B, PIO_PB7, PIO_INPUT, PIO_CFG_LCD_IRQ },\
}
#define PIN_MXT336S_IRQ {\
	{ PIO_GROUP_B, PIO_PB8, PIO_INPUT, PIO_CFG_LCD_IRQ },\
}
#define PIN_MXT768E_IRQ	{\
	{ PIO_GROUP_B, PIO_PB8, PIO_INPUT, PIO_CFG_LCD_IRQ },\
}

/* =================== PIN ISC definition ======================= */

#define PIN_ISC_RST	{\
	{ PIO_GROUP_B, PIO_PB11, PIO_OUTPUT_1, PIO_DEFAULT },\
}
#define PIN_ISC_PWD	{\
	{ PIO_GROUP_B, PIO_PB12, PIO_OUTPUT_1, PIO_DEFAULT  },\
}

/* =================== PIN HSDHC definition ===================== */

#define PIN_HSDHC1_CD	{\
	{ PIO_GROUP_A, PIO_PA30, PIO_INPUT, PIO_PULLUP },\
}

/* =================== AT25 device definition =================== */

#define AT25_PINS     PINS_SPI0_NPCS0_IOS1
#define AT25_ADDR     SPI0
#define AT25_CS       0
#define AT25_ATTRS    (SPI_MR_MODFDIS | SPI_MR_WDRBT | SPI_MR_MSTR)
#define AT25_FREQ     40000 /* (value in KHz) */
#define AT25_LOW_FREQ 20000 /* (value in KHz) */
#define AT25_DLYBS    0
#define AT25_DLYCT    0
#define AT25_SPI_MODE (SPI_CSR_NCPHA | SPI_CSR_BITS_8_BIT)

#endif /* #ifndef _BOARD_D2_H */
