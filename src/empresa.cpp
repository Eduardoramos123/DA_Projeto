#include "empresa.h"
#include "encomenda.h"
#include "stock.h"
#include "estafeta.h"

double Empresa::get_max(double a, double b) {
    if (a > b) {
        return a;
    }
    return b;
}

vector<Encomenda> Empresa::merge1(vector<Encomenda> v1, vector<Encomenda> v2) {
    vector<Encomenda> res;

    int i = 0;
    int j = 0;

    while (i < v1.size() && j < v2.size()) {
        if (v1[i].getPeso() < v2[j].getPeso()) {
            res.push_back(v1[i]);
            i++;
        } else {
            res.push_back(v2[j]);
            j++;
        }
    }

    while(i < v1.size()) {
        res.push_back(v1[i]);
        i++;
    }
    while(j < v2.size()) {
        res.push_back(v2[j]);
        j++;
    }
    return res;
}

vector<Encomenda> Empresa::merge_sort_Peso(vector<Encomenda> v, int init, int fim) {
    if (v.size() <= 1) {
        return v;
    }

    int medio = (init + fim) / 2;

    vector<Encomenda> part1;
    vector<Encomenda> part2;

    for (int i = init; i < medio; i++) {
        part1.push_back(v[i]);
    }

    for (int i = medio; i < fim; i++) {
        part2.push_back(v[i]);
    }

    vector<Encomenda> final1;
    vector<Encomenda> final2;

    final1 = merge_sort_Peso(part1, 0, part1.size());
    final2 = merge_sort_Peso(part2, 0, part2.size());

    return merge1(final1, final2);
}

vector<Encomenda> Empresa::merge2(vector<Encomenda> v1, vector<Encomenda> v2) {
    vector<Encomenda> res;

    int i = 0;
    int j = 0;

    while (i < v1.size() && j < v2.size()) {
        if (v1[i].getVolume() < v2[j].getVolume()) {
            res.push_back(v1[i]);
            i++;
        } else {
            res.push_back(v2[j]);
            j++;
        }
    }

    while(i < v1.size()) {
        res.push_back(v1[i]);
        i++;
    }
    while(j < v2.size()) {
        res.push_back(v2[j]);
        j++;
    }
    return res;
}

vector<Encomenda> Empresa::merge_sort_Vol(vector<Encomenda> v, int init, int fim) {
    if (v.size() <= 1) {
        return v;
    }

    int medio = (init + fim) / 2;

    vector<Encomenda> part1;
    vector<Encomenda> part2;

    for (int i = init; i < medio; i++) {
        part1.push_back(v[i]);
    }

    for (int i = medio; i < fim; i++) {
        part2.push_back(v[i]);
    }

    vector<Encomenda> final1;
    vector<Encomenda> final2;

    final1 = merge_sort_Vol(part1, 0, part1.size());
    final2 = merge_sort_Vol(part2, 0, part2.size());

    return merge2(final1, final2);
}

vector<Encomenda> Empresa::merge3(vector<Encomenda> v1, vector<Encomenda> v2) {
    vector<Encomenda> res;

    int i = 0;
    int j = 0;

    while (i < v1.size() && j < v2.size()) {
        if ((v1[i].getPeso() + v1[i].getVolume()) < (v2[i].getPeso() + v2[i].getVolume())) {
            res.push_back(v1[i]);
            i++;
        } else {
            res.push_back(v2[j]);
            j++;
        }
    }

    while(i < v1.size()) {
        res.push_back(v1[i]);
        i++;
    }
    while(j < v2.size()) {
        res.push_back(v2[j]);
        j++;
    }
    return res;
}

vector<Encomenda> Empresa::merge_sort_Peso_Vol(vector<Encomenda> v, int init, int fim) {
    if (v.size() <= 1) {
        return v;
    }

    int medio = (init + fim) / 2;

    vector<Encomenda> part1;
    vector<Encomenda> part2;

    for (int i = init; i < medio; i++) {
        part1.push_back(v[i]);
    }

    for (int i = medio; i < fim; i++) {
        part2.push_back(v[i]);
    }

    vector<Encomenda> final1;
    vector<Encomenda> final2;

    final1 = merge_sort_Peso_Vol(part1, 0, part1.size());
    final2 = merge_sort_Peso_Vol(part2, 0, part2.size());

    return merge3(final1, final2);
}



