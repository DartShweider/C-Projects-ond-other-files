#pragma once

#include <string>
#include <cstdlib>
#include <list>
#include "book.h"

#include "HashFunc2.h"


struct Storage
{
    std::list<Book>* storage = new std::list<Book> [10000000];
    void readDataBase();
    void saveDataBase();
    void add (std::string data);
    void delete_d(std::string data);
    std::string find(std::string data);
};


void Storage::readDataBase()
{
    
    std::string filename = "lib";

    std::ifstream DATABASE(filename);
    std::string tmp_str;
    int tmp_hash;
    int hash;
    while(DATABASE)
    {
        
        std::string str;
        std::getline(DATABASE, str);
        
        if (str != "") // Это непонятная магия, без которой прога не рабоатет.
        {
            
            tmp_str += str[0];
            tmp_str += str[1];
            tmp_str += str[2];
            //std::cout << tmp_str <<std::endl;
            int index = abs((int)(comp_hash(tmp_str) / 10));
            //std::cout <<tmp_str <<"  " << index << std::endl;
            tmp_str = "";
            Book new_book;
            new_book.hash = comp_hash(str);
            new_book.data = str;
            storage[index].push_back(new_book);      
            
        }
        
    }
    
}


void Storage::add(std::string data)
{
    std::string tmp_str;
    tmp_str += data[0];
    tmp_str += data[1];
    tmp_str += data[2];
    int index = abs((int)(comp_hash(tmp_str) / 10));
    Book new_book;
    new_book.hash = comp_hash(data);
    new_book.data = data;
    storage[index].push_back(new_book); 
    
}


void Storage::delete_d(std::string data)
{
    
    std::string tmp_str;
    tmp_str += data[0];
    tmp_str += data[1];
    tmp_str += data[2];
    int index = abs((int)(comp_hash(tmp_str) / 10));
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
    std::string tmp_str;
    tmp_str += data[0];
    tmp_str += data[1];
    tmp_str += data[2];
    int index = abs((int)(comp_hash(tmp_str) / 10));
    int hash = comp_hash(data);
    std::list<Book>::iterator iter_1;

    for (iter_1 = storage[index].begin() ;iter_1 != storage[index].end(); iter_1++ )
    {
        if (hash == iter_1->hash)
        {
            std::cout << "True" << std::endl;
            return data;
        }
        
    }
}



void Storage::saveDataBase()
{
    
    std::string filename = "lib";

    std::ofstream DATABASE(filename);
    std::list<Book>::iterator iter_1;
    for (int i = 0; i < 10000000; i++ )
    {
        for (iter_1 = storage[i].begin() ;iter_1 != storage[i].end(); iter_1++ )
        {
            DATABASE << iter_1->data << std::endl;
        
        }
        
        
    }

   
    
}
