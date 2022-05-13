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

BinTree<int> Torneo::i_crear_cuadro_emparejamientos(int num_max_niveles, int num_max_nodos, int nivel, int id_jugador) const {
    if (nivel == num_max_niveles or (nivel == num_max_niveles - 1 and id_jugador < num_max_nodos - n + 1)) return BinTree<int>(id_jugador);
    else {
        BinTree<int> left = i_crear_cuadro_emparejamientos(num_max_niveles, num_max_nodos, nivel + 1, id_jugador);
        BinTree<int> right = i_crear_cuadro_emparejamientos(num_max_niveles, num_max_nodos, nivel + 1, contrincante(id_jugador, nivel + 1));
        return BinTree<int>(id_jugador, left, right);
    }
}

void Torneo::crear_cuadro_emparejamientos() {
    int num_max_niveles = numero_max_niveles();
    int num_max_nodos = nodos_por_nivel(num_max_niveles);
    cuadro_emparejamientos = i_crear_cuadro_emparejamientos(num_max_niveles, num_max_nodos, 1, 1);
 }

void Torneo::i_imprimir_cuadro_emparejamientos(const BinTree<int>& cuadro_emparejamientos, int num_max_niveles, int num_max_nodos, int nivel) const {
    if (not cuadro_emparejamientos.empty()) {
        if (nivel == num_max_niveles or ((nivel == num_max_niveles - 1) and (cuadro_emparejamientos.value() < num_max_nodos - n + 1))) {
            cout << cuadro_emparejamientos.value() << '.' << jugadores_edicion_actual[cuadro_emparejamientos.value() - 1].first;
        }
        else {
            cout << '(';
            i_imprimir_cuadro_emparejamientos(cuadro_emparejamientos.left(), num_max_niveles, num_max_nodos, nivel + 1);
            cout << ' ';
            i_imprimir_cuadro_emparejamientos(cuadro_emparejamientos.right(), num_max_niveles, num_max_nodos, nivel + 1);
            cout << ')';
        }
    }
}

void Torneo::imprimir_cuadro_emparejamientos() const {
    int num_max_niveles = numero_max_niveles();
    int num_max_nodos = nodos_por_nivel(num_max_niveles);
    i_imprimir_cuadro_emparejamientos(cuadro_emparejamientos, num_max_niveles, num_max_nodos, 1);
    cout << endl;
}

BinTree<string> Torneo::leer_cuadro_resultado_matches() const {
    string match;
    cin >> match;
    BinTree<string> cuadro_resultado_matches;
    if (match != "0" and match != "0 0") cuadro_resultado_matches = BinTree<string> (match, leer_cuadro_resultado_matches(), leer_cuadro_resultado_matches());
    return cuadro_resultado_matches;
}

// BinTree<string> Torneo::leer_cuadro_resultado_matches(int num_max_niveles, int nivel) const {
//     string match;
//     cin >> match;
//     BinTree<string> cuadro_resultado_matches;
//     if (match == "0") {
//         if (num_max_niveles == nivel) cin >> match;
//     }
//     else cuadro_resultado_matches = BinTree<string> (match, leer_cuadro_resultado_matches(num_max_niveles, nivel + 1), leer_cuadro_resultado_matches(num_max_niveles, nivel + 1));
//     return cuadro_resultado_matches;
// }

int Torneo::ganador_del_match(const string& match, int a, int b, vector<Estadisticas>& estadisticas) {
    int length = match.length();
    int sets_ganados_a = 0;
    int sets_ganados_b = 0;
    if (length == 3) {
        if (match[0] > match[2]) ++sets_ganados_a;
        else ++sets_ganados_b;
    }
    else {
        for (int i = 0; i < length; i = i + 4) {
            estadisticas[a - 1].juegos_ganados += match[i] - '0';
            estadisticas[b - 1].juegos_ganados += match[i + 2] - '0';
            estadisticas[a - 1].juegos_perdidos += match[i + 2] - '0';
            estadisticas[b - 1].juegos_perdidos += match[i] - '0';
            if (match[i] > match[i+2]) ++sets_ganados_a;
            else ++sets_ganados_b;
        }
        estadisticas[a - 1].sets_ganados += sets_ganados_a;
        estadisticas[b - 1].sets_ganados += sets_ganados_b;
        estadisticas[a - 1].sets_perdidos += sets_ganados_b;
        estadisticas[b - 1].sets_perdidos += sets_ganados_a;
    }
    if (sets_ganados_a > sets_ganados_b) {
        ++estadisticas[a - 1].partidos_ganados;
        ++estadisticas[b - 1].partidos_perdidos;
        return a;
    }
    else {
        ++estadisticas[b - 1].partidos_ganados;
        ++estadisticas[a - 1].partidos_perdidos;
        return b;
    }
}

