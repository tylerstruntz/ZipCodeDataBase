#include <iostream>
#include <fstream>
#include <ostream>
#include <string>

#include "Record.h"
#include "Block.h"

using namespace std;
static const int blocksize = 5000;
void header();
{
  cout << "**************    HEADER RECORD    ******************\n";
  cout << "*****************************************************\n";
  cout << "block size: " << blocksize << endl;
  cout << "sequence set file type: .csv" << endl;
  cout << "max count of record of blocks: " << blocksize;
  cout << "min count of record of blocks: " << blocksize/2;
  cout << "block count: " << block.block_number << endl;
  cout << "****************************************************\n";
}
void menu()
{

  cout<<"*****************************************************"<<endl;
  cout<<"* choose a command:                                  *"<<endl;
  cout<<"* 1 for insert.                                      *"<<endl;
  cout<<"* 2 for delete.                                      *"<<endl;
  cout<<"* 3 for update.                                      *"<<endl;
  cout<<"* 4 for search.                                      *"<<endl;
  cout<<"* 5 to display the Menu.                             *"<<endl;
  cout<<"* 6 to display the header.                           *"<<endl;
  cout<<"* 7 to quit.                                         *"<<endl;
  cout<<"*****************************************************"<<endl;
  cout<<" Enter your choice: ";

}

int main()
{
  int command;

   menu();
   header();
   do
   {
     /* code */
     cout<< "Please pick a command: "<< endl;
     cin>> command;

     switch (command)
      {
       case 1: add_record();
              break;
       case 2: delete_record();
              break;
       case 3: update_record();
              break;
       case 4: search_by_zipcode();
              break;
       case 5: header();
               menu();
              break;
       default: ;
     }
   } while(command != 7);
return 0;
}
