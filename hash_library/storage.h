#pragma once
#ifndef STORAGE_H_
#define STORAGE_H_
#include <string>
#include <cstdlib>
#include <list>
#include "book.h"
#include "hashFunc.h"


struct cell
{
    std::string hash = "";  
    std::list<Book> Cell;
};

struct Storage
{
    cell storage[2756];

    void setHashValue();
    void readDataBase();
    void readBook();
    int findCell(std::string book_name);
};


void Storage::readDataBase()
{
    
    
    std::string filename = "lib";

    std::ifstream DATABASE(filename);
    std::string tmp_str;
    std::string tmp_hash;
    std::string hash;
    
    while(DATABASE)
    {
        
        std::string str;
        std::getline(DATABASE, str);
        
        if (str != "") // Это непонятная магия, без которой прога не рабоатет.
        {
            
            tmp_str += str[0];
            tmp_str += str[1];
            //std::cout << tmp_str <<std::endl;
            tmp_hash = comp_hash(tmp_str);
            tmp_str = "";
            hash = comp_hash(str);
            for (int i = 0; i < 2704; i++)
            {
                if (tmp_hash == storage[i].hash)
                {
                    Book new_book;
                    new_book.name = str;
                    storage[i].Cell.push_back(new_book);
                    break;
                }
                
            }
            
        }
        
    }
    
}

int Storage::findCell(std::string book_name)
{
    std::string tmp_book_hash = "";
    tmp_book_hash += book_name[0];
    tmp_book_hash += book_name[1];
    tmp_book_hash = comp_hash(tmp_book_hash);
    int index = -1;
    for (int i = 0; i< 2756; i++)
    {
        if(tmp_book_hash == storage[i].hash)
        {
            index = i;
            return index;
        }
        
    }
    
}



void Storage::readBook()
{
    
    
    std::string book_name = "";
    std::cin >> book_name;
    std::string book_hash = comp_hash(book_name);
    int cell_index = findCell(book_name);
    std::list <Book>::iterator  cell_iter;
    std::string lib_book_hash;

    for (cell_iter = storage[cell_index].Cell.begin(); cell_iter != storage[cell_index].Cell.end(); cell_iter++)
    {
        lib_book_hash = comp_hash((*cell_iter).name);
        if (book_hash == lib_book_hash)
        {
            (*cell_iter).loadBook();
            std::cout << (*cell_iter).data << std::endl;
        }
        
    }
    
}


void Storage::setHashValue()
{
    
    std::string tmp_char_1;
    std::string tmp_char_2;
    std::string tmp_hash_1 = "";
    std::string tmp_hash_2 = "";
    
    for (int i = 0; i < 52; i++)
    {
        if (i < 26)
        {
                tmp_char_1 = (char)(65 + i);
        } else
        {
            
            tmp_char_1 = (char)(71 + i);
        }
        
        tmp_hash_1 = comp_hash(tmp_char_1);
        
        for (int j = 0; j < 53; j++)
        {
            
            if (j < 26)
            {
                    tmp_char_2 = (char)(65 + j);
            }else if(j == 53)
            {
                tmp_char_2 = (char)(32);
                
                
            } else
            {
                
                tmp_char_2 = (char)(71 + j);
            }
            tmp_hash_2 = comp_hash(tmp_char_2);
            
            storage[52 * i + j].hash = tmp_hash_1 + tmp_hash_2;
            
        }

    }
    
}








#endif
 
