#include "Block.h"
#include <cstddef>

using namespace std;
namespace tyler
{
template <class Item>

void Block::search_by_zipcode ( int zipcode )
{
    Node *p;
    p = first;

    while ( p != NULL )
    {
      if ( zipcode >= p -> lower_bound && zipcode <= p -> upper_bound )
      {
        new_array = p -> data;

        for (int i = 0; i < 100; i++)
        {

           if (new_array[i].zip == zipcode )
           {
            cout << new_array[i].zip << new_array[i].city << new_array[i].state << new_array[i].county << new_array[i].longitude << new_array[i].latitude << endl;
            break;
           }
        }
      }
      else
      {
        p = p -> next;
      }
  }
 }

 void Block::insert(Record entry, int lower_bound, int upper_bound)
 {
   Node *prev;
   int count;

   if ( first == NULL )
   {
     first = get_node(entry, count, lower_bound, upper_bound, first);
     count++;
   }
   else
   {
     prev = first;

     while (prev -> next!= NULL)
     {
       prev = prev -> next;
       if (prev -> next == NULL)
       {
         prev -> next = get_node(entry, count, lower_bound, upper_bound, first);
         count++;
         break;
       }
     }

   }
 }

   Block::Node* Block::get_node (const Item& entry, int count, int lower_bound, int upper_bound, Node* link)
   {
     Node *temp;

     temp = new Node;
     temp -> count = count;
     temp -> lower_bound = lower_bound;
     temp -> upper_bound = upper_bound;
     temp -> data = entry;
     temp -> next = link;
     return temp;
   }

     void Block::add_record(const Item& entry)
     {
       Node *p;
       p = first;

       while (p != NULL)
        {
         if( p -> entry.zip > lower_bound && p -> entry.zip < upper_bound )
         {
           p -> data = sadfasdf( p -> data, entry); ?

         }
         else
         p = p -> next;
       }
     }
}



  void Block::fill_block()
  {
    Record post[5000];
    Block blocks;

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

          if(i == 2499){
            post[0].zip = lowerbound;
            post[2499].zip = upperbound;
            blocks.insert(post, count, lowerbound , upperbound);
            i = 0;
          }
          i++;
        }

      theFile.close();
  }

  void Block::delete_record()
  {
    string zip;
    string data;

    cout << "Enter the Zip" << endl;
    cin >> zip;

    data = search_by_zipcode ( zip );

    while ( zip >= lowerbound && zip <= upperbound)
    {
      for ( int i = 0; i < upperbound; i++)
      {
        if ( data[i].zip == zip )
        {
          data[i] = 10;
          for ( int y = i; y < upperbound; y++)
          {
            i + 1 = y;
            i++;
            y++;
          }
        }
      }
    }
  }

  void Block::update_record()
  {

  }
