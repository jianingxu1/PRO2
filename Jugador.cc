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