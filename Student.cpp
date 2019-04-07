#include <iostream>
#include <string>
#include "Student.h"
using namespace std;

Student::Student(int wT, int tA)
{
    int numbers[2] = {wT, tA};

    for (int i = 0; i < 2; ++i)
        if(numbers[i] < 0) throw invalid_argument(" recieved negative value: " + numbers[i]);

    waitTime = wT;
    timeLeft = wT;
    timeArrived = tA;
}

Student::~Student()
{

}

Student::Student()
{
    waitTime = 0;
    timeLeft = 0;
    timeArrived = 0;
}

// Prints the stats for debugging purposes
void Student::printStats()
{
    cout << "Wait Time: " << waitTime << endl;
    cout << "Time Left: " << timeLeft << endl;
    cout << "Time Arrived: " << timeArrived << endl;
}

// Moves time ahead one minute for the currentStudent
void Student::age()
{
    if(timeLeft > 0)
        timeLeft--;
    else
        throw underflow_error(" a student has waited too long and their wait time is now negative");
}
