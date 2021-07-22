#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <dirent.h>
#include <fstream>
#include <iostream>
#include <string.h>
#include <string>
#include <sys/stat.h>
#include <sys/types.h>
#include <thread>
#include <unistd.h>

using namespace std;

char** sir = (char**)malloc(10 * sizeof(char*));
time_t timesir[10];

int change = 0;
int check = 0;

int find_file(const char* nm)
{
    int i;
    for (i = 0; i < change; i++)
        if (strcmp(*(sir + i), nm) == NULL) {
            return i + 1;
        }
    return 0;
}

void stergere(int k)
{
    int i;
    for (i = k; i < change - 1; i++) {
        strcpy(*(sir + i), *(sir + i + 1));
        timesir[i] = timesir[i + 1];
    }

    free(*(sir + change - 1));
}

void dividerestore(string dir, string fullnume)
{

    string fout(dir);
    fout += "bufferdir/";

    int i = 0;
    int length = 0;
    //cautarea punctului pentru a separa extensia de nume
    for (i = fullnume.length() - 1; i >= 0; i--)
        if (fullnume[i] == '.')
            break;
    //cout << i << " " << fullnume.length() - 1 << '\n';

    char c_nume[20];
    char c_ext[10];
    length = fullnume.copy(c_nume, i, 0);
    c_nume[length] = '\0';
    length = fullnume.copy(c_ext, fullnume.length() - 1, i);
    c_ext[length] = '\0';

    //cout << c_nume << c_ext << '\n';
    string nume(c_nume);
    string ext(c_ext);

    ifstream finfile(dir + fullnume, ifstream::binary);
    ofstream foutfile(fout + nume + "_final" + ext, ofstream::binary);

    long size = 1000; //marimea fisierelor de 1KB

    i = 0;
    //crearea fisierelor mici
    while (finfile.eof() == false) {

        ofstream outfile(fout + nume + "_" + to_string(i) + ".txt",ofstream::binary);

        char* buffer = new char[size];

        finfile.read(buffer, size);

        outfile.write(buffer, size);

        delete[] buffer;

        outfile.close();

        i++;
    }
    int sup = i;
    i = 0;
    
    //restaurarea fisierului principal
    while (i < sup) {

        ifstream infile(fout + nume + "_" + to_string(i) + ".txt",ofstream::binary);

        char* buffer = new char[size];

        infile.read(buffer, size);

        foutfile.write(buffer, size);

        delete[] buffer;

        infile.close();

        i++;
    }

    foutfile.close();
    finfile.close();
}

int check_dir(const char* dir)
{

    if (chdir(dir) == -1) { //schimbarea cu directorul apelat
        perror(dir);
        return 1;
    }

    DIR* dirp = opendir(".");

    struct dirent* dent;

    while ((dent = readdir(dirp)) != NULL) { // citirea din director
        char* nm = dent->d_name;

        if (strcmp(nm, ".") == 0 || strcmp(nm, "..") == 0)
            continue;

        if (check == 0) { //crearea directorului pentru transfer
            if (mkdir("bufferdir", 0777) == -1) {
                cerr << "Error :  " << strerror(errno) << endl;
            } else {
                cout << "Directory created" << endl;
            }
            check = 1;
        } else if (strcmp(nm, "bufferdir") == 0)
            continue;

        int var = find_file(nm); //cautarea fisierului in vectorul cu denumirile

        if (var) {
        	  // check curent time
            time_t timer;
            time(&timer);

            if (difftime(timer, timesir[var - 1]) >= 10) // timpul fisierului in folder: time(nm)>10s
            {
                // transfera fisieru in fisiere 1KB si lea saambleaza la loc
                string st_dir(dir);
                string st_nm(nm);
                dividerestore(st_dir, st_nm);

                printf("\n%s | curent poz in sir:%d max poz:%d\n", nm, var - 1, change);

                //stergerea fisierlui initial
                if (remove(nm) != 0)
                    perror("Error deleting file");
                else
                    puts("File successfully deleted");

                //stregerea in vectori
                stergere(var - 1);
                change--;
            }

        } else {
            cout << nm << ' ';
            
            //*(sir + change) = nm;
            *(sir + change) = (char*)malloc(strlen(nm) + 1);
            strcpy(*(sir + change), nm);

            // set time(nm);
            timesir[change] = time(NULL);

            
            
            change++;
        }
    }
    // cout << '\n';
    closedir(dirp);

    return 0;
}

int main()
{

    while (1) {
        this_thread::sleep_for(chrono::milliseconds(500));
        check_dir("/home/ban/Desktop/pics/");
    }
    return (0);
}
