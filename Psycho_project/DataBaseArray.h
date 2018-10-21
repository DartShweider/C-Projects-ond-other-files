#pragma once
#ifndef DATABASEARRAY_H_
#define DATABASEARRAY_H_
#include <string>
#include "Patients.cpp"




struct dataBaseArray
{
  
    std::vector<DataBase> DataStorage;
/*    void showNamesOfDBs();
    int dataBaseSearch(std::string NameOfDB);
    
    void readDataBase(std::string NameOfDB);
    void saveDataBase(std::string NameOfDB);
    void getInfo(std::string NameOfDB);
    void addPatient(std::string NameOfDB);
    */
    void addDataBase(std::string NameOfDB);

};

void dataBaseArray::addDataBase(std::string NameOfDB)
{
    
    DataBase database;
    database.nameOfDB = NameOfDB;
    DataStorage.push_back(database);
    
}


/////////----------------------/////////
////////-----------------------/////////


#endif
