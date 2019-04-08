#pragma once

#include <iostream>
#include <string>
using namespace std;

// This class simulates a student at the registrar's office

class Student
{
private:
public:
    // Default Constructor
    Student();
    // Constructor
    Student(int waitTime, int timeArrived);
    // Destructor
    ~Student();
    // Moves time ahead one minute for the currentStudent
    void age();

    unsigned int waitTime;
    unsigned int timeLeft;
    unsigned int timeArrived;
    unsigned int studentIDNumber;
    static unsigned int numberOfStudents;
};
