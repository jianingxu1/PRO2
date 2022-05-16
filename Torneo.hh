/** @file Torneo.hh
    @brief Especificación de la clase Torneo
*/

#ifndef TORNEO_HH
#define TORNEO_HH

#include "Cjt_jugadores.hh"
#include "Cjt_categorias.hh"

#ifndef NO_DIAGRAM
#include "BinTree.hh"
#include <vector>
#include <map>
#include <cmath>
#include <iostream>
using namespace std;
#endif

/** @class Torneo
    @brief Representa un torneo de tenis.
*/
class Torneo {

private:
	int c;          // categoría del torneo
    int n_jugadores_edicion_anterior;
    int n;          // número de inscritos, 8 <= n <= 2^(K-1)
    bool es_primera_edicion;    // true si no se ha jugado ninguna edición
    vector< pair<string, int> > jugadores_edicion_anterior;
    vector< pair<string, int> > jugadores_edicion_actual;
    BinTree<int> cuadro_emparejamientos;
    BinTree<string> cuadro_resultado_matches;

    /** @brief Retorna el número máximo de niveles del cuadro de emparejamientos del torneo.
        \pre Cierto.
        \post Retorna el número máximo de niveles del parámetro implícito.
    */
    // calcula la h
    int numero_max_niveles() const;

    /** @brief Retorna el número máximo de nodos posibles en un nivel del cuadro de emparejamientos del torneo.
        \pre 1 <= nivel <= numero_max_niveles().
        \post Retorna el número máximo de nodos posibles en un nivel del cuadro de emparejamientos del parámetro implícito.
    */
    // calcula la z o m
    int nodos_por_nivel(int nivel) const;

    /** @brief Retorna el contrincante de a en un cierto nivel del cuadro de emparejamientos del torneo.
        \pre 1 <= id_jugador <= n, 1 <= nivel <= numero_max_niveles().
        \post Retorna el contrincante que le correspondría a id_jugador en un cierto nivel del cuadro de emparejamientos del parámetro implícito.
    */
    // calcula la b
    int contrincante(int id_jugador, int nivel) const;

    /** @brief Crea el cuadro de emparejamientos del torneo.
        \pre 4 <= num_max_niveles, 8 <= num_max_nodos, 1 <= nivel <= numero_max_niveles() y 1 <= id_jugador <= n.
        \post Retorna el cuadro de emparejamientos del parámetro implícito.
    */
    BinTree<int> i_crear_cuadro_emparejamientos(int num_max_niveles, int num_max_nodos, int nivel, int id_jugador) const;
    
    /** @brief Crea el cuadro de emparejamientos del torneo.
        \pre Cierto.
        \post Se ha creado el cuadro de emparejamientos del parámetro implícito.
    */
    void crear_cuadro_emparejamientos();

    /** @brief Imprime el cuadro de emparejamientos del torneo.
        \pre 4 <= num_max_niveles, 8 <= num_max_nodos, 1 <= nivel <= numero_max_niveles().
        \post Se ha imprimido el cuadro de emparejamientos.
    */  
    void i_imprimir_cuadro_emparejamientos(const BinTree<int>& cuadro_emparejamientos, int num_max_niveles, int num_max_nodos, int nivel) const;

    /** @brief Imprime el cuadro de emparejamientos del torneo.
        \pre Cierto.
        \post Se ha imprimido el cuadro de emparejamientos del parámetro implícito.
    */  
    void imprimir_cuadro_emparejamientos() const;

    /** @brief Crea el cuadro de resultados de los matches del torneo.
        \pre Estan preparados en el canal de entrada una secuencia de X strings en preorden que representan los resultados de un match.
        \post Se ha creado el cuadro de resultados de los matches del parámetro implícito.
    */
    void i_crear_cuadro_resultado_matches(BinTree<string>& cuadro_resultado_matches, string match, int& n);

    /** @brief Crea el cuadro de resultados de los matches del torneo.
        \pre Estan preparados en el canal de entrada una secuencia de X strings en preorden que representan los resultados de un match.
        \post Se ha creado el cuadro de resultados de los matches del parámetro implícito.
    */
    void crear_cuadro_resultado_matches();

    /** @brief Retorna el ganador de un match
        \pre match contiene el resultado de un match de tenis, que puede tener las formas a1-b1,a2-b2,a3-b3
        \post Retorna a si el jugador cuya puntuación en el match está situado en la izquierda, ha ganado. Altramente, retorna b. Se han actualizado las estadísticas del jugador a y b.
    */ 
    int ganador_del_match(const string& match, int a, int b, vector<Estadisticas>& estadisticas);

    /** @brief Crea el cuadro de emparejamientos con sus respectivos ganadores y obtiene los puntos y las estadísticas de cada jugador en el torneo.
        \pre 1 <= nivel <= numero_max_niveles(), estadisticas.size() == n.
        \post Se ha creado el cuadro de emparejamientos con sus respectivos ganadores y se han obtenido las estadísticas de cada jugador en el torneo. Se ha actualizado los puntos de cada jugador según su posición en el torneo. Se han recopilado las estadísticas de cada jugador.
    */
    void i_crear_cuadro_resultado_final(const Cjt_categorias& categorias, const BinTree<string>& cuadro_resultado_matches, BinTree<int>& cuadro_emparejamientos, vector<Estadisticas>& estadisticas, int nivel);
    
