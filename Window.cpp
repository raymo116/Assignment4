#include "Window.h"

using namespace std;

// This class simulates a Window at the registrar's office

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

}

// Moves time ahead one minute for the current Window
// Takes in a pointer to a queue of students, a pointer to studentsServed,
// a pointer to studentHead, a pointer to studentWaitTimes, and the worldtime
void Window::age(GenQ<Student>* myQueue, int* sS, int* sH, int** sWT, int worldTime)
{
    // If the window is not already helping a student
    if(!helpingStudent)
    {
        // Increase the idle time
        currentIdleTime++;
        totalIdleTime++;

        // Set longest idle time
        if(currentIdleTime>longestIdleTime) longestIdleTime = currentIdleTime;

        if(!(myQueue->isEmpty()))
        {
            // Add new student to the queue
            addStudent(myQueue->remove());
            // Record how much time that student has spend waiting
            (*sWT)[(*sH)++] = worldTime-(currentStudent.timeArrived);
            (*sS)++;
            // Age the current student
            currentStudent.age();
        }
    }
    else if(currentStudent.timeLeft > 0)
    {
        currentStudent.age();
        currentIdleTime = 0;
    }

    // If the student is done being helped
    if(helpingStudent && (currentStudent.timeLeft == 0))
        deleteStudent(myQueue, sS, sH, sWT, worldTime);
}

// Deletes the current Student
// Takes in a pointer to a queue of students, a pointer to studentsServed,
// a pointer to studentHead, a pointer to studentWaitTimes, and the worldtime
void Window::deleteStudent(GenQ<Student>* myQueue, int* sS, int* sH, int** sWT, int worldTime)
{
    helpingStudent = false;
    currentIdleTime++;

    if(!(myQueue->isEmpty()))
    {
        // Add a new student
        addStudent(myQueue->remove());
        // Record how much time that student has spend waiting
        (*sWT)[(*sH)++] = worldTime-(currentStudent.timeArrived-1);
        (*sS)++;
    }
}

// Add a new student to the window
// Takes in a student
void Window::addStudent(Student s)
{
    if(!helpingStudent) currentStudent = s;
    helpingStudent = true;
}
