#include <iostream>
using namespace std;
#include <iomanip>
#include<algorithm>
#include<math.h>
#include<cmath>
#include<vector>
#include <string>
#include "Nave.h"
#include "Player.h"
#include "Computer.h"
#include "Game.h"

int main(){
bool Modalita;
srand(static_cast<unsigned int>(time(nullptr))); // Inizializziamo il generatore di numeri casuali
bool test=true;
string answer;
    do{
        cout<<"Come vuoi giocare?\n1) Player vs Player \n2) Player vs Computer\n";
        cin>>answer;
        if(answer=="1"||answer=="2"){
            test=false;
        }
        else{
            cout<<"\nrisposta non valida";
        }
    }
    while(test);

    if(answer=="1"){
        Modalita=true;
    }
    else{
        Modalita=false;
    }

    string player1Name;
    string player2Name;
    Computer Computer1("Paul Dirac");



if(Modalita){
    cout << "Inserire il nome di Player 1: " << endl;
    cin >> player1Name;
    cout << "Inserire il nome di Player 2: " << endl;
    cin >> player2Name;

    Player Player1(player1Name);
    Player Player2(player2Name);

    Game game(&Player1, &Player2);
    game.Gioco(game, &Player1, &Player2);

}
else {
    cout << "Inserire il nome di Player 1: " << endl;
    cin >> player1Name;

    Player Player1(player1Name);
    Computer Computer1("Paul Dirac");

    Game game(&Computer1, &Player1);
    game.Gioco(game, &Computer1, &Player1);

}


    return 0;
}
