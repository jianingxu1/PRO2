#include "Cjt_jugadores.hh"

void Cjt_jugadores::leer(int P) {
    this->P = P;
    ranking = vector<string>(P);
    for (int p = 1; p <= P; ++p) {
        string nombre_jugador;
        cin >> nombre_jugador;
        ranking[p - 1] = nombre_jugador;
        Jugador j;
        j.actualizar_posicion(p);
        estadisticas.insert(make_pair(nombre_jugador, j));
    }
}

bool Cjt_jugadores::existe_jugador(string p) const {
    map<string, Jugador>::const_iterator it = estadisticas.find(p);
    return it != estadisticas.end();
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