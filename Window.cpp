#include <iostream>
#include <string>
#include "Window.h"

using namespace std;

// Constructor
Window::Window()
{
    helpingStudent = false;
}

// Destructor
Window::~Window()
{

}

// Prints the stats for debugging purposes
void Window::printStats()
{
    cout << "Current Idle Time: " << currentIdleTime << endl;
    cout << "Longest Idle time: " << longestIdleTime << endl;
}

// Moves time ahead one minute for the current Window
void Window::age()
{
    // if(!helpingStudent)
    // {
    //     currentIdleTime++;
    //     if(currentIdleTime>longestIdleTime) longestIdleTime = currentIdleTime;
    // }
    // else
        currentStudent.age();
        currentStudent.printStats();
}

// Deletes the current Student
void Window::deleteStudent(Student& s)
{
    if(helpingStudent) delete &currentStudent;
    helpingStudent = false;
}

void Window::addStudent(Student& s)
{
    if(!helpingStudent) currentStudent = s;
    helpingStudent = true;
}
