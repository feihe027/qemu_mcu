/*
 * Copyright 2023, Yeestor Co.Ltd.
 * All rights reserved.
 * FileName : case61001.sh
 * Description : Riscv-32 HelloWorld Demo
 * Author : Michael.duan
 * http: // www.yeestor.com
 * Revision : 1.0.0
 */

/* Standard includes. */
#include <stdint.h>
#include <stdarg.h>
#include "gcov_public.h"
/*-----------------------------------------------------------*/
/* register definitions */
#define REG_RBR 0x00  /* Receiver buffer reg. */
#define REG_THR 0x00  /* Transmitter holding reg. */
#define REG_IER 0x01  /* Interrupt enable reg. */
#define REG_IIR 0x02  /* Interrupt ID reg. */
#define REG_FCR 0x02  /* FIFO control reg. */
#define REG_LCR 0x03  /* Line control reg. */
#define REG_MCR 0x04  /* Modem control reg. */
#define REG_LSR 0x05  /* Line status reg. */
#define REG_MSR 0x06  /* Modem status reg. */
#define REG_SCR 0x07  /* Scratch reg. */
#define REG_BRDL 0x00 /* Divisor latch (LSB) */
#define REG_BRDH 0x01 /* Divisor latch (MSB) */

/* Line status */
#define LSR_DR 0x01   /* Data ready */
#define LSR_OE 0x02   /* Overrun error */
#define LSR_PE 0x04   /* Parity error */
#define LSR_FE 0x08   /* Framing error */
#define LSR_BI 0x10   /* Break interrupt */
#define LSR_THRE 0x20 /* Transmitter holding register empty */
#define LSR_TEMT 0x40 /* Transmitter empty */
#define LSR_EIRF 0x80 /* Error in RCVR FIFO */

struct device
{
    uintptr_t addr;
};

static uint8_t readb(uintptr_t addr)
{
    return *((uint8_t *)addr);
}

static void writeb(uint8_t b, uintptr_t addr)
{
    *((uint8_t *)addr) = b;
}

void vOutNS16550(struct device *dev, unsigned char c)
{
    uintptr_t addr = dev->addr;

    while ((readb(addr + REG_LSR) & LSR_THRE) == 0)
    {
        /* busy wait */
    }

    writeb(c, addr + REG_THR);
}

#define putchar(c) vOutNS16550(&dev, c)

struct device dev = {0x10000000};

int UartWrite(char *pcString, int iStringLength)
{
    int iNextChar;

    /* Output the formatted string to the UART. */
    for (iNextChar = 0; iNextChar < iStringLength; iNextChar++)
    {
        putchar(*pcString);
        pcString++;
    }

    return iStringLength;
}

void main(void)
{
    __gcov_call_constructors();
    for (int i = 1; i < 10; i++)
    {
        if (i % 3 == 0)
            UartWrite("Hello World!\n", 13);
        if (i % 11 == 0)
            UartWrite("12345678901!\n", 13);
    }
    __gcov_exit();
}
