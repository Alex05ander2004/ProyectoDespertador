#ifndef DESPERTADOR_H
#define DESPERTADOR_H

#include <QObject>
#include <string>
#include <chrono>

class Despertador : public QObject {
    Q_OBJECT

private:
    std::chrono::system_clock::time_point tiempoAlarma;
    bool alarmaActivada;

public:
    explicit Despertador(QObject *parent = nullptr);
    void configurarAlarma(int h, int m);
    std::string obtenerHoraActual() const;
    std::string obtenerHoraAlarma() const;
    bool esHoraAlarma() const;
    void cambiarEstadoAlarma();

signals:
    void alarmaSonando();
};

#endif // DESPERTADOR_H
