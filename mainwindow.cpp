/**
 * @file MainWindow.cpp
 * @date Feb 7, 2019
 * @author <b>Ing. Luis Alejandro Reyes Morales.</b>
 *
 * @brief
 *
 * This class implements the main window of the oximeter. The windows appearence and main function of
 * the application are implemented in this file.
 */



#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
//#include <//qDebug>
#include <QMessageBox>

const uint32_t crc32_tab[] = {
    0x00000000, 0x77073096, 0xee0e612c, 0x990951ba, 0x076dc419, 0x706af48f,
    0xe963a535, 0x9e6495a3,	0x0edb8832, 0x79dcb8a4, 0xe0d5e91e, 0x97d2d988,
    0x09b64c2b, 0x7eb17cbd, 0xe7b82d07, 0x90bf1d91, 0x1db71064, 0x6ab020f2,
    0xf3b97148, 0x84be41de,	0x1adad47d, 0x6ddde4eb, 0xf4d4b551, 0x83d385c7,
    0x136c9856, 0x646ba8c0, 0xfd62f97a, 0x8a65c9ec,	0x14015c4f, 0x63066cd9,
    0xfa0f3d63, 0x8d080df5,	0x3b6e20c8, 0x4c69105e, 0xd56041e4, 0xa2677172,
    0x3c03e4d1, 0x4b04d447, 0xd20d85fd, 0xa50ab56b,	0x35b5a8fa, 0x42b2986c,
    0xdbbbc9d6, 0xacbcf940,	0x32d86ce3, 0x45df5c75, 0xdcd60dcf, 0xabd13d59,
    0x26d930ac, 0x51de003a, 0xc8d75180, 0xbfd06116, 0x21b4f4b5, 0x56b3c423,
    0xcfba9599, 0xb8bda50f, 0x2802b89e, 0x5f058808, 0xc60cd9b2, 0xb10be924,
    0x2f6f7c87, 0x58684c11, 0xc1611dab, 0xb6662d3d,	0x76dc4190, 0x01db7106,
    0x98d220bc, 0xefd5102a, 0x71b18589, 0x06b6b51f, 0x9fbfe4a5, 0xe8b8d433,
    0x7807c9a2, 0x0f00f934, 0x9609a88e, 0xe10e9818, 0x7f6a0dbb, 0x086d3d2d,
    0x91646c97, 0xe6635c01, 0x6b6b51f4, 0x1c6c6162, 0x856530d8, 0xf262004e,
    0x6c0695ed, 0x1b01a57b, 0x8208f4c1, 0xf50fc457, 0x65b0d9c6, 0x12b7e950,
    0x8bbeb8ea, 0xfcb9887c, 0x62dd1ddf, 0x15da2d49, 0x8cd37cf3, 0xfbd44c65,
    0x4db26158, 0x3ab551ce, 0xa3bc0074, 0xd4bb30e2, 0x4adfa541, 0x3dd895d7,
    0xa4d1c46d, 0xd3d6f4fb, 0x4369e96a, 0x346ed9fc, 0xad678846, 0xda60b8d0,
    0x44042d73, 0x33031de5, 0xaa0a4c5f, 0xdd0d7cc9, 0x5005713c, 0x270241aa,
    0xbe0b1010, 0xc90c2086, 0x5768b525, 0x206f85b3, 0xb966d409, 0xce61e49f,
    0x5edef90e, 0x29d9c998, 0xb0d09822, 0xc7d7a8b4, 0x59b33d17, 0x2eb40d81,
    0xb7bd5c3b, 0xc0ba6cad, 0xedb88320, 0x9abfb3b6, 0x03b6e20c, 0x74b1d29a,
    0xead54739, 0x9dd277af, 0x04db2615, 0x73dc1683, 0xe3630b12, 0x94643b84,
    0x0d6d6a3e, 0x7a6a5aa8, 0xe40ecf0b, 0x9309ff9d, 0x0a00ae27, 0x7d079eb1,
    0xf00f9344, 0x8708a3d2, 0x1e01f268, 0x6906c2fe, 0xf762575d, 0x806567cb,
    0x196c3671, 0x6e6b06e7, 0xfed41b76, 0x89d32be0, 0x10da7a5a, 0x67dd4acc,
    0xf9b9df6f, 0x8ebeeff9, 0x17b7be43, 0x60b08ed5, 0xd6d6a3e8, 0xa1d1937e,
    0x38d8c2c4, 0x4fdff252, 0xd1bb67f1, 0xa6bc5767, 0x3fb506dd, 0x48b2364b,
    0xd80d2bda, 0xaf0a1b4c, 0x36034af6, 0x41047a60, 0xdf60efc3, 0xa867df55,
    0x316e8eef, 0x4669be79, 0xcb61b38c, 0xbc66831a, 0x256fd2a0, 0x5268e236,
    0xcc0c7795, 0xbb0b4703, 0x220216b9, 0x5505262f, 0xc5ba3bbe, 0xb2bd0b28,
    0x2bb45a92, 0x5cb36a04, 0xc2d7ffa7, 0xb5d0cf31, 0x2cd99e8b, 0x5bdeae1d,
    0x9b64c2b0, 0xec63f226, 0x756aa39c, 0x026d930a, 0x9c0906a9, 0xeb0e363f,
    0x72076785, 0x05005713, 0x95bf4a82, 0xe2b87a14, 0x7bb12bae, 0x0cb61b38,
    0x92d28e9b, 0xe5d5be0d, 0x7cdcefb7, 0x0bdbdf21, 0x86d3d2d4, 0xf1d4e242,
    0x68ddb3f8, 0x1fda836e, 0x81be16cd, 0xf6b9265b, 0x6fb077e1, 0x18b74777,
    0x88085ae6, 0xff0f6a70, 0x66063bca, 0x11010b5c, 0x8f659eff, 0xf862ae69,
    0x616bffd3, 0x166ccf45, 0xa00ae278, 0xd70dd2ee, 0x4e048354, 0x3903b3c2,
    0xa7672661, 0xd06016f7, 0x4969474d, 0x3e6e77db, 0xaed16a4a, 0xd9d65adc,
    0x40df0b66, 0x37d83bf0, 0xa9bcae53, 0xdebb9ec5, 0x47b2cf7f, 0x30b5ffe9,
    0xbdbdf21c, 0xcabac28a, 0x53b39330, 0x24b4a3a6, 0xbad03605, 0xcdd70693,
    0x54de5729, 0x23d967bf, 0xb3667a2e, 0xc4614ab8, 0x5d681b02, 0x2a6f2b94,
    0xb40bbe37, 0xc30c8ea1, 0x5a05df1b, 0x2d02ef8d
};

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);


    //Configuracion de Ventana Principal--------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------------------------

    this->setGeometry(200,200,1366,768);

    current_window=0;

    this->setWindowTitle("OXÍMETRO");

    //ui->statusBar->hide();
    //ui->mainToolBar->hide();
    //ui->menuBar->hide();

    ui->centralWidget->setPalette(QPalette(QColor(26,98,83)));
    ui->centralWidget->setAutoFillBackground(true);

    ui->lw_baby_list->hide();
    ui->pbAceptar->hide();

    window_appearence();

    hide_all_objects();
    show_pacient_window();
    //------------------------------------------------------------------------------------------------------------------------


    //Variables para muestreo en graficas--------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------------------------
    for(int i=0;i<4;i++){

        keyData_graph_HR<<i+1;
        valueData_graph_HR<<i+1;

        keyData_graph_HR_recorded<<i+1;
        valueData_graph_HR_recorded<<i+1;
    }

    for(int i=0;i<FUNCTION_BUFFER_SIZE;i++){
        keyData_graph_0<<i+1;
        valueData_graph_0<<i+1;
        keyData_graph_1<<i+1;
        valueData_graph_1<<i+1;
    }
    //------------------------------------------------------------------------------------------------------------------------


    //Configuracion de Hilos de temporizacion--------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------------------------
    thread_update_graph = new MyThread_Graph(this);
    connect(thread_update_graph, SIGNAL(process_data_graph_finished(bool)),this, SLOT(afterUpdateGraph()));

    thread_update_graph->start();
    //------------------------------------------------------------------------------------------------------------------------

    //    // Temporizacion para eje x----------------------------------------------------------------------------------
    //    //------------------------------------------------------------------------------------------------------------------------
    //    connect(&timer_axis,SIGNAL(timeout()),this,SLOT(on_time_out_update_axis()));
    //    timer_axis.setInterval(16);
    //    //------------------------------------------------------------------------------------------------------------------------


    // Seccion de inicializacion de archivos----------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------------------------
    data_base = new QFile("base_datos_oximetria.dat"); // ficheros .dat se puede utilizar formato txt tambien
    bebe_object = Bebe_Data_Class("bb","mm");
    ver_registro_activated=false;
    ver_registro_counter=0;
    //------------------------------------------------------------------------------------------------------------------------


    // Inicializacion de graficos, variables muestradas y variables a graficar------------------------------------------------
    //------------------------------------------------------------------------------------------------------------------------
    setupGraph();
    setupGraph_Bar();
    setupGraph_HR();

    primera_vuelta=true; ////en caso de que no se haya llegado a un minuto;
    SPO2_buffer_full_OXY1 = false;
    SPO2_buffer_full_OXY2 = false;

    paciente_cargado = false; //me dice si se cargo un paciente desde la base de datos;
    SPO2_OXY1_value=0;  //ultimo valor enviado por oximetro1
    SPO2_OXY2_value=0;  //ultimo valor enviado por oximetro2
    SPO2_average_value_OXY1 = 0;
    SPO2_average_value_OXY2 = 0;
    beat_per_minute_OXY1=0;
    beat_per_minute_OXY2=0;
    beat_per_minute_OXY1_average=0;
    beat_per_minute_OXY2_average=0;
    function_value_count=0;
    HR_value_count =0;
    x_axis_count=0;

    beat_per_minute_LOW =0;
    beat_per_minute_HIGH =0;
    PI_value_OXY1 = 0;  // perfusion_index
    PI_value_OXY2 = 0;
    PI_value_OXY1_average = 0;  // perfusion_index
    PI_value_OXY2_average = 0;
    PI_LOW=0;
    PI_HIGH=0;
    //------------------------------------------------------------------------------------------------------------------------



    // Inicializacion de timer y conexion de señales--------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------------------------
    timer = new QTimer(this);
    timer->setInterval(MAX_TIME_RECORDING);
    connect(timer,SIGNAL(timeout()),this,SLOT(on_time_out()));
    recording_activated = false;
    //------------------------------------------------------------------------------------------------------------------------



    // Busqueda de puertos serie, encuentra el PID y el VID del FTDI se procede a inicializar el puerto serie-----------------
    //------------------------------------------------------------------------------------------------------------------------
    ftdi_is_available=false;
    foreach (const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()) {
        if(serialPortInfo.hasProductIdentifier() && serialPortInfo.hasVendorIdentifier()){
            if(serialPortInfo.productIdentifier()==ftdiProductID && serialPortInfo.vendorIdentifier()==ftdiVendorID){
                ftdi_is_available=true;
                ftdi_port_name=serialPortInfo.portName();
            }
        }
    }
    //------------------------------------------------------------------------------------------------------------------------



    // Inicializacion de puerto serie y habilitacion de botones---------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------------------------
    last_bad_receive_pos=0;
    first_receive = true;
    signal_ready_read_connected = false;

    ftdi_serial_port=new QSerialPort(this);

    if(ftdi_is_available){
        ui->statusBar->showMessage("Dispositivo FTDI encontrado");
        ftdi_serial_port->setPortName(ftdi_port_name);
        ftdi_serial_port->open(QSerialPort::ReadWrite);
        ftdi_serial_port->setBaudRate(QSerialPort::Baud115200);
        ftdi_serial_port->setDataBits(QSerialPort::Data8);
        ftdi_serial_port->setFlowControl(QSerialPort::NoFlowControl);
        ftdi_serial_port->setParity(QSerialPort::NoParity);
        ftdi_serial_port->setStopBits(QSerialPort::OneStop);


        ui->pbIniciar->setEnabled(true);

        char write_data[16];
        for (int i=0; i<16;++i){
            write_data[i]=INIT_PROG_ID;
        }

        ftdi_serial_port->write(write_data,16);

        if(!signal_ready_read_connected){
            QObject::connect(ftdi_serial_port,SIGNAL(readyRead()),this,SLOT(readSerial()));
            signal_ready_read_connected = true;
        }

    }
    else {
        ui->pbIniciar->setEnabled(false);
        ui->statusBar->showMessage("Dispositivo FTDI no encontrado");
    }
    //------------------------------------------------------------------------------------------------------------------------

}

