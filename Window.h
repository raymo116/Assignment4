#pragma once

#include <iostream>
#include <string>
#include "Student.h"
#include "GenQ.h"
using namespace std;

class Window
{
private:
public:
    Window();
    // Destructor
    ~Window();
    // Prints the stats for debugging purposes
    void printStats();
    // Moves time ahead one minute for the current Window
    void age(GenQ<Student>* myQueue, int* sS, int* sH, int** sWT, int wT);
    // Deletes the current Student
    void deleteStudent(GenQ<Student>* myQueue);
    // Adds a new Student
    void addStudent(Student s);

    Student currentStudent;
    unsigned int currentIdleTime;
    unsigned int longestIdleTime;
    bool helpingStudent;
    // GenQ<Student>* myQueue;
};
