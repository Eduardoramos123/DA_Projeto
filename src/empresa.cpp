#include "empresa.h"

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

vector<Encomenda> Empresa::merge_sort(vector<Encomenda> v, int init, int fim) {
    if (v.size() == 1) {
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

    final1 = merge_sort(part1, 0, part1.size());
    final2 = merge_sort(part2, 0, part2.size());

    return merge1(final1, final2);
}

bool Empresa::member_Inventorio(vector<Stock> v, Encomenda value) {
    for (int i = 0; i < v.size(); i++) {
        Encomenda e1 = v[i].getEncomenda();
        if (e1.getPeso() == value.getPeso() && e1.getVolume() == value.getVolume()) {
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
    vector<Encomenda> sorted = merge_sort(inventorio, 0, inventorio.size());
    vector<Stock> res;
    int j = -1;
    for (int i = 0; i < sorted.size(); i++) {
        if (!member_Inventorio(res, sorted[i])) {
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
