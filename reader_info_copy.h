// Reader info

#ifndef READER_INFO
#define READER_INFO
#include<string>
#include "book_info_copy.h"

struct borrow_book{
    std::string book_name;
    int day,month,year;
};

struct done_reading{
    int day,month,year;
};

struct reader{
    long int ID;
    std::string name;
    borrow_book br;
    reader* next;
    reader* prev;
    done_reading ntn;
};

void add_reader(reader *&rd);
void delete_reader(reader *&rd,long int id);
reader* search(reader* rd,long int id);
void add_to_sort(reader *&rd,reader* add);
void sort_by_id(reader*& rd);
void process_student(reader* rd);
int month(int a,int year);
void date(reader *rd);
#endif