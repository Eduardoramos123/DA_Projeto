#include "scenarios.h"

using namespace std;

Scenarios::Scenarios() {
    this->empresa = new Empresa();
}

Scenarios::~Scenarios() {
    delete empresa;
}

void Scenarios::sortEstafetasDesc(vector<Estafeta>& estafetas) const {
    sort(estafetas.begin(), estafetas.end(),
         [](const Estafeta& e1, const Estafeta& e2) { return e2.getPeso() * e2.getVol() < e1.getPeso() * e1.getVol(); });
}

void Scenarios::sortEstafetasAsc(vector<Estafeta>& estafetas) const {
    sort(estafetas.begin(), estafetas.end(),
         [](const Estafeta& e1, const Estafeta& e2) { return e1.getPeso() * e1.getVol() < e2.getPeso() * e2.getVol(); });
}

void Scenarios::sortEncomendasDesc(vector<Encomenda>& encomendas) const {
    sort(encomendas.begin(), encomendas.end(),
         [](const Encomenda& e1, const Encomenda& e2) { return e2.getPeso() * e2.getVolume() < e1.getPeso() * e1.getVolume(); });
}

void Scenarios::sortEncomendasTempoAsc(vector<Encomenda>& encomendas) const {
    sort(encomendas.begin(), encomendas.end(),
         [](const Encomenda& e1, const Encomenda& e2) { return e1.getTempo() < e2.getTempo(); });
}

