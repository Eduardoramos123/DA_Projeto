#ifndef ENCOMENDA_H
#define ENCOMENDA_H


class Encomenda {
private:
    int enc_id;
    double vol;
    double peso;
    double recompensa;
    double tempo_entrega;
public:
    Encomenda();
    Encomenda(int id, double vol, double peso, double recompensa, double tempo);
    int getId() const;
    double getVolume() const;
    double getPeso() const;
    double getTempo() const;
    bool operator!= (Encomenda e) const;
    bool operator== (Encomenda e) const;
};


#endif //ENCOMENDA_H