// Destructor de la clase-----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------
MainWindow::~MainWindow()
{
    if(ftdi_serial_port->isOpen())
        ftdi_serial_port->close();
    delete ui;
}
//----------------------------------------------------------------------------------------------------------------------------

void MainWindow::afterUpdateGraph(){

    if(!ver_registro_activated){

        if(keyData_graph_HR[0]>= 400)
            customPlot_HR->xAxis->setRange(keyData_graph_HR[0]- 400,keyData_graph_HR[0] + 100);
        //memcpy( &valueData_graph_HR[0], (double*)&function_values_graph_HR[HR_value_count], (sizeof(double))*4);

        for(int i=0; i<4; i++){
            keyData_graph_HR[i]+=4;
            valueData_graph_HR[i]= function_values_graph_HR[HR_value_count+i];
        }
        HR_value_count+=4;
        if(HR_value_count >= DATA_ADC_BUFFER_SIZE){
            HR_value_count = 0;
        }
        customPlot_HR->graph(0)->addData(keyData_graph_HR, valueData_graph_HR);
        customPlot_HR->replot();

        if(x_axis_count >= 100)
            customPlot_graph_0->xAxis->setRange(x_axis_count- 100,x_axis_count + 25 );
        //customPlot_graph_0->xAxis->autoSubTicks();
        if(function_values_graph_0[function_value_count] == 0 || function_values_graph_0[function_value_count] > 97){
            if(function_value_count != 0){
                function_values_graph_0[function_value_count] = function_values_graph_0[function_value_count-1];
            }
            else{
                function_values_graph_0[function_value_count] = function_values_graph_0[DATA_FUNCTION_SIZE-1];
            }
        }
        customPlot_graph_0->graph(0)->addData(x_axis_count, function_values_graph_0[function_value_count]);
        customPlot_graph_0->replot();

        if(x_axis_count >= 100)
            customPlot_graph_1->xAxis->setRange(x_axis_count- 100,x_axis_count + 25 );
        //customPlot_graph_1->xAxis->autoSubTicks();

        if(function_values_graph_1[function_value_count] == 0 || function_values_graph_1[function_value_count] > 97){
            if(function_value_count != 0){
                function_values_graph_1[function_value_count] = function_values_graph_1[function_value_count-1];
            }
            else{
                function_values_graph_1[function_value_count] = function_values_graph_1[DATA_FUNCTION_SIZE-1];
            }
        }
        customPlot_graph_1->graph(0)->addData(x_axis_count, function_values_graph_1[function_value_count]);
        customPlot_graph_1->replot();

        function_value_count++;
        x_axis_count++;
        if(function_value_count >= DATA_FUNCTION_SIZE){
            function_value_count=0;
        }
        // Reinicio el timer---------------------------------------------------------------------------------------
        //---------------------------------------------------------------------------------------------------------
        //thread_update_graph->start_timer();  ////no iniciar timer, no detenerlo nunca, probar esto
        //---------------------------------------------------------------------------------------------------------
    }

}


// Funcion de visualizacion de ventana de paciente----------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------
void MainWindow::show_pacient_window(){

    ui->l_base_de_graficas->show();
    ui->l_base_de_graficas->lower();
    ui->l_mother_icon->show();
    ui->l_tete_icon->show();
    ui->l_nombre_madre->show();
    ui->l_bebe_name->show();
    ui->le_name_baby->show();
    ui->le_name_mother->show();
    ui->pbGuardar->show();
    ui->pbBase_de_datos->show();
    //ui->l_current_window->show();
    ui->widget_layout_datos->lower();
    ////ui->pb_change_window->show();
    ui->l_sombra_de_fondo->show();
}
//----------------------------------------------------------------------------------------------------------------------------


// Funcion de visualizacion de ventana de graficas----------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------
void MainWindow::show_graph_window(){

    ui->pbBase_de_datos->setEnabled(true);

    ui->l_baby_name_graph->show();
    ui->l_name_baby_graph->show();
    ui->l_mother_name_graph_2->show();
    ui->l_mother_name_graph->show();
    ui->l_date_graph->show();
    ui->l_date->show();
    ui->l_time->show();
    ui->l_time_icon->show();
    ui->l_SPO2_value->show();
    ui->l_BPM_value->show();
    ui->l_PI_value->show();
    ui->pbIniciar->show();
    ui->widget->show();
    ui->widget_2->show();
    ui->widget_graph_HR->show();
    ui->l_for_graph->show();
    ui->l_for_graph->lower();
    ui->l_for_graph_bar->show();
    ui->l_for_graph_bar->lower();
    ui->l_for_graph_HR->show();
    ui->l_for_graph_HR->lower();
    //ui->pb_change_window->show();
    ui->pbVer_Registro->show();

    ui->l_mother_name_graph_2->setText("  "+ui->le_name_mother->text());
    ui->l_mother_name_graph_2->setStyleSheet("QLabel {   font: 10pt Myriad Web; color : #AFAFAF; }");
    ui->l_name_baby_graph->setText("  "+ui->le_name_baby->text());
    ui->l_name_baby_graph->setStyleSheet("QLabel {   font: 10pt Myriad Web; color : #AFAFAF; }");

    ui->l_date->setStyleSheet("QLabel {   font: 10pt Myriad Web; color : #AFAFAF; }");

    ui->l_time->setStyleSheet("QLabel {   font: 10pt Myriad Web; color : #AFAFAF; }");

}
//----------------------------------------------------------------------------------------------------------------------------


// Funcion de visualizacion de ventana de configuracion----------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------
void MainWindow::show_config_window(){

    ui->pbBase_de_datos->setEnabled(true);

    ui->l_base_de_graficas->show();
    ui->l_base_de_graficas->lower();
    ui->l_res_shake_hands->show();
    ui->l_res_cal_sen->show();
    ui->l_res_mea_mode->show();
    ui->l_res_self_test->show();
    ui->l_res_type_ver->show();
    ui->l_res_set_cal_sen->show();
    ui->l_res_set_mea_mode->show();
    ui->pb_shake_hands->show();
    ui->pb_cal_sen->show();
    ui->pb_mea_mode->show();
    ui->pb_self_test->show();
    ui->pb_type_ver->show();
    ui->pb_set_cal_sen->show();
    ui->pb_set_mea_mode->show();
    //ui->pb_change_window->show();
    ui->l_config_icons->show();
    ui->l_config_mother->show();
    ui->l_config_baby->show();
    ui->l_config_date->show();
    ui->l_config_time->show();
    ui->widget_config->show();

    ui->l_config_baby->setText(bebe_object.baby_name);
    ui->l_config_mother->setText(bebe_object.mother_name);
    ui->l_config_date->setText(bebe_object.date.toString());
    ui->l_config_time->setText(bebe_object.time.toString());

    ui->l_sombra_de_fondo->show();
}
//----------------------------------------------------------------------------------------------------------------------------


// Funcion para esconder todos los objetos------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------
void MainWindow::hide_all_objects(){

    ui->pbIniciar->hide();
    ui->l_sombra_de_fondo->hide();
    ui->widget_config->hide();
    ui->l_config_icons->hide();
    ui->l_config_mother->hide();
    ui->l_config_baby->hide();
    ui->l_config_date->hide();
    ui->l_config_time->hide();
    //ui->pb_change_window->hide();
    ui->l_mother_name_graph->hide();
    ui->l_baby_name_graph->hide();
    ui->l_mother_name_graph_2->hide();
    ui->l_name_baby_graph->hide();
    //ui->l_current_window->hide();
    ui->l_for_graph->hide();
    ui->l_for_graph_bar->hide();
    ui->l_for_graph_HR->hide();
    ui->widget->hide();
    ui->widget_2->hide();
    ui->widget_graph_HR->hide();
    ui->pbDetener->hide();
    ui->pb_shake_hands->hide();
    //ui->label->hide();
    ui->pb_cal_sen->hide();
    ui->pb_mea_mode->hide();
    ui->pb_self_test->hide();
    ui->pb_type_ver->hide();
    ui->l_res_shake_hands->hide();
    ui->l_res_cal_sen->hide();
    ui->l_res_mea_mode->hide();
    ui->l_res_self_test->hide();
    ui->l_res_type_ver->hide();
    //ui->label_10->hide();
    ui->pb_set_cal_sen->hide();
    ui->pb_set_mea_mode->hide();
    //ui->label_5->hide();
    //ui->label_11->hide();
    ui->l_res_set_cal_sen->hide();
    ui->l_res_set_mea_mode->hide();
    ui->le_name_baby->hide();
    ui->le_name_mother->hide();
    ui->l_bebe_name->hide();
    ui->l_nombre_madre->hide();
    ui->pbGuardar->hide();
    ui->l_SPO2_value->hide();
    ui->l_BPM_value->hide();
    ui->l_PI_value->hide();
    ui->pbBase_de_datos->hide();
    ui->lw_baby_list->hide();
    ui->pbAceptar->hide();
    ui->l_time_icon->hide();
    ui->l_date_graph->hide();
    ui->l_time->hide();
    ui->l_date->hide();
    ui->pbVer_Registro->hide();
    ui->l_mother_icon->hide();
    ui->l_tete_icon->hide();
    ui->l_base_de_graficas->hide();

}
//----------------------------------------------------------------------------------------------------------------------------


