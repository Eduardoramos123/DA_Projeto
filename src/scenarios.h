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
     * order of weigth * volume using the STL 
     * sort method.
     *
     * @param encomendas The vector to be sorted.
     */
    void sortEncomendasDesc(vector<Encomenda>& encomendas) const;

    /**
     * Sorts a vector of Encomendas in ascending
     * order of duration using the STL sort method.
     *
     * @param encomendas The vector to be sorted.
     */
    void sortEncomendasTempoAsc(vector<Encomenda>& encomendas) const;

    /**
     * Merges to vectors in one organized vector.
     *
     * @param v1 Vector 1 to be merged.
     * @param v2 Vector 2 to be merged.
     * @return Organized Merged Vector.
     */
    vector<Encomenda> mergeEncomenda(vector<Encomenda>, vector<Encomenda>);

    /**
     * Organizes a vector through a merge
     * sort.
     *
     * @param v Vector to be merged.
     * @param init First index of the vector.
     * @param fim Size of the vector.
     *
     * @return Organized vector.
     */
    vector<Encomenda> mergeSortEncomendaRecompensa(vector<Encomenda>, int, int);

    /**
     * Merges to vectors in one organized vector.
     *
     * @param v1 Vector 1 to be merged.
     * @param v2 Vector 2 to be merged.
     * @return Organized Merged Vector.
     */
    vector<Estafeta> mergeEstafeta(vector<Estafeta>, vector<Estafeta>);

    /**
     * Organizes a vector through a merge
     * sort.
     *
     * @param v Vector to be merged.
     * @param init First index of the vector.
     * @param fim Size of the vector.
     *
     * @return Organized vector.
     */
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
     * Caculates a table that gives the best profit
     * for each value of weight and volume a estafeta can have.
     *
     * @param estafeta Estafeta which has the higher Weight * 10 + Volume.
     * @param encomendas The vector of Encomendas to get the diffrent Encomendas that are possible to carry.
     * @param usados The vector of Encomendas that were used by Estafetas.
     *
     * @return The a table with the best value a Estafeta can carry.
     */
    vector<int> knapsackMisto(Estafeta, const vector<Encomenda>, vector<vector<Encomenda>>&);

    /**
     * Gives the index of the estafeta that has the higher profit.
     *
     * @param tabela Last line of tabela that gives the profit of each estafeta.
     * @param estafetas The vector of Estafetas to get the diffrent Estafetas.
     * @param index_estafeta The index of the Encomenda that has the best profit.
     * @param usados A vecctor of used encomendas by each Estafeta.
     *
     * @return Returns the Weight * 10 + Volume of the best Estafeta.
     */
    int maximizarLucro(vector<int>, vector<Estafeta>, int&, vector<vector<Encomenda>>);

    /**
     * Removes Estafeta from a vector.
     *
     * @param estafetas Vector of estafetas.
     * @param estafeta  Estafeta to be removed from the vector.
     *
     * @return Returns The vector estafetas without the Estafeta.
     */
    vector<Estafeta> removeEstafeta(vector<Estafeta>, Estafeta);

    /**
     * Removes Encomenda from a vector.
     *
     * @param encomendas Vector of encomendas.
     * @param encomenda  Encomenda to be removed from the vector.
     *
     * @return Returns The vector encomendas without the Encomenda.
     */
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
