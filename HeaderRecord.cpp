#include "HeaderRecord.h"
#include <iostream>

using namespace std;

void HeaderRecord:: displayHeader()
{
  cout << "**************    HEADER RECORD    ******************\n";
  cout << "*****************************************************\n";
  cout << "Block size: 500 records " << endl;
  cout << "Sequence set file type: .txt" << endl;
  cout << "Max count of record of blocks: 500 " << endl;
  cout << "Min count of record of blocks: 250 "<<endl;
  cout << "Block count: " << getBC() << endl;
  cout << "Counts of fields per record: " << getCFC() << endl;
  cout << "Record countL: "<< getRC() << endl;
  cout << "****************************************************\n";
}