// Funcion de diseño de ventana-----------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------
void MainWindow::window_appearence(){


    // Configuracion de botones-----------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------------------------

    ui->widget_window_buttons->move(750,80);

    ui->lw_baby_list->setStyleSheet("border-image: url(:photos/base_de_datos.png); font: 11pt Myriad Web; color: #555555;");
    ui->lw_baby_list->setFixedSize(318,249);
    ui->widget_list_pacient_layout->move(540,300);

    ui->pb_window_pacient->setFlat(true);
    ui->pb_window_pacient->setIcon((QIcon(":photos/boton_paciente_blanco.png")));
    ui->pb_window_pacient->setIconSize(QSize(50,16));
    ui->pb_window_pacient->setFixedSize(50,16);

    ui->pb_window_graph->setFlat(true);
    ui->pb_window_graph->setIcon((QIcon(":photos/boton_graficas.png")));
    ui->pb_window_graph->setIconSize(QSize(50,16));
    ui->pb_window_graph->setFixedSize(47,16);

    ui->pb_window_config->setFlat(true);
    ui->pb_window_config->setIcon((QIcon(":photos/boton_configuracion.png")));
    ui->pb_window_config->setIconSize(QSize(83,16));
    ui->pb_window_config->setFixedSize(83,16);

    ui->pbDetener->setEnabled(false);

    //ui->pbGuardar->setAutoFillBackground(true);
    ui->pbGuardar->setFlat(true);
    ui->pbGuardar->setIcon((QIcon(":photos/entrar.png")));
    ui->pbGuardar->setIconSize(QSize(110,38));
    ui->pbGuardar->setFixedSize(110,38);

    ui->pbBase_de_datos->setFlat(true);
    ui->pbBase_de_datos->setIcon((QIcon(":photos/datos.png")));
    ui->pbBase_de_datos->setIconSize(QSize(20,19));
    ui->pbBase_de_datos->setFixedSize(20,19);
    ui->pbBase_de_datos->move(820,283);

    ui->pbIniciar->setFlat(true);
    ui->pbIniciar->setIcon((QIcon(":photos/iniciar.png")));
    ui->pbIniciar->setIconSize(QSize(76,87));
    ui->pbIniciar->setFixedSize(76,87);

    ui->pbDetener->setFlat(true);
    ui->pbDetener->setIcon((QIcon(":photos/detener.png")));
    ui->pbDetener->setIconSize(QSize(76,87));
    ui->pbDetener->setFixedSize(76,87);

    ui->pbVer_Registro->setFlat(true);
    ui->pbVer_Registro->setIcon((QIcon(":photos/boton_registrar.png")));
    ui->pbVer_Registro->setIconSize(QSize(131,31));
    ui->pbVer_Registro->setFixedSize(131,31);
    ui->pbVer_Registro->move(1200, 330);

    ui->pb_shake_hands->setFlat(true);
    ui->pb_shake_hands->setIcon((QIcon(":photos/shake_hands.png")));
    ui->pb_shake_hands->setIconSize(QSize(131,31));
    ui->pb_shake_hands->setFixedSize(131,31);

    ui->pb_cal_sen->setFlat(true);
    ui->pb_cal_sen->setIcon((QIcon(":photos/cal_sensivity.png")));
    ui->pb_cal_sen->setIconSize(QSize(132,32));
    ui->pb_cal_sen->setFixedSize(132,32);

    ui->pb_mea_mode->setFlat(true);
    ui->pb_mea_mode->setIcon((QIcon(":photos/measurement_mode.png")));
    ui->pb_mea_mode->setIconSize(QSize(131,34));
    ui->pb_mea_mode->setFixedSize(131,34);

    ui->pb_self_test->setFlat(true);
    ui->pb_self_test->setIcon((QIcon(":photos/self_test.png")));
    ui->pb_self_test->setIconSize(QSize(130,31));
    ui->pb_self_test->setFixedSize(130,31);

    ui->pb_type_ver->setFlat(true);
    ui->pb_type_ver->setIcon((QIcon(":photos/type_version.png")));
    ui->pb_type_ver->setIconSize(QSize(129,32));
    ui->pb_type_ver->setFixedSize(129,32);

    ui->pb_set_cal_sen->setFlat(true);
    ui->pb_set_cal_sen->setIcon((QIcon(":photos/set_cal_sensivity_2.png")));
    ui->pb_set_cal_sen->setIconSize(QSize(131,32));
    ui->pb_set_cal_sen->setFixedSize(131,32);

    ui->pb_set_mea_mode->setFlat(true);
    ui->pb_set_mea_mode->setIcon((QIcon(":photos/set_measumerent_mod_2.png")));
    ui->pb_set_mea_mode->setIconSize(QSize(131,31));
    ui->pb_set_mea_mode->setFixedSize(131,31);

    /*ui->pb_change_window->setFlat(true);
    ui->pb_change_window->setIcon((QIcon(":photos/pestaña_paciente.png")));
    ui->pb_change_window->setIconSize(QSize(278,16));
    ui->pb_change_window->setFixedSize(278,16);
    ui->pb_change_window->move(700,100);*/
    //------------------------------------------------------------------------------------------------------------------------


    // Configuracion de labels------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------------------------
    //ui->l_mother_icon->setStyleSheet("border-image: url(:photos/madre_verde.png);" );

    ui->l_sombra_de_fondo->setPixmap(QPixmap(":photos/sombra.png"));
    ui->l_sombra_de_fondo->setFixedSize(QSize(983,578));
    ui->l_sombra_de_fondo->move(387,192);  ////+10,+16
    ui->l_sombra_de_fondo->lower();

    ui->l_espacio_window_button->setPixmap(QPixmap(":photos/barra_espacio.png"));
    ui->l_espacio_window_button->setFixedSize(QSize(15,16));

    ui->l_espacio_window_button_2->setPixmap(QPixmap(":photos/barra_espacio.png"));
    ui->l_espacio_window_button_2->setFixedSize(QSize(15,16));

    ui->l_mother_icon->setPixmap(QPixmap(":photos/madre_verde.png"));
    ui->l_mother_icon->setFixedSize(QSize(61,61));

    ui->l_tete_icon->setPixmap(QPixmap(":photos/bebe_verde.png"));
    ui->l_tete_icon->setFixedSize(QSize(60,60));

    ui->l_nombre_madre->setPixmap(QPixmap(":photos/label_nombre_madre_solo.png"));
    ui->l_nombre_madre->setFixedSize(QSize(158,23));

    ui->l_bebe_name->setPixmap(QPixmap(":photos/label_nombre_bebe_solo.png"));
    ui->l_bebe_name->setFixedSize(QSize(131,26));

    ui->l_base_de_graficas->setPixmap(QPixmap(":photos/base_de_graficas.png"));
    //ui->l_base_de_graficas->setStyleSheet("border-image: url(:photos/base_de_graficas.png);" );
    ui->l_base_de_graficas->setFixedSize(QSize(657,381));
    //ui->l_base_de_graficas->move(350,150);

    ui->widget_layout_datos->move(360,164);  ////aqui se mueve la ventana de paciente

    ui->widget_layout_paciente->setPalette(QPalette(QColor(239,236,241)));
    ui->widget_layout_paciente->setAutoFillBackground(true);
    ui->widget_layout_paciente->move(460,230);

    ui->l_mother_name_graph->setPixmap(QPixmap(":photos/madre.png"));
    ui->l_mother_name_graph->setFixedSize(QSize(27,27));

    ui->l_baby_name_graph->setPixmap(QPixmap(":photos/bebe.png"));
    ui->l_baby_name_graph->setFixedSize(QSize(27,27));

    ui->l_date_graph->setPixmap(QPixmap(":photos/fecha.png"));
    ui->l_date_graph->setFixedSize(QSize(27,27));

    ui->l_time_icon->setPixmap(QPixmap(":photos/hora.png"));
    ui->l_time_icon->setFixedSize(QSize(28,28));

    //ui->l_date->setFixedSize(QSize(30,80));
    // ui->l_time->setFixedSize(QSize(30,100));

    //ui->l_BPM_value->setPixmap(QPixmap(":photos/label_BPM.png"));
    ui->l_BPM_value->setStyleSheet("color: #EEEEEE; font: 13pt \"Myriad  Web\"; border-image: url(:photos/label_BPM.png);" );
    ui->l_BPM_value->setFixedSize(QSize(164,28));

    //ui->l_SPO2_value->setPixmap(QPixmap(":photos/label_SPO2.png"));
    ui->l_SPO2_value->setStyleSheet("color: #EEEEEE; font: 13pt \"Myriad  Web\"; border-image: url(:photos/label_SPO2.png);" );
    ui->l_SPO2_value->setFixedSize(QSize(171,29));

    ui->l_PI_value->setStyleSheet("color: #EEEEEE; font: 13pt \"Myriad  Web\"; border-image: url(:photos/label_PI.png);" );
    ui->l_PI_value->setFixedSize(QSize(171,29));

    //ui->l_res_shake_hands->setPixmap(QPixmap(":photos/label_config_text.png"));
    ui->l_res_shake_hands->setStyleSheet("border-image: url(:photos/label_config_text.png);" );
    ui->l_res_shake_hands->setFixedSize(QSize(140,30));
    //ui->l_res_cal_sen->setPixmap(QPixmap(":photos/label_config_text.png"));
    ui->l_res_cal_sen->setStyleSheet("border-image: url(:photos/label_config_text.png);" );
    ui->l_res_cal_sen->setFixedSize(QSize(140,30));
    //ui->l_res_mea_mode->setPixmap(QPixmap(":photos/label_config_text.png"));
    ui->l_res_mea_mode->setStyleSheet("border-image: url(:photos/label_config_text.png);" );
    ui->l_res_mea_mode->setFixedSize(QSize(140,30));
    //ui->l_res_self_test->setPixmap(QPixmap(":photos/label_config_text.png"));
    ui->l_res_self_test->setStyleSheet("border-image: url(:photos/label_config_text.png);" );
    ui->l_res_self_test->setFixedSize(QSize(140,30));
    //ui->l_res_type_ver->setPixmap(QPixmap(":photos/label_config_text.png"));
    ui->l_res_type_ver->setStyleSheet("border-image: url(:photos/label_config_text.png);" );
    ui->l_res_type_ver->setFixedSize(QSize(140,30));

    ui->l_res_set_cal_sen->setPixmap(QPixmap(":photos/label_config_text.png"));
    ui->l_res_set_cal_sen->setFixedSize(QSize(140,30));

    ui->l_res_set_mea_mode->setPixmap(QPixmap(":photos/label_config_text.png"));
    ui->l_res_set_mea_mode->setFixedSize(QSize(140,30));

    ui->l_config_icons->setPixmap(QPixmap(":photos/iconos_paciente.png"));
    ui->l_config_icons->setFixedSize(QSize(20,100));

    ui->widget_config->setPalette(QPalette(QColor(236,239,241)));
    ui->widget_config->setAutoFillBackground(true);
    ui->widget_config->move(400,205);

    ui->l_for_graph->setPixmap(QPixmap(":photos/base_de_graficas.png"));
    ui->l_for_graph->setFixedSize(QSize(657,381));
    ui->l_for_graph->lower();
    ui->l_for_graph->move(680,120);

    ui->l_for_graph_bar->setPixmap(QPixmap(":photos/base_de_graficas.png"));
    ui->l_for_graph_bar->setFixedSize(QSize(657,381));
    ui->l_for_graph_bar->lower();
    ui->l_for_graph_bar->move(25,120);

    ui->l_for_graph_HR->setPixmap(QPixmap(":photos/base_de_graficas.png"));
    ui->l_for_graph_HR->setFixedSize(QSize(657,381));
    ui->l_for_graph_HR->lower();
    ui->l_for_graph_HR->move(21,5);

    ui->widget_layout_graph->move(10,350);
    ui->widget_graph_info->move(700,180);
    //------------------------------------------------------------------------------------------------------------------------


    // Configuracion de line Edit------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------------------------
    ui->le_name_mother->setStyleSheet(QStringLiteral("color: #555555; font: 11pt Myriad  Web;") + "border-image: url(:photos/label_line_edit.png);");
    ui->le_name_mother->setFixedSize(QSize(293,44));

    ui->le_name_baby->setStyleSheet(QStringLiteral("color: #555555; font: 11pt Myriad  Web;") + "border-image: url(:photos/label_line_edit.png);");
    ui->le_name_baby->setFixedSize(QSize(293,44));
    //------------------------------------------------------------------------------------------------------------------------

}
//----------------------------------------------------------------------------------------------------------------------------


