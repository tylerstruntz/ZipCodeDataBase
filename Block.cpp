#include "Block.h"
#include "Record.h"
#include <vector>
#include <fstream>


using namespace std;

void Block:: insert(vector<Record> record, int counter, int lowerBound, int upperBound)
{


    Node *prev;

    if ( first == NULL)
      first = get_node(record, counter, lowerBound,  upperBound, first);
    else
    {
      prev = first;
      while ( prev->next != NULL )
        prev = prev->next;
      prev->next = get_node(record, counter, lowerBound, upperBound, prev->next);
    }

}

void Block:: update_record(int ZipcodeToBeUpdate)
{
     Node *temp;
    temp = first;
    string city, county, state, latitude, longitude;

    while(temp -> next != NULL)
    {
        if (ZipcodeToBeUpdate >= temp -> LowerBound && ZipcodeToBeUpdate <= temp -> UpperBound)
        {
            vector<Record> record =  temp -> data;
            vector<Record>::iterator it;
            for (  it = record.begin(); it != record.end(); ++it)
            {
                if (ZipcodeToBeUpdate == it -> getzip())
                    {

                             cout << "Update city: " << endl;
                             cin >> city;
                             it -> setcity(city);

                             cout << "Update state: " << endl;
                             cin >> state;
                             it -> setstate(state);

                             cout << "Update county: " << endl;
                             cin >> county;
                             it -> setcounty(county);

                             cout << "Update latitude: " << endl;
                             cin >> latitude;
                             it -> setlatitude(latitude);

                             cout << "Update longitude: " << endl;
                             cin >> longitude;
                             it -> setlongitude(longitude);

                             temp->data = record;

                             cout << "Record successfully updated: " << endl;

                        break;
                    }
            }
            break;
        }
        else
            temp = temp->next;
    }
}

void Block::delete_record(int ZipcodeToBeDeleted)
{
    Node *temp;
    temp = first;
    while(temp -> next != NULL)
    {
        if (ZipcodeToBeDeleted >= temp -> LowerBound && ZipcodeToBeDeleted <= temp -> UpperBound)
        {
            vector<Record> record =  temp -> data;
            vector<Record>::iterator it;
            int y = 0;
            for (  it = record.begin(); it != record.end(); ++it)
            {
                if (ZipcodeToBeDeleted == it -> getzip())
                    {

                        record.erase(record.begin() + y);
                        temp->data = record;

                        break;
                    }
                    ++y;
            }
            break;
        }
        else
            temp = temp->next;
    }
}


void Block:: add_record(int ZipcodeToBeAdded)
{
    Node *temp;
    temp = first;
    int zip;
    string city, county, state, latitude, longitude;

    Record *new_record;
    new_record = new Record;

    while(temp -> next != NULL)
    {
        if (ZipcodeToBeAdded >= temp -> LowerBound && ZipcodeToBeAdded <= temp -> UpperBound)
        {
            vector<Record> record =  temp -> data;
            vector<Record>::iterator it;
            for (  it = record.begin(); it != record.end(); ++it)
            {

                if (ZipcodeToBeAdded > it -> getzip() )
                  {
                      ++it;
                      if (ZipcodeToBeAdded < it -> getzip() )
                      {
                        cout << "Enter Zipcode: " << endl;
                        cin >> zip;

                         new_record -> setzip(zip);
                         cout << "Enter city: " << endl;
                         cin >> city;
                         new_record -> setcity(city);

                         cout << "Enter state: " << endl;
                         cin >> state;
                         new_record -> setstate(state);

                         cout << "Enter county: " << endl;
                         cin >> county;
                         new_record -> setcounty(county);

                         cout << "Enter latitude: " << endl;
                         cin >> latitude;
                         new_record -> setlatitude(latitude);

                         cout << "Enter longitude: " << endl;
                         cin >> longitude;
                         new_record -> setlongitude(longitude);

                         record.push_back(*new_record);
                         temp -> data = record;
                         break;

                      }
                      else
                      {
                          --it;
                      }
                  }
            }
            break;
        }
        else
          temp = temp->next;
    }
}


Block::Node* Block::get_node (const Item& entry, int counter,int lowerBound, int upperBound, Node* link)
   {
     Node *temp;

     temp = new Node;
     temp -> data = entry;
     temp -> next = link;
     temp -> LowerBound = lowerBound;
     temp -> UpperBound = upperBound;
     temp->block_number = counter;
     return temp;
   }


void Block:: search_by_zipcode(int ZipcodeForSearch)
{
    Node *temp;
    temp = first;
    while(temp -> next != NULL)
    {
        if (ZipcodeForSearch >= temp -> LowerBound && ZipcodeForSearch <= temp -> UpperBound)
        {
            vector<Record> record =  temp -> data;
            vector<Record>::iterator it;
            for (  it = record.begin(); it != record.end(); ++it)
            {
                if (ZipcodeForSearch == it -> getzip())
                    {
                        it->print();
                        break;
                    }
            }
            break;
        }
        else
            temp = temp->next;
    }
}


void Block:: search_by_block(int block_number)
{
    Node *temp;
    temp = first;
    while (temp -> block_number != block_number)
    {
        temp = temp->next;
    }
    int zipcode;
    cout << "Enter the zipcode: "<<endl;
    cin >>zipcode;

    vector<Record> record =  temp -> data;
    vector<Record>::iterator it;
    for (  it = record.begin(); it != record.end(); ++it) {
          if (zipcode == it -> getzip())
            it->print();
     }
}


void Block::SaveToTheFile()
{
  ofstream outputFile;
  outputFile.open ("outData.txt");
  Node *temp;
  temp = first;
    while(temp -> next != NULL)
    {

            vector<Record> record =  temp -> data;
            vector<Record>::iterator it;
            for (  it = record.begin(); it != record.end(); ++it)
            {
                outputFile << it -> getzip() << "," << it -> getCity() << "," << it -> getState() << "," << it -> getCounty() << "," << it -> getLatitude() << "," << it -> getLongitude() << endl;


            }
            temp = temp -> next;
    }

   outputFile.close();
}
