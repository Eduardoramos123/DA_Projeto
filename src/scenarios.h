#ifndef SCENARIOS_H
#define SCENARIOS_H

#include <algorithm>

#include "empresa.h"

class Scenarios {
private:
    Empresa* empresa;

    void sortEstafetasDesc(vector<Estafeta>&) const;
    void sortEncomendasPesoDesc(vector<Encomenda>&) const;
    void sortEncomendasVolDesc(vector<Encomenda>&) const;

    bool fits(const Encomenda&, const Estafeta&) const;
public:
    Scenarios();
    ~Scenarios();
    void scenario1();
    void scenario2();
    void scenario3();
};

#endif // SCENARIOS_H