//Funcion que calcula valor CRC-32---------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------
uint32_t MainWindow::crc32(const void *buf, size_t size)
{
    const uint8_t *p = (uint8_t *)buf;
    uint32_t crc;

    crc = ~0U;
    while (size--)
        crc = crc32_tab[(crc ^ *p++) & 0xFF] ^ (crc >> 8);
    return crc ^ ~0U;
}
//----------------------------------------------------------------------------------------------------------------------------


void MainWindow::check_message(qint64 bytes_size){

    if(last_bad_receive_pos >= UART_SEND_TOTAL_SIZE){

        uint8_t buf_8b[4];
        uint32_t crcValue = crc32(receive_bytes, UART_SEND_BUFFER_SIZE);

        for (int i=0; i<4 ;++i){
            buf_8b[i] = ((uint8_t*)&crcValue)[3-i];
        }

        valid_receive_data = true;

        for (int i=0; i<4 ;++i){
            if(receive_bytes[i+UART_SEND_BUFFER_SIZE] != buf_8b[i]){
                valid_receive_data = false;//Error de datos solicitar reenvio
                char write_data[16];
                for (int i=0; i<16;++i){
                    write_data[i]=0x0F;
                }
                ftdi_serial_port->write(write_data,16);
                return;//Error de check_sum solicitar reenvio
            }
        }

        for(int i=HEADER_START_POS; i < HEADER_SIZE; i++){
            if(receive_bytes[i] != HEADER_ID){
                valid_receive_data = false;//Error de datos solicitar reenvio
                char write_data[16];
                for (int i=0; i<16;++i){
                    write_data[i]=0x0F;
                }
                ftdi_serial_port->write(write_data,16);
                return;//Error de cabecera solicitar reenvio
            }
        }
        //        for(int i=TAIL_START_POS; i < TAIL_SIZE; i++){
        //            if(receive_bytes[i] != TAIL_ID){
        //                valid_receive_data = false;//Error de datos solicitar reenvio
        //                char write_data[16];
        //                for (int i=0; i<16;++i){
        //                    write_data[i]=0x0F;
        //                }
        //                ftdi_serial_port->write(write_data,16);
        //                return;//Error de cola solicitar reenvio
        //            }
        //        }
    }

}
// Funcion de atencion del puerto serie, se ejecuta cuando recibe datos-------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------
void MainWindow::readSerial(){

    if(ver_registro_activated){ //Si se esta viendo el registro no hago nada en esta funcion

        return;
    }

    int x = UART_SEND_TOTAL_SIZE;
    int y = UART_SEND_BUFFER_SIZE;
    //ui->statusBar->showMessage("Ejecucion de funcion readSerial");

    // Lectura de datos del puerto serie--------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------------------------
    QByteArray serialData = ftdi_serial_port->readAll();

    qint64 bytes_size = serialData.size();
    //------------------------------------------------------------------------------------------------------------------------


    // Guardando de datos del puerto serie--------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------------------------
    for(int i=0; i < bytes_size; i++){ //el elemento i = serialData.size() no existe y da error al correr

        receive_bytes[i + last_bad_receive_pos] = serialData.at(i);
        //ui->statusBar->showMessage(QString("last_bad_receive_pos  -> ")+QString::number(last_bad_receive_pos));
    }
    last_bad_receive_pos += bytes_size;
    //------------------------------------------------------------------------------------------------------------------------


    //Comprobacion de bytes recibido por puerto serie----------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------------------------
    check_message(bytes_size);

    if(valid_receive_data && !ver_registro_activated){

        memcpy( &function_values_graph_0[function_value_pos], &receive_bytes[DATA_GRAPH_FT_INIT_BUFFER_POS], FUNCTION_BUFFER_SIZE);
        memcpy( &function_values_graph_1[function_value_pos], &receive_bytes[DATA_GRAPH_FT_2_INIT_BUFFER_POS], FUNCTION_BUFFER_SIZE);
        memcpy( &function_values_graph_HR[HR_value_pos], &receive_bytes[DATA_GRAPH_HR_INIT_BUFFER_POS], ADC_BUFFER_SIZE);

        function_value_pos+=FUNCTION_BUFFER_SIZE;
        HR_value_pos+=ADC_BUFFER_SIZE;

        if(function_value_pos >=DATA_FUNCTION_SIZE){
            function_value_pos=0;
            HR_value_pos=0;
            primera_vuelta=false;
        }


        //if(receive_bytes[DATA_INIT_BUFFER_POS] == DATA_INIT_BUFFER_ID || receive_bytes[DATA_INIT_BUFFER_POS] == DATA_BUFFER_TRANSMIT_0 || receive_bytes[DATA_INIT_BUFFER_POS] == DATA_BUFFER_TRANSMIT_1){

        SPO2_OXY1_value= receive_bytes[SPO2_BUFFER_OXY1_POS];
        SPO2_OXY2_value= receive_bytes[SPO2_BUFFER_OXY2_POS];

        beat_per_minute_LOW = receive_bytes[BPM_BUFFER_OXY1_POS];
        beat_per_minute_HIGH= receive_bytes[BPM_BUFFER_OXY1_POS+1];

        beat_per_minute_OXY1 = beat_per_minute_HIGH;
        beat_per_minute_OXY1 = beat_per_minute_OXY1 << 8;
        beat_per_minute_OXY1 = beat_per_minute_OXY1|(beat_per_minute_LOW & 0x0FF);

        beat_per_minute_LOW = receive_bytes[BPM_BUFFER_OXY2_POS];
        beat_per_minute_HIGH= receive_bytes[BPM_BUFFER_OXY2_POS+1];

        beat_per_minute_OXY2 = beat_per_minute_HIGH;
        beat_per_minute_OXY2 = beat_per_minute_OXY2 << 8;
        beat_per_minute_OXY2 = beat_per_minute_OXY2|(beat_per_minute_LOW & 0x0FF);

        PI_LOW = receive_bytes[PI_BUFFER_OXY1_POS];
        PI_HIGH = receive_bytes[PI_BUFFER_OXY1_POS+1];

        PI_value_OXY1 = PI_HIGH;
        PI_value_OXY1 = PI_value_OXY1 << 8;
        PI_value_OXY1 = PI_value_OXY1|(PI_LOW & 0x0FF);

        PI_LOW = receive_bytes[PI_BUFFER_OXY2_POS];
        PI_HIGH = receive_bytes[PI_BUFFER_OXY2_POS+1];

        PI_value_OXY2 = PI_HIGH;
        PI_value_OXY2 = PI_value_OXY2 << 8;
        PI_value_OXY2 = PI_value_OXY2|(PI_LOW & 0x0FF);


        STATUS_CHECK_OXY1_value = receive_bytes[STATUS_CHECK_OXY1_POS];
        STATUS_CHECK_OXY2_value = receive_bytes[STATUS_CHECK_OXY2_POS];

        MO_Motion_disturbance_OXY1 = (STATUS_CHECK_OXY1_value & 0x80) >> 7;
        NP_No_pulse_OXY1 = (STATUS_CHECK_OXY1_value & 0x01);
        SO_Sensor_off_OXY1 = (STATUS_CHECK_OXY1_value & 0x02) >> 1;
        NS_No_Sensor_connected_OXY1 = (STATUS_CHECK_OXY1_value & 0x04) >> 2;
        AI_Light_ambient_disturbance_OXY1 = (STATUS_CHECK_OXY1_value & 0x08) >> 3;
        SP_Search_pulse_OXY1 = (STATUS_CHECK_OXY1_value & 0x10) >> 4;
        LP_Low_perfusion_OXY1 = (STATUS_CHECK_OXY1_value & 0x20) >> 5;
        SF_Sensor_Fault_OXY1 = (STATUS_CHECK_OXY1_value & 0x40) >> 6;

        MO_Motion_disturbance_OXY2 = (STATUS_CHECK_OXY2_value & 0x80) >> 7;
        NP_No_pulse_OXY2 = (STATUS_CHECK_OXY2_value & 0x01);
        SO_Sensor_off_OXY2 = (STATUS_CHECK_OXY2_value & 0x02) >> 1;
        NS_No_Sensor_connected_OXY2 = (STATUS_CHECK_OXY2_value & 0x04) >> 2;
        AI_Light_ambient_disturbance_OXY2 = (STATUS_CHECK_OXY2_value & 0x08) >> 3;
        SP_Search_pulse_OXY2 = (STATUS_CHECK_OXY2_value & 0x10) >> 4;
        LP_Low_perfusion_OXY2 = (STATUS_CHECK_OXY2_value & 0x20) >> 5;
        SF_Sensor_Fault_OXY2 = (STATUS_CHECK_OXY2_value & 0x40) >> 6;


        if(SPO2_OXY1_value <= 100 && SPO2_OXY1_value >= 0){

            SPO2_function_values_graph_OXY1[SPO2_function_value_pos_OXY1] = SPO2_OXY1_value;
            SPO2_function_value_pos_OXY1++;

            if(SPO2_function_value_pos_OXY1 >= SPO2_FUNCTION_BUFFER_SIZE){
                SPO2_function_value_pos_OXY1=0;
                SPO2_buffer_full_OXY1  = true;
            }
        }



        ui->l_MO_OXY1->setText(QString("Ox1: ")+QString::number(MO_Motion_disturbance_OXY1));
        ui->l_NP_OXY1->setText(QString("Ox1: ")+QString::number(NP_No_pulse_OXY1));
        ui->l_SO_OXY1->setText(QString("Ox1: ")+QString::number(SO_Sensor_off_OXY1));
        ui->l_NS_OXY1->setText(QString("Ox1: ")+QString::number(NS_No_Sensor_connected_OXY1));
        ui->l_AI_OXY1->setText(QString("Ox1: ")+QString::number(AI_Light_ambient_disturbance_OXY1));
        ui->l_SP_OXY1->setText(QString("Ox1: ")+QString::number(SP_Search_pulse_OXY1));
        ui->l_LP_OXY1->setText(QString("Ox1: ")+QString::number(LP_Low_perfusion_OXY1));
        ui->l_SF_OXY1->setText(QString("Ox1: ")+QString::number(SF_Sensor_Fault_OXY1));


        if(SPO2_OXY2_value <= 100){

            SPO2_function_values_graph_OXY2[SPO2_function_value_pos_OXY2] = SPO2_OXY2_value;
            SPO2_function_value_pos_OXY2++;

            if(SPO2_function_value_pos_OXY2 >= SPO2_FUNCTION_BUFFER_SIZE){
                SPO2_function_value_pos_OXY2=0;
                SPO2_buffer_full_OXY2 = true;
            }
        }
        ui->l_MO_OXY2->setText(QString("Ox2: ")+QString::number(MO_Motion_disturbance_OXY2));
        ui->l_NP_OXY2->setText(QString("Ox2: ")+QString::number(NP_No_pulse_OXY2));
        ui->l_SO_OXY2->setText(QString("Ox2: ")+QString::number(SO_Sensor_off_OXY2));
        ui->l_NS_OXY2->setText(QString("Ox2: ")+QString::number(NS_No_Sensor_connected_OXY2));
        ui->l_AI_OXY2->setText(QString("Ox2: ")+QString::number(AI_Light_ambient_disturbance_OXY2));
        ui->l_SP_OXY2->setText(QString("Ox2: ")+QString::number(SP_Search_pulse_OXY2));
        ui->l_LP_OXY2->setText(QString("Ox2: ")+QString::number(LP_Low_perfusion_OXY2));
        ui->l_SF_OXY2->setText(QString("Ox2: ")+QString::number(SF_Sensor_Fault_OXY2));



        if(SPO2_OXY1_value <= 100){
            ui->l_SPO2_value->setText("                  "+(QString::number((SPO2_OXY1_value)))+" %");
        }

        if(PI_value_OXY1 < 20000){////poner condicion de rango de PI
            ui->l_PI_value->setText("                  "+(QString::number((int)(PI_value_OXY1/1000)))+" %");
        }

        if(beat_per_minute_OXY1 <= 300 && beat_per_minute_OXY1 >= 0){
            ui->l_BPM_value->setText("                   "+(QString::number((beat_per_minute_OXY1))));
        }

        if(first_receive){
            if(function_value_pos >= FUNCTION_BUFFER_SIZE*2){
                first_receive = false;
                thread_update_graph->start_timer();
            }
        }

        //            memcpy( function_values_graph_HR, &receive_bytes[10], sizeof(function_values_graph_HR));

        //            if(receive_bytes[4] == 0x09B){
        //                memcpy( function_values_graph_0, &receive_bytes[73], sizeof(function_values_graph_0));
        //            }else{
        //                memcpy( function_values_graph_1, &receive_bytes[73], sizeof(function_values_graph_1));
        //            }
        //}

        valid_receive_data = false;
        last_bad_receive_pos -= UART_SEND_TOTAL_SIZE;
        if(last_bad_receive_pos > 0){
            memcpy( &receive_bytes[0], &receive_bytes[UART_SEND_TOTAL_SIZE], last_bad_receive_pos);
        }
        else{
            for(int i=0; i < UART_SEND_TOTAL_SIZE; i++){
                receive_bytes[i] = 0;
            }
        }

    }
    //------------------------------------------------------------------------------------------------------------------------

}
//----------------------------------------------------------------------------------------------------------------------------


