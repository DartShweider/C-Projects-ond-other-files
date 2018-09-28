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
/*
//
//




*/
struct Patient     
{
    
    // Создаём "объект" типа пациент, в нём храним всю инфу о нём.
    
    std::string name = " ";
    std::string surname = " ";
    bool sex = true;
    int age = 0;
    std::string city = " ";
    int visitAmount = 0;
    
};
//
//
void show_vector( std::vector<std::string>&vect) 

    /* Функция вывода элементов вектора на 
    // экран, нужна была на стадии отладки 
    // первой версии программы, сейчас уже не нужна вообще,
       но пусть будет.
    */ 

{
    for (int i = 0 ;i< vect.size(); ++i)
    {
        std::cout<<vect[i];
    }
}
//
//
struct DataBase      
{
    
    /* Здесь база данных пациентов психушки //
    // Создаём "объект" типа База данных. На этот раз это -
    // динамический массив, специально для отработки навыков
    // программирования. Для этого пришлось ввести ещё дополнительную
    // переменную - счётчик текущей вместимости этого самого массива,
       чтобы в случае его переполнения увеличить размер.
    */
    
    std::string nameOfDB = " ";
    int capacity = 1;
    int numberOfPatients = 0;
    Patient* patients = new Patient[1];
    
};
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
    
    // Данная и следующая функции отвечают за разделение вводимых строк на
    // отдельные слова, затем они уже запихиваются в описание каждого пациента.
    
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
    /* А тут мы читаем файл формата .txt, хотя, как показала практика,
    // оно могёт читать и файлы других форматов, например .doc или .asc
    
    // Здесь мы построчно читаем файл, с помощью 2-х функций выше разделяем
    // вводимые слова и запихиваем в структуру каждого пациента.
    // Я не стал этого делать для всех 6-ти атрибутов, достаточно 
    // продемонстрировать на 2-х.
    // Остальные делаются аналогично.
    // Теперь тут уже нам нужен счётчик кол-ва пациентов, иначе как мы узнаем,
    // когда нам расширять объём хранилища?
    //  
    */ 
    
    DataBase database;
    std::ifstream DATABASE(filename);

    int i = 0; // Если что - это счётчик кол-ва считываемых из файла психов.
    database.nameOfDB = filename;
    
    while(DATABASE)
    {
        
        std::string str;
        std::getline(DATABASE, str);
        
        if (str != "") // Это непонятная магия, без которой прога не рабоатет.
        {
            
            if (i == database.capacity)
                
            {
                
                // Вот тут мы собственно фиксируем момент переполнения хранилища
                // и оперативненько удваиваем его объём. Весьма наркоманским
                // способом, но увы, оно только так согласилось работать.
                
                database.capacity = (i + 1) * 2;
                Patient* buff_mass = new Patient[i];
                
                for (int j = 0; j< i; j++)
                {
                    buff_mass[j] = database.patients[j];
                }
                
                database.patients = new Patient[(i + 1) * 2]; 
                
                for (int j = 0; j< i; j++)
                {
                    database.patients[j] = buff_mass[j];
                }

                delete[] buff_mass;
                
            }
            
        // А далее мы разбиваем каждую строку базы данных на отдельные
        // куски информации и пихаем их в атрибуты каждого пациента, которого,
        // в свою очередь пихаем в БД.
            
        std::vector<std::string> patientData;
        Patient patient;
        patientData = split(str, ' ');
        patient.name = patientData[0];
        patient.surname = patientData[1];
        database.patients[i] = patient;
            
        //show_vector(patientData);
            
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
    /* Ну а с помощью этой функции мы будем сохранять данные в файле, т.е.
    // перезаписывать его (или записывать его с нуля, зависит от вас). 
    // 
    */ 
    
    int DBindex = dataBaseSearch(dataBaseArray, NameOfDB);
    
    std::ofstream DATABASE(filename);
    
    for (int i = 0; i < dataBaseArray[DBindex].numberOfPatients; i++)
    {
        DATABASE<< dataBaseArray[DBindex].patients[i].name <<" "<< dataBaseArray[DBindex].patients[i].surname<<"\n";
        
    }
    DATABASE.close();
}
//
//
void getInfo(std::vector<DataBase> &dataBaseArray, std::string NameOfDB)
{
    
    /* Функция вывода данных всех пациентов, с прошлой версии не изменилась,
    // принтим в консоль до посинения всё, что видим.
    */ 
    
    showNamesOfDBs(dataBaseArray);
    int DBindex = dataBaseSearch(dataBaseArray, NameOfDB);
    if (DBindex != -666)
    { 
        
        for (int currentId = 0; currentId < dataBaseArray[DBindex].numberOfPatients; currentId++)
            {
                std::cout<<"(" <<currentId + 1 << ")  ";
                std::cout<< dataBaseArray[DBindex].patients[currentId].name << "   ";
                std::cout<< dataBaseArray[DBindex].patients[currentId].surname << "   ";
                std::cout<< "\n";
                /*std::cout<< database->patients[currentId].sex << "   ";
                //std::cout<< database->patients[currentId].age << "   ";
                //std::cout<< database->patients[currentId].city << "   ";
                */
                std::cout<< dataBaseArray[DBindex].patients[currentId].visitAmount << "   " << std::endl; 
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
    
    /* Прокачанная функция добавления пациента. Если вдруг хранилище опять заполнилось,
    // увеличиваем его объём.
    // 
    */ 
    
    int DBindex = dataBaseSearch(dataBaseArray, NameOfDB);
    
    int datCapacity = dataBaseArray[DBindex].capacity;
    
    if (dataBaseArray[DBindex].numberOfPatients >= datCapacity - 1)
            {
                dataBaseArray[DBindex].capacity = (datCapacity + 1) * 2;
                Patient* buff_mass = new Patient[(datCapacity + 1) * 2];
                for (int j = 0; j< dataBaseArray[DBindex].numberOfPatients; j++)
                {
                    buff_mass[j] = dataBaseArray[DBindex].patients[j];
                }
                dataBaseArray[DBindex].patients = new Patient[(datCapacity + 1) * 2];
                for (int j = 0; j< dataBaseArray[DBindex].numberOfPatients; j++)
                {
                    dataBaseArray[DBindex].patients[j] = buff_mass[j];
                }

                delete[] buff_mass;
            }
    
    int currentId = dataBaseArray[DBindex].numberOfPatients;
    Patient patient;
    dataBaseArray[DBindex].patients[currentId] = patient;
    dataBaseArray[DBindex].patients[currentId].name = name;
    dataBaseArray[DBindex].patients[currentId].surname = surname;
    
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
    
    /* Дабы всё, что ниже, не сидело в функции main, запихнул сюда из эстетических
    // соображений. Ну и читаемость лучше. Вводя различные циферки, добиваемся
       нужного нам результата.
    */ 
        
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
    
    /* Святая святых - функция main. Без неё невозможно существование программы.
    // Что тут ещё добавить?
    // 
    */ 
        
        std::vector<DataBase> dataBaseArray;
        startTheProgram(dataBaseArray);
        return 0;
        
}
