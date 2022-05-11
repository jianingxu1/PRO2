#include "Torneo.hh"

int Torneo::numero_max_niveles() const {
    int count = 0;
    int producto = 1;
    while (producto < n) {
        ++count;
        producto *= 2;
    }
    return count + 1;
}

int Torneo::nodos_por_nivel(int nivel) const {
    return pow(2, nivel - 1);
}

int Torneo::contrincante(int id_jugador, int nivel) const {
    return nodos_por_nivel(nivel) + 1 - id_jugador;
}

BinTree<int> Torneo::crear_cuadro_emparejamientos(int num_max_niveles, int num_max_nodos, int nivel, int id_jugador) const {
    if (nivel == num_max_niveles or (nivel == num_max_niveles - 1 and id_jugador < num_max_nodos - n + 1)) return BinTree<int>(id_jugador);
    else {
        BinTree<int> left = crear_cuadro_emparejamientos(num_max_niveles, num_max_nodos, nivel + 1, id_jugador);
        BinTree<int> right = crear_cuadro_emparejamientos(num_max_niveles, num_max_nodos, nivel + 1, contrincante(id_jugador, nivel + 1));
        return BinTree<int>(id_jugador, left, right);
    }
}

void Torneo::imprimir_cuadro_emparejamientos(const BinTree<int>& cuadro_emparejamientos, int num_max_niveles, int num_max_nodos, int nivel) const {
    if (not cuadro_emparejamientos.empty()) {
        if (nivel == num_max_niveles or ((nivel == num_max_niveles - 1) and (cuadro_emparejamientos.value() < num_max_nodos - n + 1))) {
            cout << cuadro_emparejamientos.value() << '.' << jugadores_edicion_actual[cuadro_emparejamientos.value() - 1].first;
        }
        else {
            cout << '(';
            imprimir_cuadro_emparejamientos(cuadro_emparejamientos.left(), num_max_niveles, num_max_nodos, nivel + 1);
            cout << ' ';
            imprimir_cuadro_emparejamientos(cuadro_emparejamientos.right(), num_max_niveles, num_max_nodos, nivel + 1);
            cout << ')';
        }
    }
}

BinTree<string> Torneo::leer_cuadro_resultado_matches() {
    string match;
    cin >> match;
    BinTree<string> cuadro_resultado_matches;
    if (match != "0" and match != "0 0") cuadro_resultado_matches = BinTree<string> (match, leer_cuadro_resultado_matches(), leer_cuadro_resultado_matches());
    return cuadro_resultado_matches;
}

char Torneo::ganador_del_match(const string& match) const {
    int length = match.length();
    int a = 0;
    int b = 0;
    for (int i = 0; i < length; i = i + 4) {
        if (match[i] > match[i+2]) ++a;
        else ++b;
    }
    if (a > b) return 'a';
    else return 'b';
}

void Torneo::crear_cuadro_resultado_final(const BinTree<string>& cuadro_resultado_matches, BinTree<int>& cuadro_emparejamientos) {
    if (not cuadro_resultado_matches.empty()) {
        BinTree<int> left = cuadro_emparejamientos.left();
        BinTree<int> right = cuadro_emparejamientos.right();
        crear_cuadro_resultado_final(cuadro_resultado_matches.left(), left);
        crear_cuadro_resultado_final(cuadro_resultado_matches.right(), right);
        int a = left.value();
        int b = right.value();
        int ganador;
        if (ganador_del_match(cuadro_resultado_matches.value()) == 'a') ganador = a;
        else ganador = b;
        cuadro_emparejamientos = BinTree<int>(ganador, left, right);
    }
}

void Torneo::imprimir_cuadro_resultado_final(const BinTree<string>& cuadro_resultado_matches, const BinTree<int>& cuadro_emparejamientos) const {
    if (not cuadro_resultado_matches.empty()) {
        int a = cuadro_emparejamientos.left().value();
        int b =  cuadro_emparejamientos.right().value();
        cout << '(' << a << '.' << jugadores_edicion_actual[a-1].first << " vs " << b << '.' << jugadores_edicion_actual[b-1].first << ' ' << cuadro_resultado_matches.value();
        imprimir_cuadro_resultado_final(cuadro_resultado_matches.left(), cuadro_emparejamientos.left());
        imprimir_cuadro_resultado_final(cuadro_resultado_matches.right(), cuadro_emparejamientos.right());
        cout << ')';
    }
}

// void Torneo::actualizar_estadisticas(const BinTree<string>& cuadro_resultado_matches, const BinTree<int>& cuadro_emparejamientos, Cjt_jugadores& jugadores_global) {
    
