#include "estafeta.h"

Estafeta::Estafeta() {
    matricula = "teste";
    volMax = 0;
    currVol = 0;
    pesoMax = 0;
    currPeso = 0;
    preco_entrega = 0;
    numero_entregado = 0;
}

Estafeta::Estafeta(string matricula, double volMax, double pesoMax, double preco_entrega) {
    this->matricula = matricula;
    this->volMax = volMax;
    this->pesoMax = pesoMax;
    this->numero_entregado = preco_entrega;
    currPeso = 0;
    currVol = 0;
    numero_entregado = 0;
}

vector<Encomenda> Estafeta::getEntregas() const {
    return entregas;
}

bool Estafeta::addEntrega(Encomenda e) {
    if ((e.getPeso() + currPeso) > pesoMax || (e.getVolume() + currVol) > volMax) {
        return false;
    }
    entregas.push_back(e);
    currPeso += e.getPeso();
    currVol += e.getVolume();
    return true;
}

double Estafeta::custo(int num) const {
    return preco_entrega * num;
}

void Estafeta::removeEntrega(Encomenda e) {
    vector<Encomenda> res;
    for (int i = 0; i < entregas.size(); i++) {
        if (e != entregas[i]) {
            res.push_back(entregas[i]);
        }
    }
    entregas = res;
}

void Estafeta::entregar(Encomenda e) {
    numero_entregado++;
    removeEntrega(e);
}

Encomenda Estafeta::getEncomenda(int i) {
    return entregas[i];
}

string Estafeta::getMatricula() const {
    return matricula;
}

double Estafeta::getVolMax() const {
    return volMax;
}

double Estafeta::getPesoMax() const {
    return pesoMax;
}