// Funciones de configuracion de graficos-----------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------
void MainWindow::setupGraph(){   //OXYmetro 1

    customPlot_graph_0 = (QCustomPlot *)ui->widget;

    QVector<double> time_x_axis(100),concentration_y_axis(100);

    for(int i=0; i< 100; i++){
        time_x_axis[i]=0;
        concentration_y_axis[i]=0;

    }

    customPlot_graph_0->addGraph();
    customPlot_graph_0->graph(0)->setData(time_x_axis,concentration_y_axis);

    customPlot_graph_0->xAxis->setLabel("tiempo");
    customPlot_graph_0->yAxis->setLabel("concentracion");

    customPlot_graph_0->xAxis->setRange(0,120);
    customPlot_graph_0->yAxis->setRange(0,100);


    customPlot_graph_0->xAxis->setTickLabelRotation(60);

    customPlot_graph_0->xAxis->setTickLength(0, 4);


    // Configuracion de graficas------------------------------------------------------------------------------------------------
    customPlot_graph_0->setBackground(QBrush(QColor(236,239,241)));
    customPlot_graph_0->setAutoFillBackground(true);
    customPlot_graph_0->setFixedSize(QSize(560,300));

    customPlot_graph_0->move(65,410);
    //------------------------------------------------------------------------------------------------------------------------

    customPlot_graph_0->graph(0)->setName("customPlot");
    //customPlot_graph_0->graph(0)->setPen(QPen(QColor(0, 168, 140).lighter(10)));
    //customPlot_graph_0->graph(0)->setBrush(QColor(0, 168, 140));

    customPlot_graph_0->replot();


}

void MainWindow::setupGraph_Bar(){ //OXYmetro 2

    customPlot_graph_1 = (QCustomPlot *)ui->widget_2;

    QVector<double> time_x_axis(100),concentration_y_axis(100);

    for(int i=0; i< 100; i++){
        time_x_axis[i]=0;
        concentration_y_axis[i]=0;

    }

    customPlot_graph_1->addGraph();
    customPlot_graph_1->graph(0)->setData(time_x_axis,concentration_y_axis);

    customPlot_graph_1->xAxis->setLabel("tiempo");
    customPlot_graph_1->yAxis->setLabel("concentracion");

    customPlot_graph_1->xAxis->setRange(0,120);
    customPlot_graph_1->yAxis->setRange(0,100);


    customPlot_graph_1->xAxis->setTickLabelRotation(60);

    customPlot_graph_1->xAxis->setTickLength(0, 4);

    // Configuracion de graficas------------------------------------------------------------------------------------------------
    customPlot_graph_1->setBackground(QBrush(QColor(236,239,241)));
    customPlot_graph_1->setAutoFillBackground(true);
    customPlot_graph_1->setFixedSize(QSize(560,300));

    customPlot_graph_1->move(720,410);
    //------------------------------------------------------------------------------------------------------------------------

    customPlot_graph_1->graph(0)->setName("Oxymetry CH1");
    //customPlot_graph_1->graph(0)->setPen(QPen(QColor(0, 168, 140).lighter(150)));
    //customPlot_graph_1->graph(0)->setBrush(QColor(0, 168, 140));

    customPlot_graph_1->replot();
}

void MainWindow::setupGraph_HR()  //ADC cardiometria
{
    customPlot_HR = (QCustomPlot *)ui->widget_graph_HR;

    QVector<double> time_x_axis(100),concentration_y_axis(100);

    for(int i=0; i< 100; i++){
        time_x_axis[i]=0;
        concentration_y_axis[i]=0;

    }

    customPlot_HR->addGraph();
    customPlot_HR->graph(0)->setData(time_x_axis,concentration_y_axis);

    customPlot_HR->xAxis->setLabel("tiempo");
    customPlot_HR->yAxis->setLabel("Pulso");

    customPlot_HR->xAxis->setRange(0,500);
    customPlot_HR->yAxis->setRange(0,270);

    customPlot_HR->xAxis->setTickLabelRotation(60);

    customPlot_HR->xAxis->setTickLength(0, 4);

    // Configuracion de graficas------------------------------------------------------------------------------------------------
    customPlot_HR->setBackground(QBrush(QColor(236,239,241)));
    customPlot_HR->setAutoFillBackground(true);
    customPlot_HR->setFixedSize(QSize(560,300));

    customPlot_HR->move(65,50);
    //    //------------------------------------------------------------------------------------------------------------------------

    customPlot_HR->graph(0)->setName("Oxymetry CH0");
    customPlot_HR->graph(0)->setPen(QPen(QColor(255, 0, 0).lighter(130)));
    //customPlot_HR->graph(0)->setBrush(QColor(255, 84, 70));

    customPlot_HR->replot();

}

void MainWindow::reiniciar_graficas(){

    ftdi_serial_port->flush();

    primera_vuelta=true; ////en caso de que no se haya llegado a un minuto;
    SPO2_buffer_full_OXY1 = false;
    SPO2_buffer_full_OXY2 = false;

    SPO2_OXY1_value=0;  //ultimo valor enviado por oximetro1
    SPO2_OXY2_value=0;
    SPO2_average_value_OXY1 = 0;
    SPO2_average_value_OXY2 = 0;
    beat_per_minute_OXY1=0;
    beat_per_minute_OXY2=0;
    beat_per_minute_OXY1_average=0;
    beat_per_minute_OXY2_average=0;
    x_axis_count=0;

    beat_per_minute_LOW =0;
    beat_per_minute_HIGH =0;
    PI_value_OXY1 = 0;  // perfusion_index
    PI_value_OXY2 = 0;  // perfusion_index
    PI_value_OXY1_average = 0;  // perfusion_index
    PI_value_OXY2_average = 0;  // perfusion_index

    PI_LOW=0;
    PI_HIGH=0;

    HR_value_pos=0;
    function_value_count=0;
    HR_value_count=0;
    function_value_pos =0;

    first_receive = true;

    valid_receive_data = false;
    last_bad_receive_pos = 0;

    for(int i=0;i<4;i++){

        keyData_graph_HR[i] = i+1;
        valueData_graph_HR[i] = i+1;
    }

    x_axis_count =0; ///Verificar que esto funciona

    customPlot_graph_0->graph(0)->data()->clear();
    customPlot_graph_0->clearGraphs();
    setupGraph();

    customPlot_graph_1->graph(0)->data()->clear();
    customPlot_graph_1->clearGraphs();
    setupGraph_Bar();

    customPlot_HR->graph(0)->data()->clear();
    customPlot_HR->clearGraphs();
    setupGraph_HR();
}
//----------------------------------------------------------------------------------------------------------------------------


