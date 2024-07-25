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

static int UartWrite(char *pcString, int iStringLength)
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
void *my_memset(void *s, int c, size_t n)
{
    unsigned char *p = s;

    __asm__ __volatile__(
        "1: \n"
        "cmp %[count], #0 \n"
        "beq 2f \n"
        "strb %[c], [%[p]] \n"
        "add %[p], %[p], #1 \n"
        "sub %[count], %[count], #1 \n"
        "b 1b \n"
        "2: \n"
        : [p] "+r"(p), [count] "+r"(n)
        : [c] "r"(c)
        : "cc", "memory");

    return s;
}

void my_memset1(void *s, int c, size_t n)
{
    unsigned char *p = s;

    for (size_t i = 0; i < n; i++)
    {
        *p++ = (unsigned char)c;
    }
}
void my_memset1_optimized(void *ptr, uint8_t value, size_t size)
{
    uint8_t *ptr8 = (uint8_t *)ptr;
    size_t i;

    // 使用汇编内联优化循环
    __asm volatile(
        "push    {r4-r7, lr}\n"
        "mov     r4, %[ptr]\n"
        "mov     r5, %[value]\n"
        "mov     r6, %[size]\n"
        "mov     r7, #0\n"
        "1:\n"
        // 使用循环按字节填充内存
        "strb    r5, [r4], #1\n"
        "strb    r5, [r4], #1\n"
        "strb    r5, [r4], #1\n"
        "strb    r5, [r4], #1\n"
        "strb    r5, [r4], #1\n"
        "strb    r5, [r4], #1\n"
        "strb    r5, [r4], #1\n"
        "strb    r5, [r4], #1\n"
        "strb    r5, [r4], #1\n"
        "strb    r5, [r4], #1\n"
        "strb    r5, [r4], #1\n"
        "strb    r5, [r4], #1\n"
        "strb    r5, [r4], #1\n"
        "strb    r5, [r4], #1\n"
        "strb    r5, [r4], #1\n"
        "strb    r5, [r4], #1\n"

        // 递增计数器
        "add     r7, r7, #16\n"

        // 比较计数器和大小
        "cmp     r7, r6\n"
        "blt     1b\n"

        // 恢复寄存器
        "pop     {r4-r7, pc}\n"
        :
        : [ptr] "r"(ptr8), [value] "r"(value), [size] "r"(size)
        : "r4", "r5", "r6", "r7", "memory");

    // 处理剩余字节（如果大小不是 16 字节的倍数）
    for (i = size & ~0xf; i < size; i++)
    {
        ptr8[i] = value;
    }
}

void fill_memory_32(uint32_t *ptr, uint32_t value, size_t size)
{
    __asm volatile(
        "mov r0, %[ptr]\n"
        "mov r1, %[value]\n"
        "mov r2, %[size]\n"
        "1:\n"
        "str r1, [r0, #0]\n"
        "str r1, [r0, #4]\n"
        "str r1, [r0, #8]\n"
        "str r1, [r0, #12]\n"
        "add r0, r0, #16\n"
        "sub r2, r2, #4\n"
        "cmp r2, #0\n"
        "bgt 1b\n"
        :
        : [ptr] "r"(ptr), [value] "r"(value), [size] "r"(size)
        : "r0", "r1", "r2", "memory");
}
void memset32_optimized(void *ptr, uint32_t value, size_t count)
{
    asm volatile(
        "lsrs   r3, %[count], #4      \n" // 使用右移操作计算循环次数
        "beq    end%=                 \n" // 如果循环次数为0，则跳转至end标签
        "movs   r2, %[value]          \n" // 将value值复制到r2寄存器

        "loop%=:                      \n"
        "str    r2, [%[ptr]], #4      \n" // 将r2中的值存储到ptr指向的地址，并自增指针
        "str    r2, [%[ptr]], #4      \n"
        "str    r2, [%[ptr]], #4      \n"
        "str    r2, [%[ptr]], #4      \n"
        "subs   r3, r3, #1            \n" // 循环计数减1
        "bne    loop%=                \n" // 如果循环计数不为0，则跳转到loop标签处

        "end%=:                       \n"
        :
        : [ptr] "r"(ptr), [value] "r"(value), [count] "r"(count)
        : "memory", "r2", "r3" // 声明寄存器使用
    );
}

void memset32_unrolled4(uint32_t *dst, uint32_t value, size_t n)
{
    asm volatile(
        "push {r4-r7, lr}\n"
        "mov r4, %[dst]\n"
        "mov r5, %[value]\n"
        "mov r6, %[n]\n"
        "lsr r7, r6, #2\n"
        "beq 2f\n"
        "1:\n"
        "str r5, [r4], #4\n"
        "str r5, [r4], #4\n"
        "str r5, [r4], #4\n"
        "str r5, [r4], #4\n"
        "subs r7, r7, #1\n"
        "bne 1b\n"
        "2:\n"
        "and r6, r6, #3\n"
        "beq 4f\n"
        "3:\n"
        "str r5, [r4], #4\n"
        "subs r6, r6, #1\n"
        "bne 3b\n"
        "4:\n"
        "pop {r4-r7, pc}\n"
        :
        : [dst] "r"(dst), [value] "r"(value), [n] "r"(n)
        : "r4", "r5", "r6", "r7");
}


#ifdef OPHY
#define OPHY_OFFSET 2
#else
#define OPHY_OFFSET 0
#endif

enum RegisterAddr
{
    PosA = 3,
    PosB = 5,
#ifdef OPHY
    FuncC = PosB + 2,
#endif
    PosC = PosB + 2 + OPHY_OFFSET,
    PosD = PosC + 3,
};

void process_int(int x)
{
    printf("Processing integer: %d\n", x);
}

void process_float(float x)
{
    printf("Processing float: %.2f\n", x);
}

void process_double(double x)
{
    printf("Processing double: %.4lf\n", x);
}

#define process(x) _Generic((x), int: process_int, float: process_float, double: process_double)(x)

struct MyStruct
{
    int x;
    double y;
};

struct MyStruct s = {10, 2.5}; // 指定初始化结构体成员

int main1()
{
    int a = 5;
    float b = 3.14f;
    double c = 2.718;
    int arr[5] = {1, 2, 3, 4, 5}; // 指定初始化数组元素

    process(a);
    process(b);
    process(c);

    return 0;
}
int test() ;
int main(void)
{
    InitUart();
    char szArr[32];
    szArr[0] = '0' + test();
    szArr[1] = '0' + __COUNTER__;
    szArr[2] = '0' + __COUNTER__;
    szArr[3] = '0' + __COUNTER__;
    UartWrite(szArr, 32);
    UartWrite("Hello World!\n", 13);
    while (1)
    {
        /* code */
    }
    
    return 0;
}