// }

void Torneo::i_actualizar_puntos_resultados(const Cjt_categorias& categorias, const BinTree<int>& cuadro_ganadores, int nivel, vector<bool>& esta_sumado) {
    if (not cuadro_ganadores.empty()) {
        if (not esta_sumado[cuadro_ganadores.value()]) {
            int puntos = categorias.consultar_puntos_por_nivel(c, nivel);
            jugadores_edicion_actual[cuadro_ganadores.value() - 1].second += puntos;
            esta_sumado[cuadro_ganadores.value()] = true;
        }
        i_actualizar_puntos_resultados(categorias, cuadro_ganadores.left(), nivel + 1, esta_sumado);
        i_actualizar_puntos_resultados(categorias, cuadro_ganadores.right(), nivel + 1, esta_sumado);
    }
}

void Torneo::actualizar_puntos_resultados(const Cjt_categorias& categorias) {
    vector<bool> esta_sumado(n, false);
    i_actualizar_puntos_resultados(categorias, cuadro_emparejamientos, 1, esta_sumado);
}

void Torneo::trasladar_puntos(Cjt_jugadores& jugadores_global) {
    for (int i = 0; i < n; ++i) {
        jugadores_global.sumar_puntos_jugador(jugadores_edicion_actual[i].first, jugadores_edicion_actual[i].second);
    }
}

void Torneo::sustituir_edicion_anterior() {
    jugadores_edicion_anterior.clear();
    n_jugadores_edicion_anterior = n;
    jugadores_edicion_anterior = jugadores_edicion_actual;
    n = 0;
    jugadores_edicion_actual.clear();
}

// Constructores

Torneo::Torneo(int c) {
    n_jugadores_edicion_anterior = 0;
    n = 0;
    this->c = c;
    esta_iniciado = false;
    es_primera_edicion = true;
}

// Modificadores

void Torneo::eliminar_puntos(Cjt_jugadores& jugadores_global) {
    for (int i = 0; i < n_jugadores_edicion_anterior; ++i) {
        if (jugadores_global.existe_jugador(jugadores_edicion_anterior[i].first) and jugadores_edicion_anterior[i].second != 0) {   // no hay que hacer nada si se ha dado de baja al jugador o si tiene 0 puntos
            jugadores_global.sumar_puntos_jugador(jugadores_edicion_anterior[i].first, -jugadores_edicion_anterior[i].second);
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
    esta_iniciado = true;
    cin >> this->n;
    leer_jugadores_inscritos(jugadores_global);

    int num_max_niveles = numero_max_niveles();
    int num_max_nodos = nodos_por_nivel(num_max_niveles);
    cuadro_emparejamientos = crear_cuadro_emparejamientos(num_max_niveles, num_max_nodos, 1, 1);
    imprimir_cuadro_emparejamientos(cuadro_emparejamientos, num_max_niveles, num_max_nodos, 1);
    cout << endl;
}

void Torneo::finalizar(const Cjt_categorias& categorias, Cjt_jugadores& jugadores_global) {
    cuadro_resultado_matches = leer_cuadro_resultado_matches();
    // actualizar estadísticas global
    crear_cuadro_resultado_final(cuadro_resultado_matches, cuadro_emparejamientos);
    imprimir_cuadro_resultado_final(cuadro_resultado_matches, cuadro_emparejamientos);
    cout << endl;
    
    actualizar_puntos_resultados(categorias);
    imprimir_ranking();

    eliminar_puntos(jugadores_global);
    trasladar_puntos(jugadores_global);
    sustituir_edicion_anterior();
    jugadores_global.actualizar_ranking();

    esta_iniciado = false;
    es_primera_edicion = false;
    BinTree<int> t;
    cuadro_emparejamientos = t;
    BinTree<string> r;
    cuadro_resultado_matches = r;
}

void Torneo::eliminar_puntos_jugador(const string& p) {
    bool found = false;
    int i = 0;
    while (not found and i < n_jugadores_edicion_anterior) {
        if (p == jugadores_edicion_anterior[i].first) {
            jugadores_edicion_anterior[i].second = 0;
            found = true;
        }
        ++i;
    }
}

// Consultores

void Torneo::imprimir_ranking() const {
    for (int r = 0; r < n; ++r) {
        if (jugadores_edicion_actual[r].second != 0) {
            cout << r + 1 << '.' << jugadores_edicion_actual[r].first << ' ' << jugadores_edicion_actual[r].second << endl;
        }
    }
}

int Torneo::consultar_categoria() const {
    return c;
}

bool Torneo::consulta_es_primera_edicion() const {
    return es_primera_edicion;
}