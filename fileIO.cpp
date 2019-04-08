#include <iostream>
#include <fstream>
// ToDo: remove cstring #include <cstring>
#include <string>
#include <stdlib.h>

#include "genQ.h"
#include "fileIO.h"

using namespace std;

// Deafault constructor
FileIO::FileIO()
{
    filepath = "file.test";
}

// Overloaded constructor
FileIO::FileIO(string fp)
{
    filepath = fp;

    // Checks to make sure the file exists
    ifstream file (filepath);
    if(!file)
        throw invalid_argument( "received invalid filepath: " + filepath);
    else
        file.close();
}

// Destructor
FileIO::~FileIO()
{
    delete output;
}

// Fills a Queue with the data from the file and returns it
GenQ<int>* FileIO::getQueue()
{
    ifstream file (filepath);
    output = new GenQ<int>();

    file.clear();
    file.seekg(0);

    string line;
    while (getline (file, line))
    {
        if(line != "")
        {
            for (int i = 0; i < line.length(); i++)
            {
                if((line[i] > '9')||(line[i] < '0'))
                    throw invalid_argument( "There was an invalid character entered");
            }
            output->insert(atoi(line.c_str()));
        }

    }
    file.close();

    return output;
}
