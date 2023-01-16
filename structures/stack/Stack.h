#pragma once
#ifndef _STACK_H_
#define _STACK_H_

template <typename T>
class Stack
{
    private:
        int top;
        int size;
        T* array;
    public:
        Stack(int size);
        bool isEmpty();
        bool isFull();
        void push(T value);
        T pop();
        T peek();
        void display();
};

#endif
