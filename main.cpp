#include <iostream>
#include <string>
#include <cstdlib>
// #include "Window.h"
// #include "genQ.h"
#include "Registrar.h"

using namespace std;

int main(int argc, char const *argv[])
{
    GenQ<Student> myQueue;
    Registrar myReg(3, &myQueue);

    for (size_t i = 0; i < 10; i++) {
        Student myStud(1, 1, 1);
        myQueue.insert(myStud);
    }

    while(!myQueue.isEmpty())
    {
        myReg.age();
        myReg.printStats();
        // cout << "Queue Size: " << myQueue.numElements << endl;
    }

    for (size_t i = 0; i < 10; i++) {
        myReg.age();
        myReg.printStats();
    }

    return 0;
}