// Funcion de desborde de timer ----------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------
void MainWindow::on_time_out(){

    if(ver_registro_activated){

        ui->l_SPO2_value->setText("                  "+(QString::number((bebe_object.SPO2_bebe_value_average_OXY1)))+" %");
        ui->l_PI_value->setText("                  "+(QString::number((bebe_object.PI_value_average_OXY1)))+" %");
        ui->l_BPM_value->setText("                   "+(QString::number((bebe_object.beats_per_minute_value_average_OXY1))));

        if(bebe_object.function_0_data_bebe[ver_registro_counter] < 128){

            // Incremento el valor del eje x, si paso de 60 traslado el eje hacia la izquierda-------------------------
            //---------------------------------------------------------------------------------------------------------
            // ui->amplitudeWidget->replot(QCustomPlot::rpImmediate);

            quint64 HR_value_count_recorded = ver_registro_counter*4;

            if(HR_value_count_recorded >= 400)
                customPlot_HR->xAxis->setRange(HR_value_count_recorded- 400,HR_value_count_recorded + 100);
            //memcpy( &valueData_graph_HR[0], (double*)&function_values_graph_HR[HR_value_count], (sizeof(double))*4);

            for(int i=0; i<4; i++){
                //keyData_graph_HR_recorded[i]+=4;
                valueData_graph_HR_recorded[i]= bebe_object.HR_data_bebe[HR_value_count_recorded+i];
            }

            customPlot_HR->graph(0)->addData(keyData_graph_HR_recorded, valueData_graph_HR_recorded);

            for(int i=0; i<4; i++){
                keyData_graph_HR_recorded[i]+=4;
            }

            customPlot_HR->replot();

            if(ver_registro_counter >= 100)
                customPlot_graph_0->xAxis->setRange(ver_registro_counter- 100,ver_registro_counter + 25 );

            customPlot_graph_0->graph(0)->addData(ver_registro_counter, bebe_object.function_0_data_bebe[ver_registro_counter]);
            customPlot_graph_0->replot();

            if(ver_registro_counter >= 100)
                customPlot_graph_1->xAxis->setRange(ver_registro_counter- 100,ver_registro_counter + 25 );

            customPlot_graph_1->graph(0)->addData(ver_registro_counter, bebe_object.function_1_data_bebe[ver_registro_counter]);
            customPlot_graph_1->replot();

            ver_registro_counter++;

            //            if(ver_registro_counter >= 1149){

            //                 QMessageBox::information(this,"Informacion","Error desconocido ",QMessageBox::Ok);
            //            }

            if(ver_registro_counter >= bebe_object.data_function_size){

                //                ftdi_serial_port->flush();

                //                QObject::connect(ftdi_serial_port,SIGNAL(readyRead()),this,SLOT(readSerial()));
                timer->stop();
                ver_registro_counter=0;
                ver_registro_activated=false;


                customPlot_graph_0->graph(0)->data()->clear();
                customPlot_graph_0->clearGraphs();
                setupGraph();

                customPlot_graph_1->graph(0)->data()->clear();
                customPlot_graph_1->clearGraphs();
                setupGraph_Bar();

                customPlot_HR->graph(0)->data()->clear();
                customPlot_HR->clearGraphs();
                setupGraph_HR();

                QMessageBox::information(this,"Informacion","Se ha llegado al límite máximo de muestras ",QMessageBox::Ok);

                if(!signal_ready_read_connected){
                    QObject::connect(ftdi_serial_port,SIGNAL(readyRead()),this,SLOT(readSerial()));
                    signal_ready_read_connected = true;
                }
                thread_update_graph->start_timer();

                return;
            }

        }
    }
    else{




    }
}
//----------------------------------------------------------------------------------------------------------------------------


// Funcion q llena buffer de envio con datos de relleno-----------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------
void MainWindow::send_trash_bytes(){

    send_bytes.clear();

    send_bytes.append((char)0);
    send_bytes.append((char)0);
    send_bytes.append((char)0);
    send_bytes.append((char)0);

    ftdi_serial_port->write(send_bytes);
}
//----------------------------------------------------------------------------------------------------------------------------

//Esta funcion hay q borrarla-------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------
void MainWindow::send_config_commands(){

    if(protocol_count==0){
        protocol_shake_hands();
        ftdi_serial_port->write(send_bytes);
        //send_trash_bytes();
        timer->start();  // inicio del timer enesta funcion
        //while(!timer_tick);
        //timer_tick=false;
    }
    if(protocol_count==1){
        inq_calculating_sensitivity();
        ftdi_serial_port->write(send_bytes);
        //send_trash_bytes();
        //timer->start();
        //while(!timer_tick);
        //timer_tick=false;
    }
    if(protocol_count==2){
        inq_measurant_mode();
        ftdi_serial_port->write(send_bytes);
        //send_trash_bytes();
        //timer->start();
        //while(!timer_tick);
        //timer_tick=false;
    }
    if(protocol_count==3){
        inq_system_self_test();
        ftdi_serial_port->write(send_bytes);
        //send_trash_bytes();
        //timer->start();
        //while(!timer_tick);
        //timer_tick=false;
    }
    if(protocol_count==4){
        inq_type_version_No();
        ftdi_serial_port->write(send_bytes);
        //send_trash_bytes();
        //timer->start();
        //while(!timer_tick);
        //timer_tick=false;
    }
    if(protocol_count==5){
        set_calculating_sensivity();
        ftdi_serial_port->write(send_bytes);
        //send_trash_bytes();
        //timer->start();
        //while(!timer_tick);
        //timer_tick=false;
    }
    if(protocol_count==6){
        set_measurement_mode();
        ftdi_serial_port->write(send_bytes);
        //send_trash_bytes();
    }
}
//---------------------------------------------------------------------------------------------------------------------------

// Funcion de HANDSHAKE de comunicacion---------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------
void MainWindow::protocol_shake_hands(){

    send_bytes.clear();

    send_bytes.append(0x81);
    send_bytes.append(0x32);
    send_bytes.append(0x32);
    send_bytes.append((char)0);
}
//----------------------------------------------------------------------------------------------------------------------------


// Funciones de encuesta para saber estado del modulo-------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------
void MainWindow::inq_calculating_sensitivity(){

    send_bytes.clear();

    send_bytes.append(0x82);
    send_bytes.append((char)0);
    send_bytes.append((char)0);
    send_bytes.append((char)0);
}

void MainWindow::inq_measurant_mode(){

    send_bytes.clear();

    send_bytes.append(0x83);
    send_bytes.append((char)0);
    send_bytes.append((char)0);
    send_bytes.append((char)0);
}

void MainWindow::inq_system_self_test(){

    send_bytes.clear();

    send_bytes.append(0x84);
    send_bytes.append((char)0);
    send_bytes.append((char)0);
    send_bytes.append((char)0);
}

void MainWindow::inq_type_version_No(){

    send_bytes.clear();

    send_bytes.append(0x85);
    send_bytes.append((char)0);
    send_bytes.append((char)0);
    send_bytes.append((char)0);
}
//----------------------------------------------------------------------------------------------------------------------------


// Funciones para modificar parametros del modulo-----------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------
void MainWindow::set_calculating_sensivity(){

    send_bytes.clear();

    send_bytes.append(0x0A2);
    send_bytes.append(0x01);
    send_bytes.append(0x01);
    send_bytes.append((char)0);
}

void MainWindow::set_measurement_mode(){

    send_bytes.clear();

    send_bytes.append(0x0A3);
    send_bytes.append(0x01);
    send_bytes.append(0x01);
    send_bytes.append((char)0);
}
//----------------------------------------------------------------------------------------------------------------------------


// Funcion que me devuelve el chequeo de suma de datos a enviar--------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------
quint8 MainWindow::calculate_check_sum(){

    return send_bytes.at(2) + send_bytes.at(3);
}
//----------------------------------------------------------------------------------------------------------------------------


// Funcion de atencion de botones de ventana de paciente----------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------
void MainWindow::on_pbGuardar_clicked()
{
    qDebug()<<"funcion guardar";

    if(ui->le_name_mother->text().isEmpty()){

        qDebug()<<"line edit vacio";
        QMessageBox::information(this,"Informacion","Debe insertar nombre de la madre    ",QMessageBox::Ok);
        return;
    }

    if(data_base->open(QIODevice::Append))
    {

        qDebug()<<data_base->fileName();

        //QDataStream out(data_base);
        //out.setVersion(QDataStream::Qt_5_9);

        bebe_object.baby_name = ui->le_name_baby->text();
        bebe_object.mother_name = ui->le_name_mother->text();
        //bebe_object.write_file(out);

        ui->l_date->setText(bebe_object.date.toString());
        ui->l_time->setText(bebe_object.time.toString());

        if(!ui->lw_baby_list->isHidden()){

            ui->lw_baby_list->addItem(bebe_object.mother_name);
        }

        data_base->close();

        QMessageBox::information(this,"Informacion","Se ha guardado correctamente datos del bebe:  "+ui->le_name_baby->text()+"   ",QMessageBox::Ok);

        on_pb_window_graph_clicked();
    }
}

void MainWindow::on_pbBase_de_datos_clicked()
{

    ui->lw_baby_list->clear();

    ui->lw_baby_list->addItem(QString(" "));
    ui->lw_baby_list->addItem(QString(" "));
    ui->lw_baby_list->addItem(QString(" "));

    if(data_base->open(QIODevice::ReadOnly))
    {

        ui->pbAceptar->show();

        QDataStream in(data_base);
        //in.setVersion(QDataStream::Qt_5_9); //**********************************************qt version puede dar problemas

        ui->pbBase_de_datos->setEnabled(false);
        ui->lw_baby_list->show();

        //Bebe_Data_Class bebe("bb","mm");

        while(!data_base->atEnd()){

            bebe_object.read_file(in);

            /*
            for(int i=0; i < bebe.data_function_size; i++){

                qDebug()<<"i : "+QString::number(i)+" dato: "+QString::number(n.function_data_bebe[i]);
            }
            */
            ui->lw_baby_list->addItem(QString("                ")+bebe_object.mother_name);
            ui->lw_baby_list->addItem(QString("  "));
            name_list_mothers.append(bebe_object.mother_name);
            name_list_babies.append(bebe_object.baby_name);

        }


        data_base->close();
    }
    else{
        QMessageBox::information(this,"Informacion","No se ha podido cargar la base de datos   ",QMessageBox::Ok);
    }
}

void MainWindow::on_pbAceptar_clicked()
{
    ui->pbBase_de_datos->setEnabled(true);
    ui->lw_baby_list->hide();
    ui->pbAceptar->hide();
    name_list_mothers.clear();
    paciente_cargado = true;
}
//----------------------------------------------------------------------------------------------------------------------------


// Funcion de lista de pacientes guardados me pone paciente seleccionado en variable bebe_object------------------------------
//----------------------------------------------------------------------------------------------------------------------------
void MainWindow::on_lw_baby_list_itemClicked(QListWidgetItem *item)
{
    if(data_base->open(QIODevice::ReadOnly))
    {

        QDataStream in(data_base);
        //in.setVersion(QDataStream::Qt_5_9); //**********************************************qt version puede dar problemas

        bebe_object = Bebe_Data_Class("bb","mm"); //-------------------Aqui se borra lo que haya en bebe_object-------------------

        while(!data_base->atEnd()){

            bebe_object.read_file(in);

            if(item->text()== QString("                ")+bebe_object.mother_name){

                ui->le_name_baby->setText(bebe_object.baby_name);
                ui->le_name_mother->setText(bebe_object.mother_name);
                ui->l_date->setText(bebe_object.date.toString());
                ui->l_time->setText(bebe_object.time.toString());

                bebe_object.print_bebe_data();

                break;
            }

        }
        data_base->close();
    }
    else
        QMessageBox::information(this,"Informacion","No se ha podido agregar nombre desde base de datos  ",QMessageBox::Ok);


}
//----------------------------------------------------------------------------------------------------------------------------

// Funcion de lista de pacientes guardados me pone los pacientes que coinciden con el nombre escrito--------------------------
//----------------------------------------------------------------------------------------------------------------------------
void MainWindow::on_le_name_mother_textChanged(const QString &arg1)
{
    ui->lw_baby_list->clear();


    ui->lw_baby_list->addItem(QString(" "));
    ui->lw_baby_list->addItem(QString(" "));
    ui->lw_baby_list->addItem(QString(" "));

    QString name;

    //qDebug()<<name_list_mothers;

    if(arg1.isEmpty()){

        foreach (name, name_list_mothers) {

            ui->lw_baby_list->addItem(QString("                ")+name);
            ui->lw_baby_list->addItem(QString(" "));

        }
        return;
    }



    for(int i=0; i < name_list_mothers.length(); i++){

        //qDebug()<<name_list_mothers.at(i).left(arg1.length())+"  "+arg1;

        if(name_list_mothers.at(i).left(arg1.length())== arg1){

            ui->lw_baby_list->addItem(QString("                ")+name_list_mothers.at(i));
            ui->lw_baby_list->addItem(QString(" "));
        }
        else{

            //ui->lw_baby_list->item(i)->setText(ui->lw_baby_list->item(i)->text()+"    ----------");
        }
    }
}
//----------------------------------------------------------------------------------------------------------------------------


