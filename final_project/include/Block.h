#ifndef BLOCK_H
#define BLOCK_H
#include<vector>
#include <fstream>
#include "Record.h"

class Block
{

    public:
        typedef vector<Record> Item;
        Block(){first = NULL;}

        void insert(vector<Record> record, int counter, int lowerBound, int upperBound);
        void search_by_block(int block_number);
        void search_by_zipcode(int ZipcodeForSearch);
        void add_record(int ZipcodeToBeAdded);
        void delete_record(int ZipcodeToBeDeleted);
        void update_record(int ZipcodeToBeUpdate);
        void SaveToTheFile();


    private:
        struct Node{
            Item data;
            int UpperBound;
            int LowerBound;
            int block_number;
            Node *next;
        };
        Node *first;
        Node *get_node ( const Item& record, int counter, int lowerBound, int upperBound,  Node* link);
};

#endif // BLOCK_H
