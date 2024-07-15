#ifndef Sottomarino_h
#define Sottomarino_h
#include <iostream>
#include <string>
#include <iomanip>
#include<math.h>
#include<cmath>
#include <vector>
#include "Nave.h"
using std::string;
using namespace std;

class Sottomarino : public Nave
{

public:
 Sottomarino(int *P, string D);
};


#endif // Sottomarino_h
