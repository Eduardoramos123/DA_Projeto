#include "empresa.h"

void Empresa::initEstafetas() {
    fstream file;
    file.open("../data/carrinhas.txt");

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

void Empresa::initEncomendas() {
    ifstream file("../data/encomendas.txt");

    string var1, var2, var3, var4;
    file >> var1 >> var2 >> var3 >> var4;

    int i = 0;

    double v, p, recompensa, tempo;
    while (file >> v >> p >> recompensa >> tempo) {
        Encomenda e = Encomenda(i, v, p, recompensa, tempo);
        i++;
        encomendas.push_back(e);
    }
    file.close();
}

void Empresa::initExpresso() {
    ifstream file("../data/expresso.txt"); //mudar path

    string var1, var2, var3, var4;
    file >> var1 >> var2 >> var3 >> var4;

    int i = 0;

    double v, p, recompensa, tempo;
    while (file >> v >> p >> recompensa >> tempo) {
        Encomenda e = Encomenda(i, v, p, recompensa, tempo);
        i++;
        expresso.push_back(e);
    }
    file.close();
}

Empresa::Empresa() {
    initEstafetas();
    initEncomendas();
    initExpresso();
}

vector<Encomenda> Empresa::getEncomendas() const {
    return encomendas;
}

vector<Estafeta> Empresa::getEstafetas() const {
    return estafetas;
}

vector<Encomenda> Empresa::getExpresso() const {
    return expresso;
}

void Empresa::printEstafetas() const {
    for (int i = 0; i < estafetas.size(); i++) {
        cout << "Matricula: " << estafetas[i].getMatricula() << " | Vol: " << estafetas[i].getVol() <<
            " | Peso: " << estafetas[i].getPeso() << " | Custo: " << estafetas[i].getCusto() << endl;
    }
}

void Empresa::printEncomendas() const {
    for (int i = 0; i < encomendas.size(); i++) {
        cout << "ID: " << encomendas[i].getId() << " | Vol: " << encomendas[i].getVolume() << " | Peso: " << encomendas[i].getPeso() << 
                " | Recompensa: " << encomendas[i].getRecompensa() << " | Tempo: " << encomendas[i].getTempo() << endl;
    }
}
