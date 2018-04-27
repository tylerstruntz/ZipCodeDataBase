#ifndef B_TREE_H
#define B_TREE_H
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <cctype>
#include <cstdio>
#include "Block.h"



class B_Tree
{
    public:
        B_Tree() {root = NULL;}
        ~B_Tree();
        void build_root(int [], Block *pointer);
        void btree_search(int zipcode);


    private:
        struct Node
        {
            int upperbound_data1;
            int upperbound_data2;
            int upperbound_data3;
            Node *left;
            Node *left_mid;
            Node *right_mid;
            Node *right;
            Node *PointerToUpperNode;
        };
        Node *root;
        Node *build_base(int, int, int);
};

#endif // B_TREE_H
