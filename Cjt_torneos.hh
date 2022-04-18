#ifndef CJT_TORNEOS_HH
#define CJT_TORNEOS_HH

#include "Torneo.hh"
#include "Cjt_jugadores.hh"

#ifndef NO_DIAGRAM
#include <vector>
#include <iostream>
using namespace std;
#endif

/** @class Cjt_torneos
    @brief Representa un conjunto de torneos
*/
class Cjt_torneos {

private:

    // MAP/SET DE TORNEOS (necesario para encontrar mediante nombre un torneo)

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

    /** @brief Añade el torneo al conjunto de torneos
        \pre torneo no está dentro del parámetro implícito.
        \post Se le ha añadido un torneo al parámetro implícito.
    */  
    void anadir_torneo(Torneo torneo);

    /** @brief Elimina el torneo del conjunto de torneos
        \pre t representa el nombre de un torneo. El parámetro implícito contiene un torneo con nombre t.
        \post Se ha eliminado el torneo del parámetro implícito. Se ha actualizado el ranking y los puntos del conjunto de jugadores.
    */  
    void eliminar_torneo(Cjt_jugadores jugadores, string t);

    /** @brief Modifica el torneo
        \pre Existe un torneo con nombre t en el parámetro implícito.
        \post El torneo con nombre t del parámetro implícito se ha sustituido por aux.
    */
    void modificar_torneo(string t, Torneo aux);

    // Consultores

    /** @brief Consulta si existe un torneo en el conjunto de torneos
        \pre t representa el nombre de un torneo.
        \post Si existe un torneo con nombre t en el parámetro implícito, retorna true. Altramente, false.
    */  
    bool existe_torneo(string t) const;

    /** @brief Consulta el número de torneos del conjunto de torneos
        \pre Cierto.
        \post Retorna el número de torneos del parámetro implícito.
    */ 
    int consultar_numero_torneos() const;

    /** @brief Consulta un torneo del conjunto de torneos
        \pre t representa el nombre de un torneo. El parámetro implícito contiene un torneo con nombre t.
        \post Retorna el torneo con nombre t.
    */    
    Torneo consultar_torneo(string t) const;  
};
#endif
