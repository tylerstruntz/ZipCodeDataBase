#include <iostream>
//#include "postalcode.h"
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <cctype>
#include <cstdio>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using std::ostream;

using namespace std;

bool check = true;

struct Post
{
    string zip;
    string city;
    string state;
    string county;
    string longitude;
    string latitude;
    Post *next;
    
}*head, *last_ptr;

void addRecord()
{
    ofstream data;
    data.open("out.txt", std::ios_base::out | std::ios_base::app);
    
    
    Post *p;
    p = new Post;
    cout <<"Enter zip" << endl;
    cin >> p -> zip;
    
    cout <<"Enter city" << endl;
    cin >> p -> city;
    
    cout <<"Enter state" << endl;
    cin >> p -> state;
    
    cout <<"Enter county" << endl;
    cin >> p -> county;
    
    cout <<"Enter longitude" << endl;
    cin >> p -> longitude;
    
    cout <<"Enter latitude" << endl;
    cin >> p -> latitude;
    
    p -> next = NULL;

    
    //data.close();
    
}


void readData()
{
    string BUFFER;
    ifstream IN;
    IN.open("out.txt", ios::in|ios::binary);
    getline(IN, BUFFER);
    cout << "\n\t" << BUFFER << "\n";
    IN.close();
    
}

int main()
{
    addRecord();
    //readData();
    return 0;
}

