#include "controller.h"


int find_orders_above() {
    for(int f = elevio_floorSensor() + 1; f < N_FLOORS; f++) {
        for(int b = 0; b < N_BUTTONS; b += 2) {
            if(order_matrix[f][b] == ORDER) {
                target_floor = f;
                elevio_motorDirection(DIRN_UP);
                state = MOVING;
                while (1) {
                    if (target_floor == elevio_floorSensor()) {
                        elevio_motorDirection(DIRN_STOP);
                        state = STILL;
                        target_floor = -1;
                        order_matrix[f][b] = NO_ORDER;
                        break;
                    }
                }
                return target_floor;    
            }
        }
    }  
    return 0;
}

int find_orders_below() {
    for(int f = elevio_floorSensor() - 1; f > -1; f--) {
        for(int b = 0; b < N_BUTTONS; b += 2) {
            if(order_matrix[f][b] == ORDER) {
                target_floor = f;
                elevio_motorDirection(DIRN_DOWN);
                state = MOVING;
                while (1) {
                    if (target_floor == elevio_floorSensor()) {
                        elevio_motorDirection(DIRN_STOP);
                        state = STILL;
                        target_floor = -1;
                        order_matrix[f][b] = NO_ORDER;
                        break;
                    }
                }
                return target_floor;    
            }
        }
    }
    return 0;
}

void order_matrix_logic() {
    if (state == STILL && order_matrix != zero_order_matrix) { // and we have orders in the order_matrix, and direction_state != NO_DIRECTION
        while (1) {
            if(direction_state == UP && elevio_floorSensor() != 3) {
                if (find_orders_above()) {
                    return;
                } else {
                    direction_state = DOWN;
                }

            } else if (direction_state == DOWN && elevio_floorSensor() != 0) {
                if (find_orders_below()) {
                    return;
                } else {
                    direction_state = UP;
                }
            }
        }
    }
}