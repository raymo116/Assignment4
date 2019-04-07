#include <iostream>
#include <string>
#include "Window.h"

using namespace std;

// Constructor
Window::Window()
{
    helpingStudent = false;
    currentIdleTime = 0;
    longestIdleTime = 0;
    totalIdleTime = 0;
    helpingStudent = 0;
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
void Window::age(GenQ<Student>* myQueue, int* sS, int* sH, int** sWT, int worldTime)
{
    if(!helpingStudent)
    {
        currentIdleTime++;
        totalIdleTime++;
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

    if(helpingStudent && (currentStudent.timeLeft == 0))
    {
        (*sWT)[(*sH)++] = worldTime-(currentStudent.timeArrived);
        (*sS)++;
        deleteStudent(myQueue);
    }
}

// Deletes the current Student
void Window::deleteStudent(GenQ<Student>* myQueue)
{
    helpingStudent = false;
    currentIdleTime++;


    if(!(myQueue->isEmpty()))
    {
        addStudent(myQueue->remove());
        // currentStudent.age();
    }
}

void Window::addStudent(Student s)
{
    if(!helpingStudent) currentStudent = s;
    helpingStudent = true;
    // cout << "here" << endl;
}
