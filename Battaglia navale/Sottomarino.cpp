#include "Sottomarino.h"
#include "Nave.h"
#include <iostream>
#include <string>
#include <iomanip>
#include<math.h>
#include<cmath>
#include <vector>
#include "Nave.h"
using std::string;
using namespace std;

Sottomarino::Sottomarino(int *P, string D) : Nave(P, D, 3, 'S') {}
