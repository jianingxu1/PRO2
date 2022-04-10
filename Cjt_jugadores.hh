#ifndef CJT_JUGADORES_HH
#define CJT_JUGADORES_HH

#include "jugador.hh"
#include <iostream>
#include <vector>
using namespace std;

class Cjt_jugadores {
private:
    int P;  // número de jugadores
    // VECTOR CON EL RANKING DE LOS JUGADORES, solo con su nombre, QUE ACCEDA A LA INFORMACION DESDE EL MAP
    // MAP/SET CON LA INFO DE LOS JUGADORES, key siendo su nombre
    
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
    

    // Consultores
    
    /** @brief Consulta si existe un jugador en el conjunto jugadores
        \pre p representa un identificador de un jugador.
        \post Si p está dentro del conjunto de jugadores, retorna true. Altramente, false.
    */  
    bool existe_jugador(string p);

    /** @brief Consulta el número de jugadores del conjunto de jugadores
        \pre Cierto.
        \post Retorna el número de jugadores del parámetro implícito.
    */ 
    int consultar_numero_jugadores();
};
#endif
