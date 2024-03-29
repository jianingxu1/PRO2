/** @file Cjt_torneos.cc
    @brief Implementación de la clase Cjt_torneos
*/
#include "Cjt_torneos.hh"

void Cjt_torneos::anadir_torneo(const string& t, int c) {
    ++T;
    Torneo torneo(c);
    torneos.insert(make_pair(t, torneo));
}

void Cjt_torneos::baja_torneo(const string& t, Cjt_jugadores& jugadores_global) {
    map<string, Torneo>::iterator it = torneos.find(t);
    bool contiene_puntos = not it->second.consulta_es_primera_edicion();    // si es la primera edición, los jugadores no contienen puntos
    if (contiene_puntos) {
        it->second.eliminar_puntos(jugadores_global);
        jugadores_global.actualizar_ranking();
    }
    torneos.erase(it);
    --T;
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

void Cjt_torneos::listar_torneos(const Cjt_categorias& categorias) const {
    cout << T << endl;
    for (map<string, Torneo>::const_iterator it = torneos.begin(); it != torneos.end(); ++it) {
        cout << it->first << ' ' << categorias.consultar_nombre_categoria(it->second.consultar_categoria()) << endl;
    }
}

bool Cjt_torneos::existe_torneo(const string& t) const {
    map<string, Torneo>::const_iterator it = torneos.find(t);
    return it != torneos.end();
}

int Cjt_torneos::consultar_numero_torneos() const {
    return T;
}