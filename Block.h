#ifndef BLOCK331
#define BLOCK331

#include <cstdlib>
#include <iostream>
#include <string>
#include "record.h"

using namespace std;

class Block
{

  public:
    record post[1000];

    void array( )
    {
    	string end_of_file = "eof";
    	ifstream theFile;
    	ofstream outFile;

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

        outFile.open("outdata.txt", ios::app|ios::ate);

        for (int i = 0; i < 15 ; i++)
        {
          outFile << post[i].zip << " " << post[i].city << " " << post[i].state << " " << post[i].county << " " << post[i].longitude << " " << post[i].latitude << endl;
        }

        outFile.close();
    	}
    };



    //The Block node

    struct Node
    {
      Block test;

    void pblock( ){
        test.array( );
    }

    };




#include "Block.cpp"
#endif
