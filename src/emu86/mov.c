#include <emu86/mov.h>
#include <emu86/registers.h>

#include <stdint.h>
#include <stdio.h>

void mov_immediate_register(int option, int src, int dest) {
    e86_register_t *reg = register_get(register_8_16(dest));
    if (option == I8_R8) {
        if (dest > BL) {
            reg->hi = src;
        }
        else {
            reg->lo = src;
        }
    }
    else {
        reg->lo = (uint8_t)src;
        reg->hi = (uint8_t)(src << 8);

        printf("reglo: %d, hi: %d\n", reg->lo, reg->hi);
    }
}

void e86_mov(int option, int src, int dest) {
    switch (option) {
        case I8_R8:
        case I16_R16:
            mov_immediate_register(option, src, dest);
            break;
    }
}