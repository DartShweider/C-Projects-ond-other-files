#pragma once
#include <string>
#include <fstream>
#include "storage.h"
#include <iterator>

template<typename Type>
void readDataBase(std::string filename, Storage<Type>* hashTable)
{
    std::ifstream DATABASE(filename);
    while(!DATABASE.eof())
    {
        
        std::string str;
        std::getline(DATABASE, str);
        hashTable->add(str);
    }
}


template<typename Type>
void saveDataBase(std::string filename, Storage<Type>* hashTable)
{
    std::ofstream DATABASE(filename);
    for (int i = 0; i < hashTable->cell_count; i++ )
    {
        for (auto it : hashTable->storage[i])
        {
            DATABASE << it << std::endl;
        
        }
    }
}
