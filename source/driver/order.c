#include <stdio.h>
#include "order.h"

/* void order_matrix_init() {
    for(int f = 0; f < N_FLOORS; f++) {
        for(int b = 0; b < N_BUTTONS; b++) {
            order_matrix[f][b] = NO_ORDER;
        }
    }
} */

int order_matrix[N_FLOORS][N_BUTTONS] = {{NO_ORDER}};

void find_new_order() {
    for(int f = 0; f < N_FLOORS; f++) {
        for(int b = 0; b < N_BUTTONS; b++) {
            int btnPressed = elevio_callButton(f, b);
            if (btnPressed && order_matrix[f][b] == NO_ORDER) {
                order_matrix[f][b] = ORDER;
                elevio_buttonLamp(f, b, btnPressed);
            }
        }
    }  
}

void print_order_matrix() {
    for(int f = 0; f < N_FLOORS; f++) {
        for(int b = 0; b < N_BUTTONS; b++) {
            printf("%d  ", order_matrix[f][b]);
        }
        printf("\n");
    }
}

void clear_order_matrix() {
    for(int f = 0; f < N_FLOORS; f++) {
        for(int b = 0; b < N_BUTTONS; b++) {
            order_matrix[f][b] = NO_ORDER;
            elevio_buttonLamp(f, b, NO_ORDER);
        }
    }
}

