#ifndef REGISTERS_H
#define REGISTERS_H

#include <stdint.h>
 
enum {
    AL,
    CL, 
    DL,
    BL,
    AH,
    CH,
    DH,
    BH
};

enum {
    AX,
    CX,
    DX,
    BX,
    SP,
    BP,
    SI,
    DI
};

typedef struct {
    uint8_t lo;
    uint8_t hi;
} e86_register_t;

void registers_wipe(void);
uint16_t register_get_value(e86_register_t *reg);
e86_register_t *register_get(int reg);
int register_8_16(int reg);

#endif