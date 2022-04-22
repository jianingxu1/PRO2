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
    categorias.escribir();

    // 2. lectura del conjunto inicial de torneos;
    Cjt_torneos torneos;
    int T;
    cin >> T;
    torneos.leer(T);
    torneos.listar_torneos(categorias);
    
    // // 3. lectura del conjunto inicial de jugadores;
    // Cjt_jugadores jugadores_global;    // contiene el conjunto de jugadores y ranking global del circuito
    // int P;
    // cin >> P;
    // jugadores_global.leer(P);
    
    // // 4. lee comando;
    // string comando;
    // cin >> comando;
    // while (comando != "fin") {
    //     if (comando == "nuevo_jugador" or comando == "nj") {
    //         string p;
    //         cin >> p;
    //         if (not jugadores_global.existe_jugador(p)) {
    //             jugadores_global.anadir_jugador(p);
    //             cout << "El número de jugadores es " << jugadores_global.consultar_numero_jugadores() << '.' << endl;
    //         }
    //         else cout << "ERROR1: Ya existe el jugador " << p << '.' << endl;
    //     }
    //     else if (comando == "nuevo_torneo" or comando == "nt") {
    //         string t;
    //         int c;
    //         cin >> t >> c;
    //         if (1 <= c and c <= C) {
    //             if (not torneos.existe_torneo(t)) {
    //                 Torneo aux_torneo(t, c);
    //                 torneos.anadir_torneo(aux_torneo);
    //                 cout << "El número de torneos del circuito es " << torneos.consultar_numero_torneos() << '.' << endl;
    //             }
    //             else cout << "ERROR2: el torneo " << t << " ya existe." << endl;
    //         }
    //         else {
    //             cout << "ERROR2: la categoria " << c << " no es válida." << endl;
    //         }
    //     }
    //     else if (comando == "baja_jugador" or comando == "bj") {
    //         string p;
    //         cin >> p;
    //         if (jugadores_global.existe_jugador(p)) {
    //             jugadores_global.eliminar_jugador(p);
    //             cout << "El número de jugadores del circuito es " << jugadores_global.consultar_numero_jugadores() << '.' << endl;
    //         }
    //         else cout << "ERROR3: El jugador " << p << " no existe." << endl;
    //     }
    //     else if (comando == "baja_torneo" or comando == "bt") {
    //         string t;
    //         cin >> t;
    //         if (torneos.existe_torneo(t)) {
    //             torneos.eliminar_torneo(jugadores_global, t);
    //             jugadores_global.actualizar_ranking();
    //             cout << "El número de torneos del circuito es " << torneos.consultar_numero_torneos() << '.' << endl;
    //         }
    //         else cout << "ERROR4: El torneo " << t << " no existe." << endl;
    //     }
    //     else if (comando == "iniciar_torneo" or comando == "it") {
    //         string t;
    //         int n;
    //         cin >> t >> n;
    //         Torneo aux = torneos.consultar_torneo(t);
    //         aux.iniciar(jugadores_global, n);   // pasamos jugadores_global y no el ranking ya que posee la funcion consultar_jugador_ranking()
    //         torneos.modificar_torneo(t, aux);
    //     }
    //     else if (comando == "finalizar_torneo" or comando == "ft") {
    //         string t;
    //         cin >> t;
    //         Torneo aux = torneos.consultar_torneo(t);
    //         aux.finalizar(categorias, jugadores_global);
    //         torneos.modificar_torneo(t, aux);
    //         // actualizar ranking general
    //         jugadores_global.actualizar_ranking();
    //     }
    //     else if (comando == "listar_ranking" or comando == "lr") {
    //         jugadores_global.listar_ranking();
    //     }
    //     else if (comando == "listar_jugadores" or comando == "lj") {
    //         jugadores_global.listar_jugadores();
    //     }
    //     else if (comando == "consultar_jugador" or comando == "cj") {
    //         string p;
    //         cin >> p;
    //         if (jugadores_global.existe_jugador(p)) {
    //             Jugador j = jugadores_global.consultar_jugador(p);
    //             j.escribir();
    //         }
    //         else cout << "ERROR: El jugador " << p << " no existe." << endl;
    //     }
    //     else if (comando == "listar_torneos" or comando == "lt") {
    //         torneos.listar_torneos();
    //     }
    //     else if (comando == "listar_categorías" or comando == "lc") {
    //         categorias.escribir();
    //     }
    //     cin >> comando;
    // }
}