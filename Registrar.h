#pragma once

#include <string>
#include <iostream>
#include "Window.h"

// This class simulates the Registrar's office

class Registrar
{
public:
    // Generic constructor
    Registrar();
    // Constructor - Takes in the number of windows, a pointer to a queue of students,
    // and an int for the number of students
    Registrar(unsigned int numberOfWindows, GenQ<Student>* myQueue, int numOfStudents);
    // The general houskeeping needed for both constructors
    void genSetup();
    // Destructor
    ~Registrar();
    // Age the registrar and all of its sub-units
    void age(int* sS);
    // Print the stats generated at the end
    void printStats();
    // Calculate a bunch of analytical stats
    void calculateStats(int allStudents);
    GenQ<Student>* myQueue;

    int numberOfWindows;

    unsigned int worldTime;

    // Total number of students
    unsigned int futureStudents;
    // Number of students that have already been helped by the registrar
    unsigned int studentsServed;

    // Array of windows
    Window *windows;

    // Stats
    unsigned int meanStudentWait;
    unsigned int medianStudentWait;
    unsigned int maxStudentWait;
    unsigned int longStudentWaitTimes;

    unsigned int meanWindowIdleTime;
    unsigned int maxWindowIdleTime;
    unsigned int windowsIdleFor5Minutes;

    int *studentWaitTimes;
    int studentHead;
};
