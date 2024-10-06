#ifndef DESPERTADOR_H
#define DESPERTADOR_H

#include <string>
#include <chrono>

class Despertador {
private:
    std::chrono::system_clock::time_point tiempoAlarma;
    bool alarmaActivada;

public:
    Despertador();
    void configurarAlarma(int h, int m);
    std::string obtenerHoraActual() const;
    std::string obtenerHoraAlarma() const;
    bool esHoraAlarma() const;
    void cambiarEstadoAlarma();
};

#endif // DESPERTADOR_H