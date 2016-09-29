#include "vchan_logging_interface.h"
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>

void handle_SIGINT(int unused)
{
    // On CTRL+C - close vchan
    printf("\nBye!\n");
    vchan_close();
    exit(0);
}

int main(int argc, char **argv) {
    uint8_t gidl[80];

    // Catch CTRL+C (SIGINT) signals //
    signal(SIGINT, handle_SIGINT);
    
    vchan_init();
    while (1) {
        int i;
        receive_gidl(gidl);
        printf("Received gidl message:");
        for (i = 0; i < 80; i++) {
            if (i % 20 == 0) {
                printf("\n  ");
            }
            printf("%02x ", gidl[i]);
        }
        printf("\n\n");
    }
}
