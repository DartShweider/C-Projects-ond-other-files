#include "fstream.h"

template<>
void readDataBase(std::string filename, Storage<std::string>* hashTable)
{
    std::ifstream DATABASE(filename);
    while(!DATABASE.eof())
    {
        
        std::string str;
        std::getline(DATABASE, str);
        hashTable->add(str);
    }
}


template<>
void saveDataBase(std::string filename, Storage<std::string>* hashTable)
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

