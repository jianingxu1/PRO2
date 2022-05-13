#include "Cjt_jugadores.hh"

void Cjt_jugadores::leer(int P) {
    this->P = P;
    ranking = vector<string>(P);
    for (int posicion = 1; posicion <= P; ++posicion) {
        cin >> ranking[posicion - 1];
        Jugador j;
        j.actualizar_posicion(posicion);
        estadisticas.insert(make_pair(ranking[posicion - 1], j));
    }
}

void Cjt_jugadores::anadir_jugador(const string& p) {
    if (ranking.size() == P) ranking.push_back(p);
    else ranking[P] = p;
    Jugador j;
    j.actualizar_posicion(P + 1);
    estadisticas.insert(make_pair(p, j));
    ++P;
}

void Cjt_jugadores::eliminar_jugador(const string& p) {
    --P;
    map<string, Jugador>::iterator it = estadisticas.find(p);
    int posicion = it->second.consultar_posicion();
    estadisticas.erase(it);
    for (int i = posicion; i <= P; ++i) {
        ranking[i - 1] = ranking[i];
        map<string, Jugador>::iterator it2 = estadisticas.find(ranking[i - 1]);
        it2->second.actualizar_posicion(i);
    }
}

void Cjt_jugadores::sumar_puntos_jugador(const string& p, int puntos) {
    map<string, Jugador>::iterator it = estadisticas.find(p);
    it->second.sumar_puntos(puntos);
}

void Cjt_jugadores::actualizar_estadisticas_jugador(const string& p, const Estadisticas& estadisticas) {
    map<string, Jugador>::iterator it = this->estadisticas.find(p);
    it->second.actualizar_estadisticas(estadisticas);
}


bool Cjt_jugadores::comp(map<string, Jugador>::iterator it1, map<string, Jugador>::iterator it2) {
    if (it1->second.consultar_puntos() != it2->second.consultar_puntos()) return it1->second.consultar_puntos() > it2->second.consultar_puntos();
    return it1->second.consultar_posicion() < it2->second.consultar_posicion();
}

void Cjt_jugadores::actualizar_ranking() {
    vector< map<string, Jugador>::iterator > v(P);
    int i = 0;
    for (map<string, Jugador>::iterator it = estadisticas.begin(); it != estadisticas.end(); ++it) {
        v[i] = it;
        ++i;
    }
    sort(v.begin(), v.end(), comp);
    for (int i = 0; i < P; ++i) {
        ranking[i] = v[i]->first;
        v[i]->second.actualizar_posicion(i + 1);
    }
}

bool Cjt_jugadores::existe_jugador(const string& p) const {
    map<string, Jugador>::const_iterator it = estadisticas.find(p);
    return it != estadisticas.end();
}

int Cjt_jugadores::consultar_numero_jugadores() const {
    return P;
}

string Cjt_jugadores::consultar_jugador_ranking(int posicion) const {
    return ranking[posicion - 1];
}

void Cjt_jugadores::listar_ranking() const {
    for (int posicion = 1; posicion <= P; ++posicion) {
        map<string, Jugador>::const_iterator it = estadisticas.find(ranking[posicion - 1]);
        cout << posicion << ' ' << ranking[posicion - 1] << ' ' << it->second.consultar_puntos() << endl;
    }
}

void Cjt_jugadores::listar_jugadores() const {
    cout << P << endl;
    for (map<string, Jugador>::const_iterator it = estadisticas.begin(); it != estadisticas.end(); ++it) {
        cout << it->first << ' ';
        it->second.escribir();
    }
}

void Cjt_jugadores::consultar_jugador(const string& p) const {
    map<string, Jugador>::const_iterator it = estadisticas.find(p);
    cout << it->first << ' ';
    it->second.escribir();
}