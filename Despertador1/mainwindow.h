#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTime>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void showTime();            //Hora
    void checkAlarm();          //Verifica alarma
    void goToAlarmsScreen();    // Ir a la pantalla de alarmas
    void goToAddAlarmScreen();  // Ir a la pantalla para añadir una alarma
    void addAlarm();            // Añadir una nueva alarma
    void goToClockScreen();     // Volver a la pantalla del reloj
    void goToAlarmScreen();     // Volver a la pantalla del reloj
    void ReturnToAlarmsScreen();     // Volver a la pantalla de alarmas

private:
    Ui::MainWindow *ui;
    QTime alarmTime;          //Almacena la hora de la alarma
    bool alarmSet;            //Estado de alarma
    QList<QTime> alarms;      // Lista de alarmas

};
#endif // MAINWINDOW_H
