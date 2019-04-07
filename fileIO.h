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

        string filepath;
        GenQ<int> *output;
};
