
#include "event.h"
#include "board.h"

int numEvents = 0;         // Eventos restantes 
EVENT evQueue[MAX_EVENTS]; // Cola de eventos

double totalTime = 0;
FILE* fileLog;
FILE* fileCSV;

void handleEvent(EVENT e){
    switch (e.type)
    {
    case MSG_SENT:
        fprintf(fileCSV,"%lu %lu %lf\n",e.src,e.dst,e.time);
        fprintf(fileLog,"%lu envia un mensaje hacia %lu en t = %lf us\n", e.src, e.dst, e.time);

        printf("%lu envia un mensaje hacia %lu en t = %lf us\n", e.src, e.dst, e.time);
        break;

    case TX_END:
        fprintf(fileCSV,"%lu %lu %lf\n", e.src, e.dst, e.time);
        fprintf(fileLog,"%lu ha terminado de enviar un mensaje hacia %lu en t = %lf us\n", e.src, e.dst, e.time);

        printf("%lu ha terminado de enviar un mensaje hacia %lu en t = %lf us\n", e.src, e.dst, e.time);
        break;

    case MSG_RECEIVED:
        fprintf(fileCSV, "%lu %lu %lf\n", e.dst, e.src, e.time);
        fprintf(fileLog,"%lu ha recibido un mensaje proveniente de %lu en t = %lf us\n", e.dst, e.src, e.time);

        printf("%lu ha recibido un mensaje proveniente de %lu en t = %lf us\n", e.dst, e.src, e.time);
        break;

    case PROCESSING_END:
        fprintf(fileCSV, "%lu %lu %lf\n", e.src, e.dst, e.time);
        fprintf(fileLog,"%lu ha terminado de procesar un mensaje en t = %lf us\n", e.src, e.time);

        printf("%lu ha terminado de procesar un mensaje en t = %lf us\n", e.src, e.time);
        break;
    
    default:
        break;
    }

    numEvents--;
}
void addEvent(EVENT_TYPE type, double time, unsigned long int src, unsigned long int dst){

    EVENT event;

    DEVICE* src_dev = (DEVICE *)src;
    DEVICE* dst_dev = (DEVICE *)dst;

    event.type = type;
    event.time = time;
    event.src  = src;
    event.dst  = dst;

    evQueue[numEvents] = event;

    numEvents++;
    totalTime = time;
}
