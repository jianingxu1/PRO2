/** @file Jugador.hh
    @brief Especificación de la clase Jugador
*/

#ifndef JUGADOR_HH
#define JUGADOR_HH

#ifndef NO_DIAGRAM
#include <iostream>
using namespace std;
#endif

/** @struct Estadisticas
    @brief Representa las estadísticas de un jugador de tenis.
*/
struct Estadisticas {
    int torneos_disputados;
    int partidos_ganados;
    int partidos_perdidos;
    int sets_ganados;
    int sets_perdidos;
    int juegos_ganados;
    int juegos_perdidos;

    Estadisticas() {
        torneos_disputados = 0;
        partidos_ganados = 0;
        partidos_perdidos = 0;
        sets_ganados = 0;
        sets_perdidos = 0;
        juegos_ganados = 0;
        juegos_perdidos = 0;
    }
};

/** @class Jugador
    @brief Representa un jugador de tenis.
*/
class Jugador {
private:
    int posicion;
    int puntos;
    Estadisticas estadisticas;
    
public:
    // Constructoras

    /** @brief Creadora por defecto.
        \pre Cierto
        \post El resultado es un jugador con todos sus atributos a cero
    */
    Jugador();

    // Modificadoras
    
    /** @brief Añade puntos al jugador.
        \pre Cierto
        \post Se le han añadido puntos al parámetro implícito
    */ 
    void anadir_puntos(int puntos);

    /** @brief Añade las estadísticas al jugador.
        \pre Cierto
        \post Se le han añadido las estadísticas al parámetro implícito
    */
    void anadir_estadisticas(const Estadisticas& estadisticas);

    /** @brief Modificadora de la posición del jugador.
        \pre 1 <= posición <= P (número de jugadores del circuito)
        \post Se ha modificado la posición del parámetro implícito
    */    
    void modificar_posicion(int posicion);

    // Consultoras

    /** @brief Consultora de la posición en el ranking del jugador.
        \pre Cierto
        \post Retorna la posición en el ranking del parámetro implícito
    */
    int consultar_posicion() const;

    /** @brief Consultora de los puntos del jugador.
        \pre Cierto
        \post Retorna los puntos del parámetro implícito
    */
    int consultar_puntos() const;

    // Escritura de jugador

    /** @brief Operación de escritura.
        \pre Cierto
        \post Se han escrito los atributos del parámetro implícito en el canal standard de salida
    */
    void escribir() const;
};
#endif
