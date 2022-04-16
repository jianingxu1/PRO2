#ifndef TORNEO_HH
#define TORNEO_HH

#include "cjt_jugadores.hh"
#include <iostream>
#include <vector>
using namespace std;

/** @class Torneo
    @brief Representa un torneo
*/
class Torneo {

private:

    string t;       // nombre del torneo
	int c;          // categoría del torneo
    int n;          // número de inscritos (una vez finalizado el período de inscripción). 8 <= n <= 2^(K-1)
    Cjt_jugadores jugadores;    // con info sobre la pos. en el ranking, nombre del jugador y int r, 1 <= r <= n.
    bool inicializado;
    // guardar cuadro de emparejamientos?
    // bool si hubo edición pasada
    // guardar info edición pasada con solo el conjunto de jugadores y sus stats

    /** @brief Crea el cuadro de emparejamientos del torneo
        \pre Cierto.
        \post Se ha creado el cuadro de emparejamientos del torneo.
    */
    void crear_cuadro_emparejamientos();

public:

    // Constructores

    /** @brief Constructora por defecto
        \pre Cierto.
        \post El resultado es un torneo vacío.
    */
    Torneo();

    /** @brief Constructora
        \pre Está preparado en el canal de entrada un par string t y entero c, donde t representa el nombre que identifica al torneo (sin repeticiones) y c la categoría entre 1 y C a la que pertenece el torneo.
        \post El resultado es un torneo con nombre t y categoría c.
    */    
    Torneo(string t, int c);


    // Modificadores

    /** @brief Inicia el torneo
        \pre n representa el número de jugadores inscritos al torneo. Estan preparados en el canal de entrada n enteros que representan las posiciones de los jugadores inscritos al torneo en el ranking actual/global ordenados crecientemente.
        \post El resultado es un torneo inicializado que contiene los jugadores inscritos iniciales y el ranking inicial del torneo. Se ha creado el cuadro de emparejamientos.
    */
    void iniciar_torneo(const vector<string>& ranking, int n);

    void finalizar_torneo(Cjt_jugadores& jugadores);

    // Consultores

    /** @brief Consulta los jugadores del torneo
        \pre Cierto.
        \post Retorna el conjunto de jugadores del torneo.
    */    
    Cjt_jugadores consultar_jugadores();

    /** @brief Imprime el cuadro de emparejamientos del torneo
        \pre Cierto.
        \post Imprime el cuadro de emparejamientos del torneo.
    */  
    void imprimir_emparejamientos();
};
#endif
