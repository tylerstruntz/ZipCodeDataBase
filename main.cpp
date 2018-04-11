#include <iostream>
#include <fstream>
#include <ostream>
#include <string>

#include "Record.h"
#include "Block.h"

using namespace std;

int main()
{
  Record post[100];
  // Record entryrec;
  Block blocks;

  string end_of_file = "eof";
  ifstream theFile;

  string zip;
  string city;
  string state;
  string county;
  string longitude;
  string latitude;

  string upperbound, lowerbound;

  theFile.open("data.csv");

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

        if(i == 49){
          post[0].zip = lowerbound;
          post[49].zip = upperbound;
          blocks.insert(post, count, lowerbound , upperbound);
          i = 0;
        }
        i++;
      }

    theFile.close();

    // cout << "Enter data" << endl;
    // cin >> entryrec.zip >> entryrec.city >> entryrec.state >> entryrec.county >> entryrec.latitude >> entryrec.longitude;
    // blocks.add_record(entryrec);

return 0;
}