bool Empresa::member_Inventorio_Peso(vector<Stock> v, Encomenda value) {
    for (int i = 0; i < v.size(); i++) {
        Encomenda e1 = v[i].getEncomenda();
        if (e1.getPeso() == value.getPeso()) {
            return true;
        }
    }
    return false;
}

void Empresa::initEstafeta() {
    fstream file;
    file.open("../data/carrinhas.txt"); //mudar path

    string var1, var2, var3;
    file >> var1 >> var2 >> var3;

    int i = 0;

    double volMax, pesoMax, custo;
    while (file >> volMax >> pesoMax >> custo) {
        string matricula = to_string(i);
        i++;
        Estafeta e = Estafeta(matricula, volMax, pesoMax, custo);
        estafetas.push_back(e);
    }
    file.close();
}

void Empresa::initInventorio() {
    ifstream file("../data/encomendas.txt"); //mudar path

    string var1, var2, var3, var4;
    file >> var1 >> var2 >> var3 >> var4;

    int i = 0;

    double v, p, recompensa, tempo;
    while (file >> v >> p >> recompensa >> tempo) {
        Encomenda e = Encomenda(i, v, p, recompensa, tempo);
        i++;
        inventorio.push_back(e);
    }
    file.close();
}

Empresa::Empresa() {
    initEstafeta();
    initInventorio();
}

vector<Encomenda> Empresa::getInventorio() const {
    return inventorio;
}

void Empresa::devolverEncomendas(Estafeta &e) {
    vector<Encomenda> entregas = e.getEntregas();
    for (int i = 0; i < entregas.size(); i++) {
        inventorio.push_back(entregas[i]);
        e.removeEntrega(entregas[i]);
    }
}

void Empresa::printEstafeta() {
    for (int i = 0; i < estafetas.size(); i++) {
        cout << "--------------Matricula: " << estafetas[i].getMatricula() << " --------------" << endl;
    }
}

void Empresa::printInventorio() {
    for (int i = 0; i < inventorio.size(); i++) {
        cout << "--------------Encomenda ID: " << inventorio[i].getId() << " --------------" << endl;
    }
}

vector<Stock> Empresa::getStockPeso() {
    vector<Encomenda> sorted = merge_sort_Peso(inventorio, 0, inventorio.size());
    vector<Stock> res;
    int j = -1;
    for (int i = 0; i < sorted.size(); i++) {
        if (!member_Inventorio_Peso(res, sorted[i])) {
            Stock s = Stock(sorted[i], 1);
            res.push_back(s);
            j++;
        }
        else {
            res[j].incNumber();
        }
    }
    return res;
}

bool Empresa::member_Inventorio_Vol(vector<Stock> v, Encomenda value) {
    for (int i = 0; i < v.size(); i++) {
        Encomenda e1 = v[i].getEncomenda();
        if (e1.getVolume() == value.getVolume()) {
            return true;
        }
    }
    return false;
}

vector<Stock> Empresa::getStockVol() {
    vector<Encomenda> sorted = merge_sort_Vol(inventorio, 0, inventorio.size());
    vector<Stock> res;
    int j = -1;
    for (int i = 0; i < sorted.size(); i++) {
        if (!member_Inventorio_Vol(res, sorted[i])) {
            Stock s = Stock(sorted[i], 1);
            res.push_back(s);
            j++;
        }
        else {
            res[j].incNumber();
        }
    }
    return res;
}

bool Empresa::member_Inventorio_Peso_Vol(vector<Stock> v, Encomenda value) {
    for (int i = 0; i < v.size(); i++) {
        Encomenda e1 = v[i].getEncomenda();
        if (e1.getVolume() == value.getVolume() && e1.getPeso() == value.getPeso()) {
            return true;
        }
    }
    return false;
}

