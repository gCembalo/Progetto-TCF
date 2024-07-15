#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
using namespace std;
#include <iomanip>
#include<vector>
#include<algorithm>
#include<math.h>
#include<cmath>
#include "Nave.h"
#include "Lancia.h"
#include "Sottomarino.h"
#include "Torpediniera.h"
#include "Corazzata.h"



class Player{
    
public:

    Player(string = "player");
    ~Player() {
        for (Nave* ship : Flotta) {
            delete ship;
        }
    }
// i primi due valori sono la posizione nella scacchiera il terzo il valore da modificare
    int getCella(int, int)const;
    int getNumShip()const;
    void setCella(int, int, int );
    void drawScacchiera()const;
    void drawScacchiera_posizionamento()const;
// verifica se le caselle sono libere per ospitare una nave primi due int casella iniziale il terzo 
// la lunghezza e la stringa india la direzione
    bool checkCaselle(int,int,int, string)const;
    virtual void shooting(Player &);
    string traduciCoordinate_in_Lettere(int, int); // riga colonna
    void traduciLettere_in_Coordinate(int*, int*, string);
    bool validateCoordinateFormat(const string& coord) const;
    virtual void createFleet(); // crea flotta e posiziona
    void updateFleet();
    bool checkDefeat();
    string getName() const;
    vector<Nave*> Flotta;
    int Scacchiera[10][10]={0};
    

 
private:

    string Name;    
    int NumShip;


};












#endif
