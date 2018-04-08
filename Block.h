#ifndef BLOCK331
#define BLOCK331

#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <ostream>
#include "record.h"

using namespace std;

class Block
{

  public:
    record post[100];

    string _zip[100];
    string _city[100];
    string _state[100];
    string _county[100];
    string _longitude[100];
    string _latitude[100];

    void array( )
    {
    	string end_of_file = "eof";
    	ifstream theFile;

    	string zip;
      string city;
      string state;
      string county;
      string longitude;
      string latitude;

    	theFile.open("data.txt");

      if (theFile.fail())
        {
            cout << "Unable to open sampleData.txt file\n";
        }

       int i = 0;

        while (!theFile.eof())
       {

            getline (theFile, zip, ',' );
            post[i].zip = zip;
            getline(theFile, city, ',' );
            post[i].city  = city;
            getline(theFile, state, ',' );
            post[i].state =  state;
            getline(theFile, county, ',' );
            post[i].county = county;
            getline(theFile, latitude, ',' );
            post[i].latitude =  latitude;
            getline(theFile, longitude);
            post[i].longitude =  longitude;
            ++i;

          }

        theFile.close();


         for (int i = 0; i < 10 ; i++)
          {
          _zip[i] = post[i].zip;
          _city[i] = post[i].city;
          _state[i] = post[i].state;
          _county[i] = post[i].county;
          _longitude[i] = post[i].longitude;
          _latitude[i] = post[i].latitude;
          }

      }


      void print(){
        ofstream outFile;
        outFile.open("outdata.txt", ios::app|ios::ate);

        for (int i = 0; i < 10 ; i++)
        {
           outFile << _zip[i] << " " << _city[i] << " " << _state[i] << " " << _county[i] << " " << _longitude[i] << " " << _latitude[i] << endl;
        }

        outFile.close();
      }


    };



    //The Block node
    struct Node
    {
      Block test[5];

      void pblock( ){

        test[1].array();
        test[1].print();

        test[2].array();
        test[2].print();

        }

    };

#include "Block.cpp"
#endif
