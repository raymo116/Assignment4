#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <stdlib.h>
#include <regex>

#include "genQ.h"
#include "fileIO.h"

using namespace std;

FileIO::FileIO()
{
    filepath = "file.test";
}
FileIO::FileIO(string fp)
{
    filepath = fp;
}
FileIO::~FileIO()
{
    delete output;
}

GenQ<int>* FileIO::getQueue()
{
    ifstream file (filepath);
    output = new GenQ<int>();

    if(file.is_open())
    {
        file.clear();
        file.seekg(0);

        string line;
        while (getline (file, line))
        {
            if(line != "" && regex_match(line,regex("[0-9]+")))
            {
                output->insert(atoi(line.c_str()));
            }
            else
            {
                cout << "Invalid input in file.\n" << endl;
                break;
            }

        }
        file.close();
    }
    else
    {
        cout << "Invalid filepath" << endl;
    }

    return output;
}
