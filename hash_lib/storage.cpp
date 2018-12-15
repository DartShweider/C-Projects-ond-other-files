#include "storage.h"

template <>
Storage<std::string>::Storage (int number)
{
    cell_count = number;
    storage = new std::list<std::string>[number];
}

template <>
Storage<std::string>::~Storage()
{
    for (int i = 0; i < cell_count; i++)
    {
        storage[i].clear();
    }
    delete[]storage;
}


template <>
void Storage<std::string>::print()
{
    for ( int i = 0; i < cell_count; i++)
    {
        if (storage[i].empty() == 0)
        {
            std::cout << "[" << i << "]  " << "|" << storage[i].size() << "|  ";
            for (auto it : storage[i])
            {
                std::cout << it << ",  ";
            }
            std::cout << std::endl;
        }
    }
}



template <>
void Storage<std::string>::add(std::string data)
{
    
    int index = abs((int)(comp_hash(data) % cell_count));
    storage[index].push_back(data); 
    
}

template <>
void Storage<std::string>::remove(std::string data)
{
    
    int index = abs((int)(comp_hash(data) % cell_count));
    auto it = std::find(storage[index].begin(), storage[index].end(), data);
    if (it != storage[index].end())
    {
        storage[index].erase(it);
        std::cout << "Removed" << std::endl;
    }
    else
    {
        std::cout << "Data not found" << std::endl;
    }
}

template <>
std::string Storage<std::string>::find(std::string data)
{
    int index = abs((int)(comp_hash(data) % cell_count));
    auto it = std::find(storage[index].begin(), storage[index].end(), data);
    if (it != storage[index].end())
    {
        std::cout << "Data found" << std::endl;
        return data;
    }
    else
    {
        std::cout << "Data not found" << std::endl;
    }
} 





