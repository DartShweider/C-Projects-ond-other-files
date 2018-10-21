#pragma once
#ifndef LIST_H_
#define LIST_H_
#include <string>


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
    

        ~List()
        {
            empty();

        }
        
        
        Node<Type>* head;
        int capacity = 0;
        void push_front(Type value);
        void push_back(Type value);
        void print_all();
        void empty();
        void delete_elem(int index);
        void print_elem(int index);
        void find_elem(Type value);
    
};    

template <class Type>
void List<Type>::push_back(Type value)
{
    if (0 == capacity)
    {
        head = new Node<Type>(value, 0);

    } else
    {
        Node<Type>* current = head;
    for (int i =0; i<capacity-1; i++)
    {
            current = current->next;
    }
    
    current->next = new Node<Type>(value, 0);
    
    }
    capacity++;
    
}
//_____________________________________________
//_____________________________________________
template <class Type>
void List<Type>::push_front(Type value)
{
    if(0 == capacity)
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
void List<Type>::empty()
    {
        
        Node<Type>* tmp_head = head->next;
        
        
        for (int i =0; i < capacity; i++)
        {

            
            delete head;
            head = nullptr;
            head = tmp_head;

            tmp_head = head->next;
            
        }
        head = nullptr;
        capacity = 0;

    
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
void List<Type>::print_elem(int index)
    {
        Node<Type>* current = head;
        
            for (int i = 0; i < index - 1; i++)
            {

                current = current->next;
                
            }
        std::cout << current->value << "\n";
        
    }
    
    
/*template <class Type>
int List<Type>::find_elem(Type value)
{
    Node<Type>* current = head;
    int index;
        for (int i =0; i < capacity; i++)
        {

            if (current->value == value)
            {
                index = i;
            }
            current = current->next;
            
        }
    return i;
}
*/
#endif
