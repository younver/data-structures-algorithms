#include "stack.h"
#include <iostream>
#include <stdlib.h>

template <typename T>
Stack<T>::Stack(int size){
    top = -1;
    this->size = size;
    array = (T*) malloc( size * sizeof(T) );
}

template <typename T>
bool Stack<T>::isEmpty(){
    return Stack<T>::top == -1;
}

template <typename T>
bool Stack<T>::isFull(){
    return top == (size - 1);
}
template <typename T>
void Stack<T>::push(T value)
{
    if (isFull()) {
        std::cout << "~~ stack is full" << std::endl;
        return;
    }

    array[++top] = value;
}

template <typename T>
T Stack<T>::pop()
{
    if (isEmpty()) {
        return NULL;
    }

    return array[top--];
}

template <typename T>
T Stack<T>::peek()
{
    if (isEmpty()) {
        return NULL;
    }

    return array[top];
}

template <typename T>
void Stack<T>::display()
{
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

int main(){

    Stack<int>* stack = new Stack<int>(5);

    std::cout << "* pop ~ empty case: " << stack->pop() << std::endl;
    stack->display();

    std::cout << "* push ~ empty case" << std::endl;
    stack->push(3);
    stack->display();

    std::cout << "* pop ~ single case: " << stack->pop() << std::endl;
    stack->display();

    std::cout << "* peek ~ empty case: " << stack->peek() << std::endl;
    stack->display();
    
    stack->push(4);
    std::cout << "* peek ~ single case: " << stack->peek() << std::endl;
    stack->display();

    stack->push(5);
    stack->push(6);
    stack->push(7);
    std::cout << "* peek ~ multiple case: " << stack->peek() << std::endl;
    stack->display();


    std::cout << "* pop ~ empty case: " << stack->pop() << std::endl;
    stack->display();

    return 0;
}
