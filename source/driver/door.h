#pragma once
#include <time.h>
#include "timer.h"


typedef enum {
    DOOR_CLOSED = 0,
    DOOR_OPEN   = 1
} DoorState;

DoorState door_state;

void door_open() {
    door_state = DOOR_OPEN;
    time_t start = time(NULL);
}

void door_close() {
    while(1) {
        time_t end = time(NULL);
        if(difftime(end, start) > 3) {
            door_state = DOOR_CLOSED;
            break;
        }
    }
}