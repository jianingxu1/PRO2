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

void Cjt_torneos::anadir_torneo(string t, const Torneo& torneo) {
    ++T;
    torneos.insert(make_pair(t, torneo));
}

bool Cjt_torneos::existe_torneo(string t) const {
    map<string, Torneo>::const_iterator it = torneos.find(t);
    return it != torneos.end();
}

int Cjt_torneos::consultar_numero_torneos() const {
    return T;
}

void Cjt_torneos::listar_torneos(const Cjt_categorias& categorias) const {
    cout << T << endl;
    for (map<string, Torneo>::const_iterator it = torneos.begin(); it != torneos.end(); ++it) {
        cout << it->first << ' ' << categorias.consultar_nombre(it->second.consultar_categoria()) << endl;
    }
}