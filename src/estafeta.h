#ifndef ESTAFETA_H
#define ESTAFETA_H

#include <string>
#include <vector>

#include "encomenda.h"

using namespace  std;

class Estafeta {
private:
    string matricula;
    int volMax;
    int currVol;
    int pesoMax;
    int currPeso;
    int custo;
    vector<Encomenda> entregas;
public:

    /**
     * Default estafeta constructor
     */
    Estafeta();

    /**
     * Parametized estafeta constructor
     * 
     * @param matricula The plate number
     * @param volMax The maximum volume the Estafeta can carry
     * @param pesoMax the maximum weight the Estafeta can carry
     * @param custo The cost of a trip
     */
    Estafeta(string matricula, int volMax, int pesoMax, int custo);

    /**
     * Gets the available volume
     * 
     * @return Volume
     */
    int getVol() const;

    /**
     * Gets the available peso
     * 
     * @return Weight
     */
    int getPeso() const;

    /**
     * Gets the cost of a trip
     * 
     * @return Cost
     */
    int getCusto() const;

    /**
     * Gets the Encomendas assigned
     * 
     * @return Vector of Encomendas
     */
    vector<Encomenda> getEntregas() const;

    /**
     * Assigns a new Encomenda.
     * 
     * @param encomenda The encomenda to assign
     */
    void addEntrega(const Encomenda& encomenda);

    /**
     * Gets the plate number
     * 
     * @return Plate number
     */
    string getMatricula() const;
};


#endif //ESTAFETA_H
