
#include "board.h"
#include "event.h"

DEVICE M;
DEVICE S1;
DEVICE S2;
DEVICE S3;




void requestMeasure(unsigned long int dst){

    // ------- M pide medidas a S1  ---------
    addEvent(MSG_SENT, totalTime + TG, M.ID, dst);

    // ------ S1 recibe peticion y envia medidas -----------

    addEvent(MSG_RECEIVED, totalTime + TG + UART_HEADER_SIZE*TWBUS + TBBUS, M.ID, dst);

    addEvent(PROCESSING_END, totalTime + TP, dst, dst);
    addEvent(MSG_SENT, totalTime + TG, dst, M.ID);

    // ------ M recibe medidas ----------
    addEvent(MSG_RECEIVED, totalTime + (UART_HEADER_SIZE + UART_MAX_DATA_SIZE)*TWBUS + TBBUS, dst, M.ID);
}


// Comunicacion pregunta-respuesta con espera activa sobre bus RS485
void CommActiveWait(unsigned long int numSlaves){

    for(unsigned long int i = 1; i <= numSlaves; i++)
    {
        requestMeasure(i);
    }


    for(unsigned long int i = 1; i <= numSlaves; i++)
    {
        addEvent(MSG_SENT, totalTime + TG + TG1, M.ID, i);
    } 
}

// Comunicacion pregunta-respuesta con espera activa y difusion broadcast sobre bus RS485
void CommActiveWaitBroadcast(unsigned long int numSlaves){

    for(unsigned long int i = 1; i <= numSlaves; i++)
    {
        requestMeasure(i);
    }

    DEVICE all_slaves;
    all_slaves.ID = 5;
    addEvent(MSG_SENT, totalTime + TG, M.ID, all_slaves.ID);
}

// Comunicacion pregunta-respuesta sin espera activa sobre bus RS485

void CommNoActiveWait(unsigned long int numSlaves){


}

// Comunicacion