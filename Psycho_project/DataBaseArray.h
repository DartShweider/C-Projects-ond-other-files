#pragma once
#ifndef DATABASEARRAY_H_
#define DATABASEARRAY_H_
#include <string>
#include "Patients.h"


struct dataBaseArray
{
  
    std::vector<DataBase> dbArray;
    
    void showNamesOfDBs();
    int dataBaseSearch(std::string NameOfDB);
    void readDataBase(std::string filename);
    void saveDataBase(std::string filename, std::string NameOfDB);
    void getInfo(std::string NameOfDB);
    void addPatient(std::string NameOfDB ,std::string name, std::string surname);
    
};


/////////----------------------/////////
////////-----------------------/////////





void split(const std::string &s, char delim, std::vector<std::string> &elems)
{

    std::stringstream ss(s);
    std::string item;
    while (getline(ss, item, delim)) {
        elems.push_back(item);
    }
}
//
//
std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, elems);
    return elems;
}


void dataBaseArray::showNamesOfDBs()
{
    std::cout<<"__________________________________________ \n";
    for (int index = 0; index < dbArray.size(); index++)
    {
        std::cout<<"|"<<dbArray[index].nameOfDB<<"| \n";
    }
    std::cout<<"__________________________________________ \n";
    
}


int dataBaseArray::dataBaseSearch(std::string NameOfDB)
{
    int DBindex = -666;
    
    for (int index = 0; index < dbArray.size(); index++)
    {
        if(dbArray[index].nameOfDB == NameOfDB)
        {
            DBindex = index;
            break;
        }
        
    }
    
    return DBindex;
    
    
}


void dataBaseArray::readDataBase(std::string filename)
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
    dbArray.push_back(database);
    
}


void dataBaseArray::saveDataBase(std::string filename, std::string NameOfDB)
{
    
    int DBindex = dataBaseArray::dataBaseSearch(NameOfDB);
    
    std::ofstream DATABASE(filename);
    
    Node<Patient>* current = dbArray[DBindex].patients.head;
    
    for (int i = 0; i < dbArray[DBindex].numberOfPatients; i++)
    {
        
        DATABASE<< current->value.name <<" "<< current->value.surname<<"\n";
        current = current->next;
        
    }
    DATABASE.close();
    
}


void dataBaseArray::getInfo(std::string NameOfDB)
{
    
    
    dataBaseArray::showNamesOfDBs();
    int DBindex = dataBaseSearch(NameOfDB);
    if (DBindex != -666)
    { 
        Node<Patient>* current = dbArray[DBindex].patients.head;
        
        for (int currentId = 0; currentId < dbArray[DBindex].numberOfPatients; currentId++)
            {
                std::cout<<"(" <<currentId + 1 << ")  ";
                std::cout<< current->value.name << "   ";
                std::cout<< current->value.surname << "   ";
                std::cout<< "\n";
                /*std::cout<< database->patients[currentId].sex << "   ";
                //std::cout<< database->patients[currentId].age << "   ";
                //std::cout<< database->patients[currentId].city << "   ";
                */
                std::cout<< /*current->value.visitAmount*/"" << "   " << std::endl; 
                current = current->next;
            }
    std::cout<<"Кол-во психов:  "<< dbArray[DBindex].numberOfPatients<< "\n";
    } else
    {
        std::cout<<"Файл не найден \n";
    }
    
}


void dataBaseArray::addPatient(std::string NameOfDB ,std::string name, std::string surname)
{
    
    
    int DBindex = dataBaseSearch(NameOfDB);
    

    Node<Patient>* current = dbArray[DBindex].patients.head;

    Patient patient;
    patient.name = name;
    patient.surname = surname;
    dbArray[DBindex].patients.push_back(patient);

    
    //patients[currentId].sex = sex;
    //patients[currentId].age = age;
    //patients[currentId].city = city;
    //patients[currentId].visitAmount = visitAmount;
    
    dbArray[DBindex].numberOfPatients++;
    
}
#endif
