#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    arduinoController = new ArduinoController();

    connect(this->ui->pushButton, SIGNAL(pressed()), arduinoController, SLOT(FindAndConnect()));
    connect(arduinoController, SIGNAL(connectedSignal(const QString &)), this, SLOT(_SetTextLabel(const QString &)));
    connect(arduinoController, SIGNAL(notConnectedSignal(const QString &)), this, SLOT(_SetTextLabel(const QString &)));
    connect(this->ui->pushButton_2, SIGNAL(toggled(bool)), this, SLOT(_TurnOnOffLed(bool)));
    connect(this->ui->pushButton_3, SIGNAL(pressed()), this, SLOT(_ReadData()));

    arduinoController->FindAndConnect();
}

void MainWindow::_SetTextLabel(const QString &text) {
     ui->label->setText(text);
}

void MainWindow::_TurnOnOffLed(bool toggled) {
    if(toggled){
        arduinoController->Write("1\n");
    }
    else{
        arduinoController->Write("2\n");
    }
}

void MainWindow::_ReadData()
{
    ui->lcdNumber->display(0);
    if( arduinoController->Write("3\n") == 0)
    {
        QByteArray data;
        if(arduinoController->Read(data)==0) {
            ui->lcdNumber->display(data.toInt());
        }
    }
}

MainWindow::~MainWindow()
{
    if(arduinoController)
        delete arduinoController;
}