// Funcion de atencion de botones de ventana de graficas----------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------
void MainWindow::on_pbIniciar_clicked()
{
    //ui->pbIniciar->setText("...Conectado...");
    if(ui->le_name_mother->text().isEmpty()){

        qDebug()<<"line edit vacio";
        QMessageBox::information(this,"Informacion","Debe insertar nombre de la madre    ",QMessageBox::Ok);
        return;
    }

    //      ui->pbIniciar->setEnabled(false);
    //      ui->pbDetener->setEnabled(true);
    //      ui->pbDetener->show();
    //      ui->pbIniciar->hide();

    recording_activated = true;
    //timer->start();

    if(QMessageBox::Ok==QMessageBox::question(this,"CONFIRMACIÓN","Desea guardar datos recibidos",QMessageBox::Ok,QMessageBox::No)){

        if(data_base->open(QIODevice::Append))
        {

            if(signal_ready_read_connected){
                thread_update_graph->stop_timer();
                QObject::disconnect(ftdi_serial_port,SIGNAL(readyRead()),this,SLOT(readSerial()));
                signal_ready_read_connected = false;
            }

            qDebug()<<data_base->fileName();

            QDataStream out(data_base);
            //out.setVersion(QDataStream::Qt_5_9);

            //Bebe_Data_Class bebe(ui->le_name_baby->text(),ui->le_name_mother->text())//****************************cambio no comprobado
            bebe_object.baby_name = ui->le_name_baby->text();
            bebe_object.mother_name = ui->le_name_mother->text();
            bebe_object.date = QDate::currentDate();
            bebe_object.time = QTime::currentTime();
            bebe_object.beats_per_minute_value_average_OXY1 = beat_per_minute_OXY1_average;
            bebe_object.PI_value_average_OXY1 = PI_value_OXY1_average;
            bebe_object.beats_per_minute_value_average_OXY2 = beat_per_minute_OXY2_average;
            bebe_object.PI_value_average_OXY2 = PI_value_OXY2_average;


            if(primera_vuelta){

                memcpy(&(bebe_object.function_0_data_bebe[0]), &function_values_graph_0[0], function_value_pos);
                memcpy(&(bebe_object.function_1_data_bebe[0]), &function_values_graph_1[0], function_value_pos);
                memcpy(&(bebe_object.HR_data_bebe[0]), &function_values_graph_HR[0], HR_value_pos);

                bebe_object.data_function_size = function_value_pos;
                bebe_object.data_adc_buffer_size = HR_value_pos;



            }else{
                if(function_value_pos != DATA_FUNCTION_SIZE)
                    memcpy(bebe_object.function_0_data_bebe, &function_values_graph_0[function_value_pos], DATA_FUNCTION_SIZE - function_value_pos);
                if(function_value_pos != 0)
                    memcpy(&(bebe_object.function_0_data_bebe[DATA_FUNCTION_SIZE - function_value_pos]), &function_values_graph_0[0], function_value_pos);

                if(function_value_pos != DATA_FUNCTION_SIZE)
                    memcpy(bebe_object.function_1_data_bebe, &function_values_graph_1[function_value_pos], DATA_FUNCTION_SIZE - function_value_pos);
                if(function_value_pos != 0)
                    memcpy(&(bebe_object.function_1_data_bebe[DATA_FUNCTION_SIZE - function_value_pos]), &function_values_graph_1[0], function_value_pos);

                if(HR_value_pos != DATA_ADC_BUFFER_SIZE)
                    memcpy(bebe_object.HR_data_bebe, &function_values_graph_HR[HR_value_pos], DATA_ADC_BUFFER_SIZE - HR_value_pos);
                if(HR_value_pos != 0)
                    memcpy(&(bebe_object.HR_data_bebe[DATA_ADC_BUFFER_SIZE - HR_value_pos]), &function_values_graph_HR[0], HR_value_pos);

                bebe_object.data_function_size = DATA_FUNCTION_SIZE;
                bebe_object.data_adc_buffer_size = DATA_ADC_BUFFER_SIZE;
            }

            if(!SPO2_buffer_full_OXY1){

                memcpy(&(bebe_object.SPO2_function_OXY1_data_bebe[0]), &SPO2_function_values_graph_OXY1[0], SPO2_function_value_pos_OXY1);

                bebe_object.SPO2_data_function_OXY1_size = SPO2_function_value_pos_OXY1;

                for(int i=0; i<SPO2_function_value_pos_OXY1;i++){
                    SPO2_average_value_OXY1 += SPO2_function_values_graph_OXY1[i];
                }
                SPO2_average_value_OXY1 = SPO2_average_value_OXY1/SPO2_function_value_pos_OXY1;
                bebe_object.SPO2_bebe_value_average_OXY1 = (quint8)SPO2_average_value_OXY1;
            }
            else{

                if(SPO2_function_value_pos_OXY1 != SPO2_FUNCTION_BUFFER_SIZE)
                    memcpy(bebe_object.SPO2_function_OXY1_data_bebe, &SPO2_function_values_graph_OXY1[SPO2_function_value_pos_OXY1], SPO2_FUNCTION_BUFFER_SIZE - SPO2_function_value_pos_OXY1);
                if(SPO2_function_value_pos_OXY1 != 0)
                    memcpy(&(bebe_object.SPO2_function_OXY1_data_bebe[SPO2_FUNCTION_BUFFER_SIZE - SPO2_function_value_pos_OXY1]), &SPO2_function_values_graph_OXY1[0], SPO2_function_value_pos_OXY1);

                bebe_object.SPO2_data_function_OXY1_size = SPO2_FUNCTION_BUFFER_SIZE;

                for(int i=0; i<SPO2_FUNCTION_BUFFER_SIZE;i++){
                    SPO2_average_value_OXY1 += SPO2_function_values_graph_OXY1[i];
                }
                SPO2_average_value_OXY1 = SPO2_average_value_OXY1/SPO2_FUNCTION_BUFFER_SIZE;
                bebe_object.SPO2_bebe_value_average_OXY1 = (quint8)SPO2_average_value_OXY1;
            }

            if(!SPO2_buffer_full_OXY2){

                bebe_object.SPO2_data_function_OXY2_size = SPO2_function_value_pos_OXY2;

                memcpy(&(bebe_object.SPO2_function_OXY2_data_bebe[0]), &SPO2_function_values_graph_OXY2[0], SPO2_function_value_pos_OXY2);

                for(int i=0; i<SPO2_function_value_pos_OXY2;i++){
                    SPO2_average_value_OXY2 += SPO2_function_values_graph_OXY2[i];
                }
                SPO2_average_value_OXY2 = SPO2_average_value_OXY2/SPO2_function_value_pos_OXY2;
                bebe_object.SPO2_bebe_value_average_OXY2 = (quint8)SPO2_average_value_OXY2;
            }
            else{

                if(SPO2_function_value_pos_OXY2 != SPO2_FUNCTION_BUFFER_SIZE)
                    memcpy(bebe_object.SPO2_function_OXY2_data_bebe, &SPO2_function_values_graph_OXY2[SPO2_function_value_pos_OXY2], SPO2_FUNCTION_BUFFER_SIZE - SPO2_function_value_pos_OXY2);
                if(SPO2_function_value_pos_OXY2 != 0)
                    memcpy(&(bebe_object.SPO2_function_OXY2_data_bebe[SPO2_FUNCTION_BUFFER_SIZE - SPO2_function_value_pos_OXY2]), &SPO2_function_values_graph_OXY2[0], SPO2_function_value_pos_OXY2);

                bebe_object.SPO2_data_function_OXY2_size = SPO2_FUNCTION_BUFFER_SIZE;

                for(int i=0; i<SPO2_FUNCTION_BUFFER_SIZE;i++){
                    SPO2_average_value_OXY2 += SPO2_function_values_graph_OXY2[i];
                }
                SPO2_average_value_OXY2 = SPO2_average_value_OXY2/SPO2_FUNCTION_BUFFER_SIZE;
                bebe_object.SPO2_bebe_value_average_OXY2 = (quint8)SPO2_average_value_OXY2;
            }


            bebe_object.write_file(out);

            //              ui->l_date->setText(bebe_object.date.toString());
            //              ui->l_time->setText(bebe_object.time.toString());

            data_base->close();

            //on_pb_generar_reporte_clicked();


            if(!ui->lw_baby_list->isHidden()){

                ui->lw_baby_list->addItem(bebe_object.mother_name);
            }



            QMessageBox::information(this,"Informacion","Se ha guardado correctamente datos del bebe:  "+ui->le_name_baby->text()+"   ",QMessageBox::Ok);


            if(!signal_ready_read_connected){
                reiniciar_graficas();
                QObject::connect(ftdi_serial_port,SIGNAL(readyRead()),this,SLOT(readSerial()));
                signal_ready_read_connected = true;
            }
        }

    }

}

void MainWindow::on_pbDetener_clicked()
{
    ui->pbDetener->setEnabled(false);
    ui->pbIniciar->setEnabled(true);

    ui->pbIniciar->show();
    ui->pbDetener->hide();

    recording_activated = false;
    timer->stop();

    if(QMessageBox::Ok==QMessageBox::question(this,"CONFIRMACIÓN","Desea guardar datos recibidos",QMessageBox::Ok,QMessageBox::No)){

        if(data_base->open(QIODevice::Append))
        {
            qDebug()<<data_base->fileName();

            QDataStream out(data_base);
            //out.setVersion(QDataStream::Qt_5_9);

            //Bebe_Data_Class bebe(ui->le_name_baby->text(),ui->le_name_mother->text())//****************************cambio no comprobado

            bebe_object.write_file(out);

            ui->l_date->setText(bebe_object.date.toString());
            ui->l_time->setText(bebe_object.time.toString());

            if(!ui->lw_baby_list->isHidden()){

                ui->lw_baby_list->addItem(bebe_object.mother_name);
            }

            data_base->close();

            QMessageBox::information(this,"Informacion","Se ha guardado correctamente datos del bebe:  "+ui->le_name_baby->text()+"   ",QMessageBox::Ok);
        }
    }
}

void MainWindow::on_pbVer_Registro_clicked()
{
    if(!paciente_cargado){

        QMessageBox::information(this,"Cargar paciente", "No ha cargado un paciente de la base de datos");
        return;
    }

    thread_update_graph->stop_timer();

    if(signal_ready_read_connected){
        QObject::disconnect(ftdi_serial_port,SIGNAL(readyRead()),this,SLOT(readSerial()));
        signal_ready_read_connected = false;
    }
    delete timer;
    timer = new QTimer(this);
    timer->setInterval(16);
    connect(timer,SIGNAL(timeout()),this,SLOT(on_time_out()));

    for(int i=0;i<4;i++){  //Reiniciar datos de graficas en estado ver_registro

        keyData_graph_HR_recorded[i] = i+1;
        valueData_graph_HR_recorded[i] = i+1;
    }
    reiniciar_graficas();

    ver_registro_activated=true;

    ver_registro_counter =0;

    timer->start();
}
//----------------------------------------------------------------------------------------------------------------------------


