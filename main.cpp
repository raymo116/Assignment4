#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>

#include "genQ.h"
#include "fileIO.h"
#include "Registrar.h"

using namespace std;

int main(int argc, char const *argv[])
{
    FileIO io;

    int studentsServed = 0;
    int allStudents;

    GenQ<int> *file = io.getQueue();
    int j = file->getSize();

    int windows = file->remove();
    int timeArrived;
    int numStudents;
    int timeNeeded;

    GenQ<Student> futureStudents;
    GenQ<Student> waitingLine;


    while(!file->isEmpty())
    {
        timeArrived = file->remove();
        int numStudents = file->remove();
        for(int i = 0; i < numStudents; i++)
        {
            timeNeeded = file->remove();
            futureStudents.insert(Student(timeNeeded, timeArrived));
        }
    }

    allStudents = futureStudents.getSize();

    Registrar myReg(windows, &waitingLine, allStudents);

    myReg.printStats();

    while(allStudents != studentsServed)
    {
        myReg.worldTime++;
        while((!futureStudents.isEmpty())&&(futureStudents.front().timeArrived == myReg.worldTime))
        {
            waitingLine.insert(futureStudents.remove());
        }

        myReg.age(&studentsServed);

        // myReg.printStats();
        // cout << "Queue Size: " << waitingLine.numElements << endl;
    }

    // Mean
    sort(myReg.studentWaitTimes, myReg.studentWaitTimes+allStudents);

    for (size_t i = 0; i < allStudents; i++) {
        cout << myReg.studentWaitTimes[i] << endl;
    }

    cout << "Median Student Wait Time: " ;

    if(allStudents%2!=0)
    {
        cout << (myReg.studentWaitTimes[allStudents/2]) << endl;
    }
    else
    {
        cout << ((myReg.studentWaitTimes[allStudents/2-1])+(myReg.studentWaitTimes[allStudents/2]))/2 << endl;
    }

    return 0;
}
