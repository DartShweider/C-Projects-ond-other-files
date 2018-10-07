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


template <class Type>
struct Node
{
    
    Type value;
    Node<Type>* next = nullptr;
    Node (Type value, Node* next)
    {
        this->value = value;
        this->next = next;
    }
    
};
template <class Type>
struct List
{
    
    Node<Type>* head;

    int capacity = 0;
    void push_front(Type value);
    void print_all();
    void delete_elem(int index);
    void find_elem(Type value);
    
};    


//_____________________________________________
//_____________________________________________
int main()
{
    
    List <double> mylist;
    mylist.push_front(5.98);
    for (int i = 21; i<28; i++)
    {
        mylist.push_front(i);
    }
    mylist.print_all();
    std::cout << "___________\n";
    mylist.delete_elem(7);
    mylist.print_all();
    mylist.find_elem(21);
    return 0;
}

//_____________________________________________
//_____________________________________________
template <class Type>
void List<Type>::push_front(Type value)
{
    if(!head)
        {
            head = new Node<Type>(value, 0);
            //std::cout << head->value << std::endl;
            //std::cout << head->next << std::endl;
            capacity++;
        }   else
        {    
        
        Node<Type>* tmp_head = head;
        head = new Node<Type>(value, tmp_head);
        //std::cout << head->value << std::endl;
        //std::cout << head->next << std::endl;
        capacity++;
        }
}
template <class Type>
void List<Type>::print_all()
    {
        Node<Type>* current = head;
        for (int i =0; i < capacity; i++)
        {

            std::cout << current->value << std::endl;
            current = current->next;
            
        }

        std::cout << "cap = " << capacity << std::endl;
    
    }
    
template <class Type>
void List<Type>::delete_elem(int index)
    {
        
        
        if (0 == index)
        {
            Node<Type>* tmp_head = head->next;
            delete head;
            head = tmp_head;
            capacity--;
            
        } else if (capacity - 1 == index)
        {
            Node<Type>* current = head;
            for (int i = 0; i < capacity - 1; i++)
            {

                current = current->next;
                
            }
            delete current;
            current = nullptr;
            capacity--;
            
        } else 
        {
            Node<Type>* prev_elem;
            Node<Type>* next_elem;
            Node<Type>* current = head;
            for (int i = 0; i <= index; i++)
            {
                if (1 == index-i)
                {
                    prev_elem = current;
                } 
                if (i == index )
                {
                    
                    next_elem = current->next;
                    delete current;
                    current = nullptr;
                    break;
                }
                current = current->next;
                
            }
            prev_elem->next = next_elem;
            capacity--;
        }
        
    }
    
    
    
template <class Type>
void List<Type>::find_elem(Type value)
{
    Node<Type>* current = head;
        for (int i =0; i < capacity; i++)
        {

            if (current->value == value)
            {
                std::cout << "[" << i << "]" << "\n"; 
            }
            current = current->next;
            
        }
}
