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

    int T;  // número de torneos
    map<string, Torneo> torneos;

public:
    
    // Constructores

    /** @brief Constructora por defecto
        \pre Cierto.
        \post El resultado es un conjunto de torneos vacío.
    */
    Cjt_torneos();
    

    // Destructora

    /** @brief Destructora por defecto
        \pre Cierto.
        \post Se ha eliminado el parámetro implícito.
    */
    ~Cjt_torneos();


    // Modificadores
    
    /** @brief Operación de lectura
        \pre T >= 0 representa el número de torneos. Estan preparados en el canal de entrada una secuencia de T pares de const string& t y entero c, donde t representa el nombre que identifica al torneo (sin repeticiones) y c la categoría entre 1 y C a la que pertenece el torneo.
        \post El parámetro implícito contiene el conjunto de torneos leídos en la entrada.
    */
    void leer(int T);

    /** @brief Añade el torneo al conjunto de torneos
        \pre torneo no está dentro del parámetro implícito.
        \post Se ha añadido un torneo al parámetro implícito.
    */  
    void anadir_torneo(const string& t, const Torneo& torneo);

    /** @brief Da de baja un torneo del conjunto de torneos
        \pre t representa el nombre de un torneo. El parámetro implícito contiene un torneo con nombre t.
        \post Se ha eliminado el torneo del parámetro implícito. Se han restado los puntos obtenidos por los jugadores en el torneo. Se ha actualizado el ranking.
    */  
    void baja_torneo(Cjt_jugadores& jugadores_global, const string& t);

    /** @brief Inicia un torneo
        \pre t representa el nombre de un torneo. El parámetro implícito contiene un torneo con nombre t no iniciado. Está preparado en la entrada un entero n y n enteros que representan las posiciones en el ranking actual, ordenadas crecientemente, de los jugadores inscritos al torneo.
        \post Se ha iniciado el torneo t.
    */
    void iniciar_torneo(const Cjt_jugadores& jugadores_global, const string& t);

    /** @brief Finaliza un torneo
        \pre 
        \post
    */
    void finalizar_torneo(const Cjt_categorias& categorias, const string& t, Cjt_jugadores& jugadores_global);

    // Consultores

    /** @brief Consulta si existe un torneo en el conjunto de torneos
        \pre t representa el nombre de un torneo.
        \post Si existe un torneo con nombre t en el parámetro implícito, retorna true. Altramente, false.
    */  
    bool existe_torneo(const string& t) const;

    /** @brief Consulta el número de torneos del conjunto de torneos
        \pre Cierto.
        \post Retorna el número de torneos del parámetro implícito.
    */ 
    int consultar_numero_torneos() const;

    /** @brief Lista los torneos del circuito
        \pre Cierto.
        \post Se listan, por orden creciente de identificador (nombre), el nombre y la categoría de cada torneo del circuito.
    */  
    void listar_torneos(const Cjt_categorias& categorias) const;
};
#endif