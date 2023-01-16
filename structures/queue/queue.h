#pragma once
#ifndef _QUEUE_H_
#define _QUEUE_H_


template <typename T>
class Queue{
    
    private:

        int front;
        int rear;
        int size;
        int count;
        T* array;
    
    public:

        Queue(int size);
        bool isEmpty();
        bool isFull();
        void enqueue(T value);
        T dequeue();
        void display();
};

#endif
