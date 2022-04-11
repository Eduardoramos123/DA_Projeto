#ifndef STOCK_H
#define STOCK_H

#include "encomenda.h"

class Stock {
private:
    Encomenda e;
    int number;
public:
    Stock(Encomenda encomenda, int num);
    Encomenda getEncomenda() const;
    int getNumber() const;
    void incNumber();
};

#endif //STOCK_H
