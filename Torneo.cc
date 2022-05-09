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

void Torneo::crear_cuadro_emparejamientos() const {
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






// char Torneo::ganador_del_match(const string& match) {
//     int length = match.length();
//     int a = 0;
//     int b = 0;
//     for (int i = 0; i < length; i = i + 4) {
//         if (match[i] > match[i+2]) ++a;
//         else ++b;
//     }
//     if (a > b) return 'a';
//     else return 'b';
// }

// void Torneo::actualizar_estadisticas(const string& match, int a, int b, Cjt_jugadores& jugadores_global) {  // PROVISIONAL
//     int n = match.length();
//     if (n == 3) {
//         if (match[0]) {
//             jugadores_global.actualizar_estadistica_jugador()
//         }
//     }
// }

BinTree<string> Torneo::i_leer_cuadro_resultado_matches() {
    string match;
    cin >> match;
    BinTree<string> cuadro_resultado_matches;
    if (match != "0" and match != "0 0") cuadro_resultado_matches = BinTree<string> (match, read_matches(), read_matches());
    return cuadro_resultado_matches;
}

void Torneo::leer_cuadro_resultado_matches() {
    cuadro_resultado_matches = i_leer_cuadro_resultado_matches();
}

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
    i_actualizar_puntos_resultados(categorias, cuadro_ganadores, 1, esta_sumado);
}

void Torneo::trasladar_puntos(Cjt_jugadores& jugadores_global) {
    for (int i = 0; i < n; ++i) {   // es posible que se pueda dar de baja a un jugador sin que haya terminado la edición de un torneo? si es que sí, revisar si existe en cjt_jugadores antes de intentar sumarle
        jugadores_global.sumar_puntos_jugador(jugadores_edicion_actual[i].first, jugadores_edicion_actual[i].second);
    }
    eliminar_puntos(jugadores_global);
}

void Torneo::sustituir_edicion_anterior() {
    jugadores_edicion_anterior = jugadores_edicion_actual;
    n = 0;
    jugadores_edicion_actual.clear();
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
        if (jugadores_global.existe_jugador(jugadores_edicion_anterior[i].first)) {   // si se ha dado de baja el jugador, no hay hacer nada
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
    crear_cuadro_emparejamientos();
    imprimir_cuadro_emparejamientos();
}

void Torneo::finalizar(const Cjt_categorias& categorias, Cjt_jugadores& jugadores_global) {
    leer_cuadro_resultado_matches();
    // leer_resultados(jugadores_global);  // actualizar_estadisticas(jugadores_global) mientras se leen los resultados
    // crear cuadro de resultados
    // imprimir cuadro de resultados
    actualizar_puntos_resultados(categorias);
    imprimir_ranking();
    trasladar_puntos(jugadores_global);
    sustituir_edicion_anterior();

    esta_iniciado = false;
    es_primera_edicion = false;
    BinTree<int> t;
    cuadro_emparejamientos = t;
    BinTree<string> r;
    cuadro_resultados = r;
}








void Torneo::imprimir_ranking() const {
    for (int r = 0; r < n; ++r) {
        cout << r + 1 << '.' << jugadores_edicion_actual[r].first << ' ' << jugadores_edicion_actual[r].second << endl;
    }
}

int Torneo::consultar_categoria() const {
    return c;
}

bool Torneo::consulta_es_primera_edicion() const {
    return es_primera_edicion;
}