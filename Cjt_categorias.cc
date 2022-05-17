/** @file Cjt_categorias.cc
    @brief Implementación de la clase Cjt_categorias
*/
#include "Cjt_categorias.hh"

Cjt_categorias::Cjt_categorias(int C, int K) {
    this->C = C;
    this->K = K;
    nombre_categorias = vector<string>(C);
    puntos_por_nivel_categorias = Matriz(C, vector<int>(K));
}

void Cjt_categorias::leer() {
    for (int c = 0; c < C; ++c) {
        cin >> nombre_categorias[c];
    }
    for (int c = 0; c < C; ++c) {
        for (int nivel = 0; nivel < K; ++nivel) {
            cin >> puntos_por_nivel_categorias[c][nivel];
        }
    }
}

void Cjt_categorias::escribir() const {
    cout << C << ' ' << K << endl;
    for (int c = 1; c <= C; ++c) {
        cout << nombre_categorias[c - 1];
        for (int nivel = 1; nivel <= K; ++nivel) {
            cout << ' ' << consultar_puntos_por_nivel(c, nivel);
        }
        cout << endl;
    }
}

int Cjt_categorias::consultar_puntos_por_nivel(int c, int nivel) const {
    return puntos_por_nivel_categorias[c - 1][nivel - 1];
}

string Cjt_categorias::consultar_nombre_categoria(int c) const {
    return nombre_categorias[c - 1];
}