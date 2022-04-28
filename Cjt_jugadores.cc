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

void Cjt_jugadores::anadir_jugador(const string& nombre_jugador) {
    if (ranking.size() == P) ranking.push_back(nombre_jugador);
    else ranking[P] = nombre_jugador;
    Jugador jug;
    jug.actualizar_posicion(P + 1);
    estadisticas.insert(make_pair(nombre_jugador, jug));
    ++P;
}

void Cjt_jugadores::eliminar_jugador(const string& nombre_jugador) {
    --P;
    map<string, Jugador>::iterator it = estadisticas.find(nombre_jugador);
    int posicion = it->second.consultar_posicion();
    estadisticas.erase(it);
    for (int i = posicion; i <= P; ++i) {
        ranking[i - 1] = ranking[i];
        map<string, Jugador>::iterator it2 = estadisticas.find(ranking[i - 1]);
        it2->second.actualizar_posicion(i);
    }
}

void Cjt_jugadores::sumar_puntos_jugador(const string& nombre_jugador, int puntos) {
    map<string, Jugador>::iterator it = estadisticas.find(nombre_jugador);
    it->second.sumar_puntos(puntos);
}

bool Cjt_jugadores::existe_jugador(const string& nombre_jugador) const {
    map<string, Jugador>::const_iterator it = estadisticas.find(nombre_jugador);
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

void Cjt_jugadores::consultar_jugador(const string& nombre_jugador) const {
    map<string, Jugador>::const_iterator it = estadisticas.find(nombre_jugador);
    cout << it->first << ' ';
    it->second.escribir();
}