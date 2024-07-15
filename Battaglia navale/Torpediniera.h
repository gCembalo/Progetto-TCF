#ifndef Torpediniera_h
#define Torpediniera_h
#include <iostream>
#include <string>
#include <iomanip>
#include<math.h>
#include<cmath>
#include <vector>
#include "Nave.h"
using std::string;
using namespace std;

class Torpediniera : public Nave
{

public:
      Torpediniera(int *P, string D);
};


#endif // Torpediniera_h
