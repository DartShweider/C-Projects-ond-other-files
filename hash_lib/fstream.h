#pragma once
#include <string>
#include <fstream>
#include "storage.h"



void readDataBase(std::string filename, Storage* hashTable)
{
    std::ifstream DATABASE(filename);
    while(DATABASE)
    {
        
        std::string str;
        std::getline(DATABASE, str);
        
        if (str != "") // Это непонятная магия, без которой прога не рабоатет.
        {
            hashTable->add(str);
        }
    }
}



void saveDataBase(std::string filename, Storage* hashTable)
{
    std::ofstream DATABASE(filename);
    std::list<Book>::iterator iter_1;
    for (int i = 0; i < hashTable->cell_count; i++ )
    {
        for (iter_1 = hashTable->storage[i].begin() ;iter_1 != hashTable->storage[i].end(); iter_1++ )
        {
            DATABASE << iter_1->data << std::endl;
        
        }
    }
}