// Funcion de atencion de botones de ventana de graficas----------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------
void MainWindow::on_pb_shake_hands_clicked()
{
    protocol_shake_hands();
    ftdi_serial_port->write(send_bytes);
}

void MainWindow::on_pb_cal_sen_clicked()
{
    inq_calculating_sensitivity();
    ftdi_serial_port->write(send_bytes);
}

void MainWindow::on_pb_mea_mode_clicked()
{
    inq_measurant_mode();
    ftdi_serial_port->write(send_bytes);
}

void MainWindow::on_pb_self_test_clicked()
{
    inq_system_self_test();
    ftdi_serial_port->write(send_bytes);
}

void MainWindow::on_pb_type_ver_clicked()
{
    inq_type_version_No();
    ftdi_serial_port->write(send_bytes);
}

void MainWindow::on_pb_set_cal_sen_clicked()
{
    set_calculating_sensivity();
    ftdi_serial_port->write(send_bytes);
}

void MainWindow::on_pb_set_mea_mode_clicked()
{
    set_measurement_mode();
    ftdi_serial_port->write(send_bytes);
}
//----------------------------------------------------------------------------------------------------------------------------


// Funciones de botones para cambiar de ventana-------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------
void MainWindow::on_pb_window_pacient_clicked()
{
    hide_all_objects();
    show_pacient_window();
    ui->pb_window_pacient->setIcon((QIcon(":photos/boton_paciente_blanco.png")));
    ui->pb_window_graph->setIcon((QIcon(":photos/boton_graficas.png")));
    ui->pb_window_config->setIcon((QIcon(":photos/boton_configuracion.png")));
}

void MainWindow::on_pb_window_graph_clicked()
{
    hide_all_objects();
    show_graph_window();
    ui->pb_window_pacient->setIcon((QIcon(":photos/boton_paciente.png")));
    ui->pb_window_graph->setIcon((QIcon(":photos/boton_graficas_blanco.png")));
    ui->pb_window_config->setIcon((QIcon(":photos/boton_configuracion.png")));

}

void MainWindow::on_pb_window_config_clicked()
{
    hide_all_objects();
    show_config_window();
    ui->pb_window_pacient->setIcon((QIcon(":photos/boton_paciente.png")));
    ui->pb_window_graph->setIcon((QIcon(":photos/boton_graficas.png")));
    ui->pb_window_config->setIcon((QIcon(":photos/boton_configuracion_blanco.png")));
}
//----------------------------------------------------------------------------------------------------------------------------


void MainWindow::on_actionAbout_Oximeter_triggered()
{
    QString info;
    QTextStream infoWriter(&info);
    infoWriter << QStringLiteral("Released under CNEURO license") << endl<< endl
               << QStringLiteral("Develop by:") << endl
               << QStringLiteral("Luis Alejandro Reyes Morales") << endl
               << QStringLiteral("Rene Ivan Gonzales Fernandez") << endl<< endl
               << QStringLiteral("Contact:") << endl
               << QStringLiteral("Luis A. Reyes Morales: luis.reyes@cneuro.edu.cu") << endl
               << QStringLiteral("Rene I. Gonzales Fernandez: rene.gonzalez@cneuro.edu.cu      ") << endl;
    QMessageBox::information(this, "Oxímetro", info);

}

void MainWindow::on_actionAbout_QtCreator_triggered()
{
    QApplication::aboutQt();
}

void MainWindow::on_pushButton_clicked()
{
    ui->pushButton->setEnabled(false);
    ui->pushButton->setText("Graficando...");
    char write_data[UART_SEND_TOTAL_SIZE];
    for (int i=0; i<16;++i){
        //write_data[i]=0x0AA;
        write_data[i]=INIT_SEND_ID;
    }
    ftdi_serial_port->write(write_data,16);

    ui->statusBar->showMessage("Enviando datos ---------------");

}

void MainWindow::on_pb_stop_play_graph_clicked()
{
    if(!thread_update_graph->timer_axis->isActive() && ui->pb_stop_play_graph->text() == "stop graph"){
        return;
    }
    if(thread_update_graph->timer_axis->isActive()){ //si esta andando el timer (timer_update_graph)

        thread_update_graph->stop_timer();
        timer->stop();
        ui->pb_stop_play_graph->setText("play graph");
    }
    else{

        thread_update_graph->start_timer();
        timer->start();
        ui->pb_stop_play_graph->setText("stop graph");
    }
}

void MainWindow::on_pb_generar_reporte_clicked()
{
    if(bebe_object.mother_name != "unknow"){

        int paso=40;

        QString dir_path = QFileDialog::getExistingDirectory(this,tr("Seleccione Carpeta para Guardar"));
        dir_path+=QString("/Reportes");
        QDir dir(dir_path);

        if (!dir.exists()) { // don't overwrite existing folders
            if (!dir.mkdir(dir_path)) {
                qDebug() << "Error creating directory: " <<  dir;
            }
        }



        QString file_name=QString("Reportes/Reporte de ") + bebe_object.mother_name+QString(".txt");
        int n = 1;
        while(QFile::exists(file_name)){
            n++;
            file_name = QString("Reportes/Reporte de ") + bebe_object.mother_name + QString(" numero ")+QString::number(n)+QString(".txt");
        }

        QFile *file = new QFile(file_name,this);
        file->open(QIODevice::WriteOnly);
        file->putChar('\n');
        //QDataStream stream_out(file);
        //stream_out << "Oximetro 1: \n";
        file->write("Oximetro 1:");
        file->write("\n");
        file->write("\n");

        if(primera_vuelta){

            for(unsigned int i=0; i< function_value_pos;i++){

                file->write(QString::number(function_values_graph_0[i]).toLatin1());
                file->write(",");
                if((i+1) % paso == 0){
                    file->write("\n");
                }
            }

        }
        else{
            for(unsigned int i=function_value_pos; i< DATA_FUNCTION_SIZE;i++){

                file->write(QString::number(function_values_graph_0[i]).toLatin1());
                file->write(",");
                if((i+1) % paso == 0){
                    file->write("\n");
                }
            }
            for(unsigned int i=0; i< function_value_pos;i++){

                file->write(QString::number(function_values_graph_0[i]).toLatin1());
                file->write(",");
                if((i+1) % paso == 0){
                    file->write("\n");
                }
            }
        }
        file->write("\n");
        file->write("\n");
        file->write("\n");
        file->write("\n");
        file->write("Oximetro 2:");
        file->write("\n");
        file->write("\n");
        if(primera_vuelta){

            for(unsigned int i=0; i< function_value_pos;i++){

                file->write(QString::number(function_values_graph_1[i]).toLatin1());
                file->write(",");
                if((i+1) % paso == 0){
                    file->write("\n");
                }
            }

        }
        else{
            for(unsigned int i=function_value_pos; i< DATA_FUNCTION_SIZE;i++){

                file->write(QString::number(function_values_graph_1[i]).toLatin1());
                file->write(",");
                if((i+1) % paso == 0){
                    file->write("\n");
                }
            }
            for(unsigned int i=0; i< function_value_pos;i++){

                file->write(QString::number(function_values_graph_1[i]).toLatin1());
                file->write(",");
                if((i+1) % paso == 0){
                    file->write("\n");
                }
            }
        }

        file->write("\n");
        file->write("\n");
        file->write("\n");
        file->write("\n");
        file->write("Electrocardiografia:");
        file->write("\n");
        file->write("\n");

        if(primera_vuelta){

            for(unsigned int i=0; i< HR_value_pos;i++){

                file->write(QString::number(function_values_graph_HR[i]).toLatin1());
                file->write(",");
                if((i+1) % paso == 0){
                    file->write("\n");
                }
            }
        }
        else{
            for(unsigned int i=HR_value_pos; i< DATA_ADC_BUFFER_SIZE;i++){

                file->write(QString::number(function_values_graph_HR[i]).toLatin1());
                file->write(",");
                if((i+1) % paso == 0){
                    file->write("\n");
                }
            }
            for(unsigned int i=0; i< HR_value_pos;i++){

                file->write(QString::number(function_values_graph_HR[i]).toLatin1());
                file->write(",");
                if((i+1) % paso == 0){
                    file->write("\n");
                }
            }
        }

        file->write("\n");
        file->write("\n");
        file->write("\n");
        file->write("\n");
        file->write("SPO2 OXYMETER 1:");
        file->write("\n");
        file->write("\n");

        if(!SPO2_buffer_full_OXY1){

            for(unsigned int i=0; i< SPO2_function_value_pos_OXY1;i++){

                file->write(QString::number(SPO2_function_values_graph_OXY1[i]).toLatin1());
                file->write(",");
                if((i+1) % paso == 0){
                    file->write("\n");
                }
            }

        }
        else{
            for(unsigned int i=SPO2_function_value_pos_OXY1; i< SPO2_FUNCTION_BUFFER_SIZE;i++){

                file->write(QString::number(SPO2_function_values_graph_OXY1[i]).toLatin1());
                file->write(",");
                if((i+1) % paso == 0){
                    file->write("\n");
                }
            }
            for(unsigned int i=0; i< SPO2_function_value_pos_OXY1;i++){

                file->write(QString::number(SPO2_function_values_graph_OXY1[i]).toLatin1());
                file->write(",");
                if((i+1) % paso == 0){
                    file->write("\n");
                }
            }
        }

        file->write("\n");
        file->write("\n");
        file->write("\n");
        file->write("\n");
        file->write("SPO2 OXYMETER 2:");
        file->write("\n");
        file->write("\n");

        if(!SPO2_buffer_full_OXY2){

            for(unsigned int i=0; i< SPO2_function_value_pos_OXY2;i++){

                file->write(QString::number(SPO2_function_values_graph_OXY2[i]).toLatin1());
                file->write(",");
                if((i+1) % paso == 0){
                    file->write("\n");
                }
            }

        }
        else{
            for(unsigned int i=SPO2_function_value_pos_OXY2; i< SPO2_FUNCTION_BUFFER_SIZE;i++){

                file->write(QString::number(SPO2_function_values_graph_OXY2[i]).toLatin1());
                file->write(",");
                if((i+1) % paso == 0){
                    file->write("\n");
                }
            }
            for(unsigned int i=0; i< SPO2_function_value_pos_OXY2;i++){

                file->write(QString::number(SPO2_function_values_graph_OXY2[i]).toLatin1());
                file->write(",");
                if((i+1) % paso == 0){
                    file->write("\n");
                }
            }
        }

        file->close();

        QMessageBox::information(this, "Reporte", file_name + QString(" generado correctamente"), QMessageBox::Ok);

        //x_axis_count = 0;



        if(!signal_ready_read_connected){

            reiniciar_graficas();
            QObject::connect(ftdi_serial_port,SIGNAL(readyRead()),this,SLOT(readSerial()));
            signal_ready_read_connected = true;
        }
    }
}
