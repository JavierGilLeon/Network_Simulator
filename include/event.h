#ifndef EVENT_H
#define EVENT_H


#define FOREACH_EVENT(EVENT)      \
        EVENT(MSG_SENT)           \
        EVENT(TX_END)             \
        EVENT(MSG_RECEIVED)       \
        EVENT(PROCESSING_END) \
        EVENT(MSG_LOST)           \
        EVENT(NUM_EVENTS)         \

#define GENERATE_ENUM(ENUM) ENUM, 
#define GENERATE_STRING(STRING) #STRING,

#include <stdio.h>
#include "common.h"



typedef enum event_type{
    FOREACH_EVENT(GENERATE_ENUM)
} EVENT_TYPE;

static const char* event_string[] = {
    FOREACH_EVENT(GENERATE_STRING)
};


typedef struct event{
    EVENT_TYPE         type;
    double             time;
    unsigned long int  src;
    unsigned long int  dst;
} EVENT;


extern double totalTime;
extern int numEvents;
extern EVENT evQueue[MAX_EVENTS]; 
extern FILE* fileLog;
extern FILE* fileCSV;


void handleEvent(EVENT event);
void addEvent(EVENT_TYPE type, double time, unsigned long int src, unsigned long int dst);

#endif