#include "Torneo.hh"

Torneo::Torneo(int c) {
    n = 0;
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

void Torneo::iniciar(const Cjt_jugadores& jugadores_global) {
    iniciado = true;
    int n;
    cin >> n;
    this->n = n;
    jugadores_edicion_actual = vector< pair<string, int> >(n);
    for (int r = 0; r < n; ++r) {
        int posicion;
        cin >> posicion;
        string nombre_jugador = jugadores_global.consultar_jugador_ranking(posicion);
        jugadores_edicion_actual[r] = make_pair(nombre_jugador, 0);
    }
    // crear_cuadro_emparejamientos();
    // imprimir_cuadro_emparejamientos();
}

int Torneo::consultar_categoria() const {
    return c;
}