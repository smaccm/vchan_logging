#ifndef _VCHAN_LOGGING_INTERFACE_H
#define _VCHAN_LOGGING_INTERFACE_H 

#include <stdint.h>

int vchan_init(void);
void vchan_close(void);
int receive_gidl(uint8_t* gidl);

#endif

