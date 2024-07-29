
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
    
    .inits : ALIGN(4)
    {
        __data_regions_array_start = .;
        
        LONG(LOADADDR(.data));
        LONG(ADDR(.data));
        LONG(ADDR(.data)+SIZEOF(.data));
        
        __data_regions_array_end = .;
        
        __bss_regions_array_start = .;
        
        LONG(ADDR(.bss));
        LONG(ADDR(.bss)+SIZEOF(.bss));
        
        __bss_regions_array_end = .;

        KEEP(*(.init))
        KEEP(*(.fini))
    } >ITCM

    .preinit_array    :
    {
        PROVIDE_HIDDEN (__preinit_array_start = .);
        KEEP (*(.preinit_array))
        PROVIDE_HIDDEN (__preinit_array_end = .);
    }>ITCM
    .init_array    :
    {
        PROVIDE_HIDDEN (__ctor_list = .);
        KEEP (*(SORT_BY_INIT_PRIORITY(.init_array.*) SORT_BY_INIT_PRIORITY(.ctors.*)))
        KEEP (*(.init_array EXCLUDE_FILE (*crtbegin.o *crtbegin?.o *crtend.o *crtend?.o ) .ctors))
        PROVIDE_HIDDEN (__ctor_end = .);
    }>ITCM
    .fini_array    :
    {
        PROVIDE_HIDDEN (__fini_array_start = .);
        KEEP (*(SORT_BY_INIT_PRIORITY(.fini_array.*) SORT_BY_INIT_PRIORITY(.dtors.*)))
        KEEP (*(.fini_array EXCLUDE_FILE (*crtbegin.o *crtbegin?.o *crtend.o *crtend?.o ) .dtors))
        PROVIDE_HIDDEN (__fini_array_end = .);
    }>ITCM
    .ctors          :
    {
        KEEP (*crtbegin.o(.ctors))
        KEEP (*crtbegin?.o(.ctors))
        KEEP (*(EXCLUDE_FILE (*crtend.o *crtend?.o ) .ctors))
        KEEP (*(SORT(.ctors.*)))
        KEEP (*(.ctors))
    }>ITCM
    .dtors          :
    {
        KEEP (*crtbegin.o(.dtors))
        KEEP (*crtbegin?.o(.dtors))
        KEEP (*(EXCLUDE_FILE (*crtend.o *crtend?.o ) .dtors))
        KEEP (*(SORT(.dtors.*)))
        KEEP (*(.dtors))
    }>ITCM

    .ARM.exidx :
    {
        PROVIDE_HIDDEN (__exidx_start = .);
        *(.ARM.exidx* .gnu.linkonce.armexidx.*)
        PROVIDE_HIDDEN (__exidx_end = .);
    } > ITCM

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

