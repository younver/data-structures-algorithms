#pragma once
#ifndef _STACK_H_
#define _STACK_H_

#define MAX 1000

template <typename T>
class Stack
{
private:
    int top;
    T array[MAX];
public:
    Stack();
    bool isEmpty();
    bool isFull();
    void push(T value);
    T pop();
    T peek();
    void display();
};

#endif
