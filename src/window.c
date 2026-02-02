#include "raylib.h"
#include "window.h"
#include "event.h"


void DrawGUI(void){

}

void DrawEvents(Rectangle* list, Rectangle ev[NUM_EVENTS - 1]){
    for(EVENT_TYPE i = 0; i < NUM_EVENTS; i++)
    {
        ev[i].width = list->width - 2*20;
        ev[i].height = 50;

        ev[i].x = list->x + 20;

        if(i) ev[i].y = (list->y + 20) + (ev[i-1].y + ev[i-i].height);
        else  ev[i].y =  list->y + 20;
    }

}