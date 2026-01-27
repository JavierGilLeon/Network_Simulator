
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
typedef enum device_name{
    MASTER = 0,
    SLAVE1 = 1,
    SLAVE2 = 2,
    SLAVE3 = 3
}DEVICE_NAME;

typedef struct device{
    DEVICE_NAME ID;
    int src;
    int dst;
} DEVICE;


extern DEVICE M;
extern DEVICE S1;
extern DEVICE S2;
extern DEVICE S3;


void InitBoards(void);
void requestMeasure(double time, DEVICE* dst, MSG* msg);
void sendReferences(double time, DEVICE* dst, MSG* msg);
#endif