#ifndef EVENT_H
#define EVENT_H

#include <stdio.h>
#include "common.h"



typedef enum event_type{
    MSG_SENT             = 0,
    TX_END               = 1,
    MSG_RECEIVED         = 2,
    PROCESSING_MSG_END   = 3
} EVENT_TYPE;


typedef struct event{
    EVENT_TYPE type;
    double     time;
    int        src;
    int        dst;
} EVENT;


extern double totalTime;
extern int numEvents;
extern EVENT evQueue[MAX_EVENTS]; 


void handleEvent(EVENT event);
void addEvent(EVENT_TYPE type, double time, void* src, void* dst);

#endif