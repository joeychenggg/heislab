#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include "driver/elevio.h"
#include "driver/order.h"
#include "driver/controller.h"



int main(){
    
    elevio_init();

    order_matrix_init();
    
    printf("=== Example Program ===\n");
    printf("Press the stop button on the elevator panel to exit\n");

    elevio_motorDirection(DIRN_UP);
    direction_state = UP;
    state = MOVING;
    

    while(1){
        int floor = elevio_floorSensor();
        printf("floor: %d \n",floor);

        if(floor == 0){
            elevio_motorDirection(DIRN_UP);
            direction_state = UP;
            state = MOVING;
        }

        if(floor == N_FLOORS-1){
            elevio_motorDirection(DIRN_DOWN);
            direction_state = DOWN;
            state = MOVING;
        }

/*         for(int f = 0; f < N_FLOORS; f++){
            for(int b = 0; b < N_BUTTONS; b++){
                int btnPressed = elevio_callButton(f, b);
                elevio_buttonLamp(f, b, btnPressed);
            }
        }
 */

        new_order();
        print_order_matrix();

        if(elevio_obstruction()){
            elevio_stopLamp(1);
        } else {
            elevio_stopLamp(0);
        }
        
        if(elevio_stopButton()){
            elevio_motorDirection(DIRN_STOP);
            direction_state = NO_DIRECTION;
            state = STILL;
            break;
        }

        
        nanosleep(&(struct timespec){0, 20*1000*1000}, NULL);
    }

    clear_order_matrix();

    return 0;
}
