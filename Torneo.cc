#include "Torneo.hh"

Torneo::Torneo(int c) {
    this->c = c;
    iniciado = false;
    primera_edicion = true;
}

void Torneo::eliminar_puntos(Cjt_jugadores& jugadores_global) {
    for (int i = 0; i < n; ++i) {
        if (jugadores_edicion_actual[i].second != 0) {
            jugadores_global.sumar_puntos_jugador(jugadores_edicion_actual[i].first, -jugadores_edicion_actual[i].second);
        }
    }
}

int Torneo::consultar_categoria() const {
    return c;
}