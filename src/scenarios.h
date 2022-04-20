#ifndef SCENARIOS_H
#define SCENARIOS_H

#include <algorithm>

#include "empresa.h"

class Scenarios {
private:
    Empresa* empresa;

    /**
     * Sorts a vector of Estafetas in descending
     * order of volume * weight using the STL
     * sort method.
     *
     * @param estafetas The vector to be sorted.
     */
    void sortEstafetasDesc(vector<Estafeta>& estafetas) const;

    /**
     * Sorts a vector of Estafetas in ascending
     * order of volume * weight using the STL
     * sort method.
     *
     * @param estafetas The vector to be sorted.
     */
    void sortEstafetasAsc(vector<Estafeta>& estafetas) const;

    /**
     * Sorts a vector of Encomendas in descending
     * order of weigth using the STL sort method.
     *
     * @param encomendas The vector to be sorted.
     */
    void sortEncomendasPesoDesc(vector<Encomenda>& encomendas) const;

    /**
     * Sorts a vector of Encomendas in ascending
     * order of duration using the STL sort method.
     *
     * @param encomendas The vector to be sorted.
     */
    void sortEncomendasTempoAsc(vector<Encomenda>& encomendas) const;

    /**
     * Sorts a vector of Encomendas in descending
     * order of volume using the STL sort method.
     *
     * @param encomendas The vector to be sorted.
     */
    void sortEncomendasVolDesc(vector<Encomenda>& encomendas) const;

    vector<Encomenda> mergeEncomenda(vector<Encomenda>, vector<Encomenda>);

    vector<Encomenda> mergeSortEncomendaPesoVolume(vector<Encomenda>, int, int);

    vector<Estafeta> mergeEstafeta(vector<Estafeta>, vector<Estafeta>);

    vector<Estafeta> mergeSortEstafetaPesoVolume(vector<Estafeta>, int, int);

    /**
     * Checks if a given Encomenda can be delivered by
     * a given Estafeta.
     *
     * @param encomenda The Encomenda to be delivered.
     * @param estafeta The Estafeta to check if can deliver the Encomenda.
     *
     * @return The Encomenda can be delivered by the Estafeta.
     */
    bool fits(const Encomenda& encomenda, const Estafeta& estafeta) const;

    /**
     * Calculates the sum of the delivery cost
     * of a vector of Estafetas.
     *
     * @param estafetas The vector of Estafetas to calculate the cost.
     *
     * @return The total delivery cost.
     */
    int custo(const vector<Estafeta>&) const;

    /**
     * Calculates the sum of all the rewards
     * of the deliveries of a vector of Encomendas.
     *
     * @param encomendas The vector of Encomendas to calculate the rewards.
     *
     * @return The total delivery reward.
     */
    int lucro(const vector<Encomenda>&) const;

    /**
     * Calculates the maximum value that
     * can be carried by the best Estafeta.
     *
     * @param encomendas The vector of Estafetas to get the different max carries.
     * @param encomendas The vector of Encomendas to get the diffrent Encomendas that are possible to carry.
     *
     * @return The a table with the best value a Estafeta can carry.
     */
    vector<int> knapsackMisto(Estafeta, const vector<Encomenda>, vector<vector<Encomenda>>&);

    int maximizarLucro(vector<int>, vector<vector<Encomenda>>, vector<Estafeta>, int&);

    vector<Estafeta> removeEstafeta(vector<Estafeta>, Estafeta);

    vector<Encomenda> removeEncomenda(vector<Encomenda>, Encomenda);



public:

    /**
     * Scenarios constructor, creates a new Empresa
     */
    Scenarios();

    /**
     * Scenarios destructor, cleans up used memory.
     */
    ~Scenarios();

    /**
     * Solves the first scenario using a best-fit-decreasing 
     * approach to the bin packing problem.
     */
    void scenario1();
    void scenario2();
    void scenario3();
};

#endif // SCENARIOS_H