vector<Stock> Empresa::getStockPesoVol() {
    vector<Encomenda> sorted = merge_sort_Vol(inventorio, 0, inventorio.size());
    vector<Stock> res;
    int j = -1;
    for (int i = 0; i < sorted.size(); i++) {
        if (!member_Inventorio_Peso_Vol(res, sorted[i])) {
            Stock s = Stock(sorted[i], 1);
            res.push_back(s);
            j++;
        }
        else {
            res[j].incNumber();
        }
    }
    return res;
}

vector<Estafeta> Empresa::merge4(vector<Estafeta> v1, vector<Estafeta> v2) {
    vector<Estafeta> res;

    int i = 0;
    int j = 0;

    while (i < v1.size() && j < v2.size()) {
        if (v1[i].getPesoMax() < v2[j].getPesoMax()) {
            res.push_back(v1[i]);
            i++;
        } else {
            res.push_back(v2[j]);
            j++;
        }
    }

    while(i < v1.size()) {
        res.push_back(v1[i]);
        i++;
    }
    while(j < v2.size()) {
        res.push_back(v2[j]);
        j++;
    }
    return res;
}

vector<Estafeta> Empresa::merge_sort_estafeta_Peso(vector<Estafeta> v, int init, int fim) {
    if (v.size() <= 1) {
        return v;
    }

    int medio = (init + fim) / 2;

    vector<Estafeta> part1;
    vector<Estafeta> part2;

    for (int i = init; i < medio; i++) {
        part1.push_back(v[i]);
    }

    for (int i = medio; i < fim; i++) {
        part2.push_back(v[i]);
    }

    vector<Estafeta> final1;
    vector<Estafeta> final2;

    final1 = merge_sort_estafeta_Peso(part1, 0, part1.size());
    final2 = merge_sort_estafeta_Peso(part2, 0, part2.size());

    return merge4(final1, final2);
}

vector<Estafeta> Empresa::merge5(vector<Estafeta> v1, vector<Estafeta> v2) {
    vector<Estafeta> res;

    int i = 0;
    int j = 0;

    while (i < v1.size() && j < v2.size()) {
        if (v1[i].getVolMax() < v2[j].getVolMax()) {
            res.push_back(v1[i]);
            i++;
        } else {
            res.push_back(v2[j]);
            j++;
        }
    }

    while(i < v1.size()) {
        res.push_back(v1[i]);
        i++;
    }
    while(j < v2.size()) {
        res.push_back(v2[j]);
        j++;
    }
    return res;
}

vector<Estafeta> Empresa::merge_sort_estafeta_Vol(vector<Estafeta> v, int init, int fim) {
    if (v.size() <= 1) {
        return v;
    }

    int medio = (init + fim) / 2;

    vector<Estafeta> part1;
    vector<Estafeta> part2;

    for (int i = init; i < medio; i++) {
        part1.push_back(v[i]);
    }

    for (int i = medio; i < fim; i++) {
        part2.push_back(v[i]);
    }

    vector<Estafeta> final1;
    vector<Estafeta> final2;

    final1 = merge_sort_estafeta_Vol(part1, 0, part1.size());
    final2 = merge_sort_estafeta_Vol(part2, 0, part2.size());

    return merge5(final1, final2);
}

vector<Estafeta> Empresa::merge6(vector<Estafeta> v1, vector<Estafeta> v2) {
    vector<Estafeta> res;

    int i = 0;
    int j = 0;

    while (i < v1.size() && j < v2.size()) {
        if ((v1[i].getVolMax() + v1[i].getPesoMax()) < (v2[j].getVolMax() + v2[i].getPesoMax())) {
            res.push_back(v1[i]);
            i++;
        } else {
            res.push_back(v2[j]);
            j++;
        }
    }

    while(i < v1.size()) {
        res.push_back(v1[i]);
        i++;
    }
    while(j < v2.size()) {
        res.push_back(v2[j]);
        j++;
    }
    return res;
}

