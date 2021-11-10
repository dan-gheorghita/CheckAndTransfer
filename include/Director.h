#pragma once
#include "Fisier.h"

#include <list>
#include <string>

using namespace std;

class Director {
protected:
    string path_of_directory;
    list<Fisier> lista_fisiere;

public:
    Director(string nume_director) { path_of_directory = nume_director; }
    void read_fisier(string nume_fisier);
    void delete_file(list<Fisier>::iterator to_delet);
    void create_sub_directory(string);
    //obsolete functions:
    int find_file(const char* nm);
    void read_fisiere();
};