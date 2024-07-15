#ifndef GAME_H
#define GAME_H
#include <iostream>
using namespace std;
#include <iomanip>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <string>
using std::string;
#include "Player.h" 


class Game {
public:
    Game(Player* p1, Player* p2);
    ~Game() {
        delete player1;
        delete player2;
    }
    // DA completare tutto
    void setVittoria(); // per cambiare vittoria a True
    void checkVittoria(Player *p); // verifica quando finire la partita -- usa checkDefeat
    void switchPlayer(); // fa cambiare turno
    Player *chiInizia(Player*, Player*); // lancio un dado (estraggo a caso un numero) chi fa il numero più alto inizia, restituisco il giocatore che inizia --> CurrentPlayer = quello che ha vinto
    void Gioco(Game, Player* , Player*); // implementa in ordine: chiInizia --> Player --> posizionamento, cambioPlayer, posizionamento, cambioPlayer
                                  // turno e checkVittoria finchè non finisce il gioco


private:
    Player* player1;
    Player* player2;
    Player* currentPlayer;
    Player* otherPlayer;
    bool vittoria;
};



#endif
