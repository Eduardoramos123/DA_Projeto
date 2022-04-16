#include "empresa.h"

using namespace std;



int main() {
    Empresa e;
    vector<Stock> stocks = e.getStockPeso();

    e.cenario1_1();
    cout << endl;
    e.cenario1_2();
    cout << endl;
    e.cenario1_3();
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    vector<int> v = e.knapsack_Peso_Vol();

    return 0;
}
