#include <iostream>
#include <stdint.h>
#include <string.h>
#include <signal.h>
#include <stdio.h>

#include <QApplication>

#include "ui/mainwindow.h"
#include "mbm-sdr/tmp.h"

#include "spdlog/spdlog.h"

int main(int argc, char *argv[]){
    

    QApplication app(argc, argv);
    MainWindow mainWindow;

    mainWindow.show();
    

    return app.exec();

}



/* cleanup and exit */





