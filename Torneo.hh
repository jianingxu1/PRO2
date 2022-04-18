#ifndef TORNEO_HH
#define TORNEO_HH

#include "Cjt_jugadores.hh"

#ifndef NO_DIAGRAM
#include "BinTree.hh"
#include <vector>
#include <map>
#include <iostream>
using namespace std;
#endif

/** @class Torneo
    @brief Representa un torneo
*/
class Torneo {

private:

    string t;       // nombre del torneo
	int c;          // categoría del torneo
    int n;          // número de inscritos (una vez finalizado el período de inscripción). 8 <= n <= 2^(K-1)
    map<string, int> jugadores_edicion_anterior;
    vector<string> ranking; // con info sobre la pos. en el ranking, nombre del jugador y int r, 1 <= r <= n.
    map<string, int> jugadores_edicion_actual;  // jugador - puntos
    bool iniciado;
    bool primera_edicion;   // True si no hay edición anterior. Altramente, false.
    BinTree< pair<string, string> > cuadro_emparejamientos;
    BinTree<string> cuadro_resultados;  // quizás no es necesario

    /** @brief Crea el cuadro de emparejamientos del torneo
        \pre Cierto.
        \post Se ha creado el cuadro de emparejamientos del torneo.
    */
    void crear_cuadro_emparejamientos();

    /** @brief Imprime el cuadro de emparejamientos del torneo
        \pre Cierto.
        \post Imprime el cuadro de emparejamientos del torneo.
    */  
    void imprimir_cuadro_emparejamientos();

    /** @brief Lee los resultados y crea el cuadro de resultados del torneo
        \pre Cierto.
        \post Se han leído los resultados del torneo. Se ha creado el cuadro de resultados del torneo.
    */
    void leer_resultados();     // actualiza las estadísticas de los jugadores

    // /** @brief Crea el cuadro de resultados del torneo
    //     \pre Cierto.
    //     \post Se ha creado el cuadro de resultados del torneo.
    // */
    // void crear_cuadro_resultados();     // quizás no es necesario guardarlo, solo imprimirlo

    /** @brief Imprime el cuadro de resultados del torneo
        \pre Cierto.
        \post Imprime el cuadro de resultados del torneo.
    */  
    void imprimir_cuadro_resultados();

    /** @brief Actualiza los puntos obtenidos por los jugadores en el torneo a las estadísticas y ranking globales
        \pre jugadores_global contiene los jugadores a actualizar.
        \post Se ha actualizado jugadores_global con los puntos obtenidos en la edición actual y anterior del torneo.
    */ 
    void actualizar_puntos(Cjt_jugadores& jugadores_global);

    /** @brief Actualiza las estadísticas obtenidas por los jugadores en el torneo a las estadísticas globales
        \pre jugadores_global contiene los jugadores a actualizar.
        \post Se ha actualizado jugadores_global con los puntos obtenidos en el torneo.
    */ 
    void actualizar_estadisticas(Cjt_jugadores& jugadores_global);

    /** @brief Sustituye los jugadores y sus puntos obtenidos de las edición actual a la edición anterior
        \pre Cierto.
        \post Se han sustituido los jugadores y sus puntos obtenidos de las edición actual a la edición anterior.
    */ 
    void sustituir_edicion_anterior();

public:

    // Constructores

    /** @brief Constructora por defecto
        \pre Cierto.
        \post El resultado es un torneo vacío.
    */
    Torneo();

    /** @brief Constructora con nombre y categoría
        \pre Está preparado en el canal de entrada un par string t y entero c, donde t representa el nombre que identifica al torneo (sin repeticiones) y c la categoría entre 1 y C a la que pertenece el torneo.
        \post El resultado es un torneo con nombre t y categoría c.
    */    
    Torneo(string t, int c);


    // Modificadores

    /** @brief Operación de lectura de jugadores dada su posición en el ranking global
        \pre P >= 0 que representa el número inicial de jugadores. Estan preparados en el canal de entrada una secuencia de P enteros con las posiciones del ranking global que identifican a los jugadores (sin repeticiones).
        \post El parámetro implícito contiene el conjunto de jugadores y un ranking de los jugadores según el orden que han sido leídos en la entrada con sus estadísticas a cero.
    */  
    void leer_jugadores_inscritos(const vector<string>& ranking, int P);

    /** @brief Inicia el torneo
        \pre El torneo no está iniciado. n representa el número de jugadores que se inscribirán al torneo. Estan preparados en el canal de entrada n enteros que representan las posiciones de los jugadores inscritos al torneo en el ranking global ordenados crecientemente.
        \post El resultado es un torneo inicializado que contiene los jugadores inscritos iniciales y el ranking inicial del torneo. Se ha creado y se ha imprimido el cuadro de emparejamientos.
    */
    void iniciar(const Cjt_jugadores& jugadores_global, int n);

    /** @brief Finaliza el torneo
        \pre Estan preparados en el canal de entrada los resultados del torneo. El torneo está inicializado.
        \post El resultado es un torneo finalizado. Se han leído los resultados del torneo. Se ha creado y se ha imprimido el cuadro de resultados. Se ha imprimido el nombre y los puntos de cada jugador por orden de ranking de los jugadores en el momento de iniciar el torneo. Se han actualizado los puntos y las estadísticas de los jugadores en el conjunto de jugadores global. Se han guardado los puntos obtenidos de los jugadores en la edición anterior.
    */
    void finalizar(const Cjt_categorias& categorias, Cjt_jugadores& jugadores_global);  // mientras se lee cada resultado, se actualizan las stats de los jugadores en el global.


    // Consultores

    /** @brief Consulta los jugadores del torneo
        \pre Cierto.
        \post Retorna el conjunto de jugadores del torneo.
    */    
    Cjt_jugadores consultar_jugadores() const;

    /** @brief Imprime el nombre y los puntos de los jugadores según el orden del ranking del torneo
        \pre Cierto.
        \post Imprime el nombre y los puntos de los jugadores según el orden del ranking del parámetro implícito.
    */   
    void imprimir_ranking() const;
};
#endif