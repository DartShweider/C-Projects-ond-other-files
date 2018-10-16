#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string>
#include <fstream> // работа с файлами
#include <iomanip> // манипуляторы ввода/вывода
#include <cstring>
#include <vector>           // std::(vector)
#include <sstream>          // std::(istringstream)
#include <algorithm>        // std::(copy)
#include "List.h"
#include "Patients.h"

//
//
void showNamesOfDBs(std::vector<DataBase> &dataBaseArray)
{
    std::cout<<"__________________________________________ \n";
    for (int index = 0; index < dataBaseArray.size(); index++)
    {
        std::cout<<"|"<<dataBaseArray[index].nameOfDB<<"| \n";
    }
    std::cout<<"__________________________________________ \n";
}
//
//
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
//
//
int dataBaseSearch(std::vector<DataBase> &dataBaseArray, std::string NameOfDB)
{
    int DBindex = -666;
    
    for (int index = 0; index < dataBaseArray.size(); index++)
    {
        if(dataBaseArray[index].nameOfDB == NameOfDB)
        {
            DBindex = index;
            break;
        }
        
    }
    
    return DBindex;
    
}
//
//
void readDataBase(std::string filename, std::vector<DataBase> &dataBaseArray)
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
    dataBaseArray.push_back(database);
    
}
//
//
void saveDataBase(std::string filename, std::vector<DataBase> &dataBaseArray, std::string NameOfDB)
{
    
    int DBindex = dataBaseSearch(dataBaseArray, NameOfDB);
    
    std::ofstream DATABASE(filename);
    
    Node<Patient>* current = dataBaseArray[DBindex].patients.head;
    
    for (int i = 0; i < dataBaseArray[DBindex].numberOfPatients; i++)
    {
        
        DATABASE<< current->value.name <<" "<< current->value.surname<<"\n";
        current = current->next;
        
    }
    DATABASE.close();
}
//
//
void getInfo(std::vector<DataBase> &dataBaseArray, std::string NameOfDB)
{

    showNamesOfDBs(dataBaseArray);
    int DBindex = dataBaseSearch(dataBaseArray, NameOfDB);
    if (DBindex != -666)
    { 
        Node<Patient>* current = dataBaseArray[DBindex].patients.head;
        
        for (int currentId = 0; currentId < dataBaseArray[DBindex].numberOfPatients; currentId++)
            {
                std::cout<<"(" <<currentId + 1 << ")  ";
                std::cout<< current->value.name << "   ";
                std::cout<< current->value.surname << "   ";
                std::cout<< "\n";
                /*std::cout<< database->patients[currentId].sex << "   ";
                //std::cout<< database->patients[currentId].age << "   ";
                //std::cout<< database->patients[currentId].city << "   ";
                */
                std::cout<< current->value.visitAmount << "   " << std::endl; 
                current = current->next;
            }
    std::cout<<"Кол-во психов:  "<< dataBaseArray[DBindex].numberOfPatients<< "\n";
    } else
    {
        std::cout<<"Файл не найден \n";
    }
    
}
//
//
void addPatient(std::vector<DataBase> &dataBaseArray, std::string NameOfDB ,std::string name, std::string surname)
{
    

    
    int DBindex = dataBaseSearch(dataBaseArray, NameOfDB);
    

    Node<Patient>* current = dataBaseArray[DBindex].patients.head;

    Patient patient;
    patient.name = name;
    patient.surname = surname;
    dataBaseArray[DBindex].patients.push_back(patient);

    
    //patients[currentId].sex = sex;
    //patients[currentId].age = age;
    //patients[currentId].city = city;
    //patients[currentId].visitAmount = visitAmount;
    
    dataBaseArray[DBindex].numberOfPatients++;
    
}
//
//
void startTheProgram(std::vector<DataBase> &dataBaseArray)
{
    

        
        int choise = -1;
        
        while (choise != 0)
        {
            std::cout<<"___________________________________________________ \n";
            std::cout<<" Приложение для мониторинга пациентов психушки.\n";
            std::cout<<"___________________________________________________ \n";
            std::cout<<"Для вывода списка данных пациентов введите (1).\n";
            std::cout<<"Для добалвения пациента в список введите (2).\n";
            std::cout<<"Для сохранения изменений введите (3).\n";
            std::cout<<"Для загрузки базы данных введите (4).\n";
            std::cout<<"Для отображения текущей вместимости базы данных введите (5).\n";
            std::cout<<"Для вывода имён загруженных баз данных введите (6).\n";
            std::cout<<"Для выхода из программы введите (0)"  << std::endl;
            std::cout<<"___________________________________________________ \n";
            std::cin >> choise;
            
            switch(choise)
            {
                case 1:
                {
                    
                    std::cout<<"Введите имя базы данных, список которой хотите получить:  \n";
                    std::string NameOfDB;
                    std::cin>>NameOfDB;
                    getInfo(dataBaseArray, NameOfDB); 
                    continue;
                    
                }
                case 0:
                {
                    
                    std::cout<<"___________________________________________________ \n";
                    std::cout << "Exit" << std::endl;
                    std::cout<<"___________________________________________________ \n";
                    break;
                    
                }
                case 2:
                {
                    showNamesOfDBs(dataBaseArray);
                    std::cout<<"Введите имя базы данных, в которую хотите добавить психа \n";
                    std::string NameOfDB;
                    std::cin>>NameOfDB;
                    std::cout<<"___________________________________________________ \n";
                    std::cout<< "Введите имя и фамилию психа \n";
                    std::cout<<"___________________________________________________ \n";
                    std::string name;
                    std::string surname;
                    std::cin>> name;
                    std::cin>> surname;
                    addPatient(dataBaseArray, NameOfDB, name, surname);
                    std::cout<<"___________________________________________________ \n";
                    std::cout<<"Псих успешно внесён в базу данных \n";
                    std::cout<<"___________________________________________________ \n";
                    continue;
                    
                }
                case 3:
                {
                    
                    std::cout<<"Введите имя базы данных, которую хотите сохранить \n";
                    std::string NameOfDB;
                    std::cin>>NameOfDB;
                    std::string filename;
                    std::cout<<"___________________________________________________ \n";
                    std::cout<<"Введите имя файла, в который вы хотите сохранить \n";
                    std::cout<<"___________________________________________________ \n";
                    std::cin>>filename;
                    std::cout<<"\n";
                    saveDataBase(filename, dataBaseArray, NameOfDB);
                    std::cout<<"___________________________________________________ \n";
                    std::cout<<"Данные успешно сохранены \n";
                    std::cout<<"___________________________________________________ \n";
                    continue;
                    
                }
                case 4:
                {
                    
                    std::string filename;
                    std::cout<<"___________________________________________________ \n";
                    std::cout<<"Введите имя файла, который хотите загрузить \n";
                    std::cout<<"___________________________________________________ \n";
                    std::cin>>filename;
                    std::cout<<"\n";
                    readDataBase(filename, dataBaseArray);
                    std::cout<<"___________________________________________________ \n";
                    std::cout<<"Файл успешно загружен \n";
                    std::cout<<"___________________________________________________ \n";
                    continue;
                    
                }
                case 5:
                {
                    
                    std::cout<<"Введите имя базы данных, вместимость которой хотите узнать \n";
                    std::string NameOfDB;
                    std::cin>>NameOfDB;
                    int DBindex = dataBaseSearch(dataBaseArray, NameOfDB);
                    std::cout<<"___________________________________________________ \n";
                    std::cout<<"Вместимость базы данных:  "<<dataBaseArray[DBindex].capacity<<"\n";
                    std::cout<<"___________________________________________________ \n";
                    continue;
                    
                }
                case 6:
                {
                    showNamesOfDBs(dataBaseArray);
                    continue;
                }
                    
                default: break;
                
            }
            
        }
        
}
//
//
int main()
{
    

        
        std::vector<DataBase> dataBaseArray;
        startTheProgram(dataBaseArray);
        return 0;
        
}
