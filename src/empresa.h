#ifndef EMPRESA_H
#define EMPRESA_H

#include <fstream>
#include <iostream>

#include "estafeta.h"
#include "encomenda.h"

class Empresa {
private:
    vector<Estafeta> estafetas;
    vector<Encomenda> encomendas;

    void initEstafetas();
    void initEncomendas();
public:
    Empresa();
    vector<Encomenda> getEncomendas() const;
    vector<Estafeta> getEstafetas() const;
    void printEstafetas() const;
    void printEncomendas() const;
};

#endif //EMPRESA_H
