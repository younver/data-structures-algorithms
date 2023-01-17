#pragma once

#include <iostream>
#include <stdlib.h>

template <typename T>
class Stack
{
    private:
        int top;
        int size;
        T* array;

    public:
        Stack(int size){
            top = -1;
            this->size = size;
            array = (T*) malloc( size * sizeof(T) );
        }

        bool isEmpty(){
            return Stack<T>::top == -1;
        }

        bool isFull(){
            return top == (size - 1);
        }

        void push(T value){
            if (isFull()) {
                std::cout << "~~ stack is full" << std::endl;
                return;
            }

            array[++top] = value;
        }

        T pop(){
            if (isEmpty()) {
                return 
                    NULL;
            }

            return array[top--];
        }

        T peek(){    
            if (isEmpty()) {
                return NULL;
            }

            return array[top];
        }

        void display(){
            if (isEmpty()) {
                std::cout << "~~ stack is empty" << std::endl << std::endl;
                return;
            }

            std::cout << "display: ";
            for (uint i=0; i <= top; i++) {
                std::cout << array[i] << ", ";
            }
            std::cout << std::endl << std::endl;
        }
};

