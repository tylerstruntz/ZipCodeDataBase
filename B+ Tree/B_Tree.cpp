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
        temp ->  p -> upperbound_data1 = block_upper_bounds[i];
        temp -> left =  NULL;

        temp ->  p -> upperbound_data2 = block_upper_bounds[i++];
        temp -> left_mid = NULL;

        temp ->  p -> upperbound_data3 = block_upper_bounds[i++];
        temp -> right_mid = NULL;

        temp -> right = NULL;



        if( i == 2){
            temp2 -> left = temp;
            temp2 ->  p -> upperbound_data1 = block_upper_bounds[i+2];
            std::cout << temp2 ->  p -> upperbound_data1 <<std::endl;
        }
        else if (i==6){
            temp2 -> left_mid = temp;
            temp2 ->  p -> upperbound_data2 = block_upper_bounds[i+2];
            std::cout << temp2 ->  p -> upperbound_data2 <<std::endl;

        }
        else if (i==10){
            temp2 -> right_mid = temp;
            temp2 ->  p -> upperbound_data3 = block_upper_bounds[i+2];
            std::cout << temp2 ->  p -> upperbound_data3 <<std::endl;

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

    if (temp-> p -> upperbound_data1 >= target)
        temp = temp->left;

    else if(temp-> p -> upperbound_data2 >= target)
        temp = temp->left_mid;

    else if (temp-> p -> upperbound_data3 >= target)
        temp = temp->right_mid;
    else
        temp = temp->right;
    }
    temp =

}*/

void B_Tree:: btree_search(int zipcode)
{

  node*p;
  p = root;

    for(int depth = 0; depth < 2; depth++)
    {
      while (depth != 2)
      {
        if (zipcode < p ->  p -> upperbound_data1)
        {
          p = p -> left;
          depth++;

        }
        else if (zipcode >  p -> upperbound_data1 && zipcode <  p -> upperbound_data2 )
        {
          p = p -> left_mid;
          depth++;
        }
        else if (zipcode >  p -> upperbound_data2 && zipcode <  p -> upperbound_data3)
        {
          p = p -> right_mid;
          depth++;
        }
        else if (zipcode >  p -> upperbound_data3)
        {
          p = p-> right;
          depth++;
        }
      }
      vector<Record> record =  p -> data;
      vector<Record>::iterator it;
      for (  it = record.begin(); it != record.end(); ++it)
      {
        if (zipcode == it -> getzip())
            {
                     cout << zipcode << ", ";

                     cout << city << ", ";

                     cout << state << ", ";

                     cout << county << ", ";

                     cout << latitude << ", ";

                     cout << longitude <<  endl;

                break;
            }
      }
    }

    search();
}
