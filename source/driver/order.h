#pragma once
#include "elevio.h"


#define N_DOOR_STATES 2

typedef enum {
    DOOR_CLOSED   = 0,
    DOOR_OPEN     = 1
} DoorState;

typedef enum {
    NO_ORDER = 0,
    ORDER    = 1
} OrderState;

int order_matrix[N_FLOORS][N_BUTTONS];

void order_matrix_init();
void new_order();
void print_order_matrix();