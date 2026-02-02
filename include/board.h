
#ifndef BOARD_H
#define BOARD_H

#include "common.h"

// -------------- MENSAJES -----------------------
typedef struct header{
    byte action;
    byte id;
    byte crc;
    byte lenght;
}HEADER;

typedef struct msg{
    HEADER header;
    word data[UART_MAX_DATA_SIZE];
}MSG;


 // ----------- DECLARACION DE LAS PLACAS SIMULADAS -----------------

typedef struct device{
    long unsigned int ID;
    int src;
    int dst;
} DEVICE;


extern DEVICE M;
extern DEVICE S1;
extern DEVICE S2;
extern DEVICE S3;


void requestMeasure(unsigned long int dst);
void sendReferences(DEVICE* dst);

void CommActiveWait(unsigned long int numSlaves);
void CommActiveWaitBroadcast(unsigned long int numSlaves);
#endif