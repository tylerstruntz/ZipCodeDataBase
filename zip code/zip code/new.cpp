#include <iostream>
#include <fstream>
using namespace std;

struct Post
{
    
    string zipcode;
    string city;
    string state;
    string county;
    string latitude;
    string longititude;
    
};

void addRecord()
{
    int n;
    
    ofstream myfile("example.txt");
    myfile.open("example.txt");
    
    if(myfile.is_open())
    {
        cout << "file open" << endl;
        cout << "how many records? ";
        cin >> n;
        
        for(int i = 0; i < n; i++)
        {
            Post p[i];
            
            
            cout << "zip" << endl;
            cin >> p[i].zipcode;
            
            cout << "city" << endl;
            cin >> p[i].city;
            
            cout << "state" << endl;
            cin >> p[i].state;
            
            cout << "county" << endl;
            cin >> p[i].county;
            
            cout << "longititude" << endl;
            cin >> p[i].longititude;
            
            cout << "latitude" << endl;
            cin >> p[i].latitude;
            
            cout << p[i].zipcode;
            cout << p[i].zipcode ;
            cout << p[i].city ;
            cout << p[i].city  ;
            cout << p[i].county;
            cout << p[i].longititude;
            cout << p[i].latitude ;
            
        }
        
        
        
        
    }
}


int main()
{
    ifstream theFile("b.csv");
    ofstream myfile ("example.txt");
    string zipcode;
    string city, state, county;
    string latitude, longititude;
    addRecord();
    
    Post post[10];
    int i = 0;
    while ( theFile.good() )
    {
        
        getline ( theFile, zipcode, ',' );
        post[i].zipcode = zipcode;
        getline(theFile, city, ',' );
        post[i].city  = city;
        getline(theFile, state, ',' );
        post[i].state =  state;
        getline(theFile, county, ',' );
        post[i].county = county;
        myfile << county;
        getline(theFile, latitude, ',' );
        post[i].latitude =  latitude;
        myfile << latitude;
        getline(theFile, longititude);
        post[i].longititude =  longititude;
        myfile <<longititude;
        
        ;
        
        cout << " | " << "\n\n";
        
        i = i + 1;
        if (i == 10)
        {
            for (int x =0; x <= 10; x++){
                post[x].zipcode = '\0';
                post[x].city  = '\0';
                post[x].state =  '\0';
                post[x].county = '\0';
                post[x].latitude =  '\0';
                post[x].longititude =  '\0';
                
            }
            cout << "object deleted";
            i = 0;
        }
        
    }
    
    
}

