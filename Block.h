#ifndef BLOCK331
#define BLOCK331

#include <cstdlib>
#include <iostream>
#include <string>
#include "record.h"

using namespace std;


template <class Item>
class Block
{

private:
  struct Node
  {
    Item data;
    int block_number;
    int upper_bound, lower_bound;
    Node *next;

  };
  Node* first;

  Node* get_node (const Item& entry, Node* link);

public:
    Record new_array[100];
    Block(){first=NULL;}
    ~Block();
    //Member Functions
    void insert(Record entry, int count, int key);
    void add_record(const Item& entry);
    Item search_by_zipcode(int zipcode);




    };


#include "Block.cpp"
#endif
