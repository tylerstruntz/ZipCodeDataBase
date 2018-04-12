#ifndef BLOCK_H
#define BLOCK_H
#include "Record.h"
#include <cstdlib>
#include <iostream>
#include <string>

class Block
{
    public:
    Block(){first=NULL;}
    void insert(Record entry, int lowerbound, int upperbound,  int block_count);


    private:
    struct Node
    {
        Record data[100];
        int block_number;
        int UpperBound, LowerBound;
        Node *next;

    };

    Node* first;
    Node *get_node (Record entry, int upper_bound, int lower_bound, int block_count, Node* link);

};

#endif // BLOCK_H
