#include "Cjt_categorias.hh"

Cjt_categorias::Cjt_categorias(int C, int K) {
    this->C = C;
    this->K = K;
    categorias = vector<string>(C);
    puntos_por_nivel = vector< vector<int> >(C, vector<int>(K));
}

Cjt_categorias::~Cjt_categorias() {}

void Cjt_categorias::leer() {
    for (int categoria = 0; categoria < C; ++categoria) {
        string nombre_categoria;
        cin >> nombre_categoria;
        categorias[categoria] = nombre_categoria;
    }
    for (int categoria = 0; categoria < C; ++categoria) {
        for (int nivel = 0; nivel < K; ++nivel) {
            int puntos;
            cin >> puntos;
            puntos_por_nivel[categoria][nivel] = puntos;
        }
    }
}

int Cjt_categorias::consultar_puntos_por_nivel(int categoria, int nivel) const {
    return puntos_por_nivel[categoria - 1][nivel - 1];
}

void Cjt_categorias::escribir() const {
    cout << C << ' ' << K << endl;
    for (int categoria = 1; categoria <= C; ++categoria) {
        cout << categorias[categoria-1] << ' ';
        for (int nivel = 1; nivel <= K; ++nivel) {
            if (nivel != 0) cout << ' ';
            cout << consultar_puntos_por_nivel(categoria, nivel);
        }
        cout << endl;
    }
}