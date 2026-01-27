
#ifndef COMMON_H
#define COMMON_H

#include <stdint.h>

//----------------------------------------------------------------
#define UART_HEADER_SIZE   2     
#define UART_MAX_DATA_SIZE 16
#define UART_MSG_WORDS     (UART_HEADER_SIZE + UART_MAX_DATA_SIZE)

//----------------------------------------------------------------
#define FREQ 12500000 // 12.5 Mbps
#define TWBUS 1.28     // us por word de 16 bits
#define TBBUS 0.640   // us por word de 16 bits
#define TG   0.01     // us decidido
#define TP   12       // us de RTT por esclavo
#define TG1  5        // us entre envio y envio de referencias
#define TWAIT 15      // us que espera la recepción del mensaje

//----------------------------------------------------------------
#define MAX_EVENTS 1024

//----------------------------------------------------------------
typedef uint8_t  byte;
typedef uint16_t word;




#endif