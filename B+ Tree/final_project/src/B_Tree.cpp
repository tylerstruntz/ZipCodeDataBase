#include "B_Tree.h"
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <cctype>
#include <string>
#include <cstdio>
#include "Block.h"

B_Tree::~B_Tree()
{

}
void B_Tree:: build_root( int block_upper_bounds[], Block *pointer)
{
    Node *temp;
    Node *temp2;
    temp2 = new Node;
    Block b;
    *b = &pointer;
    b.SaveToTheFile();
    int x = -1;
    std::cout<< pointer <<std::endl;
    for (int i = 0; i < 16 ; i++){

        temp = new Node;
        temp -> upperbound_data1 = block_upper_bounds[i];
        temp -> left =  NULL;

        temp -> upperbound_data2 = block_upper_bounds[i++];
        temp -> left_mid = NULL;

        temp -> upperbound_data3 = block_upper_bounds[i++];
        temp -> right_mid = NULL;

        temp -> right = NULL;



        if( i == 2){
            temp2 -> left = temp;
            temp2 -> upperbound_data1 = block_upper_bounds[i+2];
            std::cout << temp2 -> upperbound_data1 <<std::endl;
        }
        else if (i==6){
            temp2 -> left_mid = temp;
            temp2 -> upperbound_data2 = block_upper_bounds[i+2];
            std::cout << temp2 -> upperbound_data2 <<std::endl;

        }
        else if (i==10){
            temp2 -> right_mid = temp;
            temp2 -> upperbound_data3 = block_upper_bounds[i+2];
            std::cout << temp2 -> upperbound_data3 <<std::endl;

        }
        else{
            temp2 -> right = temp;

        }


        i++;
    }
    root = temp2;
}

B_Tree::Node *B_Tree::build_base(int x, int y, int z)
{
}
/*void B_Tree:: search_with_btree (int target)
{
    Node *temp;
    temp = root;
    for(int i = 0; i < 2; i++){

    if (temp->upperbound_data1 >= target)
        temp = temp->left;

    else if(temp->upperbound_data2 >= target)
        temp = temp->left_mid;

    else if (temp->upperbound_data3 >= target)
        temp = temp->right_mid;
    else
        temp = temp->right;
    }
    temp =

}*/
