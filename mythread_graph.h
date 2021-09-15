#ifndef MYTHREAD_GRAPH_H
#define MYTHREAD_GRAPH_H

#include <QThread>

#ifndef TIMER_TIMEOUT_ADC_READ
#include "globals.h"
#endif

#include <QTimer>

using namespace std;

class MyThread_Graph : public QThread
{
    Q_OBJECT

public:
    explicit MyThread_Graph(QObject *parent = 0);
    QTimer *timer_axis;
    bool timer_finished;

public slots:

    void on_time_out_update_axis();
    void start_timer();
    void process_Data();
    bool stop();
    //void run();

    void stop_timer();
signals:
    void process_data_graph_finished(const bool result);
};

#endif // MYTHREAD_GRAPH_H
