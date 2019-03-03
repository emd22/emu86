#include <emu86/registers.h>

#include <string.h>
#include <stdint.h>

e86_register_t registers[4];

int register_8_16(int reg) {
    if (reg == AL || reg == AH) return AX;
    if (reg == CL || reg == CH) return CX;
    if (reg == DL || reg == DH) return DX;
    if (reg == BL || reg == BH) return BX;
    return -1;
}

void registers_wipe(void) {
    memset(registers, 0, sizeof(registers));
}

uint16_t register_get_value(e86_register_t *reg) {
    return (reg->hi | reg->lo);
}

e86_register_t *register_get(int reg) {
    return &registers[reg];
}