#include "mythread_graph.h"
#include <QtCore>

MyThread_Graph::MyThread_Graph(QObject *parent)
{
    // Temporizacion para eje x----------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------------------------
    timer_axis = new QTimer(this);
    connect(timer_axis,SIGNAL(timeout()),this,SLOT(on_time_out_update_axis()));
    timer_axis->setInterval(16);
    timer_finished = false;
    //------------------------------------------------------------------------------------------------------------------------
}

void MyThread_Graph::on_time_out_update_axis()
{
    //timer_axis->stop();
    timer_finished = true;
    emit process_data_graph_finished(timer_finished);
}

void MyThread_Graph::start_timer()
{
    timer_axis->start();
}

void MyThread_Graph::stop_timer()
{
    timer_axis->stop();
}

void MyThread_Graph::process_Data()
{
    return;
}

//void MyThread_Graph::run()
//{

//}

bool MyThread_Graph::stop()
{
   return true;
}
