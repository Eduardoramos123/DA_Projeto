#include "stock.h"

Stock::Stock(Encomenda encomenda, int num) {
    e = encomenda;
    number = num;
}

Encomenda Stock::getEncomenda() const {
    return e;
}

int Stock::getNumber() const {
    return number;
}

void Stock::incNumber() {
    number++;
}

void Stock::decNumber() {
    number--;
}