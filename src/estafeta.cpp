#include "estafeta.h"

Estafeta::Estafeta() {
    this->matricula = "teste";
    this->volMax = 0;
    this->currVol = 0;
    this->pesoMax = 0;
    this->currPeso = 0;
    this->custo = 0;
}

Estafeta::Estafeta(string matricula, int volMax, int pesoMax, int custo) {
    this->matricula = matricula;
    this->volMax = volMax;
    this->pesoMax = pesoMax;
    this->custo = custo;
    this->currPeso = 0;
    this->currVol = 0;
}

vector<Encomenda> Estafeta::getEntregas() const {
    return entregas;
}

void Estafeta::addEntrega(const Encomenda& e) {
    entregas.push_back(e);
    currPeso += e.getPeso();
    currVol += e.getVolume();
}

string Estafeta::getMatricula() const {
    return matricula;
}

int Estafeta::getVol() const {
    return volMax - currVol;
}

int Estafeta::getPeso() const {
    return pesoMax - currPeso;
}

int Estafeta::getCusto() const {
    return custo;
}