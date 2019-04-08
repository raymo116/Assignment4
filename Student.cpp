#include <iostream>
#include <string>
#include "Student.h"
using namespace std;

// This class simulates a student at the registrar's office

// Constructor - Takes in the time that the student is going to take and the time that they arrived
Student::Student(int wT, int tA)
{
    int numbers[2] = {wT, tA};

    // Error checking
    for (int i = 0; i < 2; ++i)
        if(numbers[i] < 0) throw invalid_argument(" recieved negative value: " + numbers[i]);

    waitTime = wT;
    timeLeft = wT;
    timeArrived = tA;
}

// Destructor
Student::~Student()
{

}

// Default constructor
Student::Student()
{
    waitTime = 0;
    timeLeft = 0;
    timeArrived = 0;
}

// Moves time ahead one minute for the currentStudent
void Student::age()
{
    if(timeLeft > 0)
        timeLeft--;
    else
        throw underflow_error(" a student has waited too long and their wait time is now negative");
}
