#include "encomenda.h"

Encomenda::Encomenda() {
    this->id = -1;
    this->vol = 0;
    this->peso = 0;
    this->tempo_entrega = -1;
}

Encomenda::Encomenda(int id, int v, int p, int recompensa, int tempo) {
    this->id = id;
    this->vol = v;
    this->peso = p;
    this->recompensa = recompensa;
    this->tempo_entrega = tempo;

}

int Encomenda::getId() const {
    return id;
}

int Encomenda::getVolume() const {
    return vol;
}

int Encomenda::getPeso() const {
    return peso;
}

int Encomenda::getRecompensa() const {
    return recompensa;
}

int Encomenda::getTempo() const {
    return tempo_entrega;
}

bool Encomenda::operator!= (Encomenda e) const {
    return id != e.getId();
}

bool Encomenda::operator== (Encomenda e) const {
    return id == e.getId();
}