    /** @brief Crea el cuadro de emparejamientos con sus respectivos ganadores y obtiene los puntos y las estadísticas de cada jugador en el torneo.
        \pre estadisticas.size() == n.
        \post Se ha creado el cuadro de emparejamientos con sus respectivos ganadores y se han obtenido las estadísticas de cada jugador en el torneo. Se ha actualizado los puntos de cada jugador según su posición en el torneo.
    */    
    void crear_cuadro_resultado_final(const Cjt_categorias& categorias, vector<Estadisticas>& estadisticas);

    /** @brief Imprime los matches de cada ronda del torneo con sus respectivos jugadores y resultados.
        \pre Cierto.
        \post Se ha imprimido los matches de cada ronda del parámetro implícito con sus respectivos jugadores y resultados.
    */
    void i_imprimir_cuadro_resultado_final(const BinTree<string>& cuadro_resultado_matches, const BinTree<int>& cuadro_emparejamientos) const;

    /** @brief Imprime los matches de cada ronda del torneo.
        \pre Cierto.
        \post Se ha imprimido los matches de cada ronda del parámetro implícito con sus respectivos jugadores y resultados.
    */
    void imprimir_cuadro_resultado_final() const;

    /** @brief Traslada las estadísticas obtenidas por los jugadores en el torneo a las estadísticas globales.
        \pre Cierto.
        \post Se han trasladado las estadísticas obtenidas por los jugadores en el parámetro implícito a las estadísticas globales de los jugadores.
    */ 
    void trasladar_estadisticas(const vector<Estadisticas>& estadisticas, Cjt_jugadores& jugadores_global) const;

    /** @brief Traslada los puntos obtenidos por los jugadores en el torneo a las estadísticas globales del circuito.
        \pre jugadores_global contiene los jugadores del parámetro implícito.
        \post Se han trasladado a jugadores_global los puntos obtenidos por los jugadores. Se han sumado los de la edición actual y se han restado, si existieran, los de la edición anterior del torneo.
    */ 
    void trasladar_puntos(Cjt_jugadores& jugadores_global);

    /** @brief Sustituye los jugadores y sus puntos obtenidos de la edición actual a la edición anterior.
        \pre Cierto.
        \post Se han sustituido los jugadores y sus puntos obtenidos de las edición actual a la edición anterior. Se ha limpiado el contenido de la edición actual.
    */ 
    void sustituir_edicion_anterior();

public:
    // Constructoras

    /** @brief Creadora con valores concretos.
        \pre 1 <= c <= C.
        \post El resultado es un torneo con c "c".
    */    
    Torneo(int c);

    // Modificadoras

    /** @brief Elimina de las estadísticas globales de los jugadores los puntos que han obtenido en el torneo.
        \pre Cierto.
        \post Si el parámetro implícito no es la primera edición, no hace nada. Altramente, se han eliminado de las estadísticas globales de los jugadores los puntos que han obtenido en la edición anterior del parámetro implícito.
    */   
    void eliminar_puntos(Cjt_jugadores& jugadores_global);

    /** @brief Operación de lectura de jugadores dada su posición en el ranking global.
        \pre n contiene el número de jugadores inscritos al torneo. Estan preparados en el canal de entrada una secuencia de n enteros con las posiciones del ranking global que identifican a los jugadores (sin repeticiones).
        \post El parámetro implícito contiene los jugadores inscritos y un ranking de los jugadores según el orden que han sido leídos en la entrada con sus estadísticas a cero.
    */  
    void leer_jugadores_inscritos(const Cjt_jugadores& jugadores_global);

    /** @brief Inicia el torneo.
        \pre El torneo no está iniciado. Estan preparados en el canal de entrada un entero n que representa el número de jugadores que se inscribirán al torneo y n enteros que representan las posiciones en el ranking actual, ordenadas crecientemente, de los jugadores inscritos al torneo.
        \post El resultado es un torneo iniciado que contiene los jugadores inscritos iniciales. Se ha creado y se ha imprimido el cuadro de emparejamientos.
    */
    void iniciar(const Cjt_jugadores& jugadores_global);

    /** @brief Finaliza el torneo
        \pre Estan preparados en el canal de entrada los resultados del torneo. El torneo está inicializado.
        \post El resultado es un torneo finalizado. Se han leído los resultados del torneo. Se ha creado y se ha imprimido el cuadro de resultados. Se ha imprimido el nombre y los puntos de cada jugador por orden de ranking de los jugadores en el momento de iniciar el torneo. Se han actualizado los puntos y las estadísticas de los jugadores en el conjunto de jugadores global. Se han guardado los puntos obtenidos de los jugadores en la edición anterior.
    */
    void finalizar(const Cjt_categorias& categorias, Cjt_jugadores& jugadores_global);

    /** @brief Elimina los puntos obtenidos por un jugador en la última edición
        \pre p es un nombre de un jugador.
        \post Si p ha participado en la última edición del torneo, se le han eliminado los puntos que obtuvo en esta última edición.
    */
    void eliminar_puntos_jugador(const string& p);

    // Consultoras

    /** @brief Imprime el nombre y los puntos de los jugadores según el orden del ranking del torneo
        \pre Cierto.
        \post Imprime el nombre y los puntos de los jugadores según el orden del ranking del parámetro implícito.
    */   
    void imprimir_ranking() const;

    /** @brief Consultora de la categoría del torneo 
        \pre Cierto.
        \post Retorna la categoría del parámetro implícito.
    */  
    int consultar_categoria() const;

    /** @brief Consultora de si el torneo está en su primera edición
        \pre Cierto.
        \post Retorna true si el torneo está en su primera edición (no se ha jugado ninguna edición del torneo). False, altramente.
    */  
    bool consulta_es_primera_edicion() const;
};
#endif