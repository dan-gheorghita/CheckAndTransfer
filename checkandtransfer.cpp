#include "Director_input.h"

#include <thread> //sleep_for
#include <chrono>

int main()
{
    Director_input dir("/home/ban/Desktop/pics/");
    dir.set_output_name("bufferdir");

    while (1) {
        dir.check_and_transfer();
        //this_thread::sleep_for(chrono::milliseconds(500));
    }
}

//daca folosessti un fisier prea mare foloseste inods si nu mai merge sistemul in folder