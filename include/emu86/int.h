#ifndef INT_H
#define INT_H

#define INTERRUPT_VIDEO 0x10
#define INTERRUPT_DISK  0x13

void e86_interrupt(int interrupt);

#endif