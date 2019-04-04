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
    // cout << "sub" << endl;
}

// Prints the stats for debugging purposes
void Window::printStats()
{
    cout << "Current Idle Time: " << currentIdleTime << endl;
    cout << "Longest Idle time: " << longestIdleTime << endl;
    cout << "Currently Helping Student: " << ((helpingStudent)?"True":"False") << endl;
    currentStudent.printStats();
    cout << endl;
}

// Moves time ahead one minute for the current Window
void Window::age(GenQ<Student>* myQueue)
{
    if(!helpingStudent)
    {
        currentIdleTime++;
        if(currentIdleTime>longestIdleTime) longestIdleTime = currentIdleTime;

        if(!(myQueue->isEmpty()))
        {
            addStudent(myQueue->remove());
            currentStudent.age();
        }
    }
    else if(currentStudent.timeLeft > 0)
    {
        currentStudent.age();
        currentIdleTime = 0;
    }
    else deleteStudent(myQueue);
}

// Deletes the current Student
void Window::deleteStudent(GenQ<Student>* myQueue)
{
    helpingStudent = false;

    if(!(myQueue->isEmpty()))
    {
        addStudent(myQueue->remove());
        currentStudent.age();
    }
}

void Window::addStudent(Student s)
{
    if(!helpingStudent) currentStudent = s;
    helpingStudent = true;
}
