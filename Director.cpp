#include "Director.h"

#include <iostream>
#include <list>
#include <string>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <cstring>
#include <ctime>

using namespace std;

void Director::read_fisier(string nume_fisier)
{
    Fisier* dummy = new Fisier(nume_fisier, time(NULL));
    cout << dummy->nume << ' ';
    cout << ctime(&dummy->timp) << '\n';
    lista_fisiere.push_back(*dummy);
    delete dummy;
}

void Director::delete_file(list<Fisier>::iterator to_delet)
{
    string str = path_of_directory + to_delet->nume;

    if (remove(str.c_str()) != 0)
        perror("Error deleting file");
    else
        cout << "File " + str + " successfully deleted\n";

    lista_fisiere.erase(to_delet);
}

int Director::find_file(const char* nm)
{
    string str(nm);
    for (list<Fisier>::iterator it = lista_fisiere.begin(); it != lista_fisiere.end(); it++) {
        if (str.compare(it->nume) == 0) {
            return 1;
        }
    }
    return 0;
}

void Director::read_fisiere()
{
    DIR* dirp = opendir(path_of_directory.c_str());

    struct dirent* dent;

    while ((dent = readdir(dirp)) != NULL) { // citirea din director

        char* nm = dent->d_name;

        if (strcmp(nm, ".") == 0 || strcmp(nm, "..") == 0 || strcmp(nm, "bufferdir") == 0)
            continue;

        int var = Director::find_file(nm); // cautarea fisierului in vectorul cu denumirile
        cout << var << ' ';
        if (var) {

        } else {
            string str(nm);
            Director::read_fisier(str);
        }
    }
    cout << endl;
    closedir(dirp);
}
