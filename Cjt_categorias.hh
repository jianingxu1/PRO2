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

    vector<string> nombre_categorias;     // tamaño C
    vector< vector<int> > puntos_por_nivel; // tamaño C x K

public:
    
    // Constructores

    /** @brief Constructora por defecto
        \pre Cierto.
        \post El resultado es un conjunto de categorías vacío.
    */
    Cjt_categorias();


    // Modificadores
    
    /** @brief Operación de lectura
        \pre C >= 0 que representa el número de categorías y K >= 0 que representa el número máximo de niveles. Estan preparados en el canal de entrada C strings con el nombre de cada categoría, y C × K enteros que representan los puntos por categoría y nivel. representa el nombre que identifica al torneo (sin repeticiones) y c la categoría entre 1 y C a la que pertenece el torneo.
        \post El parámetro implícito contiene el conjunto de categorías leídos en la entrada, ordenados crecientemente por categorías y dentro de cada categoría, ordenados crecientemente por nivel.
    */
    void leer(int C, int K);
    

    // Consultores


    /** @brief Consulta los puntos de la categoría dependiendo del nivel
        \pre c >= 0 representa la categoría del torneo y k >= 1 representa el nivel.
        \post Retorna los puntos por el nivel de la categoría.
    */
    int consultar_puntos_por_nivel(int c, int k) const;
};
#endif