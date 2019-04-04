#include <string>
#include <iostream>
// #include "Window.h"
#include "Registrar.h"
// #include "GenQ.h"

Registrar::Registrar(unsigned int nOW, GenQ<Student>* mQ)
{
    numberOfWindows = nOW;
    genSetup();
    myQueue = mQ;
}

void Registrar::genSetup()
{
    worldTime = 0;
    futureStudents = 0;
    studentsServed = 0;

    // Determined later
    meanStudentWait = 0;
    medianStudentWait = 0;
    maxStudentWait = 0;
    longStudentWaitTimes = 0;
    meanWindowIdleTime = 0;
    maxWindowIdleTime = 0;
    windowsIdleFor5Minutes = 0;

    for (int i = 0; i < numberOfWindows; ++i)
    {
        Window* myWindow = new Window();
        windows[i] = *myWindow;
    }
}

Registrar::Registrar()
{
    numberOfWindows = 8;
    genSetup();
}

// I don't think we need this because the destructors for the windows are being called anyway
Registrar::~Registrar()
{
    /*
    for (int i = 0; i < numberOfWindows; ++i)
    {
        delete &windows[i];
    }
    */
}

void Registrar::age()
{
    for (int i = 0; i < numberOfWindows; ++i)
    {
        // if(!(windows[i].helpingStudent) && !(myQueue->isEmpty()))
        // {
        //     windows[i].addStudent(myQueue->remove());
        // }
        windows[i].age(myQueue);
    }
    worldTime++;
}

void Registrar::printStats()
{
    cout << "WORLD TIME: " << worldTime << endl;
    for (int i = 0; i < numberOfWindows; i++)
    {
        windows[i].printStats();
    }
    cout << "==========" << endl;
}

bool Registrar::isFull()
{

}

bool Registrar::isEmpty()
{

}

void Registrar::calculateStats()
{
    

    /*
    unsigned int meanStudentWait;
    unsigned int medianStudentWait;
    unsigned int maxStudentWait;
    unsigned int longStudentWaitTimes;

    unsigned int meanWindowIdleTime;
    unsigned int maxWindowIdleTime;
    unsigned int windowsIdleFor5Minutes;
    */
}
