#include "Block.h"
#include <cstddef>

using namespace std;

template <class Item>

// void Block::search_by_zipcode ( int zipcode )
// {
//     Node *p;
//     p = first;
//
//     while ( p != NULL )
//     {
//       if ( zipcode >= p -> lower_bound && zipcode <= p -> upper_bound )
//       {
//         new_array = p -> data;
//
//         for (int i = 0; i < 100; i++)
//         {
//
//            if (new_array[i].zip == zipcode )
//            {
//             cout << new_array[i].zip << new_array[i].city << new_array[i].state << new_array[i].county << new_array[i].longitude << new_array[i].latitude << endl;
//             break;
//            }
//         }
//       }
//       else
//       {
//         p = p -> next;
//       }
//   }
//  }

 void Block::<Item>insert(const Item& entry, int lower_bound, int upper_bound)
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

    // void Block::add_record(const Item& entry)
    // {
    //   Node *p;
    //   p = first;
    //
    //   while (p != NULL)
    //   {
    //     if( p -> entry.zip > lower_bound && p -> entry.zip < upper_bound )
    //     {
    //       p -> data = sadfasdf( p -> data, entry); ?
    //
    //     }
    //     else
    //     p = p -> next;
    //   }
    // }
