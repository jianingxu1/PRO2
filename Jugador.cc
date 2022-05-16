/** @file Jugador.cc
    @brief Implementación de la clase Jugador
*/
#include "Jugador.hh"

// Constructoras
Jugador::Jugador() {
    posicion = 0;
    puntos = 0;
}

// Modificadoras
void Jugador::anadir_puntos(int puntos) {
    this->puntos += puntos;
}

void Jugador::anadir_estadisticas(const Estadisticas& estadisticas) {
    this->estadisticas.torneos_disputados += estadisticas.torneos_disputados;
    this->estadisticas.partidos_ganados += estadisticas.partidos_ganados;
    this->estadisticas.partidos_perdidos += estadisticas.partidos_perdidos;
    this->estadisticas.sets_ganados += estadisticas.sets_ganados;
    this->estadisticas.sets_perdidos += estadisticas.sets_perdidos;
    this->estadisticas.juegos_ganados += estadisticas.juegos_ganados;
    this->estadisticas.juegos_perdidos += estadisticas.juegos_perdidos;
}

void Jugador::modificar_posicion(int posicion) {
    this->posicion = posicion;
}

// Consultoras
int Jugador::consultar_posicion() const {
    return posicion;
}

int Jugador::consultar_puntos() const {
    return puntos;
}

// Escritura de un jugador
void Jugador::escribir() const {
    cout << "Rk:" << posicion << " Ps:" << puntos << " Ts:" << estadisticas.torneos_disputados 
         << " WM:" << estadisticas.partidos_ganados << " LM:" << estadisticas.partidos_perdidos
         << " WS:" << estadisticas.sets_ganados << " LS:" << estadisticas.sets_perdidos
         << " WG:" << estadisticas.juegos_ganados << " LG:" << estadisticas.juegos_perdidos
         << endl;
}