#pragma once

#include <string>
#include <iostream>
#include "Window.h"
// #include "GenQ.h"

class Registrar
{
private:
public:
    Registrar();
    Registrar(unsigned int numberOfWindos, GenQ<Student>* myQueue, int allStudents);
    ~Registrar();
    void age(int* sS);
    void printStats();
    bool isFull();
    bool isEmpty();
    void genSetup();
    void calculateStats();
    GenQ<Student>* myQueue;

    unsigned int numberOfWindows;

    unsigned int worldTime;

    unsigned int futureStudents;
    unsigned int studentsServed;

    Window windows[8];

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
