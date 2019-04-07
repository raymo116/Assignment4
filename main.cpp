#include <iostream>
#include <string>
#include <cstdlib>
#include "genQ.h"
#include "fileIO.h"
#include "Registrar.h"

using namespace std;

void analyze(string filepath)
{
    FileIO io (filepath);
    GenQ<int> *file = io.getQueue();

    int studentsServed = 0;
    int allStudents;
    int timeArrived;
    int numStudents;
    int timeNeeded;

    int windows = file->remove();

    //We have 2 queues, one of all students ever and one of ones in the building
    GenQ<Student> futureStudents;
    GenQ<Student> waitingLine;

    //Parse input for setup
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

    //we get the size of the queue of all students for metrics later
    allStudents = futureStudents.getSize();

    //Create a simulation
    Registrar myReg(windows, &waitingLine, allStudents);

    //Run simulation
    while(allStudents != studentsServed)
    {
        //Advance time
        myReg.worldTime++;

        //If there are any students left and the front student's arrival time is the world time
        while((!futureStudents.isEmpty())&&(futureStudents.front().timeArrived == myReg.worldTime))
        {
            //That student walks in
            waitingLine.insert(futureStudents.remove());
        }

        myReg.age(&studentsServed);
    }

    //Calcuate and print stats
    myReg.calculateStats(allStudents);
    myReg.printStats();
}

int main(int argc, char const *argv[])
{
    if(argc > 0)
    {
        string filepath = argv[1];
        analyze(filepath);
    }
    else
    {
        cout << "Please provide the file path for a text document" << endl;
        cout << "USAGE ./main.out <file-path>" << endl;
    }
    return 0;
}
