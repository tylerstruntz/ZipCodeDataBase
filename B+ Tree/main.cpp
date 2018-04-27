#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <cctype>
#include <cstdio>
#include <string>
#include <stdio.h>
#include <sstream>
#include "B_Tree.h"
#include <vector>
#include <stdlib.h>
#include "Record.h"
#include "Block.h"
#include "HeaderRecord.h"
using namespace std;
void menu();

int main(int argc, char** argv)
{
    vector<Record> _record;
    Block block;
    Block *block_pointer;
    block_pointer = &block;
    cout << block_pointer <<endl;
    B_Tree btree;
    HeaderRecord header;
    Record *record_of_info;
    int upper_bound_array[16];
    int btree_array_counter = 0;

    ifstream theFile;
    int i = 0;
    int zip;
    int counter = 0;
    theFile.open("outData.txt");

   string zipcode, city, county, state, latitude, longitude;

 while (!theFile.eof())
   {
        record_of_info = new Record;
        getline (theFile, zipcode, ',' );
        stringstream geek(zipcode);
        geek >> zip;
        record_of_info -> setzip(zip);

        getline(theFile, city, ',' );
        record_of_info -> setcity(city);

        getline(theFile, state, ',' );
        record_of_info -> setstate(state);

        getline(theFile, county, ',' );
        record_of_info -> setcounty(county);

        getline(theFile, latitude, ',' );
        record_of_info -> setlatitude(latitude);

        getline(theFile, longitude);
        record_of_info -> setlongitude(longitude);

        _record.push_back(*record_of_info);

        if (i == 2499 )
        {
            counter = counter + 1;
            header.setblockcounter(counter);
            header.count_of_fields_per_record(6);
            header.record_count(i);

            int lowerBoundofBlock = _record.at(1).getzip();
            int upperBoundofBlock = _record.at(_record.size() - 1).getzip();
            block.insert(_record, counter, lowerBoundofBlock, upperBoundofBlock);
            i = 0;

            upper_bound_array[btree_array_counter] = upperBoundofBlock;
            btree_array_counter = 1 + btree_array_counter;
            _record.clear();
        }
        else
            i++;


}
    int ZipToBeSearch, zipCodeDelete, ZipcodeToBeUpdate, RecordToBeAdded;

    int command;
    btree.build_root(upper_bound_array, block_pointer);
    menu();

   do
   {
     /* code */
     cout<< "Please pick a command: "<< endl;
     cin>> command;

     switch (command)
      {
       case 1:
           cout << "Enter a Zipcode of the record you want to add: ";
           cin >> RecordToBeAdded;
           block.add_record(RecordToBeAdded);
              break;
       case 2:

           cout << "Enter the Zipcode you want to delete: ";
           cin >> zipCodeDelete;
           block.delete_record(zipCodeDelete);
              break;

       case 3:
           cout << "Enter the Zipcode of the record you want to update: ";
           cin >> ZipcodeToBeUpdate;
           block.update_record(ZipcodeToBeUpdate);
              break;

       case 4:
           cout << "Enter the Zipcode you want to search: ";
           cin >> ZipToBeSearch;
           block.search_by_zipcode(ZipToBeSearch);
              break;
       case 5:
           block.SaveToTheFile();
            break;
       case 6:
               menu();
              break;

        case 7:
            header.displayHeader();
            break;

       default: ;
     }
   } while(command != 8);

    block.array_block();
    return 0;

}


void menu()
{

  cout<<"*****************************************************"<<endl;
  cout<<"* choose a command:                                  *"<<endl;
  cout<<"* 1 for Insert.                                      *"<<endl;
  cout<<"* 2 for Delete.                                      *"<<endl;
  cout<<"* 3 for Update.                                      *"<<endl;
  cout<<"* 4 for Search.                                      *"<<endl;
  cout<<"* 5 to save the data to the output file              *"<<endl;
  cout<<"* 6 to Display the Menu.                             *"<<endl;
  cout<<"* 7 to Display the Header.                           *"<<endl;
  cout<<"* 8 to quit.                                         *"<<endl;
  cout<<"*****************************************************"<<endl;

}
