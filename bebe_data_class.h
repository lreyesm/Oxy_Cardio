#ifndef BEBE_DATA_CLASS_H
#define BEBE_DATA_CLASS_H

#include <QString>
#include <QDataStream>
#include <QDate>
#include <QTime>

#ifndef DATA_FUNCTION_SIZE
#include "globals.h"
#endif


class Bebe_Data_Class
{
public:
    Bebe_Data_Class(QString b="unknow",QString m= "unknow");

    void operator_equal(Bebe_Data_Class);
    bool is_equal(Bebe_Data_Class);
    /*
    QDataStream& operator <<(Bebe_Data_Class);
    QDataStream& operator >>(Bebe_Data_Class);
    */
    void write_file(QDataStream &);
    void read_file(QDataStream &);

    void print_bebe_data();

    quint64 ID;
    QString baby_name;
    QString mother_name;
    QString sexo;
    quint32 cantidad_de_pruebas;
    QString state;
    QDate birth_date;
    QDate date;
    QTime time;
    quint8 SPO2_bebe_value_average_OXY1;
    quint8 SPO2_bebe_value_average_OXY2;
    qint16 beats_per_minute_value_average_OXY1;
    qint16 beats_per_minute_value_average_OXY2;
    quint16 PI_value_average_OXY1;
    quint16 PI_value_average_OXY2;
    quint8 SPO2_function_OXY1_data_bebe[SPO2_FUNCTION_BUFFER_SIZE];
    quint8 SPO2_function_OXY2_data_bebe[SPO2_FUNCTION_BUFFER_SIZE];
    quint16 BPM_function_OXY1_data_bebe[SPO2_FUNCTION_BUFFER_SIZE];
    quint16 BPM_function_OXY2_data_bebe[SPO2_FUNCTION_BUFFER_SIZE];
    quint16 PI_function_OXY1_data_bebe[SPO2_FUNCTION_BUFFER_SIZE];
    quint16 PI_function_OXY2_data_bebe[SPO2_FUNCTION_BUFFER_SIZE];

    quint8 function_0_data_bebe[DATA_FUNCTION_SIZE];
    quint8 function_1_data_bebe[DATA_FUNCTION_SIZE];
    quint8 HR_data_bebe[DATA_ADC_BUFFER_SIZE];
    int data_function_size;
    int data_adc_buffer_size;
    int SPO2_data_function_OXY1_size;
    int SPO2_data_function_OXY2_size;
    int BPM_data_function_OXY1_size;
    int BPM_data_function_OXY2_size;
    int PI_data_function_OXY1_size;
    int PI_data_function_OXY2_size;
};



#endif // BEBE_DATA_CLASS_H
