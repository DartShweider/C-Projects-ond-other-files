#include "DataBaseArray.h"
#include <string>







/*
void dataBaseArray::showNamesOfDBs()
{
    
    std::cout<<"__________________________________________ \n";
    for (int index = 0; index < DataStorage.size(); index++)
    {
        std::cout<<"|"<<DataStorage[index].nameOfDB<<"| \n";
    }
    std::cout<<"__________________________________________ \n";
    
}


int dataBaseArray::dataBaseSearch(std::string NameOfDB)
{
    int DBindex = -666;
    
    for (int index = 0; index < DataStorage.size(); index++)
    {
        if(DataStorage[index].nameOfDB == NameOfDB)
        {
            DBindex = index;
            break;
        }
        
    }
    
    return DBindex;
    
    
}


void dataBaseArray::readDataBase(std::string NameOfDB)
{
    

    int DBindex = dataBaseSearch(NameOfDB);
    std::string filename;
    std::cin >> filename;
    DataStorage[DBindex].readDataBase(filename);
    
}


void dataBaseArray::saveDataBase(std::string NameOfDB)
{
    
    int DBindex = dataBaseSearch(NameOfDB);
    std::string filename;
    std::cin>>filename;
    std::cout<<"\n";
    DataStorage[DBindex].saveDataBase(filename);
    
}


void dataBaseArray::getInfo(std::string NameOfDB)
{
    
    
    showNamesOfDBs();
    int DBindex = dataBaseSearch(NameOfDB);
    if (DBindex != -666)
    { 
        DataStorage[DBindex].printPatients();
    
        std::cout<<"Кол-во психов:  "<< DataStorage[DBindex].patients.capacity << "\n";
    } else
    {
        std::cout<<"Файл не найден \n";
    }
    
}


void dataBaseArray::addPatient(std::string NameOfDB)
{
    
    int DBindex = dataBaseSearch(NameOfDB);
    std::string name;
    std::string surname;
    std::cin >> name;
    std::cin >>  surname;
    DataStorage[DBindex].addPatient(name, surname);
    
}

*/






