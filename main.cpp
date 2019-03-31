#include <iostream>
#include <string>
#include "Window.h"
using namespace std;

int main(int argc, char const *argv[])
{

    Window myWindow1;
    Window myWindow2;
    // cout << myWindow.helpingStudent << endl;
    Student myStudent(10, 10, 10);

    myWindow1.addStudent(myStudent);
    myWindow2.addStudent(myStudent);
    // cout << myWindow.helpingStudent << endl;

    for (size_t i = 0; i < 3; i++)
    {
        myStudent.printStats();
        cout << endl;
        myWindow1.age();
        cout << endl;
        // myStudent.age();
        // myWindow2.age();
        // myWindow2.age();
    }

    // cout << "\n\n\n\n";

    // myWindow1.age();
    // myWindow2.age();


    return 0;
}
