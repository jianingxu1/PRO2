#ifndef TORNEO_HH
#define TORNEO_HH

#include "cjt_jugadores.hh"
#include <iostream>
#include <vector>
using namespace std;

// - COMO EXPRESAR LAS EDICIONES ANTERIORES DE UN TORNEO? Con dos estr. de datos para jugadores, uno con la info de la edición anterior y otro con la actual
// - COMO EXPRESAR JUGADORES INSCRITOS, MAP?
// - TORNEO EDICIÓN PASADA, CON LOS STATS DE LOS JUGADORES PASADOS (MAP? DE JUGADORES)
// - TORNEO EDICION ACTUAL (MAP? DE JUGADORES)
// - AL FINALIZAR UN TORNEO, RECOPILAR LOS STATS DE CADA JUGADOR Y ACTUALIZAR SUS STATS PERSONALES
class Torneo {
	private:
    string t;       // nombre del torneo
	int c;          // categoría del torneo
    int n;          // número de inscritos (una vez finalizado el período de inscripción). 8 <= n <= 2^(K-1)
    Cjt_jugadores jugadores;    // con info sobre la pos. en el ranking, nombre del jugador y int r, 1 <= r <= n.
    // RANKING DEL TORNEO
    
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

    
    // Consultores

    /** @brief Consulta los jugadores del torneo
        \pre Cierto.
        \post Retorna el conjunto de jugadores del torneo.
    */    
    Cjt_jugadores consultar_jugadores();
};
#endif
