#pragma once
#ifndef DATABASEARRAY_H_
#define DATABASEARRAY_H_
#include <string>
#include "Patients.cpp"




struct dataBaseArray
{
  
    std::vector<DataBase> DataStorage;
    void roadDataBase(std::string filename);
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

void dataBaseArray::roadDataBase(std::string filename)
{
    
    DataBase database;
    std::ifstream DATABASE(filename);

    int i = 0; 
    database.nameOfDB = filename;
    
    while(DATABASE)
    {
        
        std::string str;
        std::getline(DATABASE, str);
        
        if (str != "") // Это непонятная магия, без которой прога не рабоатет.
        {
            
        std::vector<std::string> patientData;
        Patient patient;
        patientData = split(str, ' ');
        patient.name = patientData[0];
        patient.surname = patientData[1];
        database.patients.push_back(patient);
            
        i++;
            
        }
        
    }
    
    database.numberOfPatients = i;
    DataStorage.push_back(database);
    
}
/////////----------------------/////////
////////-----------------------/////////


#endif
