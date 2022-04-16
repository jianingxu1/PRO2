#ifndef JUGADOR_HH
#define JUGADOR_HH

#include <iostream>
using namespace std;

/** @class Jugador
    @brief Representa un jugador
*/
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
    
    /** @brief Suma o elimina puntos al jugador
        \pre Si el booleano suma_resta es true, se le suma los puntos al jugador. Altramente, se le restan los puntos.
        \post Se le han sumado o restado los puntos al parámetro implícito.
    */ 
    void actualizar_puntos(int puntos, bool suma_resta);
};
#endif
