#include <iostream>
#include <string>
#include <cstdlib>
// #include "Window.h"
#include "genQ.h"
#include "fileIO.h"
#include "Registrar.h"

using namespace std;

int main(int argc, char const *argv[])
{
    FileIO io;

    GenQ<int> *test = io.getQueue();
    int j = test->getSize();

    int windows = test->remove();
    int timeArrived;
    int numStudents;
    int timeNeeded;

    GenQ<Student> waitingLine;
    Registrar myReg(windows, &waitingLine);

    while(!test->isEmpty())
    {
        timeArrived = test->remove();
        int numStudents = test->remove();
        for(int i = 0; i < numStudents; i++)
        {
            timeNeeded = test->remove();
            waitingLine.insert(Student(timeNeeded, timeArrived));
        }
    }

    while(!waitingLine.isEmpty())
    {
        myReg.age();
        myReg.printStats();
        cout << "Queue Size: " << waitingLine.numElements << endl;
    }

    return 0;
}
