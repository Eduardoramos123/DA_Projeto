#ifndef ESTAFETA_H
#define ESTAFETA_H

#include <string>
#include <vector>

#include "encomenda.h"

using namespace  std;

class Estafeta {
private:
    string matricula;
    int volMax;
    int currVol;
    int pesoMax;
    int currPeso;
    int custo;
    vector<Encomenda> entregas;
public:
    Estafeta();
    Estafeta(string, int, int, int);
    int getVol() const;
    int getPeso() const;
    int getCusto() const;
    vector<Encomenda> getEntregas() const;
    void addEntrega(const Encomenda&);
    string getMatricula() const;
};


#endif //ESTAFETA_H
