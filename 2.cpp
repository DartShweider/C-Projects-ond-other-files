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




struct Patient     //Создаём "объект" типа пациент, в нём храним всю инфу о нём.
{
    std::string name = " ";
    std::string surname = " ";
    bool sex = true;
    int age = 0;
    std::string city = " ";
    int visitAmount = 0;
    
};


void show_vector( std::vector<std::string>&vect) 

    // Функция вывода элементов вектора на 
    // экран, нужна была на стадии отладки 
    // программы.

{
    for (int i = 0 ;i< vect.size(); ++i)
    {
        std::cout<<vect[i];
    }
}

struct DataBase     // Создаём "объект" типа База данных. По сути - просто вектор,
                    // в который мы можем аппендить пациентов до посинения.
{
    //Здесь база данных пациентов психушки//
    
    std::vector<Patient> patients;
    int length = 0;
};




void split(const std::string &s, char delim, std::vector<std::string> &elems)
{
    
    // Данная и следующая функции отвечают за разделение вводимых строк на
    // отдельные слова, затем они уже запихиваются в описание каждого пациента.
    
    std::stringstream ss(s);
    std::string item;
    while (getline(ss, item, delim)) {
        elems.push_back(item);
    }
}


std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, elems);
    return elems;
}



void readDataBase(std::string filename, DataBase* database)
{
    // А тут мы читаем файл формата .txt
    // Здесь мы построчно читаем файл, с помощью 2-х функций выше разделяем
    // вводимые слова и запихиваем в структуру каждого пациента.
    // Я не стал это делать для всех 6-ти атрибутов, достаточно продемонстрировать на 2-х.
    // Остальные делаются аналогично.
    // Так же я непонятно зачем сделал счётчик кол-ва пациентов, хотя их легко
    // посчитать методом .size() от вектора, хранящего всех пациентов в структуpe 
    // DataBase.
    
    std::ifstream DATABASE(filename);

    int i = 0;
    while(DATABASE)
    {
        
        std::string str;
        std::getline(DATABASE, str);
        
        if (str != "")
        {
            std::vector<std::string> patientData;
            Patient patient;
            database->patients.push_back(patient);
            patientData = split(str, ' ');
            database->patients[i].name = patientData[0];
            database->patients[i].surname = patientData[1];
            //show_vector(patientData);
            i = i + 1;
            
        }
        
    }
    database->length = i;
}


void saveDataBase(std::string filename, DataBase* database)
{
    // Ну а с помощью этой функции мы будем сохранять данные в файле, т.е.
    // перезаписывать его. Плохое решение для базы данных с большим кол-вом
    // пациентов, но пусть пока будет так.
    
    std::ofstream DATABASE(filename);
    
    for (int i = 0; i < database->length; i++)
    {
        DATABASE<< database->patients[i].name <<" "<< database->patients[i].surname<<"\n";
        
    }
    DATABASE.close();
}




void getInfo(DataBase* database)
{
    
    // Функция вывода данных в консоль. Всё примитивно и просто, прогоняем файл
    // циклом и принтим всё что видим. Но пока реализовано отображение имени и фамилии,
    // остальные атрибуты добавляются в функционал аналогично.
    
    for (int currentId = 0; currentId < database->length; currentId++)
        {
            std::cout<< currentId + 1 << "  ";
            std::cout<< database->patients[currentId].name << "   ";
            std::cout<< database->patients[currentId].surname << "   ";
            //std::cout<< database->patients[currentId].sex << "   ";
            //std::cout<< database->patients[currentId].age << "   ";
            //std::cout<< database->patients[currentId].city << "   ";
            //std::cout<< database->patients[currentId].visitAmount << "   " << std::endl; 
        }
    std::cout<<"Кол-во психов:  "<< database->length<< "\n";
    
}


void addPatient(DataBase* database, std::string name, std::string surname)
{
    
    // Функция добавления пациента вручную, путём ввода данных в консоль. Специально
    // для любителей работать ручками. Вообще можно сделать это чуть проще и через цикл,
    // чтобы было проще добавлять большие кол-ва психов. Также вполне нетрудно будет
    // реализовать слияние двух баз данных, но мне пока лень.
    
    int currentId = database->length;
    database->patients[currentId].name = name;
    database->patients[currentId].surname = surname;
    //patients[currentId].sex = sex;
    //patients[currentId].age = age;
    //patients[currentId].city = city;
    //patients[currentId].visitAmount = visitAmount;
    database->length++;
}


int main()
{
    
    // Ну и главная функция. Можно введением нужного числа выбрать соответствующую
    // опцию, реализовано ясен пень через цикл while. Вообще по хорошему всё что идёт
    // ниже надо отделить в отдельную функцию, но времени катастрофически мало.
    // В дальнейшем функционал расширю, доавблю чутка новых плюшек.
    
        DataBase database;
        int index = -1;
        readDataBase("arkham_asylum.txt", &database);
        int currentAmount = database.length;
        std::cout<<" Приложение для мониторинга пациентов психушки.\n Для вывода списка данных пациентов введите (1).\n Для добалвения пациента в список введите (2).\n Для сохранения изменений введите (3).\n Для выхода из программы введите (0)"  << std::endl;
        while (index != 0)
        {
            std::cin >> index;
            if (index == 1)
            {
               getInfo(&database); 
            } else if (index == 0)
            {
                std::cout << "exit" << std::endl;
            } else if (index == 2)
            {
                std::cout<< "Введите имя и фамилию психа \n";
                std::string name;
                std::string surname;
                std::cin>> name;
                std::cin>> surname;
                addPatient(&database, name, surname);
                
            } else if (index == 3)
            {
                
                saveDataBase("arkham_asylum.txt", &database);
            }
            
        }
        
        return 0;
}
