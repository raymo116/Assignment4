#pragma once
#include <iostream>

using namespace std;

class FileIO
{
    public:
        FileIO();
        FileIO(string filepath);
        ~FileIO();

        GenQ<int>* getQueue();
        int getSize(ifstream &file);

        string filepath;
        GenQ<int> *output;
};
