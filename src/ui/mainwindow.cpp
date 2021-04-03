#include "ui/mainwindow.h"
#include "../uiDesign/ui_mainwindow.h"
#include "spdlog/spdlog.h"
#include <vector>

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

    dManager.getDeviceList(dList);
    ui->comboBox->addItem("Not Selected");
    for(auto& d: dList) {
        ui->comboBox->addItem(QString::fromStdString(d));
    }
 
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_releaseDevice_clicked()
{
    
}

void MainWindow::on_getDeviceBtn_clicked()
{
    struct iio_context *ctx;

    int dvInd = ui->comboBox->currentIndex() - 1;
    if(dvInd < 0) {
        spdlog::error("Device is not selected");
    }

    ctx = iio_create_context_from_uri(&dList[dvInd][0]);

    if (!ctx) {
		spdlog::error("Unable to create IIO context");
		return;
	}

    struct iio_device *tx;

    bool res = dManager.get_ad9361_stream_dev(ctx, 0, &tx);
    if(res) {
        ui->deviceGet->setText("Device retrieved");
        ui->releaseDevice->setEnabled(true);
        ui->getDeviceBtn->setEnabled(false);
    }
}


