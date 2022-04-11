#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class Encomenda {
private:
    int enc_id;
    double vol;
    double peso;
    double recompensa;
    double tempo_entrega;
public:
    Encomenda();
    Encomenda(int id, double vol, double peso, double recompensa, double tempo);
    int getId() const;
    double getVolume() const;
    double getPeso() const;
    double getTempo() const;
    bool operator!= (Encomenda e) const {
        return enc_id != e.enc_id;
    }
    bool operator== (Encomenda e) const {
        return enc_id == e.enc_id;
    }
};

Encomenda::Encomenda() {
    enc_id = -1;
    vol = 0;
    peso = 0;
    tempo_entrega = -1;
}

Encomenda::Encomenda(int id, double v, double p, double recompensa, double tempo) {
    enc_id = id;
    vol = v;
    peso = p;
    this->recompensa = recompensa;
    tempo_entrega = tempo;

}

int Encomenda::getId() const {
    return enc_id;
}

double Encomenda::getVolume() const {
    return vol;
}

double Encomenda::getPeso() const {
    return peso;
}

double Encomenda::getTempo() const {
    return tempo_entrega;
}

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
    void addEntrega(Encomenda e);
    double custo_tota() const;
    void removeEntrega(Encomenda e);
    void entregar(Encomenda e);
    Encomenda getEncomenda(int i);
    string getMatricula() const;
};

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

void Estafeta::addEntrega(Encomenda e) {
    entregas.push_back(e);
}

double Estafeta::custo_tota() const {
    return preco_entrega * numero_entregado;
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

class Stock {
private:
    Encomenda e;
    int number;
public:
    Stock(Encomenda encomenda, int num) {
        e = encomenda;
        number = num;
    }
    Encomenda getEncomenda() const {
        return e;
    }
    int getNumber() const {
        return number;
    }
    void incNumber() {
        number++;
    }
};

class Empresa {
private:
    vector<Estafeta> estafetas;
    vector<Encomenda> inventorio;
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

void Empresa::initEstafeta() {
    fstream file;
    file.open("../carrinhas.txt"); //mudar path

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
    ifstream file("../encomendas.txt"); //mudar path

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

double get_max(double a, double b) {
    if (a > b) {
        return a;
    }
    return b;
}

vector<Encomenda> merge1(vector<Encomenda> v1, vector<Encomenda> v2) {
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

vector<Encomenda> merge_sort(vector<Encomenda> v, int init, int fim) {
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

bool member_Inventorio(vector<Stock> v, Encomenda value) {
    for (int i = 0; i < v.size(); i++) {
        Encomenda e1 = v[i].getEncomenda();
        if (e1.getPeso() == value.getPeso() && e1.getVolume() == value.getVolume()) {
            return true;
        }
    }
    return false;
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

int main() {
    Empresa e;
    vector<Stock> stocks = e.getStockPeso();

    for (int i = 0; i < stocks.size() ; i++) {
        cout << stocks[i].getEncomenda().getPeso() << "/" << stocks[i].getEncomenda().getVolume() << " -- " << stocks[i].getNumber() << endl;
    }

    return 0;
}
