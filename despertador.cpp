#include "despertador.h"
#include <iomanip>
#include <sstream>
#include <ctime>

Despertador::Despertador(QObject *parent) : QObject(parent), alarmaActivada(false) {}

void Despertador::configurarAlarma(int h, int m) {
    auto ahora = std::chrono::system_clock::now();
    time_t tiempoActual = std::chrono::system_clock::to_time_t(ahora);
    tm *tiempoLocal = localtime(&tiempoActual);

    tiempoLocal->tm_hour = h;
    tiempoLocal->tm_min = m;
    tiempoLocal->tm_sec = 0;

    tiempoAlarma = std::chrono::system_clock::from_time_t(mktime(tiempoLocal));

    if (tiempoAlarma <= ahora) {
        tiempoAlarma += std::chrono::hours(24);
    }
}

std::string Despertador::obtenerHoraActual() const {
    auto ahora = std::chrono::system_clock::now();
    time_t tiempoActual = std::chrono::system_clock::to_time_t(ahora);
    tm *tiempoLocal = localtime(&tiempoActual);

    std::ostringstream oss;
    oss << std::setfill('0') << std::setw(2) << tiempoLocal->tm_hour << ":"
        << std::setfill('0') << std::setw(2) << tiempoLocal->tm_min << ":"
        << std::setfill('0') << std::setw(2) << tiempoLocal->tm_sec;
    return oss.str();
}

std::string Despertador::obtenerHoraAlarma() const {
    time_t tiempoAlarmaT = std::chrono::system_clock::to_time_t(tiempoAlarma);
    tm *tiempoAlarmaLocal = localtime(&tiempoAlarmaT);

    std::ostringstream oss;
    oss << std::setfill('0') << std::setw(2) << tiempoAlarmaLocal->tm_hour << ":"
        << std::setfill('0') << std::setw(2) << tiempoAlarmaLocal->tm_min;
    return oss.str();
}

bool Despertador::esHoraAlarma() const {
    if (!alarmaAct
