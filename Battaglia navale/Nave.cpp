#include <iostream>
using namespace std;
#include <iomanip>
#include<algorithm>
#include<vector>
#include<math.h>
#include<cmath>
#include <string>
//commento perché non capisco come funzionano le branch su github
#include "Nave.h"


Nave::Nave(int *P, string D, int L, char type):Direzione(D),Size(L),naveType(type),Affondato(false),StartPosition(P)
{this->setPosition();}


void Nave::calcoloDanni(){
    int x=Size;
    for(int i=0;i<this->getSize();i++){
        if(*Position[i]==2){
            x--;
        }
    }
    if(x==0){
        Affondato = true;
        cout<<"La nave "<< this->getSimbolo()<< " e' colpita e affondata!"<< endl;
    }
}

bool Nave::getAffondato()const{
    return Affondato;
}

void Nave::setPosition(){
    if(Direzione=="Ovest"||Direzione=="ovest"){
        for(int i =0;i<Size;i++){
            Position.push_back(StartPosition-i);
            *Position[i]=1;
        }
    }
    if(Direzione=="est"||Direzione=="Est"){
        for(int i =0;i<Size;i++){
            Position.push_back(StartPosition+i);
            *Position[i]=1;
        }
    }
    if(Direzione=="Nord"||Direzione=="nord"){
        for(int i =0;i<Size;i++){
            Position.push_back(StartPosition-10*i);
            *Position[i]=1;
        }
    }
    if(Direzione=="Sud"||Direzione=="sud"){
        for(int i =0;i<Size;i++){
            Position.push_back(StartPosition+i*10);
            *Position[i]=1;
        }
    }
}


int Nave::getSize() const {
    return Size;
}

char Nave::getSimbolo() const {
    return naveType; // di default n****
}




