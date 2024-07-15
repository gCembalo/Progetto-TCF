#ifndef NAVE_H
#define NAVE_H
#include <iostream>
using namespace std;
#include <iomanip>
#include<algorithm>
#include<math.h>
#include<cmath>
#include <vector>
#include <string>

class Nave{

public:

//costruttore della nave posizione iniziale, direzione, lunghezza (size), tipo di nave
    Nave(int *P, string D, int L, char naveType);
//penso serva
    virtual ~Nave() {}
// check delle componenti della nave aggiorna il valore della variabile affondato
    void calcoloDanni();
// return del valore di affondato
    bool getAffondato() const;
// inizializza Position dando i puntotori alla scacchiera
    void setPosition();
//simbolo delle navi (lettera iniziale) 
    char getSimbolo() const;
//return size navi
    int getSize() const;

private:
    string Direzione;
    int Size ;
    bool Affondato;
    int *StartPosition;
    vector<int*> Position;
    char naveType;

};

/*
//lancia dim 1
class Lancia : public Nave {
public:
    Lancia(int &P, string D);
    char getSimbolo() const override;
};
//torpediniera dim 2
class Torpediniera : public Nave {
public:
    Torpediniera(int &P, string D);
    char getSimbolo() const override;
};
//sottomarino, dim 3
class Sottomarino : public Nave {
public:
    Sottomarino(int &P, string D);
    char getSimbolo() const override;
};
//corazzata dim 4
class Corazzata : public Nave {
public:
    Corazzata(int &P, string D);
    char getSimbolo() const override;
};

*/


#endif
