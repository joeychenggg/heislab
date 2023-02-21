#pragma once
#include "elevio.h"


#define N_DOOR_STATES 2

typedef enum {
    DOOR_CLOSED   = 0,
    DOOR_OPEN     = 1
} DoorState;

typedef enum {
    NOT_PRESSED = -1,
    FLOOR_0   = 0,
    FLOOR_1   = 1,
    FLOOR_2   = 2,
    FLOOR_3   = 3
} ButtonCab;

struct Order {
    int floor;
    ButtonType b;
    ButtonCab bc = NOT_PRESSED;
};


Order order_queue[]; // Array or not? Try to make an order.