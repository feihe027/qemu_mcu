

#ifndef __TYPES_H__
#define __TYPES_H__ (1)

/* Typedef for u8_t. */
typedef unsigned char u8_t;
typedef unsigned char u8;

/* Typedef for u16_t. */
typedef unsigned short u16_t;
typedef unsigned short u16;

/* Typedef for u32_t. */
typedef unsigned int u32_t;
typedef unsigned int u32;

/* Typedef for u64_t. */
typedef unsigned long long u64_t;

/* Typedef for s8_t. */
typedef signed char s8_t;

/* Typedef for s16_t. */
typedef signed short s16_t;

/* Typedef for s32_t. */
typedef signed int s32_t;

/* Typedef for s64_t. */
typedef signed long long s64_t;

/* Typedef for bool_t. */
typedef unsigned int bool_t;

#if (WORDSIZE == 64)
typedef u64_t uintptr_t;
typedef s64_t sintptr_t;
#else
typedef u32_t uintptr_t;
typedef s32_t sintptr_t;
#endif

//typedef unsigned int size_t;

typedef union
{
    u32_t   U32;    // 0x01234567
    u16_t   U16[2]; // U16[0] is 0x4567; U16[1] is 0x0123.
    u8_t    U8[4];  // U8[0] is 0x67; U8[1] is 0x45; U8[2] is 0x23; U8[4] is 0x01.
} u32_u;

typedef union
{
    u64_t   U64;    // 0x0000000001234567.
    u32_u   U32[2]; // U32[0] is 0x01234567; U32[1] is 0x00000000.
    u16_t   U16[4];
    u8_t    U8[8];
} u64_u;

/* Define for FALSE. */
#ifndef FALSE
    #define FALSE (0)
#endif

/* Define for TRUE. */
#ifndef TRUE
    #define TRUE (1==1)
#endif

#ifndef NULL
    /* Define for NULL. */
    #define NULL ((void *) 0)
#endif

#define U8_MAX          ((u8_t)  (~0U))
#define U16_MAX         ((u16_t) (~0U))
#define U32_MAX         ((u32_t) (~0U))
#define U48_MAX         ((u64_t) 0x0000FFFFFFFFFFFF)
#define U64_MAX         ((u64_t) (~0ULL))
#define GET_BYTE0(__X)  ((u8_t)((__X) >> 0))
#define GET_BYTE1(__X)  ((u8_t)((__X) >> 8))
#define GET_BYTE2(__X)  ((u8_t)((__X) >> 16))
#define GET_BYTE3(__X)  ((u8_t)((__X) >> 24))

#define ALIGN_TO_4BYTE(X)  (((X) + 3) & ~0x3)
#define ALIGN_TO_8BYTE(X)  (((X) + 7) & ~0x7)

#define LOWER_DWORD(QWORD)          (u32_t)(QWORD)
#define UPPER_DWORD(QWORD)          (u32_t)((u64_t)(QWORD) >> 32)
#define QWORD(LOWER, UPPER)         (((u64_t)(UPPER) << 32) + (LOWER))

#ifndef IN
    #define IN
#endif

#ifndef OUT
    #define OUT
#endif

#define    SIZE_OF_STRUCT_EQUAL_TO(type, size) \
    static inline char size_of_##type##_equal_to_size() \
    { \
        char __dummy1[1 + sizeof(type) - (size)]; \
        char __dummy2[1 + (size) - sizeof(type)]; \
        __dummy1[0] = 0; \
        __dummy2[0] = 0; \
        return __dummy1[0] + __dummy2[0]; \
    }

#define    SIZE_OF_STRUCT_NOT_LARGER_THAN(type, size) \
    static inline char size_of_##type##_not_larger_than_size() \
    { \
        char __dummy1[1 + (size) - sizeof(type)]; \
        __dummy1[0] = 0; \
        return __dummy1[0]; \
    }

#define    SIZE_OF_STRUCT_NOT_SMALLER_THAN(type, size) \
    static inline char size_of_##type##_not_smaller_than_size() \
    { \
        char __dummy1[1 + sizeof(type) - (size)]; \
        __dummy1[0] = 0; \
        return __dummy1[0]; \
    }


#define    SIZE_OF_STRUCT_MODULAR_TO(type, size) \
    static inline char size_of_##type##_modular_to_size() \
    { \
        char __dummy1[1 + (sizeof(type) % (size))]; \
        char __dummy2[1 - (sizeof(type) % (size))]; \
        __dummy1[0] = 0; \
        __dummy2[0] = 0; \
        return __dummy1[0] + __dummy2[0]; \
    }

#define max(a,b)            (((a) > (b)) ? (a) : (b))
#define min(a,b)            (((a) < (b)) ? (a) : (b))

#endif

