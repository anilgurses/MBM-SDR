#include "ui/mainwindow.h"
#include "../uiDesign/ui_mainwindow.h"
#include "spdlog/spdlog.h"

#include "mbm-sdr/definitions.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    

    std::string cfgPatg = "config.json";
    
    if(cReader.readConfig(cfgPatg)) {
        spdlog::info("Config found on path: {}", cfgPatg);
    }else {
        spdlog::error("Config is not found. Exiting...");
    }

    std::string deviceType = cReader.getConfigForKey(KEY_TYPE);
    
    spdlog::info("Device Type: {}", deviceType);

    auto isDeviceExist = dManager.isExist();

    if(isDeviceExist){
        spdlog::info("Device Found. Count : {}", dManager.getDeviceCount());
    }else{
        spdlog::error("Device Not Found.");
    }

    spdlog::info("Software Init Completed. Starting ");

    if(deviceType == "tx") {

    }else if(deviceType == "rx") {
        
    }else {
        spdlog::error("Device type configuration wrong. It must be tx or rx");
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_refreshDeviceBtn_clicked()
{
    struct iio_context *ctx;
    ctx = iio_create_default_context();
    iio_context_get_devices_count(ctx);

    struct iio_device *tx;

    dManager.get_ad9361_stream_dev(ctx, 0, &tx);
    spdlog::info("Device refreshed");
    
}

void MainWindow::on_releaseDevice_clicked()
{
    
}




