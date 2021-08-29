#pragma once

#include <string>
#include <ctime>

using namespace std;

class Fisier {
public:
    string nume;
    time_t timp;
    Fisier(string nume_fisier, time_t timp_constr)
    {
        nume = nume_fisier;
        timp = timp_constr;
    }
};