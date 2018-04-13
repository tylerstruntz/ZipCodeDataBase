#include "Record.h"
#include <iostream>

using namespace std;

void Record::print()
{
    cout << zip <<", ";
    cout << city <<", ";
    cout << state <<", ";
    cout << county <<", ";
    cout << latitude <<", ";
    cout << longitude<< endl;

}
