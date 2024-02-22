
ENTRY(Reset_Handler)

__STACK_SIZE     = 1024 * 5;
__HEAP_SIZE      = 1024 * 3;

MEMORY
{
    ITCM             : ORIGIN = 0x000000000, LENGTH = 192K
    D0TCM_COMMON     : ORIGIN = 0x020000000, LENGTH = 120K
    D0TCM_STACK      : ORIGIN = 0x02001E000, LENGTH =  8K
    SHRAM            : ORIGIN = 0x03F000000, LENGTH = 16M 
    DDR              : ORIGIN = 0x060000000, LENGTH = 1024M
}


PHDRS 
{
    text		 PT_LOAD;
    data		 PT_LOAD;
    heapPhdr	         PT_NULL;
    stackPhdr	         PT_NULL;
    shRamPhdr	         PT_NULL;
}

SECTIONS
{
    .text : 
    {
       KEEP(*(.vectors))
       *(.text*)
    } > ITCM : text

/*
   .copy.table :
   {
      . = ALIGN(4);
      __copy_table_start__ = .;

     LONG (__etext)
     LONG (__data_start__)
     LONG ((__data_end__ - __data_start__) / 4)
     __copy_table_end__ = .;
  } > ITCM : text
*/

   __etext = ALIGN (4);
  
    .data :
    {
        __data_start__ = .;
        *(.drvParam)
        *(vtable)
        *(.data)
        *(.data*)
        *(.rodata)	
       *(.rodata*)
      __data_end__ = .;
   } > D0TCM_COMMON : data

   .bss :
   {
       . = ALIGN(4);
       __bss_start__ = .;
       *(.bss)
       *(.bss.*)
       *(COMMON)
       . = ALIGN(4);
       __bss_end__ = .;
   } > D0TCM_COMMON : data
    
    .heap (NOLOAD) : ALIGN(8)
    {
       . = ALIGN(8);
       __end__ = .;
       PROVIDE(end = .);
       . = . + __HEAP_SIZE;
       . = ALIGN(8);
        __HeapLimit = .;
    } > D0TCM_STACK : heapPhdr
    
    .stack (NOLOAD) : ALIGN(8)
    {
    . = ALIGN(8);
        __stack_sentry = .;
        . += __STACK_SIZE;
    . = ALIGN(8);
        __StackTop = .;
   } > D0TCM_STACK : stackPhdr

   PROVIDE(__stack = __StackTop);

  .sh_ram (NOLOAD) : 
  {
    *(.sh.ram)
  } > SHRAM : shRamPhdr	
}

