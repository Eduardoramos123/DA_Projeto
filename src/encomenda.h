#ifndef ENCOMENDA_H
#define ENCOMENDA_H


class Encomenda {
private:
    int id;
    int vol;
    int peso;
    int recompensa;
    int tempo_entrega;
public:

    /**
     * Default Encomenda constructor
     */
    Encomenda();

    /**
     * Parametized Encomenda constructor
     * 
     * @param id The ID
     * @param v The volume
     * @param p The weight
     * @param recompensa The delivery reward
     * @param tempo The time needed to deliver
     */
    Encomenda(int id, int v, int p, int recompensa, int tempo);

    /**
     * Gets the ID
     * 
     * @return The ID
     */
    int getId() const;

    /**
     * Gets the volume
     * 
     * @return The volume
     */
    int getVolume() const;

    /**
     * Gets the weight
     * 
     * @return The weight
     */
    int getPeso() const;

    /**
     * Gets the delivery rewards
     * 
     * @return The delivery reward
     */
    int getRecompensa() const;

    /**
     * Gets the time to deliver
     * 
     * @return The time to deliver
     */
    int getTempo() const;

    /**
     * Checks if an Encomenda is not the same as another
     * 
     * @return The encomendas are not the same
     */
    bool operator!= (Encomenda) const;

    /**
     * Checks if an Encomenda is the same as another
     * 
     * @return The encomendas are the same
     */
    bool operator== (Encomenda) const;
};


#endif //ENCOMENDA_H
