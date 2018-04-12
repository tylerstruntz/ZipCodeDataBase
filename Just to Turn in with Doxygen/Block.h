#ifndef BLOCK331
#define BLOCK331

#include <cstdlib>
#include <iostream>
#include <string>
#include "Record.h"

using namespace std;

namespace tyler
{
static const int blocksize = 5000
template <class Item>
class Block
{

public:
    typedef string Item;
    Record new_array[blocksize];
    Block(){first=NULL;}
    ~Block();
    //Member Functions
    void insert(Record entry, int count, int key);
    void add_record(const Item& entry);
    void delete_record();
    void update_record();
    void fill_block()
    Item search_by_zipcode(int zipcode);


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




    };
}

#include "Block.cpp"
#endif
