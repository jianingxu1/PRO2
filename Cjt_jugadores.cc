/** @file Cjt_jugadores.cc
    @brief Implementación de la clase Cjt_jugadores
*/
#include "Cjt_jugadores.hh"

bool Cjt_jugadores::comp(const map_it& a, const map_it& b) {
    int puntos_a = a->second.consultar_puntos();
    int puntos_b = b->second.consultar_puntos();
    if (puntos_a != puntos_b) return puntos_a > puntos_b;
    return a->second.consultar_posicion() < b->second.consultar_posicion();
}

void Cjt_jugadores::anadir_jugador(const string& p) {
    Jugador j;
    j.modificar_posicion(P + 1);
    pair<map_it, bool> it = estadisticas.insert(make_pair(p, j));
    ranking.push_back(it.first);
    ++P;
}

void Cjt_jugadores::eliminar_jugador(const string& p) {
    --P;
    map_it it = estadisticas.find(p);
    int posicion = it->second.consultar_posicion();
    estadisticas.erase(it);
    for (int i = posicion; i <= P; ++i) {
        ranking[i - 1] = ranking[i];
        ranking[i - 1]->second.modificar_posicion(i);
    }
    ranking.pop_back();
}


void Cjt_jugadores::anadir_puntos_jugador(const string& p, int puntos) {
    map_it it = estadisticas.find(p);
    if (it != estadisticas.end()) it->second.anadir_puntos(puntos);
}

void Cjt_jugadores::anadir_estadisticas_jugador(const string& p, const Estadisticas& estadisticas) {
    map_it it = this->estadisticas.find(p);
    if (it != this->estadisticas.end()) {
        it->second.anadir_estadisticas(estadisticas);
    }
}

void Cjt_jugadores::actualizar_ranking() {
    sort(ranking.begin(), ranking.end(), comp);
    for (int i = 0; i < P; ++i) {
        ranking[i]->second.modificar_posicion(i + 1);
    }
}

void Cjt_jugadores::leer(int P) {
    this->P = P;
    ranking = vector<map_it>(P);
    for (int i = 0; i < P; ++i) {
        string nombre_jugador;
        cin >> nombre_jugador;
        Jugador j;
        j.modificar_posicion(i + 1);
        pair<map_it, bool> it = estadisticas.insert(make_pair(nombre_jugador, j));
        ranking[i] = it.first;
    }
}

void Cjt_jugadores::consultar_jugador(const string& p) const {
    const_map_it it = estadisticas.find(p);
    cout << it->first << ' ';
    it->second.escribir();
}

void Cjt_jugadores::listar_jugadores() const {
    cout << P << endl;
    for (const_map_it it = estadisticas.begin(); it != estadisticas.end(); ++it) {
        cout << it->first << ' ';
        it->second.escribir();
    }
}

void Cjt_jugadores::listar_ranking() const {
    for (int posicion = 1; posicion <= P; ++posicion) {
        cout << posicion << ' ' << ranking[posicion - 1]->first << ' ' <<
        ranking[posicion - 1]->second.consultar_puntos() << endl;
    }
}

bool Cjt_jugadores::existe_jugador(const string& p) const {
    const_map_it it = estadisticas.find(p);
    return it != estadisticas.end();
}

int Cjt_jugadores::consultar_numero_jugadores() const {
    return P;
}

string Cjt_jugadores::consultar_jugador_ranking(int posicion) const {
    return ranking[posicion - 1]->first;
}