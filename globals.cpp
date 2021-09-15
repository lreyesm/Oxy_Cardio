#include "globals.h"

quint8 SPO2_function_values_graph_OXY1[SPO2_FUNCTION_BUFFER_SIZE];
quint8 SPO2_function_values_graph_OXY2[SPO2_FUNCTION_BUFFER_SIZE];
quint8 function_values_graph_0[DATA_FUNCTION_SIZE];
quint8 function_values_graph_1[DATA_FUNCTION_SIZE];
quint8 function_values_graph_HR[DATA_ADC_BUFFER_SIZE];
quint32 function_value_pos =0;
quint32 HR_value_pos=0;
quint32 function_value_count=0;
quint32 HR_value_count=0;
quint32 SPO2_function_value_pos_OXY1=0;
quint32 SPO2_function_value_pos_OXY2=0;

quint8 receive_bytes[UART_SEND_TOTAL_SIZE*10];
quint32 x_axis_count=0;
//QCustomPlot *customPlot;
bool first_buffer;
