#include "Cjt_jugadores.hh"

void Cjt_jugadores::leer(int P) {
    this->P = P;
    ranking = vector<string>(P);
    for (int p = 1; p <= P; ++p) {
        cin >> ranking[p - 1];
        Jugador j;
        j.actualizar_posicion(p);
        estadisticas.insert(make_pair(ranking[p - 1], j));
    }
}

void Cjt_jugadores::anadir_jugador(string p) {
    ++P;
    if (ranking.size() == P - 1) ranking.push_back(p);
    else ranking[P] = p;
    Jugador j;
    j.actualizar_posicion(P);
    estadisticas.insert(make_pair(p, j));
}

void Cjt_jugadores::eliminar_jugador(string p) {
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

void Cjt_jugadores::sumar_puntos_jugador(string p, int puntos) {
    map<string, Jugador>::iterator it = estadisticas.find(p);
    it->second.sumar_puntos(puntos);
}

bool Cjt_jugadores::existe_jugador(string p) const {
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

void Cjt_jugadores::consultar_jugador(string p) const {
    map<string, Jugador>::const_iterator it = estadisticas.find(p);
    cout << it->first << ' ';
    it->second.escribir();
}