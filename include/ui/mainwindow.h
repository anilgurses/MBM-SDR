#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "mbm-sdr/deviceManager.h"
#include "mbm-sdr/configReader.h"

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
   #ifdef _WIN64
      //Windows (64-bit only)
   #else
      //Windows (32-bit only)
   #endif
#elif __linux__
    #include <iio.h>
#elif __APPLE__
    #include <iio/iio.h>
#endif



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_refreshDeviceBtn_clicked();
    
    void on_releaseDevice_clicked();
    

private:
    Ui::MainWindow *ui;

    deviceManager dManager;
    configReader cReader;


};

#endif // MAINWINDOW_H
