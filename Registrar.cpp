#include <string>
#include <iostream>
#include <algorithm>

#include "Registrar.h"

// This class simulates the Registrar's office

// Generic constructor
Registrar::Registrar()
{
    // Creates windows
    numberOfWindows = 8;
    windows = new Window[numberOfWindows];
    genSetup();
}

// Constructor - Takes in the number of windows, a pointer to a queue of students,
// and an int for the number of students
Registrar::Registrar(unsigned int nOW, GenQ<Student>* mQ, int numOfStudents)
{
    // Create array for windows
    numberOfWindows = nOW;
    windows = new Window[numberOfWindows];

    genSetup();

    // Assign queue
    myQueue = mQ;
    // Create student wait times array
    studentWaitTimes = new int[numOfStudents];
    // Front of the array for student wait times
    studentHead = 0;
}

// The general houskeeping needed for both constructors
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

// Destructor
Registrar::~Registrar()
{
    // Delete dynamically created arrays
    delete[] studentWaitTimes;
    delete[] windows;
}

// Age the registrar and all of its sub-units
void Registrar::age(int* sS)
{
    for (int i = 0; i < numberOfWindows; ++i)
        windows[i].age(myQueue, sS, &studentHead, &studentWaitTimes, worldTime);
}

// Print the stats generated at the end
void Registrar::printStats()
{
    cout << "=====================================================" << endl
         << "Mean student wait time: " << meanStudentWait << endl
         << "Median student wait time: " << medianStudentWait << endl
         << "Longest a student waited: " << maxStudentWait << endl
         << "Number of students waiting over 10 minutes: " << longStudentWaitTimes << endl
         << "Mean window idle time: " << meanWindowIdleTime << endl
         << "Longest window idle time: " << maxWindowIdleTime << endl
         << "Number of windows idle for over 5 minutes: " << windowsIdleFor5Minutes << endl
         << "=====================================================" << endl;
}

// Calculate a bunch of analytical stats
void Registrar::calculateStats(int allStudents)
{
    //========================================
    //Student calcuations
    //========================================

    //Sort array
    sort(studentWaitTimes, studentWaitTimes+allStudents);

    //Longest student wait time
    maxStudentWait = studentWaitTimes[allStudents-1];

    int studentSum = 0;

    //Iterate to find sum and number of students waiting over 10
    for (size_t i = 0; i < allStudents; i++) {
        if(studentWaitTimes[i] > 10)
            longStudentWaitTimes++;
        studentSum += studentWaitTimes[i];
    }

    //Calcuate mean
    meanStudentWait = studentSum/allStudents;

    //Find median
    if(allStudents%2!=0)
        medianStudentWait = studentWaitTimes[allStudents/2];
    else
        medianStudentWait = ((studentWaitTimes[allStudents/2-1])+(studentWaitTimes[allStudents/2]))/2;

    //========================================
    //Window calcuations
    //========================================

    maxWindowIdleTime = windows[numberOfWindows-1].longestIdleTime;

    int windowSum = 0;

    // Cycle through the windows
    for (int i = 0; i < numberOfWindows; ++i)
    {
        // Checks for a new longest idle time
        if(windows[i].longestIdleTime>maxWindowIdleTime) maxWindowIdleTime = windows[i].longestIdleTime;

        // Checks how many windows were idle for more than 5 minutes
        if(windows[i].longestIdleTime > 5)
            windowsIdleFor5Minutes++;

        // Add to the total window idle time
        windowSum += windows[i].totalIdleTime;
    }

    // Calculate the mean idle time
    meanWindowIdleTime = windowSum/numberOfWindows;
}
