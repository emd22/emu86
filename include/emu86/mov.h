#ifndef MOV_H
#define MOV_H

enum {
    I8_R8,
    I16_R16,

    R8_R8,
    R16_R16,
};

void e86_mov(int option, int src, int dest);

#endif