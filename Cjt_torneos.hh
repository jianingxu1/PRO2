#ifndef CJT_TORNEOS_HH
#define CJT_TORNEOS_HH

#include "torneo.hh"
#include "cjt_jugadores.hh"
#include <vector>
#include <iostream>
using namespace std;

/** @class Cjt_torneos
    @brief Representa un conjunto de torneos
*/
class Cjt_torneos {
private:
    // TORNEO EDICIÓN PASADA, CON LOS STATS DE LOS JUGADORES PASADOS (MAP? DE JUGADORES)
    // TORNEO EDICION ACTUAL (MAP? DE JUGADORES)
    // AL FINALIZAR UN TORNEO, RECOPILAR LOS STATS DE CADA JUGADOR Y ACTUALIZAR SUS STATS PERSONALES
    
public:
    
    // Constructores

    /** @brief Constructora por defecto
        \pre Cierto.
        \post El resultado es un conjunto de torneos vacío.
    */
    Cjt_torneos();
    

    // Modificadores
    
    /** @brief Operación de lectura
        \pre T >= 0 representa el número de torneos. Estan preparados en el canal de entrada una secuencia de T pares de string t y entero c, donde t representa el nombre que identifica al torneo (sin repeticiones) y c la categoría entre 1 y C a la que pertenece el torneo.
        \post El parámetro implícito contiene el conjunto de torneos leídos en la entrada.
    */
    void leer(int T);
};
#endif
