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
    map<string, Jugador> estadisticas; // string <- identificador del jugador
    
public:

    // Constructores

    /** @brief Constructora por defecto
        \pre Cierto.
        \post El resultado es un conjutno de jugadores vacío.
    */ 
    Cjt_jugadores();


    // Modificadores
    
    /** @brief Operación de lectura
        \pre P >= 0 que representa el número inicial de jugadores. Estan preparados en el canal de entrada una secuencia de P strings con los nombres que identifican a los jugadores (sin repeticiones).
        \post El parámetro implícito contiene el conjunto de jugadores y un ranking de los jugadores según el orden que han sido leídos en la entrada.
    */    
    void leer(int P);
    
    /** @brief Añade un jugador al conjunto de jugadores
        \pre p representa un identificador de un jugador. p no está en el parámetro implícito.
        \post El parámetro implícito contiene el jugador p, con todas sus estadísticas a cero y posicionado último en el ranking.
    */  
    void anadir_jugador(string p);

    /** @brief Da de baja a un jugador del conjunto de jugadores
        \pre p representa un identificador de un jugador. p está en el parámetro implícito.
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
        \post Se ha actualizado el ranking de jugadores decrecientemente por puntos. En caso de empate, se ordena según la posición del jugador en el ranking sin actualizar.
    */
    void actualizar_ranking();


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

    /** @brief Consulta el ranking
        \pre Cierto.
        \post Retorna el ranking del parámetro implícito.
    */ 
    vector<string> consultar_ranking() const;
};
#endif
