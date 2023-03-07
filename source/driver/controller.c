#include "controller.h"

int zero_order_matrix[N_FLOORS][N_BUTTONS] = {{NO_ORDER}};

int find_orders_above() {
    int button_precedence[N_BUTTONS] = {0, 2, 1};
    for(int f = elevio_floorSensor() + 1; f < N_FLOORS; f++) {
        for(int i = 0; i < N_BUTTONS; i++) {
            int b = button_precedence[i];
            if(order_matrix[f][b] == ORDER) {
                target_floor = f;
                elevio_motorDirection(DIRN_UP);
                state = MOVING;
                while (1) {
                    find_new_order();
                    print_order_matrix();
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
    int button_precedence[N_BUTTONS] = {1, 2, 0};
    for(int f = elevio_floorSensor() - 1; f > -1; f--) {
        for(int i = 0; i < N_BUTTONS; i++) {
            int b = button_precedence[i];
            if(order_matrix[f][b] == ORDER) {
                target_floor = f;
                elevio_motorDirection(DIRN_DOWN);
                state = MOVING;
                while (1) {
                    find_new_order();
                    print_order_matrix();
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

int check_have_orders() {
    for(int f = 0; f < N_FLOORS; f++) {
        for(int b = 0; b < N_BUTTONS; b++) {
            if (order_matrix[f][b] != zero_order_matrix[f][b]) {
                return 1;
            }
        }
    }
    return 0;
}

void order_matrix_logic() {
    if (state == STILL && check_have_orders()) { // and we have orders in the order_matrix, and direction_state != NO_DIRECTION
        while (1) {
            if((direction_state == UP && elevio_floorSensor() != 3) || (elevio_floorSensor() == 0)) {
                direction_state = UP;
                if (find_orders_above()) {
                    return;
                } else {
                    direction_state = DOWN;
                }

            } else if ((direction_state == DOWN && elevio_floorSensor() != 0) || (elevio_floorSensor() == 3)) {
                direction_state = DOWN;
                if (find_orders_below()) {
                    return;
                } else {
                    direction_state = UP;
                }
            }
        }
    }
}