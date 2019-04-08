#pragma once

#include <iostream>
#include <string>
#include "Student.h"
#include "GenQ.h"
using namespace std;

class Window
{
public:
    // Constructor
    Window();

    // Destructor
    ~Window();

    // Moves time ahead one minute for the current Window
    // Takes in a pointer to a queue of students, a pointer to studentsServed,
    // a pointer to studentHead, a pointer to studentWaitTimes, and the worldtime
    void age(GenQ<Student>* myQueue, int* sS, int* sH, int** sWT, int wT);

    // Deletes the current Student
    // Takes in a pointer to a queue of students, a pointer to studentsServed,
    // a pointer to studentHead, a pointer to studentWaitTimes, and the worldtime
    void deleteStudent(GenQ<Student>* myQueue, int* sS, int* sH, int** sWT, int worldTime);

    // Add a new student to the window
    // Takes in a student
    void addStudent(Student s);

    Student currentStudent;
    unsigned int currentIdleTime;
    unsigned int longestIdleTime;
    unsigned int totalIdleTime;
    bool helpingStudent;
};
