// Book_info
#ifndef BOOK_INFO_H
#define BOOK_INFO_H

#include <string>
#include<vector>
struct book_info{
    std::string name;
    std::string author;
    std::string code;
    int quanti;
    book_info* next;
};

std::string create_code();
void book_init(book_info* &a) ;
void add_new_book(book_info* &a);
void process_book(book_info* a);
void delete_book_by_code(book_info *&a,std::string code);
void delete_by_name(book_info *&a,std::string name);
void add_to_sorted_list(book_info *a);
void sort_by_quanti(book_info*& a);
book_info* search_by_code(book_info *a);
book_info* search_by_name(book_info *a);
#endif