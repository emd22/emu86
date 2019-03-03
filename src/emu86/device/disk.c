#include <emu86/device/disk.h>

#include <stdio.h>
#include <stdlib.h>

#define SECTOR_SIZE 512

unsigned long fsize;
FILE *fp = NULL;

unsigned long disk_init(const char *filename) {
    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Could not find file %s\n", filename);
        exit(1);
    }
    fseek(fp, 0, SEEK_END);
    fsize = ftell(fp);
    rewind(fp);
    return fsize;
}

unsigned get_fsize_blocks(void) {
    unsigned blocks = fsize/512;
    if (fsize % 512)
        blocks++;
    
    return blocks;
}

char *disk_read(unsigned lba, unsigned amt_sectors) {
    if (fp == NULL)
        return NULL;

    if ((lba+amt_sectors) > get_fsize_blocks())
        return NULL;

    char *block = malloc(amt_sectors*SECTOR_SIZE);
    fseek(fp, lba*SECTOR_SIZE, SEEK_SET);
    fread(block, 1, amt_sectors*SECTOR_SIZE, fp);

    return block;
}

void disk_cleanup(void) {
    free(fp);
}