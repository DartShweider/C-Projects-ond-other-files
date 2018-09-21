#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string>

struct equationData             //Объявление структуры, содержащей данные, необходимые для  решения уравнения. После создания экземпляра структуры, мы будем изменять его данные по     ходу решения, используя указатели//
{
    
    int numberOfRoots = 0;      //Объявление и инициализация переменных: кол-во корней, коэффициенты уравнения, массив с корнями уравнения//
    float a = 0;
    float b = 0;
    float c = 0;
    float roots[2] = {0, 0};
    
};

void inputData(equationData* eqData)        //Функция ввода данных//
{
        
    std::cout<< "Уравнение вида ax^2 + bx + c = 0. Введите параметры a, b, c. " << std::endl;
    std::cout<< "Параметр а: ";
    std::cin >> eqData->a;                  //Ввод коэффициентов "a", "b", "c"//
    std::cout<< "Параметр b: ";
    std::cin >> eqData->b;
    std::cout<< "Параметр c: ";
    std::cin >> eqData->c;

}

void solutionOfEquation(equationData* eqData)       //Функция решения уравнения//
{
    
    float conditional_zero = 0.00001;       //Условный нуль - значение, с которым мы сравниваем модуль числа//
    float a = eqData->a;                    //Извлекаем коэффициент "а" из структуры для более удобной работы//
    float b = eqData->b;                    //Извлекаем коэффициент "b" из структуры для более удобной работы//
    float c = eqData->c;                    //Извлекаем коэффициент "с" из структуры для более удобной работы//
    
    // А далее рассамтриваем разные случаи квадратного уравнения и решаем их//
    
        if (abs(a) > conditional_zero)      
        {
            
            float d = pow(b, 2) - 4*a*c;
            
            if (d > conditional_zero) 
            {
                eqData->roots[0] = (-b - sqrt(d))/(2*a);
                eqData->roots[1] = (-b + sqrt(d))/(2*a);
                eqData->numberOfRoots = 2;
                
            } else if (abs(d) <= conditional_zero) 
            {
                eqData->roots[0] = -b/2;
                eqData->numberOfRoots = 1;
                
            } else if (d < -conditional_zero)
            {
                eqData->numberOfRoots = 0;
            }
            
        } else if (abs(a) < conditional_zero and abs(b) > conditional_zero) 
        {
            eqData->roots[0] = -c/b;
            eqData->numberOfRoots = 1;   
            
        }  else if (abs(b) < conditional_zero and abs(a) < conditional_zero) 
        {
            eqData->numberOfRoots = 0;
        }
    
}

void outputValues(equationData* eqData)     //Функция вывода решений уравнения//
{
    if (eqData->numberOfRoots > 0)
    {
       std::cout << "Корни уравнения:" << std::endl;
        for (int i = 0; i < eqData->numberOfRoots; i++) //Извлекаем корни уравнения из массива с помощью цикла, если они есть//
        {
         std::cout<< eqData->roots[i] << "   "<<std::endl;
        }
    } else
    {
        std::cout<< "Действительных корней нет"<< std::endl;
    }
}

int main()
{
    
        equationData eqData_1;          //Создаём экземпляр структуры//
        inputData(&eqData_1);           //Производим ввод данных и сохраняем их в атрибутах структуры//
        solutionOfEquation(&eqData_1);  //Решаем уравнение//
        outputValues(&eqData_1);        //Выводим решения в консоль//
        return 0;
}
