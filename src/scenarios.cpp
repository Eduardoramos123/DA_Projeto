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

void Scenarios::sortEncomendasPesoDesc(vector<Encomenda>& encomendas) const {
    sort(encomendas.begin(), encomendas.end(), 
         [](const Encomenda& e1, const Encomenda& e2) { return e2.getPeso() < e1.getPeso(); });
}

void Scenarios::sortEncomendasVolDesc(vector<Encomenda>& encomendas) const {
    sort(encomendas.begin(), encomendas.end(), 
         [](const Encomenda& e1, const Encomenda& e2) { return e2.getVolume() < e1.getVolume(); });
}

void Scenarios::sortEncomendasTempoAsc(vector<Encomenda>& encomendas) const {
    sort(encomendas.begin(), encomendas.end(), 
         [](const Encomenda& e1, const Encomenda& e2) { return e1.getTempo() < e2.getTempo(); });
}

bool Scenarios::fits(const Encomenda& encomenda, const Estafeta& estafeta) const {
    return (encomenda.getVolume() <= estafeta.getVol()) || 
           (encomenda.getPeso() <= estafeta.getVol());
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

vector<int> Scenarios::knapsackMisto(const vector<Estafeta> estafetas, const vector<Encomenda> encomendas) {
    Estafeta final = estafetas[estafetas.size() - 1];
    vector<vector<int>> tabela(encomendas.size(), vector<int>(final.getPeso() * 10 + final.getVol()));
    for (int i = 0; i < encomendas.size() + 1; i++) {
        for (int w = 0; w < final.getPeso() * 10 + final.getVol() + 1; w++) {
            if (i == 0 || w == 0) {
                tabela[i][w] = 0;
            }
            else if (encomendas[i - 1].getPeso() * 10 + encomendas[i - 1].getVolume() <= w) {
                tabela[i][w] = max(encomendas[i - 1].getRecompensa() + tabela[i - 1][w - encomendas[i - 1].getPeso() * 10 - encomendas[i - 1].getVolume()], tabela[i - 1][w]);
            }
            else {
                tabela[i][w] = tabela[i - 1][w];
            }

        }
    }
    return tabela[tabela.size() - 1];
}

void Scenarios::scenario1() {
    vector<Estafeta> estafetas = empresa->getEstafetas();
    vector<Encomenda> encomendas = empresa->getEncomendas();

    sortEstafetasDesc(estafetas);
    sortEncomendasPesoDesc(encomendas);

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

void Scenarios::scenario2() {}

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
