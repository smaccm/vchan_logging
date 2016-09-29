/*
 * Copyright 2014, NICTA
 *
 * This software may be distributed and modified according to the terms of
 * the GNU General Public License version 2. Note that NO WARRANTY is provided.
 * See "LICENSE_GPLv2.txt" for details.
 *
 * @TAG(NICTA_GPL)
 */

#include "includes/vmm_manager.h"
#include "includes/vchan_copy.h"
#include "includes/libvchan.h"

#include <sys/ioctl.h>
#include <string.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/mman.h>
#include <stdint.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <time.h>
#include <stdint.h>

static libvchan_t *connection;

int receive_gidl(uint8_t* gidl) {
    libvchan_wait(connection);
    libvchan_read(connection, gidl, 80);
    return 0;
}

int vchan_init(void){
    printf("vchan: Creating connection image\n");
    connection = libvchan_client_init(50, 25);
    assert(connection != NULL);
    printf("vchan: Connection Established!\n");

    return 0;
}

void vchan_close(void){
    libvchan_close(connection);
}

