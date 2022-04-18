#ifndef CJT_JUGADORES_HH
#define CJT_JUGADORES_HH

#include "Jugador.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#include <vector>
#include <map>
using namespace std;
#endif

/** @class Cjt_jugadores
    @brief Representa un conjunto de jugadores
*/
class Cjt_jugadores {

private:

    int P;  // número de jugadores
    vector<string> ranking; // ranking de jugadores con su nombre. accesos fáciles. modificaciones difíciles (altas, bajas, etc.)
    map<string, Jugador> estadisticas_jugadores;
    
public:

    // Constructores

    /** @brief Constructora por defecto
        \pre Cierto.
        \post El resultado es un conjunto de jugadores vacío.
    */ 
    Cjt_jugadores();


    // Modificadores
    
    /** @brief Operación de lectura de jugadores dado su nombre
        \pre P >= 0 que representa el número inicial de jugadores. Estan preparados en el canal de entrada una secuencia de P strings con los nombres que identifican a los jugadores (sin repeticiones).
        \post El parámetro implícito contiene el conjunto de jugadores y un ranking de los jugadores según el orden que han sido leídos en la entrada con sus estadísticas a cero.
    */    
    void leer(int P);

    /** @brief Añade un jugador al conjunto de jugadores
        \pre p representa un identificador de un jugador. p existe en el parámetro implícito.
        \post El parámetro implícito contiene el jugador p, con todas sus estadísticas a cero y posicionado último en el ranking.
    */  
    void anadir_jugador(string p);

    /** @brief Da de baja a un jugador del conjunto de jugadores
        \pre p representa un identificador de un jugador. p existe en el parámetro implícito.
        \post El parámetro implícito no contiene el jugador p y éste ha sido eliminado del ranking. Se ha actualizado el ranking.
    */
    void eliminar_jugador(string p);

    /** @brief Suma o resta los puntos de los jugadores del conjunto de jugadores al parámetro implícito
        \pre Si el booleano suma_resta es true, se le suma los puntos a los jugadores. Altramente, se le restan los puntos.
        \post Se le han sumado o restado los puntos de los jugadores del conjunto de jugadores a los jugadores del parámetro implícito.
    */
    void actualizar_puntos(Cjt_jugadores jugadores, bool suma_resta);

    /** @brief Actualiza el ranking de jugadores
        \pre Cierto.
        \post Se ha actualizado el ranking de jugadores decrecientemente por puntos. En caso de empate, se ordena según la posición del jugador en el ranking sin actualizar. Al mismo tiempo, se ha actualizado el atributo posición de los jugadores según este nuevo ranking.
    */
    void actualizar_ranking();

    // /** @brief Añade los jugadores inscritos inicialmente
    //     \pre n representa el número de jugadores inscritos inicialmente.
    //     \post Se ha actualizado el ranking de jugadores decrecientemente por puntos. En caso de empate, se ordena según la posición del jugador en el ranking sin actualizar.
    // */
    // void anadir_jugadores_iniciales(int n);

    /** @brief Modifica el jugador con nombre p
        \pre p representa el nombre de un jugador. p existe en el parámetro implícito.
        \post El jugador con nombre p ha sido sustituido por jugador (parámetro de entrada).
    */
    void modificar_jugador(string p, const Jugador& jugador);

    // Consultores
    
    /** @brief Consulta si existe un jugador en el conjunto jugadores
        \pre p representa un identificador de un jugador.
        \post Si p está dentro del conjunto de jugadores, retorna true. Altramente, false.
    */  
    bool existe_jugador(string p) const;

    /** @brief Consulta el número de jugadores del conjunto de jugadores
        \pre Cierto.
        \post Retorna el número de jugadores del parámetro implícito.
    */ 
    int consultar_numero_jugadores() const;

    /** @brief Consulta el nombre del jugador que está en una cierta posición en el ranking
        \pre 1 <= posicion <= P.
        \post Retorna el nombre del jugador que está en la posición (parámetro de entrada) del ranking.
    */ 
    string consultar_jugador_ranking(int posicion) const;

    /** @brief Lista el ranking del circuito
        \pre Cierto.
        \post Se lista el ranking por orden creciente de ranking actual, la posición, el nombre y los puntos de cada jugador del circuito.
    */
    void listar_ranking();

    /** @brief Lista los jugadores del circuito
        \pre Cierto.
        \post Se listan, por orden creciente de identificador (nombre), el nombre, la posición en el ranking, los puntos y el resto de las estadísticas de cada jugador del circuito.
    */
    void listar_jugadores();

    /** @brief Consulta un jugador dado su nombre
        \pre p existe en el parámetro implícito.
        \post Retorna el jugador con nombre p.
    */
    Jugador consultar_jugador(string p);
};
#endif
