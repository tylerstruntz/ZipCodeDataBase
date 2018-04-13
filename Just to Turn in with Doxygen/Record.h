#ifndef RECORD331
#define RECORD331

#include <iostream>
#include <string>
#include <fstream>
#include <ostream>

using namespace std;

class Record
{
public:
	string zip;
	string city;
	string state;
	string county;
	string longitude;
	string latitude;
};

#include "Record.cpp"
#endif
