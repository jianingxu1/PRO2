#ifndef JUGADOR_HH
#define JUGADOR_HH

#include <iostream>
using namespace std;


class Jugador {
private:
    string p;       // identificador del jugador
    int puntos;
    int torneos_disputados;
    int partidos_ganados;
    int partidos_perdidos;
    int sets_ganados;
    int sets_perdidos;
    int juegos_ganados;
    int juegos_perdidos;
    
public:

    // Constructores

    /** @brief Constructora por defecto
        \pre Cierto.
        \post El resultado es un jugador sin identificador p y con todos sus atributos a cero.
    */ 
    Jugador();

    /** @brief Constructora
        \pre Cierto.
        \post El resultado es un jugador con identificador p y todos sus atributos a cero.
    */ 
    Jugador(int p);


    // Modificadores
};
#endif
