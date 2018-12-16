#pragma once
#include <string>
#include <cstdlib>
#include <list>
#include <iostream>
#include <iterator>
#include <algorithm>
#include "HashFunc2.h"

template <typename Type>
class Storage
{
    
public:
    Storage (int number);
    ~Storage ();
    void add(Type data);
    void remove(Type data);
    Type find(Type data);
    void print(); 
    int cell_count;
    std::list<Type>* storage; 
private:
    
    
    
};


template <typename Type>
Storage<Type>::Storage (int number)
{
    cell_count = number;
    storage = new std::list<Type>[number];
}


template <typename Type>
Storage<Type>::~Storage()
{
    for (int i = 0; i < cell_count; i++)
    {
        storage[i].clear();
    }
    delete[]storage;
}


template <typename Type>
void Storage<Type>::print()
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



template <typename Type>
void Storage<Type>::add(Type data)
{
    
    int index = abs((int)(comp_hash(data) % cell_count));
    if (std::find(storage[index].begin(), storage[index].end(), data) == storage[index].end())
    {
        storage[index].push_back(data); 
    }
}

template <typename Type>
void Storage<Type>::remove(Type data)
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

template <typename Type>
Type Storage<Type>::find(Type data)
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


