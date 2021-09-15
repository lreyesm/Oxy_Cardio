#ifndef GLOBALS_H
#define GLOBALS_H

#include <QtCore>
#include "qcustomplot.h"

#define FUNCTION_BUFFER_SIZE 25
#define FUNCTION_BUFFER_STORAGE_SIZE FUNCTION_BUFFER_SIZE*4

#define ADC_BUFFER_SIZE 100
#define ADC_BUFFER_STORAGE_SIZE ADC_BUFFER_SIZE*4
#define TIMER_TIMEOUT_ADC_READ 4 ////en milisegundos

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define HEADER_ID 0x0FA
//#define TAIL_ID 0x0FA
#define HEADER_START_POS 0
//#define TAIL_START_POS 162
#define HEADER_SIZE 2
//#define TAIL_SIZE 2
#define CHECK_SUM_SIZE 4 //32bits

#define DATA_INIT_BUFFER_POS HEADER_START_POS + HEADER_SIZE  //2
//#define DATA_INIT_BUFFER_ID 0x09B
#define DATA_BUFFER_TRANSMIT_0 0x011
#define DATA_BUFFER_TRANSMIT_1 0x022
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define OXYMETER_1  1 //UART2
#define OXYMETER_2  2 //UART3
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define SPO2_BUFFER_OXY1_POS DATA_INIT_BUFFER_POS //2
#define BPM_BUFFER_OXY1_POS SPO2_BUFFER_OXY1_POS+1 //3
#define PI_BUFFER_OXY1_POS SPO2_BUFFER_OXY1_POS+3 //5
#define SPO2_BUFFER_OXY2_POS PI_BUFFER_OXY1_POS+2 //7
#define BPM_BUFFER_OXY2_POS SPO2_BUFFER_OXY2_POS+1 //8
#define PI_BUFFER_OXY2_POS SPO2_BUFFER_OXY2_POS+3 //10

#define DATA_GRAPH_HR_INIT_BUFFER_POS DATA_INIT_BUFFER_POS+10 //12
#define DATA_GRAPH_FT_INIT_BUFFER_POS DATA_GRAPH_HR_INIT_BUFFER_POS + ADC_BUFFER_SIZE //110
#define DATA_GRAPH_FT_2_INIT_BUFFER_POS DATA_GRAPH_FT_INIT_BUFFER_POS+FUNCTION_BUFFER_SIZE //135

#define INIT_PROG_ID 0x0AA   ////Inicio de Programa
#define INIT_SEND_ID 0x0FE  ////Inicio de Envio de informacion
#define ERROR_ID 0x0F  ////Envio de Error de recivo

//#define HEADER_END_POS 160

//#define CURRENT_OXYMETER_OXY1_POS DATA_INIT_BUFFER_POS+1 //3
#define STATUS_CHECK_OXY1_POS DATA_GRAPH_FT_2_INIT_BUFFER_POS+FUNCTION_BUFFER_SIZE //162
#define STATUS_CHECK_OXY2_POS STATUS_CHECK_OXY1_POS+1 //163
//#define CURRENT_OXYMETER_OXY2_POS DATA_GRAPH_FT_INIT_BUFFER_POS+(FUNCTION_BUFFER_SIZE*2) //160
//#define SPO2_BUFFER_OXY2_POS CURRENT_OXYMETER_OXY2_POS //160

#define UART_SEND_BUFFER_SIZE STATUS_CHECK_OXY2_POS + 1 //164
#define UART_SEND_TOTAL_SIZE UART_SEND_BUFFER_SIZE + CHECK_SUM_SIZE //168
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#define MAX_TIME_RECORDING 20////en segundos (solo valores pares)
#define DATA_FUNCTION_SIZE  (int)(FUNCTION_BUFFER_SIZE*MAX_TIME_RECORDING*2.5)  ////FUNCTION_BUFFER_SIZE * 150
#define DATA_ADC_BUFFER_SIZE  (int)(ADC_BUFFER_SIZE*MAX_TIME_RECORDING*2.5)  ////
#define SPO2_TIME_RECORDING 20 //en segundos
#define SPO2_FUNCTION_BUFFER_SIZE int(SPO2_TIME_RECORDING*2.5)


//extern const quint8 function_values_size = FUNCTION_BUFFER_SIZE;
extern quint8 SPO2_function_values_graph_OXY1[SPO2_FUNCTION_BUFFER_SIZE];
extern quint8 SPO2_function_values_graph_OXY2[SPO2_FUNCTION_BUFFER_SIZE];
extern quint8 function_values_graph_0[DATA_FUNCTION_SIZE];
extern quint8 function_values_graph_1[DATA_FUNCTION_SIZE];
extern quint8 function_values_graph_HR[DATA_ADC_BUFFER_SIZE];
extern quint32 function_value_pos;
extern quint32 SPO2_function_value_pos_OXY1;
extern quint32 SPO2_function_value_pos_OXY2;
extern quint32 HR_value_pos;

extern quint32 function_value_count;
extern quint32 HR_value_count;

extern quint8 receive_bytes[UART_SEND_TOTAL_SIZE*10];
extern quint32 x_axis_count;
//extern QCustomPlot *customPlot;
extern bool first_buffer;


#endif // GLOBALS_H
