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
#include "Player.h"
#include "Computer.h"
#include <cstdlib>
#include <ctime>


Computer::Computer(string nome):Player(nome),Status(0),SizeShip(0){};


//controllarlo magari facendoci una partita funziona solo se le navi non sono attaccate
//modificare i vari cout
void Computer::shooting(Player &p){
	const int value_colpito = 2;
	const int value_mancato = 3;
	int NumShipEnemyBefore;
	int NumShipEnemyAfter;
	int x;
	int y;
	bool test;
	switch (Status)
	{

	case 0:
		srand(time(NULL));

		test=false;
		do{
    		x = rand()%10;
    		y = rand()%10;
			if(p.getCella(x,y) == 2 || p.getCella(x,y) == 3){
				test=true;
			}
			if(p.getCella(x,y) == 0 ||p.getCella(x,y)== 1){
				test=false;
			}
		}
		while(test);

			if(p.getCella(x,y) == 1){
				p.setCella(x,y, value_colpito);
				// Volendo aggiungere coordinata colpita con eventuale traduzione in lettere
				cout << "\nIl Computer ha colpito una tua nave\n" << endl;
        		XLastShot=x;
        		YLastShot=y;
				SizeShip++;
        		Status=1;
			}
			if(p.getCella(x,y) == 0){
				p.setCella(x,y, value_mancato);
				cout << "\nMancato!\n" << endl;
			}

		NumShipEnemyBefore=p.getNumShip();
		p.updateFleet();
		NumShipEnemyAfter=p.getNumShip();
		if(NumShipEnemyAfter<NumShipEnemyBefore){
			Status=0;
			SizeShip=0;
		}


		break;
	case 1:
	{
		srand(time(NULL));
		vector<string> PosDir;

		if(XLastShot<9){Scacchiera[8][8];
			if(p.getCella(XLastShot+1,YLastShot) == 0 ||p.getCella(XLastShot+1,YLastShot)== 1){
			PosDir.push_back("sud");}}
		if(XLastShot>0){
			if(p.getCella(XLastShot-1,YLastShot) == 0 ||p.getCella(XLastShot-1,YLastShot)== 1){
			PosDir.push_back("nord");}}
		if(YLastShot<9){
			if(p.getCella(XLastShot,YLastShot+1) == 0 ||p.getCella(XLastShot,YLastShot+1)== 1){
			PosDir.push_back("est");}}
		if(YLastShot>0){
			if(p.getCella(XLastShot,YLastShot-1) == 0 ||p.getCella(XLastShot,YLastShot-1)== 1){
			PosDir.push_back("ovest");}}
		//bisogna aggiungere controllo che effettivamente ci sia una direzione possibile
		 if (PosDir.size() > 0) {
                int CasualIndex = rand() % PosDir.size();
                DirShip = PosDir[CasualIndex];

                if (DirShip == "nord") {
                    if (p.getCella(XLastShot - 1, YLastShot) == 1) {
                        p.setCella(XLastShot - 1, YLastShot, value_colpito);
                        cout << "\nIl Computer ha colpito una tua nave\n" << endl;
                        XLastShot--;
                        SizeShip++;
                        Status = 2;
                    } else if (p.getCella(XLastShot - 1, YLastShot) == 0) {
                        p.setCella(XLastShot - 1, YLastShot, value_mancato);
                        cout << "\nMancato!\n" << endl;
                    }
                } else if (DirShip == "sud") {
                    if (p.getCella(XLastShot + 1, YLastShot) == 1) {
                        p.setCella(XLastShot + 1, YLastShot, value_colpito);
                        cout << "\nIl Computer ha colpito una tua nave\n" << endl;
                        XLastShot++;
                        SizeShip++;
                        Status = 2;
                    } else if (p.getCella(XLastShot + 1, YLastShot) == 0) {
                        p.setCella(XLastShot + 1, YLastShot, value_mancato);
                        cout << "\nMancato!\n" << endl;
                    }
                } else if (DirShip == "est") {
                    if (p.getCella(XLastShot, YLastShot + 1) == 1) {
                        p.setCella(XLastShot, YLastShot + 1, value_colpito);
                        cout << "\nIl Computer ha colpito una tua nave\n" << endl;
                        YLastShot++;
                        SizeShip++;
                        Status = 2;
                    } else if (p.getCella(XLastShot, YLastShot + 1) == 0) {
                        p.setCella(XLastShot, YLastShot + 1, value_mancato);
                        cout << "\nMancato!\n" << endl;
                    }
                } else if (DirShip == "ovest") {
                    if (p.getCella(XLastShot, YLastShot - 1) == 1) {
                        p.setCella(XLastShot, YLastShot - 1, value_colpito);
                        cout << "\nIl Computer ha colpito una tua nave\n" << endl;
                        YLastShot--;
                        SizeShip++;
                        Status = 2;
                    } else if (p.getCella(XLastShot, YLastShot - 1) == 0) {
                        p.setCella(XLastShot, YLastShot - 1, value_mancato);
                        cout << "\nMancato!\n" << endl;
                    }
                }
            } else {
                cout << "\nNessuna direzione valida trovata. Il Computer ritorna allo stato precedente per ripensare la strategia.\n" << endl;
                Status = 0;
            }

            NumShipEnemyBefore = p.getNumShip();
            p.updateFleet();
            NumShipEnemyAfter = p.getNumShip();
            if (NumShipEnemyAfter < NumShipEnemyBefore) {
                Status = 0;
                SizeShip = 0;
            }
            break;
    }
	case 2:

		if(DirShip=="nord"){
			if(p.getCella(XLastShot-1,YLastShot)== 1){
				p.setCella(XLastShot-1,YLastShot, value_colpito);
				// Volendo aggiungere coordinata colpita con eventuale traduzione in lettere
				cout << "\nIl Computer ha colpito una tua nave\n" << endl;

        		XLastShot--;
				SizeShip++;
			}
			if(p.getCella(XLastShot-1,YLastShot)==0){
				p.setCella(XLastShot-1,YLastShot, value_mancato);
				cout << "\nMancato!\n" << endl;
				XLastShot+=(SizeShip-1);
				SizeShip=1;
				DirShip="sud";
			}
		}
		if(DirShip=="sud"){
			if(p.getCella(XLastShot+1,YLastShot)== 1){
				p.setCella(XLastShot+1,YLastShot, value_colpito);
				// Volendo aggiungere coordinata colpita con eventuale traduzione in lettere
				cout << "\nIl Computer ha colpito una tua nave\n" << endl;

        		XLastShot++;
				SizeShip++;
			}
			if(p.getCella(XLastShot+1,YLastShot)==0){
				p.setCella(XLastShot+1,YLastShot, value_mancato);
				cout << "\nMancato!\n" << endl;
				XLastShot-=(SizeShip-1);
				SizeShip=1;
				DirShip="nord";
			}
		}
		if(DirShip=="est"){
			if(p.getCella(XLastShot,YLastShot+1)== 1){
				p.setCella(XLastShot,YLastShot+1, value_colpito);
				// Volendo aggiungere coordinata colpita con eventuale traduzione in lettere
				cout << "\nIl Computer ha colpito una tua nave\n" << endl;

        		YLastShot++;
				SizeShip++;
			}
			if(p.getCella(XLastShot,YLastShot+1)==0){
				p.setCella(XLastShot,YLastShot+1, value_mancato);
				cout << "\nMancato!\n" << endl;
				YLastShot-=(SizeShip-1);
				SizeShip=1;
				DirShip="ovest";
			}
		}
		if(DirShip=="ovest"){
			if(p.getCella(XLastShot,YLastShot-1)== 1){
				p.setCella(XLastShot,YLastShot-1, value_colpito);
				// Volendo aggiungere coordinata colpita con eventuale traduzione in lettere
				cout << "\nIl Computer ha colpito una tua nave\n" << endl;

        		YLastShot--;
				SizeShip++;
			}
			if(p.getCella(XLastShot,YLastShot-1)==0){
				p.setCella(XLastShot,YLastShot-1, value_mancato);
				cout << "\nMancato!\n" << endl;
				YLastShot+=(SizeShip-1);
				SizeShip=1;
				DirShip="est";
			}
		}

		if(YLastShot==0 && DirShip=="ovest"){
					XLastShot+=(SizeShip-1);
					SizeShip=1;
					DirShip="est";
				}
		if(YLastShot==9 && DirShip=="est"){
				XLastShot-=(SizeShip-1);
				SizeShip=1;
				DirShip="ovest";
			}
		if(XLastShot==0 && DirShip=="nord"){
				YLastShot+=(SizeShip-1);
				SizeShip=1;
				DirShip="sud";
			}
		if(XLastShot==9 && DirShip=="sud"){
				YLastShot-=(SizeShip-1);
				SizeShip=1;
				DirShip="nord";
			}

		NumShipEnemyBefore=p.getNumShip();
		p.updateFleet();
		NumShipEnemyAfter=p.getNumShip();
		if(NumShipEnemyAfter<NumShipEnemyBefore){
			Status=0;
			SizeShip=0;
		}

		break;

	default:
		srand(time(NULL));

		test=false;
		do{
    		x = rand()%10;
    		y = rand()%10;
			if(p.getCella(x,y) == 2 || p.getCella(x,y) == 3){
				test=true;
			}
			if(p.getCella(x,y) == 0 ||p.getCella(x,y)== 1){
				test=false;
			}
		}
		while(test);

			if(p.getCella(x,y) == 1){
				p.setCella(x,y, value_colpito);
				// Volendo aggiungere coordinata colpita con eventuale traduzione in lettere
				cout << "\nIl Computer ha colpito una tua nave\n" << endl;
        		XLastShot=x;
        		YLastShot=y;
				SizeShip++;
        		Status=1;
			}
			if(p.getCella(x,y) == 0){
				p.setCella(x,y, value_mancato);
				cout << "\nMancato!\n" << endl;
			}

		NumShipEnemyBefore=p.getNumShip();
		p.updateFleet();
		NumShipEnemyAfter=p.getNumShip();
		if(NumShipEnemyAfter<NumShipEnemyBefore){
			Status=0;
			SizeShip=0;
		}



		break;
	}
}


