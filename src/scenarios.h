#ifndef SCENARIOS_H
#define SCENARIOS_H

#include "empresa.h"

class Scenarios {
private:
    Empresa* e;
public:
    Scenarios();
    ~Scenarios();
    void scenario1();
    void scenario2();
    void scenario3();
};

#endif // SCENARIOS_H