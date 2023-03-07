/* #include "stop_and_obstr.h"

void check_obstr() {
    if(elevio_obstruction()) {
        elevio_stopLamp(1);
    } else {
        elevio_stopLamp(0);
    }
}

void init_stop_mode() {
    if(elevio_stopButton()) {
        elevio_motorDirection(DIRN_STOP);
        state = STILL;
        clear_order_matrix();
        elevio_stopLamp(1);

        if(elevio_floorSensor() != -1) {
            door_open();
        }

        while(elevio_stopButton()) {

        }
        door_state = DOOR_CLOSED;
        elevio_doorOpenLamp(door_state);
    }
}
 */
