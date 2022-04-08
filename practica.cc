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
    Cjt_jugadores jugadores;
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
                jugadores.anadir_nuevo_jugador(p);
                cout << jugadores.consultar_numero_jugadores() << endl;
            }
            else cout << "ERROR1: Ya existe el jugador " << p << endl;
        }
        else if (comando == "nuevo_torneo") {}
        else if (comando == "baja_jugador") {}
        else if (comando == "baja_torneo") {}
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
