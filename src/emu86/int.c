#include <emu86/int.h>
#include <emu86/registers.h>

#include <stdio.h>
#include <string.h>

void e86_interrupt(int interrupt) {
    e86_register_t *reg;
    switch (interrupt) {
        case INTERRUPT_VIDEO:
            reg = register_get(AX);
            switch (reg->hi) {
                case 0x0E:
                    printf("%c", reg->lo);
                    fflush(stdout);
                    break;
            }
            break;
    }
}