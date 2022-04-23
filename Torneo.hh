#ifndef TORNEO_HH
#define TORNEO_HH

#include "Cjt_jugadores.hh"     // analizar si es necesario
#include "Cjt_categorias.hh"    // analizar si es necesario

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

	int c;          // categoría del torneo
    int n;          // número de inscritos (una vez finalizado el período de inscripción). 8 <= n <= 2^(K-1)
    vector< pair<string, int> > jugadores_edicion_anterior;
    vector< pair<string, int> > jugadores_edicion_actual;
    bool iniciado;
    bool primera_edicion;   // True si no hay edición anterior. Altramente, false.
    BinTree<int> cuadro_emparejamientos;
    BinTree< pair<int, string> > cuadro_resultados;  // quizás no es necesario

    // /** @brief Crea el cuadro de emparejamientos del torneo
    //     \pre Cierto.
    //     \post Se ha creado el cuadro de emparejamientos del torneo.
    // */
    // void crear_cuadro_emparejamientos();

    // /** @brief Imprime el cuadro de emparejamientos del torneo
    //     \pre Cierto.
    //     \post Imprime el cuadro de emparejamientos del torneo.
    // */  
    // void imprimir_cuadro_emparejamientos();

    // /** @brief Lee los resultados y crea el cuadro de resultados del torneo
    //     \pre Cierto.
    //     \post Se han leído los resultados del torneo. Se ha creado el cuadro de resultados del torneo.
    // */
    // void leer_resultados();     // actualiza las estadísticas de los jugadores

    // // /** @brief Crea el cuadro de resultados del torneo
    // //     \pre Cierto.
    // //     \post Se ha creado el cuadro de resultados del torneo.
    // // */
    // // void crear_cuadro_resultados();     // quizás no es necesario guardarlo, solo imprimirlo

    // /** @brief Imprime el cuadro de resultados del torneo
    //     \pre Cierto.
    //     \post Imprime el cuadro de resultados del torneo.
    // */  
    // void imprimir_cuadro_resultados();

    // /** @brief Traslada los puntos obtenidos por los jugadores en el torneo a las estadísticas y ranking globales
    //     \pre jugadores_global contiene las estadísticas globales y el ranking global de los jugadores del circuito.
    //     \post Se han trasladado a jugadores_global los puntos obtenidos por los jugadores. Se han sumado los de la edición actual y se han restado los de la edición anterior del torneo.
    // */ 
    // void trasladar_puntos(Cjt_jugadores& jugadores_global);

    // // /** @brief Actualiza las estadísticas obtenidas por los jugadores en el torneo a las estadísticas globales
    // //     \pre jugadores_global contiene los jugadores a actualizar.
    // //     \post Se ha actualizado jugadores_global con los puntos obtenidos en el torneo.
    // // */ 
    // // void actualizar_estadisticas(Cjt_jugadores& jugadores_global);

    // /** @brief Sustituye los jugadores y sus puntos obtenidos de las edición actual a la edición anterior
    //     \pre Cierto.
    //     \post Se han sustituido los jugadores y sus puntos obtenidos de las edición actual a la edición anterior.
    // */ 
    // void sustituir_edicion_anterior();

public:

    // Constructores

    /** @brief Constructora con categoría
        \pre c representa la categoría entre 1 y C a la que pertenece el torneo.
        \post El resultado es un torneo con categoría c.
    */    
    Torneo(int c);


    // Modificadores

    /** @brief Elimina de las estadisticas globales de los jugadores los puntos que han obtenido en este torneo
        \pre jugadores_global contiene las estadísticas globales y el ranking global de los jugadores del circuito.
        \post Se han eliminado de las estadísticas globales de los jugadores los puntos que han obtenido en el parámetro implícito.
    */   
    void eliminar_puntos(Cjt_jugadores& jugadores_global);

    // /** @brief Operación de lectura de jugadores dada su posición en el ranking global
    //     \pre P >= 0 que representa el número inicial de jugadores. Estan preparados en el canal de entrada una secuencia de P enteros con las posiciones del ranking global que identifican a los jugadores (sin repeticiones).
    //     \post El parámetro implícito contiene el conjunto de jugadores y un ranking de los jugadores según el orden que han sido leídos en la entrada con sus estadísticas a cero.
    // */  
    // void leer_jugadores_inscritos(const vector<string>& ranking, int P);

    /** @brief Inicia el torneo
        \pre El torneo no está iniciado. Estan preparados en el canal de entrada un entero n que representa el número de jugadores que se inscribirán al torneo y n enteros que representan las posiciones en el ranking actual, ordenadas crecientemente, de los jugadores inscritos al torneo.
        \post El resultado es un torneo iniciado que contiene los jugadores inscritos iniciales. Se ha creado y se ha imprimido el cuadro de emparejamientos.
    */
    void iniciar(const Cjt_jugadores& jugadores_global);

    // /** @brief Finaliza el torneo
    //     \pre Estan preparados en el canal de entrada los resultados del torneo. El torneo está inicializado.
    //     \post El resultado es un torneo finalizado. Se han leído los resultados del torneo. Se ha creado y se ha imprimido el cuadro de resultados. Se ha imprimido el nombre y los puntos de cada jugador por orden de ranking de los jugadores en el momento de iniciar el torneo. Se han actualizado los puntos y las estadísticas de los jugadores en el conjunto de jugadores global. Se han guardado los puntos obtenidos de los jugadores en la edición anterior.
    // */
    // void finalizar(const Cjt_categorias& categorias, Cjt_jugadores& jugadores_global);  // mientras se lee cada resultado, se actualizan las stats de los jugadores en el global.


    // // Consultores

    // /** @brief Consulta los jugadores del torneo
    //     \pre Cierto.
    //     \post Retorna el conjunto de jugadores del torneo.
    // */    
    // Cjt_jugadores consultar_jugadores() const;

    // /** @brief Imprime el nombre y los puntos de los jugadores según el orden del ranking del torneo
    //     \pre Cierto.
    //     \post Imprime el nombre y los puntos de los jugadores según el orden del ranking del parámetro implícito.
    // */   
    // void imprimir_ranking() const;

    /** @brief Consulta la categoría del torneo 
        \pre Cierto.
        \post Retorna la categoría del parámetro implícito.
    */  
    int consultar_categoria() const;
};
#endif