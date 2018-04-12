#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <cctype>
#include <cstdio>
#include <string>
#include <stdio.h>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include "Block.h"
#include "Record.h"

using namespace std;

int main()
{
    vector<Record> record;
    Block block;
    Record *record_of_info;
    ifstream theFile;
    int i = 0;
    int zip;
    int counter = 0;
    theFile.open("zip.txt");

    string zipcode, city, county, state, latitude, longitude;
 while (!theFile.eof())
   {
        getline (theFile, zipcode, ',' );
        stringstream geek(zipcode);
        geek >> zip;
        record_of_info -> zip = zip;

        getline(theFile, city, ',' );
        record_of_info -> city  = city;

        getline(theFile, state, ',' );
        record_of_info -> state =  state;

        getline(theFile, county, ',' );
        record_of_info -> county = county;

        getline(theFile, latitude, ',' );
        record_of_info -> latitude =  latitude;

        getline(theFile, longitude);
        record_of_info -> longitude =  longitude;
        record.push_back(*record_of_info);

         if(i == 49){

          //block.insert(post, post[49].zip,  post[0].zip, counter);
          counter++;
          cout << "Inserted";
           i = 0;
          }

         else{
            i++;
        }

      }

    return 0;

   }

