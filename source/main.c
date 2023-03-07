#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
//#include <time.h>
// #include "driver/timer.h"
// #include "driver/elevio.h"
#include "driver/controller.h"
// #include "driver/stop_and_obstr.h"


int main(){
    
    elevio_init();
    // order_matrix_init();
    clear_order_matrix();
    elevio_floorIndicator(elevio_floorSensor());
    
    printf("=== Jstrid's Program ===\n");
    printf("Press the stop button on the elevator panel to exit\n");

    state = STILL;
    direction_state = UP;
    if (elevio_floorSensor() == -1) {
        elevio_motorDirection(DIRN_UP);
        state = MOVING;
        while (1) {
            if (elevio_floorSensor() != -1) {
                elevio_motorDirection(DIRN_STOP);
                state = STILL;
                break;
            }
        }
    }

    while(1){
        int floor = elevio_floorSensor();
        printf("floor: %d \n",floor);


        find_new_order(); // ideally a callback func instead of this
        print_order_matrix();
        printf("direction: %d \n",direction_state);
        order_matrix_logic();

        nanosleep(&(struct timespec){0, 20*1000*1000}, NULL);
    }

    // clear_order_matrix();

    return 0;
}
