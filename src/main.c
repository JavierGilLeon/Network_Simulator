#include <stdio.h>

#include "common.h"
#include "board.h"
#include "event.h"

int main(int argc, char* argv[])
{

    InitBoards();

    MSG msg1;
    MSG msg2;
    MSG msg3;

    msg1.header.lenght = UART_MAX_DATA_SIZE;
    msg2.header.lenght = UART_MAX_DATA_SIZE;
    msg3.header.lenght = UART_MAX_DATA_SIZE;

    requestMeasure(totalTime, &S1, &msg1);
    requestMeasure(totalTime, &S2, &msg2);
    requestMeasure(totalTime, &S3, &msg3);

    sendReferences(totalTime, &S1, &msg1);
    sendReferences(totalTime, &S2, &msg2);
    sendReferences(totalTime, &S3, &msg3);


    printf("---------------------\n");
    int i = numEvents;
    while(numEvents > 0)
    {
        handleEvent(evQueue[i - numEvents]);
        printf("---------------------\n");
    }

    return 0;
}