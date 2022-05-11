#include "Cjt_jugadores.hh"
#include "Cjt_torneos.hh"
#include "Cjt_categorias.hh"

#ifndef NO_DIAGRAM
#include <iostream>
using namespace std;
#endif

int main() {
    // 1. lectura del conjunto de categorías;
    int C, K;
    cin >> C >> K;
    Cjt_categorias categorias(C, K);
    categorias.leer();

    // 2. lectura del conjunto inicial de torneos;
    Cjt_torneos torneos;
    int T;
    cin >> T;
    torneos.leer(T);
    
    // 3. lectura del conjunto inicial de jugadores;
    Cjt_jugadores jugadores_global;
    int P;
    cin >> P;
    jugadores_global.leer(P);
    
    // 4. lee comando;
    string comando;
    cin >> comando;
    while (comando != "fin") {
        cout << "#" << comando;
        if (comando == "nuevo_jugador" or comando == "nj") {
            string p;
            cin >> p;
            cout << ' ' << p << endl;
            if (not jugadores_global.existe_jugador(p)) {
                jugadores_global.anadir_jugador(p);
                cout << jugadores_global.consultar_numero_jugadores() << endl;
            }
            else cout << "error: ya existe un jugador con ese nombre" << endl;
        }
        else if (comando == "nuevo_torneo" or comando == "nt") {
            string t;
            int c;
            cin >> t >> c;
            cout << ' ' << t << ' ' << c << endl;
            if (1 <= c and c <= C) {
                if (not torneos.existe_torneo(t)) {
                    Torneo aux_torneo(c);
                    torneos.anadir_torneo(t, aux_torneo);
                    cout << torneos.consultar_numero_torneos() << endl;
                }
                else cout << "error: ya existe un torneo con ese nombre" << endl;
            }
            else {
                cout << "error: la categoria no existe" << endl;
            }
        }
        else if (comando == "baja_jugador" or comando == "bj") {
            string p;
            cin >> p;
            cout << ' ' << p << endl;
            if (jugadores_global.existe_jugador(p)) {
                torneos.eliminar_puntos_jugador(p);
                jugadores_global.eliminar_jugador(p);
                cout << jugadores_global.consultar_numero_jugadores() << endl;
            }
            else cout << "error: el jugador no existe" << endl;
        }
        else if (comando == "baja_torneo" or comando == "bt") {
            string t;
            cin >> t;
            cout << ' ' << t << endl;
            if (torneos.existe_torneo(t)) {
                torneos.baja_torneo(jugadores_global, t);
                cout << torneos.consultar_numero_torneos() << endl;
            }
            else cout << "error: el torneo no existe" << endl;
        }
        else if (comando == "iniciar_torneo" or comando == "it") {
            string t;
            cin >> t;
            cout << ' ' << t << endl;
            torneos.iniciar_torneo(jugadores_global, t);
        }
        else if (comando == "finalizar_torneo" or comando == "ft") {
            string t;
            cin >> t;
            cout << ' ' << t << endl;
            torneos.finalizar_torneo(categorias, t, jugadores_global);
        }
        else if (comando == "listar_ranking" or comando == "lr") {
            cout << endl;
            jugadores_global.listar_ranking();
        }
        else if (comando == "listar_jugadores" or comando == "lj") {
            cout << endl;
            jugadores_global.listar_jugadores();
        }
        else if (comando == "consultar_jugador" or comando == "cj") {
            string p;
            cin >> p;
            cout << ' ' << p << endl;
            if (jugadores_global.existe_jugador(p)) {
                jugadores_global.consultar_jugador(p);
            }
            else cout << "error: el jugador no existe" << endl;
        }
        else if (comando == "listar_torneos" or comando == "lt") {
            cout << endl;
            torneos.listar_torneos(categorias);
        }
        else if (comando == "listar_categorias" or comando == "lc") {
            cout << endl;
            categorias.escribir();
        }
        cin >> comando;
    }
}