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
    @brief Representa un conjunto de estadísticas de un jugador de tenis.
*/
struct Estadisticas {
    /** @brief Entero que representa el número de torneos en los que se ha participado */
    int torneos_disputados;
    /** @brief Entero que representa el número de partidos ganados */
    int partidos_ganados;
    /** @brief  Entero que representa el número de partidos perdidos */
    int partidos_perdidos;
    /** @brief  Entero que representa el número de sets ganados */
    int sets_ganados;
    /** @brief  Entero que representa el número de sets perdidos */
    int sets_perdidos;
    /** @brief  Entero que representa el número de juegos ganados */
    int juegos_ganados;
    /** @brief  Entero que representa el número de juegos perdidos */
    int juegos_perdidos;

    /** @brief Creadora por defecto.
        \pre Cierto.
        \post El resultado son unas estadísticas con todos sus atributos a cero.
    */
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
    @brief Representa el conjunto de características y operaciones de un jugador de tenis.
*/
class Jugador {
private:
    /** @brief Entero que representa la posición en el ranking del jugador */
    int posicion;
    /** @brief Entero que representa los puntos del jugador. */
    int puntos;
    /** @brief Estructura de datos que contiene las estadísticas del jugador */
    Estadisticas estadisticas;
    
public:
    // Constructoras

    /** @brief Creadora por defecto.
        \pre Cierto.
        \post El resultado es un jugador con todos sus atributos a cero.
    */
    Jugador();

    // Modificadoras
    
    /** @brief Añade puntos al jugador.
        \pre Cierto.
        \post Se le han añadido puntos al parámetro implícito.
    */ 
    void anadir_puntos(int puntos);

    /** @brief Añade las estadísticas al jugador.
        \pre Cierto.
        \post Se le han añadido las estadísticas al parámetro implícito.
    */
    void anadir_estadisticas(const Estadisticas& estadisticas);

    /** @brief Modificadora de la posición del jugador.
        \pre 1 <= posición <= P (número de jugadores del circuito).
        \post Se ha modificado la posición del parámetro implícito.
    */    
    void modificar_posicion(int posicion);

    // Lectura/Escritura

    /** @brief Operación de escritura.
        \pre Cierto.
        \post Se han escrito los atributos del parámetro implícito en el canal standard de salida.
    */
    void escribir() const;
    
    // Consultoras

    /** @brief Consultora de la posición en el ranking del jugador.
        \pre Cierto.
        \post Retorna la posición en el ranking del parámetro implícito.
    */
    int consultar_posicion() const;

    /** @brief Consultora de los puntos del jugador.
        \pre Cierto.
        \post Retorna los puntos del parámetro implícito.
    */
    int consultar_puntos() const;
};
#endif
