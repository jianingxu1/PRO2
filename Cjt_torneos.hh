/** @file Cjt_torneos.hh
    @brief Especificación de la clase Cjt_torneos
*/
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
    @brief Representa las características y las operaciones de un conjunto de torneos de tenis.
*/
class Cjt_torneos {

private:
    /** @brief Entero que representa el número de torneos */
    int T;
    /** @brief Map que contiene como elementos, el nombre y las características de un torneo */
    map<string, Torneo> torneos;

public:
    // Modificadoras

    /** @brief Añade un torneo al conjunto de torneos.
        \pre No existe un torneo con nombre t en el parámetro implícito.
        \post Se ha añadido un torneo con nombre t y categoría c al parámetro implícito.
    */  
    void anadir_torneo(const string& t, int c);

    /** @brief Da de baja un torneo del conjunto de torneos.
        \pre Existe un torneo con nombre t en el parámetro implícito.
        \post Se ha eliminado el torneo con nombre t del parámetro implícito. Si se ha disputado han restado los puntos obtenidos por los jugadores en la última edición del torneo.
    */  
    void baja_torneo(const string& t, Cjt_jugadores& jugadores_global);

    /** @brief Inicia un torneo.
        \pre Existe un torneo con nombre t en el parámetro implícito. Estan preparados en el canal de entrada un entero n y n enteros que representan las posiciones en el ranking actual, ordenadas crecientemente, de los jugadores inscritos al torneo.
        \post Se ha iniciado el torneo con nombre t del parámetro implícito.
    */
    void iniciar_torneo(const Cjt_jugadores& jugadores_global, const string& t);

    /** @brief Finaliza un torneo.
        \pre Existe un torneo con nombre t en el parámetro implícito y éste esta iniciado.
        \post Se ha finalizado el torneo con nombre t del parámetro implícito.
    */
    void finalizar_torneo(const Cjt_categorias& categorias, const string& t, Cjt_jugadores& jugadores_global);

    /** @brief Elimina los puntos obtenidos por un jugador en todos los torneos.
        \pre Cierto.
        \post Se han eliminado los puntos obtenidos por el jugador con nombre p en todos los torneos en los que haya participado en la última edición.
    */
    void eliminar_puntos_jugador(const string& p);

    // Lectura/Escritura

    /** @brief Operación de lectura.
        \pre T >= 0. Estan preparados en el canal de entrada una secuencia de T pares de string t y entero c, donde t representa el nombre que identifica al torneo (sin repeticiones) y c la categoría entre 1 y C a la que pertenece el torneo.
        \post El parámetro implícito contiene el conjunto de torneos leídos en la entrada.
    */
    void leer(int T);

    /** @brief Operación de escritura.
        \pre Cierto.
        \post Se listan, por orden creciente de identificador (nombre), el nombre y la categoría de cada torneo del parámetro implícito.
    */  
    void listar_torneos(const Cjt_categorias& categorias) const;

    // Consultoras

    /** @brief Consultora de la existencia de un torneo en el conjunto de torneos.
        \pre Cierto.
        \post Si existe un torneo con nombre t en el parámetro implícito, retorna true. Altramente, false.
    */  
    bool existe_torneo(const string& t) const;

    /** @brief Consultora del número de torneos.
        \pre Cierto.
        \post Retorna el número de torneos del parámetro implícito.
    */ 
    int consultar_numero_torneos() const;
};
#endif