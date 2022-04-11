#ifndef EMPRESA_H
#define EMPRESA_H

#include <fstream>
#include <iostream>

#include "estafeta.h"
#include "encomenda.h"
#include "stock.h"

class Empresa {
private:
    vector<Estafeta> estafetas;
    vector<Encomenda> inventorio;

    double get_max(double a, double b);
    vector<Encomenda> merge1(vector<Encomenda> v1, vector<Encomenda> v2);
    vector<Encomenda> merge_sort(vector<Encomenda> v, int init, int fim);
    bool member_Inventorio(vector<Stock> v, Encomenda value);
public:
    void initEstafeta();
    void initInventorio();
    Empresa();
    vector<Encomenda> getInventorio() const;
    void devolverEncomendas(Estafeta &e);
    void printEstafeta(); //teste da função initEstafeta
    void printInventorio(); //teste da função initInventorio
    vector<Stock> getStockPeso();
    void knapsackPeso(Estafeta estafeta);
};

#endif //EMPRESA_H
