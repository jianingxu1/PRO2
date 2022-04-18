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

    /** @brief 
        \pre 2 <= estadistica <= 8.
        \post Si estadistica == 2, le suma cantidad a torneos disputados. Si == 3, le suma cantidad a partidos ganados. Si == 4, le suma cantidad a partidos perdidos. Si == 5, le suma cantidad a sets ganados. Si == 6, le suma cantidad a sets perdidos. Si == 7, le suma cantidad a juegos ganados. Si == 8, le suma cantidad a juegos perdidos.
    */
    void actualizar_estadistica(string estadistica, int cantidad);

    // Consultores

    /** @brief Consulta los puntos del jugador
        \pre Cierto.
        \post Retorna los puntos del parámetro implícito.
    */ 
    int consultar_puntos() const;

    /** @brief Consulta un atributo del jugador
        \pre 1 <= atributo <= 8.
        \post Si atributo == 1, devuelve los puntos. Si == 2, devuelve los torneos disputados. Si == 3, devuelve los partidos ganados. Si == 4, devuelve los partidos perdidos. Si == 5, devuelve los sets ganados. Si == 6, devuelve los sets perdidos. Si == 7, devuelve juegos ganados. Si == 8, devuelve los juegos perdidos.
    */
    int consultar_atributo(int atributo) const;
};
#endif
