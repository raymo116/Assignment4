#ifndef WINDOW_H

#include <iostream>
#include <string>
#include "Student.h"
using namespace std;

class Window
{
private:
public:
    // Constructor
    Window();
    // Destructor
    ~Window();
    // Prints the stats for debugging purposes
    void printStats();
    // Moves time ahead one minute for the current Window
    void age();
    // Deletes the current Student
    void deleteStudent(Student& s);
    // Adds a new Student
    void addStudent(Student& s);

    Student currentStudent;
    unsigned int currentIdleTime;
    unsigned int longestIdleTime;
    bool helpingStudent;
};

#endif
