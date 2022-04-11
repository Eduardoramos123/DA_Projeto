#include "empresa.h"

using namespace std;



int main() {
    Empresa e;
    vector<Stock> stocks = e.getStockPeso();

    for (int i = 0; i < stocks.size() ; i++) {
        cout << stocks[i].getEncomenda().getPeso() << "/" << stocks[i].getEncomenda().getVolume() << " -- " << stocks[i].getNumber() << endl;
    }

    return 0;
}
