#include "cjt_jugadores.hh"
#include "cjt_torneos.hh"
#include "cjt_categorias.hh"
#include <iostream>
using namespace std;

int main() {
    // 1. lectura del conjunto de categorías;
    Cjt_categorias categorias;
    int C, K;
    cin >> C >> K;
    categorias.leer(C, K);
    
    // 2. lectura del conjunto inicial de torneos;
    Cjt_torneos torneos;
    int T;
    cin >> T;
    torneos.leer(T);
    
    // 3. lectura del conjunto inicial de jugadores;
    Cjt_jugadores jugadores;    // contiene el conjunto de jugadores y ranking global del circuito
    int P;
    cin >> P;
    jugadores.leer(P);
    
    // 4. lee comando;
    string comando;
    cin >> comando;
    while (comando != "fin") {
        if (comando == "nuevo_jugador") {
            string p;
            cin >> p;
            if (not jugadores.existe_jugador(p)) {
                jugadores.anadir_jugador(p);
                cout << "El número de jugadores es " << jugadores.consultar_numero_jugadores() << '.' << endl;
            }
            else cout << "ERROR1: Ya existe el jugador " << p << '.' << endl;
        }
        else if (comando == "nuevo_torneo") {
            string t;
            int c;
            cin >> t >> c;
            if (1 <= c and c <= C) {
                if (not torneos.existe_torneo(t)) {
                    Torneo aux_torneo(t, c);
                    torneos.anadir_torneo(aux_torneo);
                    cout << "El número de torneos del circuito es " << torneos.consultar_numero_torneos() << '.' << endl;
                }
                else cout << "ERROR2: el torneo " << t << " ya existe." << endl;
            }
            else {
                cout << "ERROR2: la categoria " << c << " no es válida." << endl;
            }
        }
        else if (comando == "baja_jugador") {
            string p;
            cin >> p;
            if (jugadores.existe_jugador(p)) {
                jugadores.eliminar_jugador(p);
                cout << "El número de jugadores del circuito es " << jugadores.consultar_numero_jugadores() << '.' << endl;
            }
            else cout << "ERROR3: El jugador " << p << " no existe." << endl;
        }
        else if (comando == "baja_torneo") {
            string t;
            cin >> t;
            if (torneos.existe_torneo(t)) {
                torneos.eliminar_torneo(jugadores, t);
                cout << "El número de torneos del circuito es " << torneos.consultar_numero_torneos() << '.' << endl;
            }
            else cout << "ERROR4: El torneo " << t << " no existe." << endl;
        }
        else if (comando == "iniciar_torneo") {}
        else if (comando == "finalizar_torneo") {}
        else if (comando == "listar_ranking") {}
        else if (comando == "listar_jugadores") {}
        else if (comando == "consultar_jugador") {}
        else if (comando == "listar_torneos") {}
        else if (comando == "listar_categorías") {}
        cin >> comando;
    }
}
