#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <ArduinoController.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:

    void _SetTextLabel(const QString &text);

    void _TurnOnOffLed(bool toggled);

    void _ReadData();

private:
    Ui::MainWindow *ui;
    ArduinoController *arduinoController;

};

#endif // MAINWINDOW_H
