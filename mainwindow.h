#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QtMultimedia/QSound>
#include "bebe_data_class.h"
#include "mythread_graph.h"

#define POS_Y_WINDOW_BUTTONS 80
#define POS_X_WINDOW_BUTTONS 750

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    void setupGraph();
    void setupGraph_Bar();
    void setupGraph_HR();

    void window_appearence();
    void hide_all_objects();
    void show_pacient_window();
    void show_graph_window();
    void show_config_window();

    ~MainWindow();

    void protocol_shake_hands();
    void inq_calculating_sensitivity();
    void inq_measurant_mode();
    void inq_system_self_test();
    void inq_type_version_No();
    void set_calculating_sensivity();
    void set_measurement_mode();

    quint8 calculate_check_sum();

    bool is_protocol_shake_hands();
    bool is_inq_calculating_sensitivity();
    bool is_inq_measurant_mode();
    bool is_inq_system_self_test();
    bool is_inq_type_version_No();
    bool is_set_calculating_sensivity();
    bool is_set_measurement_mode();
    bool is_pulse_rate_data();
    bool is_SPO2_data();
    bool is_real_time_display_data();

    bool is_check_sum_ok();

    void send_config_commands();
    void send_trash_bytes();

    void reiniciar_graficas();

public slots:
    void afterUpdateGraph();


private slots:
    void readSerial();
    void on_time_out();


    void on_pbIniciar_clicked();

    void on_pb_shake_hands_clicked();

    void on_pb_cal_sen_clicked();

    void on_pb_mea_mode_clicked();

    void on_pb_self_test_clicked();

    void on_pb_type_ver_clicked();

    void on_pb_set_cal_sen_clicked();

    void on_pb_set_mea_mode_clicked();



    void on_pbGuardar_clicked();

    void on_pbBase_de_datos_clicked();

    void on_lw_baby_list_itemClicked(QListWidgetItem *item);

    void on_pbAceptar_clicked();

    void on_le_name_mother_textChanged(const QString &arg1);

    void on_pbDetener_clicked();

    void on_pbVer_Registro_clicked();

    //void on_pb_change_window_clicked();

    void on_pb_window_pacient_clicked();

    void on_pb_window_graph_clicked();

    void on_pb_window_config_clicked();

    void on_actionAbout_Oximeter_triggered();

    void on_actionAbout_QtCreator_triggered();

    void on_pushButton_clicked();

    void on_pb_stop_play_graph_clicked();

    void on_pb_generar_reporte_clicked();

private:
    Ui::MainWindow *ui;
    QSound *beat_sound;
    QTimer *timer;
    bool timer_tick;
    bool recording_activated;
    Bebe_Data_Class bebe_object;
    bool ver_registro_activated;
    quint64 ver_registro_counter;

    QSerialPort *ftdi_serial_port;
    bool signal_ready_read_connected;
    QByteArray data;
    QFile *data_base;
    QStringList name_list_mothers;
    QStringList name_list_babies;

    QCustomPlot *customPlot_graph_0;
    QCustomPlot *customPlot_graph_1;
    QCustomPlot *customPlot_HR;
    QCPBars *bar_graph;

    static const quint16 ftdiVendorID=0x403;
    static const quint16 ftdiProductID=0x6014;

    bool ftdi_is_available;
    QString ftdi_port_name;

    QByteArray send_bytes;
    qint16 beat_per_minute_OXY1;
    qint16 beat_per_minute_OXY2;
    qint16 beat_per_minute_OXY1_average;
    qint16 beat_per_minute_OXY2_average;
    quint8 beat_per_minute_LOW;
    quint8 beat_per_minute_HIGH;
    quint8 SPO2_OXY1_value;
    quint8 SPO2_OXY2_value;
    double_t SPO2_average_value_OXY1;
    double_t SPO2_average_value_OXY2;
    quint16 PI_value_OXY1;  // perfusion_index
    quint16 PI_value_OXY2;  // perfusion_index
    quint16 PI_value_OXY1_average;  // perfusion_index
    quint16 PI_value_OXY2_average;  // perfusion_index
    quint8 PI_LOW;
    quint8 PI_HIGH;
    quint8 STATUS_CHECK_OXY1_value;
    quint8 STATUS_CHECK_OXY2_value;

    quint8 MO_Motion_disturbance_OXY1;
    quint8 NP_No_pulse_OXY1;
    quint8 SO_Sensor_off_OXY1;
    quint8 NS_No_Sensor_connected_OXY1;
    quint8 AI_Light_ambient_disturbance_OXY1;
    quint8 SP_Search_pulse_OXY1;
    quint8 LP_Low_perfusion_OXY1;
    quint8 SF_Sensor_Fault_OXY1;

    quint8 MO_Motion_disturbance_OXY2;
    quint8 NP_No_pulse_OXY2;
    quint8 SO_Sensor_off_OXY2;
    quint8 NS_No_Sensor_connected_OXY2;
    quint8 AI_Light_ambient_disturbance_OXY2;
    quint8 SP_Search_pulse_OXY2;
    quint8 LP_Low_perfusion_OXY2;
    quint8 SF_Sensor_Fault_OXY2;
    quint8 current_oxymeter;

    bool beat_pulse;
    quint8 protocol_count;

    quint8 current_window;

    quint32 last_bad_receive_pos;
    bool valid_data;
    bool valid_receive_data;
    bool first_receive;

    MyThread_Graph *thread_update_graph;

    uint32_t crc32(const void *buf, size_t size);

    QVector<double> keyData_graph_0;
    QVector<double> valueData_graph_0;

    QVector<double> keyData_graph_1;
    QVector<double> valueData_graph_1;

    QVector<double> keyData_graph_HR;
    QVector<double> valueData_graph_HR;

    QVector<double> keyData_graph_HR_recorded;
    QVector<double> valueData_graph_HR_recorded;

    quint32 temp_x_axis;

    quint32 HR_data_bebe_recorded_buffer_pos;
    quint32 function_data_bebe_recorded_buffer_pos;
    bool primera_vuelta;  //variable que me dice si se llenaron los buffers de las funciones y el ADC
    bool SPO2_buffer_full_OXY1; //me dice si ya se lleno el buffer del SPO2 function
    bool SPO2_buffer_full_OXY2;
    void check_message(qint64 bytes_size);

    bool paciente_cargado;
};

#endif // MAINWINDOW_H
