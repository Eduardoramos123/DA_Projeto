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
    Encomenda();
    Encomenda(int, int, int, int, int);
    int getId() const;
    int getVolume() const;
    int getPeso() const;
    int getRecompensa() const;
    int getTempo() const;
    bool operator!= (Encomenda) const;
    bool operator== (Encomenda) const;
};


#endif //ENCOMENDA_H
