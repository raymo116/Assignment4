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
            for (int i = 0; i < line.length(); i++)
            {
                if((line[i] > '9')||(line[i] < '0'))
                    throw invalid_argument( "There was an invalid character entered");
            }
            output->insert(atoi(line.c_str()));
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