//parte nuova


pair<int, int> Computer::generateRandomCoordinates() {
    return make_pair(rand() % 10, rand() % 10); // (scacchiera 10x10)
}


string Computer::generateRandomDirection() {
    vector<string> directions = { "Nord", "Sud", "Est", "Ovest" };
    return directions[rand() % 4];
}


void Computer::createFleet() {
    srand(time(0)); // Inizializza il generatore di numeri casuali
    int x;
	int y;
    string dir;
    bool test;

    for(int l = 1; l < 3; l++) {
        do {
            tie(x, y) = generateRandomCoordinates();
            //dir = generateRandomDirection(); Genera una direzione casuale
			dir = "Nord";
            test = this->checkCaselle(x, y, 1, dir);
        } while(!test);
        Flotta.push_back(new Lancia(&Scacchiera[x][y], dir));
        drawScacchiera_posizionamento();
    }

    for(int t = 1; t < 3; t++) {
        do {
            tie(x, y) = generateRandomCoordinates();
            dir = generateRandomDirection();
            test = this->checkCaselle(x, y, 2, dir);
        } while(!test);
        Flotta.push_back(new Torpediniera(&Scacchiera[x][y], dir));
        drawScacchiera_posizionamento();
    }

    for(int s = 1; s < 2; s++) {
        do {
            tie(x, y) = generateRandomCoordinates();
            dir = generateRandomDirection();
            test = this->checkCaselle(x, y, 3, dir);
        } while(!test);
        Flotta.push_back(new Sottomarino(&Scacchiera[x][y], dir));
        drawScacchiera_posizionamento();
    }

    for(int c = 1; c < 2; c++) {
        do {
            tie(x, y) = generateRandomCoordinates();
            dir = generateRandomDirection();
            test = this->checkCaselle(x, y, 4, dir);
        } while(!test);
        Flotta.push_back(new Corazzata(&Scacchiera[x][y], dir));
        drawScacchiera_posizionamento();
    }
}

