#ifndef STUDENT_H

#include <iostream>
#include <string>
using namespace std;

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
    // Prints the stats for debugging purposes
    void printStats();
    // Moves time ahead one minute for the currentStudent
    void age();

    unsigned int waitTime;
    unsigned int timeLeft;
    unsigned int timeArrived;
    unsigned int studentIDNumber;
    static unsigned int numberOfStudents;
};


#endif
