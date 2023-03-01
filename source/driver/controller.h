#pragma once
#include "order.h"

typedef enum {
    DOWN  = 0,
    UP    = 1
} DirectionState;

typedef enum {
    STILL  = 0,
    MOVING = 1
} State;

DirectionState direction_state;
State state;
int target_floor;
int zero_order_matrix[N_FLOORS][N_BUTTONS] = {{NO_ORDER}};

int find_orders_above();
int find_orders_below();
void order_matrix_logic();