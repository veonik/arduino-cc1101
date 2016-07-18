/**
 * Copyright (c) 2011 panStamp <contact@panstamp.com>
 * Copyright (c) 2016 Tyler Sommer <contact@tylersommer.pro>
 *
 * This file is part of the CC1101 project.
 *
 * CC1101 is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * any later version.
 *
 * CC1101 is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with CC1101; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301 
 * USA
 * 
 * Author: Daniel Berenguer
 * Creation date: 03/03/2011
 */

#ifndef _SIMPLESPI_H
#define _SIMPLESPI_H

#include <stdint.h>

/**
 * SPI pins
 */

#if defined(__AVR_ATmega2560__) || defined(__AVR_ATmega1280__)

#define SPI_SS   53     // PB0 = SPI_SS
#define SPI_MOSI 51     // PB2 = MOSI
#define SPI_MISO 50     // PB3 = MISO
#define SPI_SCK  52     // PB1 = SCK
#define GDO0     19     // PD2 = INT2

#define PORT_SPI_MISO  PINB
#define BIT_SPI_MISO   3

#define PORT_SPI_SS  PORTB
#define BIT_SPI_SS   0

#define PORT_GDO0  PIND
#define BIT_GDO0   2

#else

#define SPI_SS   SS              // PB2 = SPI_SS
#define SPI_MOSI MOSI            // PB3 = MOSI
#define SPI_MISO MISO            // PB4 = MISO
#define SPI_SCK  SCK             // PB5 = SCK
#define GDO0     2               // PD2 = INT0

#define PORT_SPI_MISO  PINB
#define BIT_SPI_MISO  4

#define PORT_SPI_SS  PORTB
#define BIT_SPI_SS   2

#define PORT_GDO0  PIND
#define BIT_GDO0  2

#endif

/**
 * Macros
 */
// Wait until SPI operation is terminated
#define wait_Spi()  while(!(SPSR & _BV(SPIF)))

/**
 * Class: SIMPLESPI
 * 
 * Description:
 * Basic SPI class
 */
class SIMPLESPI
{
  public:
    /**
     * init
     * 
     * SPI initialization
     */
    void init();

    /**
     * send
     * 
     * Send byte via SPI
     * 
     * 'value'	Value to be sent
     * 
     * Return:
     * 	Response received from SPI slave
     */
    uint8_t send(uint8_t value);
};
#endif
