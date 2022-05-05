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

// void Torneo::actualizar_estadisticas(Cjt_jugadores& jugadores_global) {}

// void Torneo::leer_resultados(Cjt_jugadores& jugadores_global) {}

// void actualizar_puntos_resultados(const Cjt_categorias& categorias) {}

void Torneo::trasladar_puntos(Cjt_jugadores& jugadores_global) {
    for (int i = 0; i < n; ++i) {
        jugadores_global.sumar_puntos_jugador(jugadores_edicion_actual[i].first, jugadores_edicion_actual[i].second);
    }
    eliminar_puntos(jugadores_global);
}

void Torneo::sustituir_edicion_anterior() {
    jugadores_edicion_anterior = jugadores_edicion_actual;
    jugadores_edicion_actual = vector< pair<string, int> >(0);
}

Torneo::Torneo(int c) {
    n = 0;
    this->c = c;
    esta_iniciado = false;
    es_primera_edicion = true;
}

void Torneo::eliminar_puntos(Cjt_jugadores& jugadores_global) {
    int n = jugadores_edicion_anterior.size();
    for (int i = 0; i < n; ++i) {
        jugadores_global.sumar_puntos_jugador(jugadores_edicion_anterior[i].first, -jugadores_edicion_anterior[i].second);
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
    esta_iniciado = true;
    cin >> this->n;
    leer_jugadores_inscritos(jugadores_global);
    int h = numero_max_niveles(n);
    int m = nodos_por_nivel(h);
    cuadro_emparejamientos = crear_cuadro_emparejamientos(h, m, 1, 1);
    imprimir_cuadro_emparejamientos(cuadro_emparejamientos, h, m, 1);
    cout << endl;
}

void Torneo::finalizar(const Cjt_categorias& categorias, Cjt_jugadores& jugadores_global) {
    // leer_resultados(jugadores_global);  // actualizar_estadisticas(jugadores_global) mientras se leen los resultados
    // crear cuadro de resultados
    // imprimir cuadro de resultados
    // actualizar_puntos_resultados(categorias);
    string s = categorias.consultar_nombre(0); // quitar esta línea
    imprimir_ranking();
    trasladar_puntos(jugadores_global);
    sustituir_edicion_anterior();
}

void Torneo::imprimir_ranking() const {
    for (int i = 0; i < n; ++i) {
        cout << i + 1 << '.' << jugadores_edicion_actual[i].first << ' ' << jugadores_edicion_actual[i].second << endl;
    }
}

int Torneo::consultar_categoria() const {
    return c;
}

bool Torneo::consulta_es_primera_edicion() const {
    return es_primera_edicion;
}