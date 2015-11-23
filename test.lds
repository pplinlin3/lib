ENTRY(main)

SECTIONS
{
    . = 0x08048000 + SIZEOF_HEADERR
    
    tinytext  : { *(.text) *(.data) *(.rodata) }

    /DISCARD/ : { *(.comment) }
}
