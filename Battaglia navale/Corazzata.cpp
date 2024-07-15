#include "Corazzata.h"
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

Corazzata::Corazzata(int *P, string D) : Nave(P, D, 4, 'C') {}
