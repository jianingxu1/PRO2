#ifndef JUGADOR_HH
#define JUGADOR_HH

#ifndef NO_DIAGRAM
#include <iostream>
using namespace std;
#endif

/** @class Jugador
    @brief Representa un jugador
*/
class Jugador {

private:

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
        \post El resultado es un jugador con todos sus atributos a cero.
    */
    Jugador();


    // Modificadores
    
    /** @brief Suma o elimina puntos al jugador
        \pre Si el booleano suma_resta es true, se le suma los puntos al jugador. Altramente, se le restan los puntos.
        \post Se le han sumado o restado los puntos al parámetro implícito.
    */ 
    void actualizar_puntos(int puntos, bool suma_resta);


    // Consultores

    /** @brief Consulta los puntos del jugador
        \pre Cierto.
        \post Retorna los puntos del parámetro implícito.
    */ 
    int consultar_puntos() const;
};
#endif
