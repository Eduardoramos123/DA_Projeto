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

void Scenarios::sortEncomendasPesoDesc(vector<Encomenda>& encomendas) const {
    sort(encomendas.begin(), encomendas.end(), 
         [](const Encomenda& e1, const Encomenda& e2) { return e2.getPeso() < e1.getPeso(); });
}

void Scenarios::sortEncomendasVolDesc(vector<Encomenda>& encomendas) const {
    sort(encomendas.begin(), encomendas.end(), 
         [](const Encomenda& e1, const Encomenda& e2) { return e2.getVolume() < e1.getVolume(); });
}

bool Scenarios::fits(const Encomenda& encomenda, const Estafeta& estafeta) const {
    return (encomenda.getVolume() <= estafeta.getVol()) || 
           (encomenda.getPeso() <= estafeta.getVol());
}

void Scenarios::scenario1() {
    vector<Estafeta> estafetas = empresa->getEstafetas();
    vector<Encomenda> encomendas = empresa->getEncomendas();

    sortEstafetasDesc(estafetas);
    sortEncomendasPesoDesc(encomendas);

    vector<Estafeta> estafetasUsados;

    unsigned nEntregues = 0;
    const unsigned nEstafetas = estafetas.size();

    for (const auto encomenda : encomendas) {
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

        if (delivered) nEntregues++;
    }

    cout << "Foram entregues " << nEntregues << "/" << encomendas.size() << " encomendas e foram usados " <<
            estafetasUsados.size() << "/" << nEstafetas << " estafetas." << endl;
    
}

void Scenarios::scenario2() {}

void Scenarios::scenario3() {}