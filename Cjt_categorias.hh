#ifndef CJT_CATEGORIAS_HH
#define CJT_CATEGORIAS_HH

#ifndef NO_DIAGRAM
#include <vector>
#include <iostream>
using namespace std;
#endif

/** @class Cjt_categorias
    @brief Representa un conjunto de categorías
*/
class Cjt_categorias {

private:

    int C;  // número de categorías
    int K;  // número máximo de niveles por categoría
    vector<string> categorias;    // nombre de las categorías según su identificador
    vector< vector<int> > puntos_por_nivel; // tamaño C x K

public:
    
    // Constructores

    /** @brief Constructora
        \pre C >= 1 representa el número de categorías y K >= 4 representa el número máximo de niveles.
        \post El resultado es un conjunto de categorías vacío.
    */
    Cjt_categorias(int C, int K);


    // Destructora

    /** @brief Destructora por defecto
        \pre Cierto.
        \post Se ha eliminado el parámetro implícito.
    */
    ~Cjt_categorias();


    // Modificadores
    
    /** @brief Operación de lectura
        \pre Estan preparados en el canal de entrada C strings con el nombre de cada categoría, y C × K enteros que representan los puntos por categoría y nivel.
        \post El parámetro implícito contiene el conjunto de categorías leídos en la entrada.
    */
    void leer();
    

    // Consultores

    /** @brief Consulta los puntos de la categoría dependiendo del nivel
        \pre 1 <= categoria <= C y 1 <= nivel <= K.
        \post Retorna los puntos por el nivel de la categoría.
    */
    int consultar_puntos_por_nivel(int categoria, int nivel) const;

    /** @brief Escribe las categorías del circuito
        \pre Cierto.
        \post Escribe, por orden creciente de identificador, el nombre y la tabla de puntos por niveles (en orden creciente de nivel) de cada categoría del circuito.
    */
    void escribir() const;

    /** @brief Consulta el nombre de la categoría
        \pre c representa el identificador de la categoría.
        \post Retorna el nombre de la categoría con identificador c.
    */
    string consultar_nombre(int c) const;
};
#endif