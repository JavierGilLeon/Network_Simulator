
#include "board.h"
#include "event.h"
#include "stdlib.h"

DEVICE M;
DEVICE S1;
DEVICE S2;
DEVICE S3;

void InitBoards(void){
    M.ID  = MASTER;
    S1.ID = SLAVE1;
    S2.ID = SLAVE2;
    S3.ID = SLAVE3; 
}



// --------- PUNTO A PUNTO --------------------
void requestMeasure(double time, DEVICE* dst, MSG* msg){

    // ------- M pide medidas a S1  ---------
    addEvent(MSG_SENT, totalTime + TG, &M, dst);

    // ------ S1 recibe peticion y envia medidas -----------

    if((rand() % (10)) == 3)
        addEvent(MSG_LOST, totalTime + TG + TWAIT, &M, dst);
    else 
    {
        addEvent(MSG_RECEIVED, totalTime + TG + UART_HEADER_SIZE*TWBUS + TBBUS, &M, dst);

        addEvent(PROCESSING_MSG_END, totalTime + TP, dst, dst);
        addEvent(MSG_SENT, totalTime + TG, dst, &M);

        // ------ M recibe medidas ----------
        addEvent(MSG_RECEIVED, totalTime + (UART_HEADER_SIZE + msg->header.lenght)*TWBUS + TBBUS, dst, &M);
    }
}

void sendReferences(double time, DEVICE* dst, MSG* msg){
    addEvent(MSG_SENT, totalTime + TG + TG1, &M, dst);
}