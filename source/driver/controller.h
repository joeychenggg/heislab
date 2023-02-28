#pragma once
#include "order.h"
#include "elevio.h"

typedef enum {
    NO_DIRECTION = -1,
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

void order_matrix_logic() {
    int floor = elevio_floorSensor();
    if (state == STILL) { // and we have orders in the order_matrix, and direction_state != NO_DIRECTION
        if(direction_state == UP && floor != 3) {
            for(int f = floor + 1; f < N_FLOORS; f++) {
                for(int b = 0; b < N_BUTTONS; b += 2) {
                    if(order_matrix[f][b] == ORDER) {
                        target_floor = f;
                        return;       
                    }
                }
            }
        } else if (direction_state == DOWN && floor != 0) {
            for(int f = floor - 1; f > -1; f--) {
                for(int b = 0; b < N_BUTTONS; b += 2) {
                    if(order_matrix[f][b] == ORDER) {
                        target_floor = f;
                        return;   
                    }
                }
            }
        } /* else if (direction_state == NO_DIRECTION) {} */

        if(direction_state == UP) {
            direction_state = DOWN;
        } else if (direction_state == DOWN) {
            direction_state = UP;
        }



    }
}