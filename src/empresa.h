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
public:
    void initEstafeta();
    void initInventorio();
    Empresa();
    vector<Encomenda> getInventorio() const;
    void devolverEncomendas(Estafeta &e);
    void printEstafeta(); //teste da função initEstafeta
    void printInventorio(); //teste da função initInventorio
    vector<Encomenda> merge1(vector<Encomenda> v1, vector<Encomenda> v2);
    vector<Encomenda> merge_sort_Peso(vector<Encomenda> v, int init, int fim);
    vector<Encomenda> merge2(vector<Encomenda> v1, vector<Encomenda> v2);
    vector<Encomenda> merge_sort_Vol(vector<Encomenda> v, int init, int fim);
    vector<Encomenda> merge3(vector<Encomenda> v1, vector<Encomenda> v2);
    vector<Encomenda> merge_sort_Peso_Vol(vector<Encomenda> v, int init, int fim);
    bool member_Inventorio_Peso(vector<Stock> v, Encomenda value);
    vector<Stock> getStockPeso();
    bool member_Inventorio_Vol(vector<Stock> v, Encomenda value);
    vector<Stock> getStockVol();
    bool member_Inventorio_Peso_Vol(vector<Stock> v, Encomenda value);
    vector<Stock> getStockPesoVol();

    vector<Estafeta> merge4(vector<Estafeta> v1, vector<Estafeta> v2);
    vector<Estafeta> merge_sort_estafeta_Peso(vector<Estafeta> v, int init, int fim);
    vector<Estafeta> merge5(vector<Estafeta> v1, vector<Estafeta> v2);
    vector<Estafeta> merge_sort_estafeta_Vol(vector<Estafeta> v, int init, int fim);
    vector<Estafeta> merge6(vector<Estafeta> v1, vector<Estafeta> v2);
    vector<Estafeta> merge_sort_estafeta_Peso_Vol(vector<Estafeta> v, int init, int fim);


    vector<Encomenda> merge7(vector<Encomenda> v1, vector<Encomenda> v2);
    vector<Encomenda> merge_sort_Peso_Vol_V2(vector<Encomenda> v, int init, int fim);
    bool member_Inventorio_Peso_Vol_V2(vector<Stock> v, Encomenda value);
    vector<Stock> getStockPesoVol_V2();
    vector<Estafeta> merge8(vector<Estafeta> v1, vector<Estafeta> v2);
    vector<Estafeta> merge_sort_estafeta_Peso_Vol_V2(vector<Estafeta> v, int init, int fim);
    vector<int> knapsackPeso();
    vector<int> knapsack_Peso_Vol();


    int cenario1_1();
    int cenario1_2();
    int cenario1_3();
};

#endif //EMPRESA_H
