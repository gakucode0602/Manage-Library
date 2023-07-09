#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#include<string>
#include "book_info_copy.h"
using namespace std;
string create_code()
{
    std::string a = "";
    char list[] = {'1','2','3','4','5',
                   '6','7','8','9','Q',
                   'W','E','R','T','Y',
                   'U','I','O','P','A',
                   'S','D','F','G','H',
                   'J','K','L','Z','X',
                   'C','V','B','N','M'};
    for(int i = 0;i<6;i++) { a+=list[rand()%35+1]; }
    return a;
}

void book_init(book_info* &a) { a = NULL; }


// Add new book to the lib
void add_new_book(book_info* &a)
{
    std::string name;
    std::string author;
    int quanti;
    std::string code;
    cout << "Book's name : ";getline(cin,name);
    cout << "Author' name : ";getline(cin,author);
    cout << "Book's quantity : ";cin >> quanti;cin.ignore();
    code = create_code();
    book_info* insert = new book_info;
    insert->author = author;
    insert->name = name;
    insert->code = code;
    insert->quanti = quanti;
    insert->next = NULL;
    if(a==NULL) {a = insert;}
    else
    {
        book_info* p = a;
        while(p->next!=NULL)
        {
            p = p->next;
        }
        p->next = insert;
    }
}

// Traversal the list
void process_book(book_info* a)
{
    book_info* p = a;
    cout << "***** List Book *****" << endl;
    while(p!=NULL)
    {
        cout << "Book's author : " << p->author << endl;
        cout << "Book's name : "<< p->name << endl;
        cout << "Code : "<< p->code << endl;
        cout << "Book's quantity : "<< p->quanti << endl;
        p = p->next;
    }
    cout << endl;
}

void delete_book_by_code(book_info *&a,std::string code)
{
    book_info *p = a;
    book_info *q = NULL;
    while(p!=NULL && p->code!=code) {q = p; p = p->next;}
    if(q==NULL) { a = NULL; }
    else if(p==NULL) { q->next = NULL; }
    else { q->next = p-> next; }
    delete p;
}

void delete_by_name(book_info *&a,std::string name)
{
    book_info *p = a;
    book_info *q = NULL;
    while(p!=NULL && p->name!=name) { q = p;p = p->next;}
    if(q==NULL) { a = NULL; }
    else if(p==NULL) { q->next = NULL; }
    else { q->next = p-> next; }
    delete p;
}

void add_to_sorted_list(book_info *&a,book_info *ins)
{
    book_info* insert = new book_info;
    insert->author = ins->author;
    insert->name = ins->name;
    insert->code = ins->code;
    insert->quanti = ins->quanti;
    insert->next = NULL;
    if(a==NULL)
    {
        a = insert;
    }
    else
    {
        book_info *p = a;
        book_info *q = NULL;
        while(p!=NULL && p->quanti < ins->quanti)
        {
            q = p;
            p = p->next;
        }
        q->next = insert;
        insert->next = p;
    }
}

void sort_by_quanti(book_info*& a)
{
    book_info* p = a;
    book_info* new_book = new book_info();
    while(p!=NULL)
    {
        add_to_sorted_list(new_book,p);
        a = a->next;
        p = p->next;
    }
    a = new_book->next;
}

book_info* search_by_code(book_info *a)
{
    std::string code;cout << "Input code : ";cin >> code;
    book_info * find = a;
    while(find!=NULL && find->code!=code) 
    {
        find = find -> next;
    }
    return find;
}

book_info* search_by_name(book_info *a)
{
    std::string name;cout << "Input name : ";cin >> name;
    book_info * find = a;
    while(find!=NULL && find->name!=name) 
    {
        find = find -> next;
    }
    return find;
}