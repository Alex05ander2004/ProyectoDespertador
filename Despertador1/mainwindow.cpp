#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QTimer>
#include<QDateTime>
#include<QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTimer *timer=new QTimer(this);

    connect(timer , SIGNAL(timeout()),this,SLOT(showTime()));
    connect(timer, SIGNAL(timeout()), this, SLOT(checkAlarm()));  // Ejecutar checkAlarm periódicamente
    timer->start();

    QDateTime dateTime=QDateTime::currentDateTime();
    QString datetimetext=dateTime.toString();
    ui->DateTime_->setText(datetimetext);
    // Actualizar la hora cada segundo
    connect(timer, SIGNAL(timeout()), this, SLOT(updateDateTime()));  // Actualizar la fecha y hora
    timer->start();

    // Conectar el botón "Ver Alarmas" con la función para cambiar a la pantalla de alarmas
    connect(ui->alarmsButton, &QPushButton::clicked, this, &MainWindow::ReturnToAlarmsScreen);

    // Conectar el botón "+" (añadir alarma) para ir a la pantalla de agregar alarma
    connect(ui->addAlarmButton, &QPushButton::clicked, this, &MainWindow::goToAddAlarmScreen);

    // Conectar el botón para añadir la alarma seleccionada
    connect(ui->confirmAddAlarmButton, &QPushButton::clicked, this, &MainWindow::addAlarm);

    // Botón para volver al reloj desde la pantalla de agregar alarma
    connect(ui->backToClockButton, &QPushButton::clicked, this, &MainWindow::goToAlarmScreen);

    // Botón para volver al reloj desde la pantalla de agregar alarma
    connect(ui->ReturnButton, &QPushButton::clicked, this, &MainWindow::goToClockScreen);


}

void MainWindow::showTime()
{
    QTime time = QTime::currentTime();
    QString time_text = time.toString("hh : mm : ss");
    ui->Digital_clock->setText(time_text);

}

void MainWindow::checkAlarm()
{
    QTime currentTime = QTime::currentTime();
    for (QTime alarm : alarms) {
        if (alarm.hour() == currentTime.hour() && alarm.minute() == currentTime.minute()) {
            QMessageBox::information(this, "Alarma", "¡Es hora de una alarma!");
            alarms.removeOne(alarm);
            break;
        }
    }
}

void MainWindow::ReturnToAlarmsScreen()
{
    ui->stackedWidget->setCurrentIndex(2);  // Cambia a la pantalla de alarmas

}

void MainWindow::goToAlarmsScreen()
{
    ui->stackedWidget->setCurrentIndex(2);  // Cambia a la pantalla de alarmas

    // Mostrar las alarmas que ya están configuradas
    for (QTime alarm : alarms) {
        ui->alarmListWidget->addItem(alarm.toString("hh:mm"));
    }
}

void MainWindow::goToAddAlarmScreen()
{
    ui->stackedWidget->setCurrentIndex(1);  // Cambia a la pantalla para añadir una nueva alarma
}

void MainWindow::addAlarm()
{
    QTime newAlarm = ui->alarmTimeEdit->time();  // Obtener la hora de la alarma seleccionada
    alarms.append(newAlarm);

    // Volver a la pantalla de alarmas y actualizar la lista
    goToAlarmsScreen();
}

void MainWindow::updateDateTime()
{
    QDateTime dateTime = QDateTime::currentDateTime();
    QString datetimetext = dateTime.toString("yyyy-MM-dd hh:mm:ss");  // Puedes personalizar el formato si lo deseas
    ui->DateTime_->setText(datetimetext);  // Actualizar el widget con la nueva fecha y hora
}

void MainWindow::goToAlarmScreen()
{
    ui->stackedWidget->setCurrentIndex(2);  // Volver a la pantalla de alarma
}

void MainWindow::goToClockScreen()
{
    ui->stackedWidget->setCurrentIndex(0);  // Volver a la alarma(alarmas)
}


MainWindow::~MainWindow()
{
    delete ui;
}
