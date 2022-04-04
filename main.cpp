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

class Empresa {
private:
    vector<Estafeta> estafetas;
    vector<Encomenda> inventorio;
public:
    void initEstafeta();
    void initInventorio();
    Empresa();
    void devolverEncomendas(Estafeta &e);
    void printEstafeta(); //teste da função initEstafeta
    void printInventorio(); //teste da função initInventorio
};

void Empresa::initEstafeta() {
    fstream file;
    file.open("C:\\Users\\Eduardo\\Desktop\\DA-Projeto\\carrinhas.txt"); //mudar path

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
    ifstream file("C:\\Users\\Eduardo\\Desktop\\DA-Projeto\\encomendas.txt"); //mudar path

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

int main() {
    Empresa e;
    e.printEstafeta();
    cout << endl;
    e.printInventorio();
    return 0;
}
