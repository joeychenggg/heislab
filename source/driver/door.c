#include "door.h"

time_t door_open() {
    door_state = DOOR_OPEN;
    elevio_doorOpenLamp(door_state);
    return time(NULL);
}

void door_close(time_t start) {
    while(1) {
        time_t end = time(NULL);
        printf("time open: %f \n",difftime(end, start));
        if(difftime(end, start) > 3) {
            door_state = DOOR_CLOSED;
            elevio_doorOpenLamp(door_state);
            break;
        }
    }
}