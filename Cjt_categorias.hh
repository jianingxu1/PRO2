/** @file Cjt_categorias.hh
    @brief Especificación de la clase Cjt_categorias
*/
#ifndef CJT_CATEGORIAS_HH
#define CJT_CATEGORIAS_HH

#ifndef NO_DIAGRAM
#include <vector>
#include <iostream>
using namespace std;
#endif

/** @class Cjt_categorias
    @brief Representa las características de un conjunto de categorías de tenis.
*/
class Cjt_categorias {
private:
    typedef vector< vector<int> > Matriz;
    /** @brief Entero que representa el número de categorías */
    int C;
    /** @brief Entero que representa el número máximo de niveles de las categorías */
    int K;
    /** @brief Vector que contiene el nombre de las categorías en orden creciente de su identificador */
    vector<string> nombre_categorias;
    /** @brief Matriz que contiene en cada fila, los puntos por nivel en orden creciente de nivel de una categoría */
    Matriz puntos_por_nivel_categorias;

public:
    // Constructoras

    /** @brief Creadora con valores concretos.
        \pre C >= 1 y K >= 4.
        \post El resultado es un conjunto de categorías con C "C" y K "K".
    */
    Cjt_categorias(int C, int K);

    // Lectura/Escritura
    
    /** @brief Operación de lectura.
        \pre Estan preparados en el canal de entrada una secuencia de C strings con los nombres asociados a las categorías identificadas por los valores entre 1 y C en orden creciente (de identificador, no de nombre). Luego se leerán C × K enteros >= 0, que serán los puntos por categoría y nivel, ordenados crecientemente por categorías y dentro de cada categoría ordenados crecientemente por nivel.
        \post El parámetro implícito contiene el conjunto de categorías leídos en la entrada
    */
    void leer();

    /** @brief Operación de escritura.
        \pre Cierto.
        \post Se han escrito, por orden creciente de identificador, el nombre y la tabla de puntos por niveles (en orden creciente de nivel) de cada categoría del circuito.
    */
    void escribir() const;
    
    // Consultoras

    /** @brief Consultora de los puntos de una categoría según el nivel.
        \pre 1 <= c <= C y 1 <= nivel <= K.
        \post Retorna los puntos de la categoría en el nivel especificado del parámetro implícito.
    */
    int consultar_puntos_por_nivel(int c, int nivel) const;

    /** @brief Consultora del nombre de una categoría.
        \pre Existe una categoría con identificador c en el parámetro implícito.
        \post Retorna el nombre de la categoría cuyo identificador es c del parámetro implícito.
    */
    string consultar_nombre_categoria(int c) const;
};
#endif