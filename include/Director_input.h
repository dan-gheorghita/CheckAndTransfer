#pragma once
#include "Director.h"

#include <list>
#include <string>

using namespace std;

class Director_input : public Director {
    string path_director_output;
    string nume_director_output;

public:
    using Director::Director;
    void set_output_name(string str);
    void transfer(list<Fisier>::iterator trans);
    int check_file(const char* nm);
    void check_and_transfer();
};