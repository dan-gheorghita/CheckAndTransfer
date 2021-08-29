#include "Director_input.h"

#include <fstream>
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

void Director_input::set_output_name(string str)
{
    nume_director_output = str;
    path_director_output = path_of_directory + str + "/";
    if (mkdir(path_director_output.c_str(), 0777) == -1) {
        cerr << "Error :  " << strerror(errno) << endl;
    } else {
        cout << "Output directory created" << endl;
    }
}

void Director_input::transfer(list<Fisier>::iterator trans)
{
    string path_of_fisier = path_of_directory + trans->nume;
    ifstream file_to_read(path_of_fisier, ifstream::binary);

    string nume_fara_ext = trans->nume.substr(0, trans->nume.find_last_of("."));
    string extensia = trans->nume.substr(trans->nume.find_last_of(".") + 1);

    struct stat file_stats;

    if (stat(path_of_fisier.c_str(), &file_stats) == -1)
        perror(path_of_fisier.c_str());

    int size_of_files = 1000; //marimea fisierelor de 1KB

    unsigned long filesize = (unsigned long)file_stats.st_size;
    double middle = (double)filesize / size_of_files;
    unsigned long maxim = (unsigned long)middle;
    int last = (int)((middle - maxim) * size_of_files + 0.5);

    int i = 0;

    // crearea fisierelor mici
    while (i < maxim) {
        ofstream file_to_write(path_director_output + nume_fara_ext + "_" + to_string(i) + ".txt", ofstream::binary);

        char* buffer = new char[size_of_files];

        file_to_read.read(buffer, size_of_files);

        file_to_write.write(buffer, size_of_files);

        delete[] buffer;

        file_to_write.close();

        i++;
    }

    if (last) {
        ofstream file_to_write(path_director_output + nume_fara_ext + "_" + to_string(i) + ".txt", ofstream::binary);

        char* buffer = new char[last];

        file_to_read.read(buffer, last);

        file_to_write.write(buffer, last);

        delete[] buffer;

        file_to_write.close();
    }

    file_to_read.close();
}

int Director_input::check_file(const char* nm)
{
    string str(nm);
    for (list<Fisier>::iterator it = lista_fisiere.begin(); it != lista_fisiere.end(); it++) {
        if (str.compare(it->nume) == 0) {

            time_t timer;
            time(&timer);

            if (difftime(timer, it->timp) >= 10) //check time de fisier
            {
                Director_input::transfer(it);
                Director::delete_file(it);
            }

            return 1;
        }
    }

    Director::read_fisier(str); // adauga noul fisier

    return 0;
}

void Director_input::check_and_transfer()
{
    DIR* dirp = opendir(path_of_directory.c_str());

    struct dirent* dent;

    while ((dent = readdir(dirp)) != NULL) { // citirea din director

        char* nm = dent->d_name;

        if (strcmp(nm, ".") == 0 || strcmp(nm, "..") == 0 || nume_director_output.compare(nm) == 0)
            continue;

        Director_input::check_file(nm);
    }
    closedir(dirp);
}