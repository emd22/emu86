.code16
.text
.globl _start

_start:
    mov $0x0E, %ah
    mov $65, %al
    int $0x10

    cli
    hlt