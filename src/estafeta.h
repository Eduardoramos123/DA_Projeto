#ifndef ESTAFETA_H
#define ESTAFETA_H

#include <string>
#include <vector>

#include "encomenda.h"

using namespace  std;

class Estafeta {
private:
    string matricula;
    double volMax;
    double currVol;
    double pesoMax;
    double currPeso;
    vector<Encomenda> entregas;
    double preco_entrega;
    int numero_entregado;
public:
    Estafeta();
    Estafeta(string matricula, double volMax, double pesoMax, double preco_entrega);
    double getVolMax() const;
    double getPesoMax() const;
    vector<Encomenda> getEntregas() const;
    bool addEntrega(Encomenda e);
    double custo_tota() const;
    void removeEntrega(Encomenda e);
    void entregar(Encomenda e);
    Encomenda getEncomenda(int i);
    string getMatricula() const;
};


#endif //ESTAFETA_H
