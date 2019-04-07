#include <string>
#include <iostream>
#include <algorithm>
#include "Registrar.h"

Registrar::Registrar(unsigned int nOW, GenQ<Student>* mQ, int sWT)
{
    numberOfWindows = nOW;
    windows = new Window[numberOfWindows];
    genSetup();
    myQueue = mQ;
    studentWaitTimes = new int[sWT];
    studentHead = 0;
}

void Registrar::genSetup()
{
    worldTime = 0;
    futureStudents = 0;
    studentsServed = 0;

    //Stats
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
    windows = new Window[numberOfWindows];
    genSetup();
}

Registrar::~Registrar()
{
    delete[] studentWaitTimes;
    delete[] windows;
}

void Registrar::age(int* sS)
{
    for (int i = 0; i < numberOfWindows; ++i)
        windows[i].age(myQueue, sS, &studentHead, &studentWaitTimes, worldTime);
}

void Registrar::printStats()
{
    // cout << "WORLD TIME: " << worldTime << endl;
    // for (int i = 0; i < numberOfWindows; i++)
    // {
    //     windows[i].printStats();
    // }
    // cout << "==================================================" << endl;

    cout << "Mean student wait time: " << meanStudentWait << endl;

    cout << "Median student wait time: " << medianStudentWait << endl;

    cout << "Longest a student waited: " << maxStudentWait << endl;

    cout << "Number of students waiting over 10 minutes: " << longStudentWaitTimes << endl;

    cout << "Mean window idle time: " << meanWindowIdleTime << endl;

    cout << "Longest window idle time: "<<maxWindowIdleTime << endl;

    cout << "Number of windows idle for over 5 minutes: " << windowsIdleFor5Minutes << endl;
}

bool Registrar::isFull()
{

}

bool Registrar::isEmpty()
{

}

void Registrar::calculateStats(int allStudents)
{
    //Student calcuations
    //Sort array first
    sort(studentWaitTimes, studentWaitTimes+allStudents);

    //Longest student wait time
    maxStudentWait = studentWaitTimes[allStudents-1];

    int studentSum = 0;

    //Iterate to find sum and number of students waiting over 10
    for (size_t i = 0; i < allStudents; i++) {
        //cout << myReg.studentWaitTimes[i] << endl;
        if(studentWaitTimes[i] > 10)
            longStudentWaitTimes++;
        studentSum += studentWaitTimes[i];
    }

    //Calcuate mean
    meanStudentWait = studentSum/allStudents;

    //Find median
    if(allStudents%2!=0)
    {
        medianStudentWait = studentWaitTimes[allStudents/2];
    }
    else
    {
        medianStudentWait = ((studentWaitTimes[allStudents/2-1])+(studentWaitTimes[allStudents/2]))/2;
    }


    //Window calcuations run the same way
    maxWindowIdleTime = windows[numberOfWindows-1].longestIdleTime;

    int windowSum = 0;

    for (int i = 0; i < numberOfWindows; ++i)
    {
        if(windows[i].longestIdleTime>maxWindowIdleTime) maxWindowIdleTime = windows[i].longestIdleTime;
        if(windows[i].longestIdleTime > 5)
            windowsIdleFor5Minutes++;
        windowSum += windows[i].totalIdleTime;
    }

    meanWindowIdleTime = windowSum/numberOfWindows;

}
