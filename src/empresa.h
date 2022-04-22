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
    vector<Encomenda> expresso;

    void initEstafetas();
    void initEncomendas();
    void initExpresso();
public:

    /**
     * Default empresa constructor
     */
    Empresa();

    /**
     * Gets the Encomendas that need to be delivered
     * 
     * @return A vector of Encomendas
     */
    vector<Encomenda> getEncomendas() const;

    /**
     * Gets the registered Estafetas
     * 
     * @return A vector of Estafetas
     */
    vector<Estafeta> getEstafetas() const;

    /**
     * Gets the Encomendas that are to be
     * expresso delivered
     * 
     * @return A vector of Encomendas
     */
    vector<Encomenda> getExpresso() const;
};

#endif //EMPRESA_H
