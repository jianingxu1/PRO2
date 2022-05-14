#include "Cjt_torneos.hh"

Cjt_torneos::Cjt_torneos() {}

Cjt_torneos::~Cjt_torneos() {}

void Cjt_torneos::leer(int T) {
    this->T = T;
    for (int i = 0; i < T; ++i) {
        string t;
        int c;
        cin >> t >> c;
        Torneo torneo(c);
        torneos.insert(make_pair(t, torneo));
    }
}

void Cjt_torneos::anadir_torneo(const string& t, const Torneo& torneo) {
    ++T;
    torneos.insert(make_pair(t, torneo));
}

void Cjt_torneos::baja_torneo(Cjt_jugadores& jugadores_global, const string& t) {
    map<string, Torneo>::iterator it = torneos.find(t);
    bool contiene_puntos = not it->second.consulta_es_primera_edicion();    // si es la primera edición, los jugadores no contienen puntos
    if (contiene_puntos) it->second.eliminar_puntos(jugadores_global);
    torneos.erase(it);
    --T;
    jugadores_global.actualizar_ranking();
}

void Cjt_torneos::iniciar_torneo(const Cjt_jugadores& jugadores_global, const string& t) {
    map<string, Torneo>::iterator it = torneos.find(t);
    it->second.iniciar(jugadores_global);
}

void Cjt_torneos::finalizar_torneo(const Cjt_categorias& categorias, const string& t, Cjt_jugadores& jugadores_global) {
    map<string, Torneo>::iterator it = torneos.find(t);
    it->second.finalizar(categorias, jugadores_global);
}

void Cjt_torneos::eliminar_puntos_jugador(const string& p) {
    for (map<string, Torneo>::iterator it = torneos.begin(); it != torneos.end(); ++it) {
        if (not it->second.consulta_es_primera_edicion()) it->second.eliminar_puntos_jugador(p);
    }
}

bool Cjt_torneos::existe_torneo(const string& t) const {
    map<string, Torneo>::const_iterator it = torneos.find(t);
    return it != torneos.end();
}

int Cjt_torneos::consultar_numero_torneos() const {
    return T;
}

void Cjt_torneos::listar_torneos(const Cjt_categorias& categorias) const {
    cout << T << endl;
    for (map<string, Torneo>::const_iterator it = torneos.begin(); it != torneos.end(); ++it) {
        cout << it->first << ' ' << categorias.consultar_nombre_categoria(it->second.consultar_categoria()) << endl;
    }
}