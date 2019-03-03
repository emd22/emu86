#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

#include <emu86/mov.h>
#include <emu86/int.h>
#include <emu86/registers.h>
#include <emu86/device/disk.h>

char *fdata;

void exit_emu(int sig) {
    printf("exitting emulation...\n");

    disk_cleanup();
    free(fdata);
    
    exit(1);
}

int main() {
    unsigned long fsize = disk_init("../test.bin");
    fdata = disk_read(0, 1);
    if (fdata == NULL) {
        printf("Cannot load initial sector\n");
        return 1;
    }

    signal(SIGINT, exit_emu);

    registers_wipe();

    unsigned long i;
    unsigned char ch;
    for (i = 0; i < fsize; i++) {
        ch = fdata[i];
        if (ch >= 0xB0 && ch <= 0xB7) {
            e86_mov(I8_R8, fdata[++i], ch-0xB0);
            continue;
        }
        else if (ch == 0xCD) {
            e86_interrupt(fdata[++i]);
            continue;
        }
        else if (ch == 0xFA) {
            continue;
        }
        else if (ch == 0xF4) {
            while (1);
        }
        else {
            printf("cpu error: triple fault\n");
            break;
        }
    }

    exit_emu(0);

    return 0;
}