vector<Encomenda> Scenarios::mergeEncomenda(vector<Encomenda> v1, vector<Encomenda> v2) {
    vector<Encomenda> res;

    int i = 0;
    int j = 0;

    while (i < v1.size() && j < v2.size()) {
        if ((v1[i].getPeso() * 10 + v1[i].getVolume()) < (v2[j].getPeso() * 10 + v2[j].getVolume())) {
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

vector<Encomenda> Scenarios::mergeSortEncomendaPesoVolume(vector<Encomenda> v, int init, int fim) {
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

    final1 = mergeSortEncomendaPesoVolume(part1, 0, part1.size());
    final2 = mergeSortEncomendaPesoVolume(part2, 0, part2.size());

    return mergeEncomenda(final1, final2);
}

vector<Estafeta> Scenarios::mergeEstafeta(vector<Estafeta> v1, vector<Estafeta> v2) {
    vector<Estafeta> res;

    int i = 0;
    int j = 0;

    while (i < v1.size() && j < v2.size()) {
        if ((v1[i].getVol() + v1[i].getPeso() * 10) < (v2[j].getVol() + v2[j].getPeso() * 10)) {
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

vector<Estafeta> Scenarios::mergeSortEstafetaPesoVolume(vector<Estafeta> v, int init, int fim) {
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

    final1 = mergeSortEstafetaPesoVolume(part1, 0, part1.size());
    final2 = mergeSortEstafetaPesoVolume(part2, 0, part2.size());

    return mergeEstafeta(final1, final2);
}

bool Scenarios::fits(const Encomenda& encomenda, const Estafeta& estafeta) const {
    return (encomenda.getVolume() <= estafeta.getVol()) &&
           (encomenda.getPeso() <= estafeta.getPeso());
}

int Scenarios::custo(const vector<Estafeta>& estafetas) const {
    int custoTotal = 0;
    for (const auto& e : estafetas) custoTotal += e.getCusto();
    return custoTotal;
}

int Scenarios::lucro(const vector<Encomenda>& encomendas) const {
    int lucroTotal = 0;
    for (const auto& e : encomendas) lucroTotal += e.getRecompensa();
    return lucroTotal;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

vector<int> Scenarios::knapsackMisto(Estafeta estafeta, const vector<Encomenda> encomendas, vector<vector<Encomenda>>& usadas) {
    vector<vector<int>> tabela(encomendas.size() + 1, vector<int>(estafeta.getPeso() * 10 + estafeta.getVol() + 1));
    //vector<vector<Encomenda>> delivery(estafeta.getPeso() + estafeta.getVol() + 1, vector<Encomenda>{});
    vector<vector<Encomenda>> delivery;
    for (int v = 0; v < estafeta.getPeso() * 10 + estafeta.getVol() + 1; v++) {
        vector<Encomenda> en;
        delivery.push_back(en);
    }
    for (int i = 0; i <= encomendas.size(); i++) {
        for (int w = 0; w <= estafeta.getPeso() * 10 + estafeta.getVol() ; w++) {
            if (i == 0 || w == 0) {
                tabela[i][w] = 0;
            }
            else if (encomendas[i - 1].getPeso() * 10 + encomendas[i - 1].getVolume() <= w) {
                tabela[i][w] = max(encomendas[i - 1].getRecompensa() + tabela[i - 1][w - encomendas[i - 1].getPeso() * 10 - encomendas[i - 1].getVolume()], tabela[i - 1][w]);
                if (tabela[i][w] != tabela[i - 1][w]) {
                    delivery[w].push_back(encomendas[i - 1]);
                }
            }
            else {
                tabela[i][w] = tabela[i - 1][w];
            }

        }
    }
    usadas = delivery;
    return tabela[tabela.size() - 1];
}

int Scenarios::maximizarLucro(vector<int> tabela, vector<Estafeta> estafetas, int &index_estafeta) {
    int max = 0;
    int index = -1;

    for (int i = 0; i < estafetas.size(); i++) {
        int w = estafetas[i].getPeso() * 10 + estafetas[i].getVol();
        if (tabela[w] - estafetas[i].getCusto() >= max) {
            max = tabela[w] - estafetas[i].getCusto();
            index = w;
            index_estafeta = i;
        }
    }
    return index;
}

vector<Estafeta> Scenarios::removeEstafeta(vector<Estafeta> v, Estafeta e) {
    vector<Estafeta> res;
    for (int i = 0; i < v.size(); i++) {
        if (v[i].getMatricula() != e.getMatricula()) {
            res.push_back(v[i]);
        }
    }
    return res;
}

vector<Encomenda> Scenarios::removeEncomenda(vector<Encomenda> v, Encomenda e) {
    vector<Encomenda> res;
    for (int i = 0; i < v.size(); i++) {
        if (v[i].getId() != e.getId()) {
            res.push_back(v[i]);
        }
    }
    return res;
}

void Scenarios::scenario1() {
    vector<Estafeta> estafetas = empresa->getEstafetas();
    vector<Encomenda> encomendas = empresa->getEncomendas();

    sortEstafetasDesc(estafetas);
    sortEncomendasDesc(encomendas);

    vector<Estafeta> estafetasUsados;
    vector<Encomenda> encomendasEntregues;

    const unsigned nEstafetas = estafetas.size();

    for (const auto& encomenda : encomendas) {
        bool delivered = false;

        for (auto& estafeta : estafetasUsados) {
            if (fits(encomenda, estafeta)) {
                delivered = true;
                estafeta.addEntrega(encomenda);
                break;
            }
        }

        if (!delivered) {
            // Need to use a new estafeta
            for (auto it = estafetas.begin(); it != estafetas.end(); it++) {
                Estafeta estafeta = *it;
                if (fits(encomenda, estafeta)) {
                    delivered = true;
                    estafeta.addEntrega(encomenda);
                    estafetasUsados.push_back(estafeta);
                    estafetas.erase(it);
                    break;
                }
            }
        }

        if (delivered) encomendasEntregues.push_back(encomenda);

        // Keep the Estafetas sorted in order to always choose the one
        // with the maximum load
        sortEstafetasAsc(estafetasUsados);
    }

    cout << "Foram entregues " << encomendasEntregues.size() << "/" << encomendas.size() << " encomendas e foram usados " <<
         estafetasUsados.size() << "/" << nEstafetas << " estafetas." << endl <<
         "Lucro total: " << lucro(encomendasEntregues) - custo(estafetasUsados) << "." << endl;

}

void Scenarios::scenario2() {
    vector<Estafeta> estafetas = empresa->getEstafetas();
    vector<Encomenda> encomendas = empresa->getEncomendas();

    estafetas = mergeSortEstafetaPesoVolume(estafetas, 0, estafetas.size());
    encomendas = mergeSortEncomendaPesoVolume(encomendas, 0, encomendas.size());

    int profit = 0;
    int numero_estafetas = 0;
    int numero_encomendas = 0;

    while (!estafetas.empty() && !encomendas.empty()) {
        vector<vector<Encomenda>> usadas;
        vector<int> tabela = knapsackMisto(estafetas[estafetas.size() - 1], encomendas, usadas);
        int estafeta_index;
        int index = maximizarLucro(tabela, estafetas, estafeta_index);
        if (index == -1) {
            break;
        }
        numero_estafetas++;
        for (int i = 0; i < usadas[index].size(); i++) {
            if (fits(usadas[index][i], estafetas[estafeta_index])) {
                estafetas[estafeta_index].addEntrega(usadas[index][i]);
                encomendas = removeEncomenda(encomendas, usadas[index][i]);
                numero_encomendas++;
                profit += usadas[index][i].getRecompensa();
            }
        }
        estafetas = removeEstafeta(estafetas, estafetas[estafeta_index]);
    }

    cout << "Lucro: " << profit << endl;
    cout << "Estafetas usados: " << numero_estafetas << endl;
    cout << "Encomendas entregues: " << numero_encomendas << endl;
}

void Scenarios::scenario3() {
    vector<Encomenda> expresso = empresa->getExpresso();

    sortEncomendasTempoAsc(expresso);

    vector<Encomenda> encomendasEntregues;
    int tempo = 0;
    const int tempoMax = 8 * 60 * 60; // Tempo em segundos das 9h00 às 17h00

    for (const auto& e : expresso) {
        int tempoAux = e.getTempo();
        if (tempoAux + tempo <= tempoMax) {
            tempo += tempoAux;
            encomendasEntregues.push_back(e);
        }
        else break;
    }

    cout << "Foram entregues " << encomendasEntregues.size() << "/" << expresso.size() << " encomendas com um tempo médio de " <<
         tempo / encomendasEntregues.size() << " segundos." << endl <<
         "Tempo restante: " << tempoMax - tempo << " segundos." << endl <<
         "Lucro total: " << lucro(encomendasEntregues) << "." << endl;

}