vector<Estafeta> Empresa::merge_sort_estafeta_Peso_Vol(vector<Estafeta> v, int init, int fim) {
    if (v.size() <= 1) {
        return v;
    }

    int medio = (init + fim) / 2;

    vector<Estafeta> part1;
    vector<Estafeta> part2;

    for (int i = init; i < medio; i++) {
        part1.push_back(v[i]);
    }

    for (int i = medio; i < fim; i++) {
        part2.push_back(v[i]);
    }

    vector<Estafeta> final1;
    vector<Estafeta> final2;

    final1 = merge_sort_estafeta_Peso_Vol(part1, 0, part1.size());
    final2 = merge_sort_estafeta_Peso_Vol(part2, 0, part2.size());

    return merge6(final1, final2);
}

/*
void Empresa::knapsackPeso(Estafeta estafeta) {
    vector<Stock> stock_peso = getStockPeso();
    vector<vector<double>> tabela(estafeta.getPesoMax() + 1, vector<double>(stock_peso.size()));

    for (int i = 0; i < estafeta.getPesoMax() + 1; i++) {
        for (int w = 0; w < stock_peso.size(); w++)  {
            if (i == 0 || w == 0) {
                tabela[i][w] = 0;
            }
            else if () {

            }
        }
    }
}
 */

int Empresa::cenario1_1() {
    int res = 0, est = 0;
    vector<bool> v_est;
    vector<Stock> stocks = getStockPeso();
    vector<Estafeta> v = merge_sort_estafeta_Peso(estafetas, 0, estafetas.size());
    for (int w = 0; w < v.size(); w++) {
        v_est.push_back(false);
    }
    int i = v.size() - 1;
    for (int j = 0; j < stocks.size(); j++) {
        while (stocks[j].getNumber() > 0) {
            if (i < 0) {
                return res;
            }
            if (v[i].addEntrega(stocks[j].getEncomenda())) {
                stocks[j].decNumber();
                res++;
                v_est[i] = true;
            }
            else {
                i--;
            }
        }
    }
    for (int i = 0; i < v_est.size(); i++) {
        if (v_est[i]) {
            est++;
        }
    }

    cout << "Cenario 1 com criterio de Peso: " << endl;
    cout << "Estafetas usados: " << est << endl;
    cout << "Encomendas entregues: " << res << endl;
    return res;
}

int Empresa::cenario1_2() {
    int res = 0, est = 0;
    vector<bool> v_est;
    vector<Stock> stocks = getStockVol();
    vector<Estafeta> v = merge_sort_estafeta_Vol(estafetas, 0, estafetas.size());
    for (int w = 0; w < v.size(); w++) {
        v_est.push_back(false);
    }
    int i = v.size() - 1;
    for (int j = 0; j < stocks.size(); j++) {
        while (stocks[j].getNumber() > 0) {
            if (i < 0) {
                return res;
            }
            if (v[i].addEntrega(stocks[j].getEncomenda())) {
                stocks[j].decNumber();
                res++;
                v_est[i] = true;
            }
            else {
                i--;
            }
        }
    }
    for (int i = 0; i < v_est.size(); i++) {
        if (v_est[i]) {
            est++;
        }
    }

    cout << "Cenario 1 com criterio de Volume: " << endl;
    cout << "Estafetas usados: " << est << endl;
    cout << "Encomendas entregues: " << res << endl;
    return res;
}

int Empresa::cenario1_3() {
    int res = 0, est = 0;
    vector<bool> v_est;
    vector<Stock> stocks = getStockPesoVol();
    vector<Estafeta> v = merge_sort_estafeta_Peso_Vol(estafetas, 0, estafetas.size());
    for (int w = 0; w < v.size(); w++) {
        v_est.push_back(false);
    }
    int i = v.size() - 1;
    for (int j = 0; j < stocks.size(); j++) {
        while (stocks[j].getNumber() > 0) {
            if (i < 0) {
                return res;
            }
            if (v[i].addEntrega(stocks[j].getEncomenda())) {
                stocks[j].decNumber();
                res++;
                v_est[i] = true;
            }
            else {
                i--;
            }
        }
    }
    for (int i = 0; i < v_est.size(); i++) {
        if (v_est[i]) {
            est++;
        }
    }

    cout << "Cenario 1 com criterio de Peso e Volume: " << endl;
    cout << "Estafetas usados: " << est << endl;
    cout << "Encomendas entregues: " << res << endl;
    return res;
}
