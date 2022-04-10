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

    /** @brief Añade un torneo al conjunto de torneos
        \pre Cierto.
        \post Se le ha añadido un torneo al parámetro implícito.
    */  
    void anadir_torneo(Torneo torneo);


    // Consultores

    /** @brief Consulta si existe un torneo en el conjunto de torneos
        \pre t representa el nombre de un torneo.
        \post Si existe un torneo con nombre t en el parámetro implícito, retorna true. Altramente, false.
    */  
    bool existe_torneo(string t);

    /** @brief Consulta el número de torneos del conjunto de torneos
        \pre Cierto.
        \post Retorna el número de torneos del parámetro implícito.
    */ 
    int consultar_numero_torneos();
};
#endif
