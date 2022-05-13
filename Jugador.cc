#include "Jugador.hh"

Jugador::Jugador() {
    puntos = 0;
    torneos_disputados = 0;
    partidos_ganados = 0;
    partidos_perdidos = 0;
    sets_ganados = 0;
    sets_perdidos = 0;
    juegos_ganados = 0;
    juegos_perdidos = 0;
}

void Jugador::sumar_puntos(int puntos) {
    this->puntos += puntos;
}

void Jugador::actualizar_estadisticas(const Estadisticas& estadisticas) {
    ++torneos_disputados;
    partidos_ganados += estadisticas.partidos_ganados;
    partidos_perdidos += estadisticas.partidos_perdidos;
    sets_ganados += estadisticas.sets_ganados;
    sets_perdidos += estadisticas.sets_perdidos;
    juegos_ganados += estadisticas.juegos_ganados;
    juegos_perdidos += estadisticas.juegos_perdidos;
}

int Jugador::consultar_posicion() const {
    return posicion;
}

void Jugador::actualizar_posicion(int posicion) {
    this->posicion = posicion;
}

int Jugador::consultar_puntos() const {
    return puntos;
}

void Jugador::escribir() const {
    cout << "Rk:" << posicion << " Ps:" << puntos << " Ts:" << torneos_disputados <<
    " WM:" << partidos_ganados << " LM:" << partidos_perdidos << " WS:" << sets_ganados <<
    " LS:" << sets_perdidos << " WG:" << juegos_ganados << " LG:" << juegos_perdidos << endl;
}