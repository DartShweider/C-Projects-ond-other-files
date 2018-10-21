#pragma once
#ifndef PATIENTS_H_
#define PATIENTS_H_
#include <string>
#include "List.h"
#include <vector>


struct Patient
{
    
    std::string name = " ";
    std::string surname = " ";
    bool sex = true;
    int age = 0;
    std::string city = " ";
    int visitAmount = 0;
    
}; 


struct DataBase      
{
    

    std::string nameOfDB = " ";
    int capacity = 1;
    int numberOfPatients = 0;
    List<Patient> patients;
    void addPatient(std::string name, std::string surname);
    void deletePatient(std::string name, std::string surname);
    int findPatient(std::string name, std::string surname);
    void emptyBase();
    void readDataBase(std::string filename);
    void saveDataBase(std::string filename);
    void printPatients();
    
    
};


#endif
