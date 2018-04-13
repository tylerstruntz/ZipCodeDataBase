/*
    @file Record.h
    @author Neeraj, Tyler, Scott, Nadika
    @date 04/12/2018
    @version 7
    @brief CSCI 331 Project 2 Sequence Sets

    @brief Description
    This program puts data in a linked structure called Blocks and performs multiple efficient operations on this data.


*/
#ifndef RECORD_H
#define RECORD_H

#include <iostream>
#include <string>
#include <fstream>
#include <ostream>

using namespace std;

class Record
{
private:
	int zip;
	string city;
	string state;
	string county;
	string longitude;
	string latitude;

public:
    Record(){};

    //Set Function
    /** @brief Sets inputted
     *
     * @param _zipcode int
     * @return void
     *
     */
    void setzip(int _zipcode){zip = _zipcode;}
    void setcity(string _city){city = _city;}
    void setstate(string _state){state = _state;}
    void setcounty(string _county){county = _county;}
    void setlongitude(string _longitude){longitude = _longitude;}
    void setlatitude(string _latitude){latitude = _latitude;}
    void print();

    //Get Functions
    int getzip(){return zip;}
    string getCity(){return city;}
    string getState(){return state;}
    string getCounty(){return county;}
    string getLatitude(){return latitude;}
    string getLongitude(){return longitude;}


};

#include "Record.cpp"

#endif // RECORD_H
