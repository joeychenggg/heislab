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
int zero_order_matrix[N_FLOORS][N_BUTTONS];

int find_orders_above();
int find_orders_below();
int check_have_orders();
void order_matrix_logic();