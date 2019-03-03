#ifndef DISK_H
#define DISK_H

unsigned long disk_init(const char *filename);
char *disk_read(unsigned lba, unsigned amt_sectors);
void disk_cleanup(void);

#endif