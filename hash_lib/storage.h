#pragma once

#include <string>
#include <cstdlib>
#include <list>
#include "book.h"

#include "HashFunc2.h"


class Storage
{
public:
    int cell_count = 300;
    std::list<Book>* storage = new std::list<Book> [300];
    void add(std::string data);
    void remove(std::string data);
    std::string find(std::string data);
    void print();
    
};


void Storage::print()
{
    std::list<Book>::iterator iter_1;
    for ( int i = 0; i < cell_count; i++)
    {
        if (storage[i].empty() == 0)
        {
            std::cout << "[" << i << "]  " << "|" << storage[i].size() << "|  ";
            for (iter_1 = storage[i].begin(); iter_1!= storage[i].end(); iter_1++)
            {
                std::cout << iter_1->data << ",  ";
            }
            std::cout << std::endl;
        }
    }
}




void Storage::add(std::string data)
{
    
    int index = abs((int)(comp_hash(data) % cell_count));
    Book new_book;
    new_book.data = data;
    storage[index].push_back(new_book); 
    
}


void Storage::remove(std::string data)
{
    
    int index = abs((int)(comp_hash(data) % cell_count));
    std::list<Book>::iterator iter_1;
    for (iter_1 = storage[index].begin() ;iter_1 != storage[index].end(); iter_1++ )
    {
        if (data == iter_1->data)
        {
            storage[index].erase(iter_1);
            break;
        }
        
    }
    
    
}


std::string Storage::find(std::string data)
{
    int index = abs((int)(comp_hash(data) % cell_count));
    std::list<Book>::iterator iter_1;
    for (iter_1 = storage[index].begin() ;iter_1 != storage[index].end(); iter_1++ )
    {
        if (data == iter_1->data)
        {
            std::cout << "True" << std::endl;
            return data;
        }
    }
}



