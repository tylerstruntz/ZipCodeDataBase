#ifndef HEADERRECORD_H
#define HEADERRECORD_H

using namespace std;

class HeaderRecord
{
    public:
        HeaderRecord(){};
        void setblockcounter(int x){blockcounter = x;}
        void count_of_fields_per_record(int y){countfields_per_record = y;}
        void record_count(int z){rc_count = z;}
        void displayHeader();

        int getBC(){return blockcounter;}
        int getCFC(){return countfields_per_record;}
        int getRC(){return rc_count;}


    private:
        int blockcounter;
        int countfields_per_record;
        int rc_count;
};

#include "HeaderRecord.cpp"

#endif // HEADERRECORD_H
