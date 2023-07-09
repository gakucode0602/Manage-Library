// #include"reader_info.h"
#include"reader_info_copy.h"
#include"book_info_copy.h"
#include<iostream>
#include<vector>
#include<cstdlib>
#include<string>
using namespace std;

void add_reader(reader *&rd){
    string book_name,name;
    long int id;
    int day,month,year;
    cout << "Input the book's name : ";getline(cin,book_name);
    cout << "Input the student's name : ";getline(cin,name);
    cout << "Input the id";cin >> id;
    cout << "Input the day-month-year : ";cin >> day >> month >> year;
    reader *new_rd = new reader;
    new_rd->name = name; new_rd->ID = id;
    new_rd->br.book_name = book_name;
    new_rd->br.day = day;new_rd->br.month = month;new_rd->br.year = year;
    new_rd->prev = NULL; new_rd->next = NULL;
    if(rd==NULL) {  rd = new_rd; }
    else
    {
        reader *p = rd;
        while(p->next!=NULL) { p = p->next;  }
        p->next = new_rd; new_rd->prev = p;  
    }
}

void delete_reader(reader *&rd,long int id){
    reader* p = rd;
    reader* q = NULL;
    while(p!=NULL && p->ID!=id) { q = p; p = p->next; }
    if(q==NULL)
    {  rd = NULL; }
    else if(p==NULL)  { q->next = NULL; }
    else
    {  q->next = p->next; p->next->prev = q; }
    delete p;
}

reader* search(reader* rd,long int id)
{
    if(rd!=NULL)
    {
        reader* p = rd;
        while(p!=NULL && p->ID!=id)
        {
            p = p->next;
        }
        if(p!=NULL)
        {
            return p;
        }
        else
        {
            return NULL;
        }
    }
}

void add_to_sort(reader *&rd,reader* add)
{
    reader *new_rd = new reader;
    new_rd->name = add->name;
    new_rd->ID = add->ID;
    new_rd->br.book_name = add->br.book_name;
    new_rd->br.day = add->br.day;new_rd->br.month = add->br.month;new_rd->br.year = add->br.year;
    new_rd->prev = NULL;
    new_rd->next = NULL;
    reader* p = rd;
    reader* q = NULL;
    while(p!=NULL && p->ID < new_rd->ID)
    {
        q = p;
        p = p->next;
    }
    q->next = new_rd;
    p->prev = new_rd;
}

void sort_by_id(reader*& rd)
{
    reader* new_rd = new reader;
    new_rd = NULL;
    reader* p = rd;
    while(p!=NULL)
    {
        add_to_sort(new_rd,p);
        reader* temp = rd;
        rd = rd->next;
        delete temp;
        p = p->next;
    }
    rd = new_rd;
}

void process_student(reader* rd)
{
    if(rd!=NULL)
    {
        reader *p = rd;
        while(p!=NULL)
        {
           cout << "Student's name : " << p->name << endl;
           cout << "Class ID : " << p->ID << endl;
           cout << "Book's name : " << p->br.book_name << endl;
           cout << "dd/mm/yyyy : " << p->br.day << " - " << p->br.month << " - " << p->br.year << endl;
           p = p->next; 
        }
    }
}

int month(int month,int year)
{
    switch (month)
    {
        case 1:case 3:case 5:case 7:case 8:case 10:case 12:
        {
            return 31;
        }
        case 2:
        {
            if(year%100==0 ||year%400==0)
            {
                return 29;
            }
            else
            {
                return 28;
            }
        }
        case 4:case 6:case 9:case 11:
        {
            return 30;
        }
    }
}

void date(reader *rd)
{
    done_reading a;
    int day = rd->br.day + 20;
    if(day>30)
    {
        day = month(rd->br.month+1,rd->br.year) - 20;
    }
    else
    {
        a.day = day;
        a.month = rd->br.month;
        a.year = rd->br.year;
    }
    cout << "Book return time : " << a.day << " - " << a.month << "-" << a.year << endl;
}