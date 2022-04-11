#include "encomenda.h"

Encomenda::Encomenda() {
    enc_id = -1;
    vol = 0;
    peso = 0;
    tempo_entrega = -1;
}

Encomenda::Encomenda(int id, double v, double p, double recompensa, double tempo) {
    enc_id = id;
    vol = v;
    peso = p;
    this->recompensa = recompensa;
    tempo_entrega = tempo;

}

int Encomenda::getId() const {
    return enc_id;
}

double Encomenda::getVolume() const {
    return vol;
}

double Encomenda::getPeso() const {
    return peso;
}

double Encomenda::getTempo() const {
    return tempo_entrega;
}

bool Encomenda::operator!= (Encomenda e) const {
    return enc_id != e.enc_id;
}

bool Encomenda::operator== (Encomenda e) const {
    return enc_id == e.enc_id;
}