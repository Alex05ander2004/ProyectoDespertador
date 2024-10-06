#include <iostream>
#include <thread>
#include <chrono>
#include "despertador.h"

int main() {
    Despertador reloj;
    
    // Se configura la alarma para que suene 2 minutos después de la hora actual
    auto ahora = std::chrono::system_clock::now();
    time_t tiempoActual = std::chrono::system_clock::to_time_t(ahora);
    tm *tiempoLocal = localtime(&tiempoActual);
    int minutoAlarma = (tiempoLocal->tm_min + 2) % 60;
    int horaAlarma = tiempoLocal->tm_hour + (tiempoLocal->tm_min + 2) / 60;
    horaAlarma %= 24;

    reloj.configurarAlarma(horaAlarma, minutoAlarma);
    reloj.cambiarEstadoAlarma();

    std::cout << "Reloj iniciado. Alarma establecida para las " << reloj.obtenerHoraAlarma() << std::endl;

    while (true) {
        std::cout << "Hora actual: " << reloj.obtenerHoraActual() << "\r" << std::flush;
        
        if (reloj.esHoraAlarma()) {
            std::cout << std::endl << "¡ALARMA!" << std::endl;
            break;
        }

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}