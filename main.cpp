/*
CPSC 350-02
Assignment 4

Matt Raymond
2270559
raymo116@mail.chapman.edu

Christian Valencia
2275944
valen193@mail.chapman.edu

*/
#include "genQ.h"
#include "fileIO.h"
#include "Registrar.h"

using namespace std;

// This function takes in a filepath and parses the file into the registrar class
void analyze(string filepath);

// This project simulates the registrar's office. It takes one file via commandline parameters
int main(int argc, char const *argv[])
{
    // Extra space
    cout << endl;

    // Checks to make sure that the inputs are valid
    if((argc > 0) && (argv[1] != NULL))
    {
        string filepath = argv[1];
        try
        {
            // Analyze the filme and simulate the registrar
            analyze(filepath);
        }
        catch(const invalid_argument& message)
        {
            cout << message.what() << endl;
            cout << "Please try again." << endl;
        }
    }
    else
    {
        cout << "Please provide the file path for a text document" << endl;
        cout << "USAGE ./mRaymond_cValencia.out <file-path>" << endl;
    }

    cout << "\nThe program exited successfully." << endl;
    return 0;
}

// Takes in a filepath and parses the file into the registrar class
void analyze(string filepath)
{
    cout << "Begin reading from file..." << endl;
    // File io object
    FileIO io (filepath);
    // Queue for numbers in file
    GenQ<int> *file = io.getQueue();

    int studentsServed = 0;
    int allStudents = 0;
    int timeArrived = 0;
    int numStudents = 0;
    int timeNeeded = 0;

    int windows = file->remove();

    //We have 2 queues, one of all students ever and one of ones in the building
    GenQ<Student> futureStudents;
    GenQ<Student> waitingLine;

    try
    {
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

        cout << "Success.\n" << endl;

        cout << "Begining simulation..." << endl;
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
        cout << "Simulation terminated successfully.\n\nPrinting results..." << endl;
        //Calcuate and print stats
        myReg.calculateStats(allStudents);
        myReg.printStats();

        cout << "Done." << endl;
    }
    catch(out_of_range)
    {
        cout << "There was an error parsing your file. Please try again." << endl;
    }
}
