/*
 *-----------------------------------------------------------------------------
 * The confidential and proprietary information contained in this file may
 * only be used by a person authorised under and to the extent permitted
 * by a subsisting licensing agreement from ARM Limited.
 *
 *            (C) COPYRIGHT 2011-2014  ARM Limited.
 *                ALL RIGHTS RESERVED
 *
 * This entire notice must be reproduced on all copies of this file
 * and copies of this file may only be made by a person if such person is
 * permitted to do so under the terms of a subsisting license agreement
 * from ARM Limited.
 *
 *      SVN Information
 *
 *      Checked In          : $Date: 2014-01-24 16:41:40 +0000 (Fri, 24 Jan 2014) $
 *
 *      Revision            : $Revision: 268403 $
 *
 *      Release Information : CORTEX-M7-r1p2-00rel0
 *-----------------------------------------------------------------------------
 */

#include <stdio.h>
#include "cm7ikmcu.h"
#include "IKtests.h"
#include "gcov_public.h"

//
// Function Prototypes
//

void invalid_icache(void)
{
    __asm__ volatile("dsb \n " /*  */
                     "mov r0, #0x0 \n"
                     "ldr r11, =0xE00EF50 \n"
                     "str r0, [r11] \n"
                     "dsb \n"
                     "isb \n"
                     :        /* output */
                     :        /* no input */
                     : "cc"); /* clean condition register status */
}

void invalid_icache_ex(void)
{
    __asm__ volatile("dsb \n " /*  */
                     "mov r0, #0x0 \n"
                     "mcr p15, 0, r1, c7, c5, 1\n"
                     "dsb \n"
                     "isb \n"
                     :        /* output */
                     :        /* no input */
                     : "cc"); /* clean condition register status */
}

#define UART0_ADDRESS (0x40004000UL)
#define UART0_DATA (*(((volatile uint32_t *)(UART0_ADDRESS + 0UL))))
#define UART0_STATE (*(((volatile uint32_t *)(UART0_ADDRESS + 4UL))))
#define UART0_CTRL (*(((volatile uint32_t *)(UART0_ADDRESS + 8UL))))
#define UART0_BAUDDIV (*(((volatile uint32_t *)(UART0_ADDRESS + 16UL))))
#define TX_BUFFER_MASK (1UL)

static void InitUart(void)
{
    UART0_BAUDDIV = 16;
    UART0_CTRL = 1;
}
/*-----------------------------------------------------------*/

int UartWrite(char *pcString, int iStringLength)
{
    int iNextChar;

    /* Output the formatted string to the UART. */
    for (iNextChar = 0; iNextChar < iStringLength; iNextChar++)
    {
        while ((UART0_STATE & TX_BUFFER_MASK) != 0)
        {
        }

        UART0_DATA = *pcString;
        pcString++;
    }

    return iStringLength;
}

// extern void (*__preinit_array_start[])(void) __attribute__((weak));
// extern void (*__preinit_array_end[])(void) __attribute__((weak));
// extern void (*__init_array_start[])(void) __attribute__((weak));
// extern void (*__init_array_end[])(void) __attribute__((weak));
// extern void (*__fini_array_start[])(void) __attribute__((weak));
// extern void (*__fini_array_end[])(void) __attribute__((weak));

// void static_init(void)
// {
//     void (**p)(void);
//     uint32_t beg = (uint32_t)&__init_array_start;
//     uint32_t end = (uint32_t)&__init_array_end;

//     while (beg < end)
//     {
//         p = (void (**)(void))beg; /* get function pointer */
//         (*p)();                   /* call constructor */
//         beg += sizeof(p);         /* next pointer */
//     }
// }
ssize_t _write_r(struct _reent *ptr, int fd, const void *buf, size_t count)
{
    const char *data = (const char *)buf;
    for (int i = 0; i < count; i++)
    {
        UartWrite(&data[i], 1);
    }
    return count;
}

int main (void)
{
    InitUart();
    __gcov_call_constructors();
    for (int i = 1; i < 10; i++)
    {
        if (i % 3 == 0)
            UartWrite("Hello World!\n", 13);
        if (i % 11 == 0)
            UartWrite("12345678901!\n", 13);
    }
   // __gcov_exit();

    return 0;
}

