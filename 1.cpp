#include <iostream>
#include <stdio.h>
#include <math.h>

int main()
{
        
        float a, b, c;
        float conditional_zero = 0.00001;
        
        std::cout<< "Уравнение вида ax^2 + bx + c = 0. Введите параметры a, b, c. " << std::endl;
        std::cout<< "Параметр а: ";
        std::cin >> a;
        std::cout<< "Параметр b: ";
        std::cin >> b;
        std::cout<< "Параметр c: ";
        std::cin >> c;
        
        
        if (abs(a) > conditional_zero and abs(b) > conditional_zero and abs(c) > conditional_zero)
        {
            float d = pow(b, 2) - 4*a*c;
            std::cout <<"Дискриминант: " << d << std::endl;
            if (d > conditional_zero) 
            {
                std::cout<< "Корень_1: "<< (-b - sqrt(d))/(2*a)<< "  " << "Корень_2: " << (-b + sqrt(d))/(2*a) << std::endl;
            } else if (abs(d) <= conditional_zero) 
            {
                std::cout<< "Корень: "<< -b/2 << std::endl;
            } else if (d < -conditional_zero)
            {
                std::cout<< "Действительных корней нет" << std::endl;
            }
            
        } else if (abs(a) < conditional_zero) 
        {
            if (abs(b) > conditional_zero)
            {
                std::cout<< "Корень: "<< -c/b << std::endl;
            } else 
            {
                std::cout<< " Действительных корней нет" << std::endl;
            }
            
            
        }  else if (abs(b) < conditional_zero) 
        {
            if (abs(a) > conditional_zero)
            {
                std::cout<<"Корень_1: "<< -sqrt(c/a)<< "  " << "Корень_2: " << sqrt(c/a) << std::endl;
            } else 
            {
                std::cout<< " Действительных корней нет" << std::endl;
            }
        } else if (abs(c) < conditional_zero) 
        {
            if (abs(a) > conditional_zero)
            {
                std::cout<< "Корень_1: "<< -b/a << "  "<< "Корень_2: "<< 0 << std::endl;
            } else 
            {
                std::cout << " Действительных корней нет" << std::endl;
            }
        }
        return 0;
}
