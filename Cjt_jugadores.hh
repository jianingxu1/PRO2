/** @file Cjt_jugadores.hh
    @brief Especificación de la clase Cjt_jugadores
*/

#ifndef CJT_JUGADORES_HH
#define CJT_JUGADORES_HH

#include "Jugador.hh"

#ifndef NO_DIAGRAM
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
#endif

/** @class Cjt_jugadores
    @brief Representa un conjunto de jugadores de tenis.
*/
class Cjt_jugadores {
private:
    int P;  // número de jugadores
    vector<string> ranking;
    map<string, Jugador> estadisticas;

    /** @brief Comparadora de dos iteradores, que apuntan a un jugador, según sus puntos y su posición en el ranking.
        \pre it1 y it2 son iteradores que apuntan a un par string, Jugador de un map.
        \post Si el jugador apuntado por it1 tiene más puntos que it2, retorna true. Si tienen los mismos puntos, si el jugador apuntado por it1 tiene posición menor que it2 en el ranking, retorna true. Altramente, false.
    */
    static bool comp(const map<string, Jugador>::iterator& it1, const map<string, Jugador>::iterator& it2);

public:
    // Modificadoras
    
    /** @brief Operación de lectura de los jugadores iniciales.
        \pre P >= 0. Estan preparados en el canal de entrada una secuencia de P strings con los nombres que identifican a los jugadores (sin repeticiones).
        \post El parámetro implícito contiene el conjunto de jugadores con todos sus atributos a cero y un ranking de estos jugadores según el orden que han sido leídos en la entrada.
    */    
    void leer(int P);

    /** @brief Añade un jugador al conjunto de jugadores.
        \pre No existe un jugador con identificador p en el parámetro implícito.
        \post El parámetro implícito contiene el jugador p, con todos sus puntos y estadísticas a cero y posicionado último en el ranking.
    */  
    void anadir_jugador(const string& p);

    /** @brief Da de baja a un jugador del conjunto de jugadores.
        \pre Existe un jugador con identificador p en el parámetro implícito.
        \post El parámetro implícito no contiene el jugador p y éste ha sido eliminado del ranking. Se han actualizado las posiciones de los jugadores en el ranking.
    */
    void eliminar_jugador(const string& p);

    /** @brief Añade puntos a un jugador del conjunto de jugadores.
        \pre Cierto.
        \post Si existe el jugador con identificador p en el parámetro implícito, se le han añadido puntos. Altramente, nada.
    */
    void anadir_puntos_jugador(const string& p, int puntos);

    /** @brief Añade las estadísticas a un jugador del conjunto de jugadores.
        \pre Existe un jugador con identificador p en el parámetro implícito.
        \post Se le han añadido las estadísticas al jugador con identificador p del parámetro implícito.
    */
    void anadir_estadisticas_jugador(const string& p, const Estadisticas& estadisticas);

    /** @brief Actualiza el ranking de jugadores.
        \pre Cierto.
        \post Se ha actualizado el ranking de jugadores decrecientemente por puntos. En caso de empate, se ordena según la posición del jugador en el ranking sin actualizar. Al mismo tiempo, se ha actualizado el atributo posición de los jugadores según este nuevo ranking.
    */
    void actualizar_ranking();

    // Consultoras
    
    /** @brief Consultora de la existencia de un jugador en el conjunto jugadores.
        \pre p representa el identificador de un jugador.
        \post Si existe un jugador con identificador p en el parámetro implícito, retorna true. Altramente, false.
    */  
    bool existe_jugador(const string& p) const;

    /** @brief Consultora del número de jugadores del conjunto de jugadores.
        \pre Cierto.
        \post Retorna el número de jugadores del parámetro implícito.
    */ 
    int consultar_numero_jugadores() const;

    /** @brief Consultora del nombre de un jugador que está en una cierta posición en el ranking.
        \pre 1 <= posicion <= P.
        \post Retorna el nombre del jugador que está en la posición "posicion" del ranking.
    */ 
    string consultar_jugador_ranking(int posicion) const;

    // Operaciones de escritura

    /** @brief Escribe un jugador dado su nombre.
        \pre Existe un jugador con identificador p en el parámetro implícito.
        \post Se ha escrito el nombre y las estadísticas del jugador con identificador p del parámetro implícito.
    */
    void consultar_jugador(const string& p) const;

    /** @brief Lista los jugadores del conjunto de jugadores.
        \pre Cierto.
        \post Se ha listado, por orden creciente de identificador (nombre), el nombre, la posición en el ranking, los puntos y el resto de las estadísticas de cada jugador del parámetro implícito.
    */
    void listar_jugadores() const;

    /** @brief Lista el ranking del conjunto de jugadores.
        \pre Cierto.
        \post Se ha listado el ranking de jugadores por orden creciente de posición del parámetro implícito.
    */
    void listar_ranking() const;
};
#endif
