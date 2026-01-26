
#include "event.h"
#include "board.h"

int numEvents = 0;         // Eventos restantes 
EVENT evQueue[MAX_EVENTS]; // Cola de eventos

double totalTime = 0;

void handleEvent(EVENT e){

    switch (e.type)
    {
    case MSG_SENT:
        printf("%d envia un mensaje hacia %d en t = %lf us\n", e.src, e.dst, e.time);
        break;

    case TX_END:
        printf("%d ha terminado de enviar un mensaje hacia %d en t = %lf us\n", e.src, e.dst, e.time);
        break;

    case MSG_RECEIVED:
        printf("%d ha recibido un mensaje proveniente de %d en t = %lf us\n", e.dst, e.src, e.time);
        break;

    case PROCESSING_MSG_END:
        printf("%d ha terminado de procesar un mensaje en t = %lf us\n", e.src, e.time);
        break;
    
    case MSG_LOST:
        printf("Ha vencido el timer de %d sin que llegue el mensaje, t = %lf us\n",e.dst,e.time);
    
    default:
        break;
    }


    numEvents--;
}
void addEvent(EVENT_TYPE type, double time, void* src, void* dst){

    EVENT event;

    DEVICE* src_dev = (DEVICE *)src;
    DEVICE* dst_dev = (DEVICE *)dst;

    event.type = type;
    event.time = time;
    event.src  = src_dev->ID;
    event.dst  = dst_dev->ID;

    evQueue[numEvents] = event;

    numEvents++;
    totalTime = time;
}
