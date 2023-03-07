#pragma once
#include <stdio.h>
#include <time.h>
#include "elevio.h"

typedef enum {
    DOOR_CLOSED = 0,
    DOOR_OPEN   = 1
} DoorState;

DoorState door_state;

time_t door_open();

void door_close(time_t start);