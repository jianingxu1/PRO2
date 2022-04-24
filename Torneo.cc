#include "Torneo.hh"

int Torneo::numero_max_niveles(int n) const {
    int count = 0;
    int exp = 1;
    while (exp < n) {
        ++count;
        exp *= 2;
    }
    return count + 1;
}

int Torneo::nodos_por_nivel(int nivel) const {
    return pow(2, nivel - 1);
}

int Torneo::contrincante(int a, int l) const {
    return nodos_por_nivel(l) + 1 - a;
}

BinTree<int> Torneo::crear_cuadro_emparejamientos(int h, int m, int l, int a) const {
    if (l == h or (l == h - 1 and a < m - n + 1)) return BinTree<int>(a);
    else {
        BinTree<int> left = crear_cuadro_emparejamientos(h, m, l + 1, a);
        BinTree<int> right = crear_cuadro_emparejamientos(h, m, l + 1, contrincante(a, l + 1));
        return BinTree<int>(a, left, right);
    }
}

void Torneo::imprimir_cuadro_emparejamientos(const BinTree<int>& t, int h, int m, int l) const {
    if (not t.empty()) {
        if (l == h or (l == h - 1 and t.value() < m - n + 1)) cout << t.value() << '.' << jugadores_edicion_actual[t.value() - 1].first;
        else {
            cout << '(';
            imprimir_cuadro_emparejamientos(t.left(), h, m, l + 1);
            cout << ' ';
            imprimir_cuadro_emparejamientos(t.right(), h, m, l + 1);
            cout << ')';
        }
    }
}

Torneo::Torneo(int c) {
    n = 0;
    this->c = c;
    iniciado = false;
    primera_edicion = true;
}

void Torneo::eliminar_puntos(Cjt_jugadores& jugadores_global) {
    for (int i = 0; i < n; ++i) {
        if (jugadores_edicion_actual[i].second != 0) {
            jugadores_global.sumar_puntos_jugador(jugadores_edicion_actual[i].first, -jugadores_edicion_actual[i].second);
        }
    }
}

void Torneo::leer_jugadores_inscritos(const Cjt_jugadores& jugadores_global) {
    jugadores_edicion_actual = vector< pair<string, int> >(n);
    for (int r = 0; r < n; ++r) {
        int posicion;
        cin >> posicion;
        string nombre_jugador = jugadores_global.consultar_jugador_ranking(posicion);
        jugadores_edicion_actual[r] = make_pair(nombre_jugador, 0);
    }
}

void Torneo::iniciar(const Cjt_jugadores& jugadores_global) {
    iniciado = true;
    cin >> this->n;
    leer_jugadores_inscritos(jugadores_global);
    int h = numero_max_niveles(n);
    int m = nodos_por_nivel(h);
    cuadro_emparejamientos = crear_cuadro_emparejamientos(h, m, 1, 1);
    imprimir_cuadro_emparejamientos(cuadro_emparejamientos, h, m, 1);
    cout << endl;
}

int Torneo::consultar_categoria() const {
    return c;
}