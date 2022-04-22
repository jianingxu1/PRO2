#include "Torneo.hh"

Torneo::Torneo(int c) {
    this->c = c;
    iniciado = false;
    primera_edicion = true;
}

int Torneo::consultar_categoria() const {
    return c;
}