void Torneo::i_crear_cuadro_resultado_final(const Cjt_categorias& categorias, const BinTree<string>& cuadro_resultado_matches, BinTree<int>& cuadro_emparejamientos, vector<Estadisticas>& estadisticas, int nivel) {
    BinTree<int> left = cuadro_emparejamientos.left();
    BinTree<int> right = cuadro_emparejamientos.right();
    int ganador;
    if (cuadro_resultado_matches.left().empty() and cuadro_resultado_matches.right().empty()) {
        ganador = ganador_del_match(cuadro_resultado_matches.value(), left.value(), right.value(), estadisticas);
    }
    else {
        if (not cuadro_resultado_matches.left().empty()) i_crear_cuadro_resultado_final(categorias, cuadro_resultado_matches.left(), left, estadisticas, nivel + 1);
        if (not cuadro_resultado_matches.right().empty()) i_crear_cuadro_resultado_final(categorias, cuadro_resultado_matches.right(), right, estadisticas, nivel + 1);
        ganador = ganador_del_match(cuadro_resultado_matches.value(), left.value(), right.value(), estadisticas);
    }
    cuadro_emparejamientos = BinTree<int>(ganador, left, right);

    if (ganador == left.value()) {
        jugadores_edicion_actual[right.value() - 1].second += categorias.consultar_puntos_por_nivel(c, nivel + 1);
        estadisticas[right.value() - 1].torneos_disputados = 1;
    }
    else {
        jugadores_edicion_actual[left.value() - 1].second += categorias.consultar_puntos_por_nivel(c, nivel + 1);
        estadisticas[left.value() - 1].torneos_disputados = 1;
    }
    if (nivel == 1) {
        jugadores_edicion_actual[ganador - 1].second += categorias.consultar_puntos_por_nivel(c, nivel);
        estadisticas[ganador - 1].torneos_disputados = 1;
    }
}

void Torneo::crear_cuadro_resultado_final(const Cjt_categorias& categorias, vector<Estadisticas>& estadisticas) {
    i_crear_cuadro_resultado_final(categorias, cuadro_resultado_matches, cuadro_emparejamientos, estadisticas, 1);
}

void Torneo::i_imprimir_cuadro_resultado_final(const BinTree<string>& cuadro_resultado_matches, const BinTree<int>& cuadro_emparejamientos) const {
    if (not cuadro_resultado_matches.empty()) {
        int a = cuadro_emparejamientos.left().value();
        int b = cuadro_emparejamientos.right().value();
        cout << '(' << a << '.' << jugadores_edicion_actual[a-1].first << " vs " << b << '.' << jugadores_edicion_actual[b-1].first << ' ' << cuadro_resultado_matches.value();
        i_imprimir_cuadro_resultado_final(cuadro_resultado_matches.left(), cuadro_emparejamientos.left());
        i_imprimir_cuadro_resultado_final(cuadro_resultado_matches.right(), cuadro_emparejamientos.right());
        cout << ')';
    }
}

void Torneo::imprimir_cuadro_resultado_final() const {
    i_imprimir_cuadro_resultado_final(cuadro_resultado_matches, cuadro_emparejamientos);
    cout << endl;
}

void Torneo::trasladar_estadisticas(const vector<Estadisticas>& estadisticas, Cjt_jugadores& jugadores_global) const {
    for (int r = 0; r < n; ++r) {
        jugadores_global.anadir_estadisticas_jugador(jugadores_edicion_actual[r].first, estadisticas[r]);
    }
}

// void Torneo::i_actualizar_puntos_resultados(const Cjt_categorias& categorias, const BinTree<int>& cuadro_ganadores, int nivel, vector<bool>& esta_sumado) {
//     if (not cuadro_ganadores.empty()) {
//         if (not esta_sumado[cuadro_ganadores.value()]) {
//             int puntos = categorias.consultar_puntos_por_nivel(c, nivel);
//             jugadores_edicion_actual[cuadro_ganadores.value() - 1].second += puntos;
//             esta_sumado[cuadro_ganadores.value()] = true;
//         }
//         i_actualizar_puntos_resultados(categorias, cuadro_ganadores.left(), nivel + 1, esta_sumado);
//         i_actualizar_puntos_resultados(categorias, cuadro_ganadores.right(), nivel + 1, esta_sumado);
//     }
// }

// void Torneo::actualizar_puntos_resultados(const Cjt_categorias& categorias) {
//     vector<bool> esta_sumado(n, false);
//     i_actualizar_puntos_resultados(categorias, cuadro_emparejamientos, 1, esta_sumado);
// }

void Torneo::trasladar_puntos(Cjt_jugadores& jugadores_global) {
    for (int i = 0; i < n; ++i) {
        jugadores_global.anadir_puntos_jugador(jugadores_edicion_actual[i].first, jugadores_edicion_actual[i].second);
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
            jugadores_global.anadir_puntos_jugador(jugadores_edicion_anterior[i].first, -jugadores_edicion_anterior[i].second);
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
    crear_cuadro_emparejamientos();
    imprimir_cuadro_emparejamientos();
}

void Torneo::finalizar(const Cjt_categorias& categorias, Cjt_jugadores& jugadores_global) {
    cuadro_resultado_matches = leer_cuadro_resultado_matches();
    // vector que almacena las estadísticas de cada jugador, con su id siendo su posición en el ranking del torneo
    vector<Estadisticas> estadisticas(n);
    crear_cuadro_resultado_final(categorias, estadisticas);
    imprimir_cuadro_resultado_final();
    trasladar_estadisticas(estadisticas, jugadores_global);
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