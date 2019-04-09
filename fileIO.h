#pragma once
#include <iostream>
#include <fstream>
#include <stdlib.h>

#include "genQ.h"

using namespace std;

class FileIO
{
    public:
        // Default constructor
        FileIO();
        // Overloaded constructor
        FileIO(string filepath);
        // Desctructor
        ~FileIO();

        // Method to turn input into a queue
        GenQ<int>* getQueue();

        string filepath;
        GenQ<int> *output;
};
