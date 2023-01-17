#pragma once


#include <iostream>
#include <stdlib.h>

template <typename T>
class Queue{
    
    private:

        int front;
        int rear;
        int size;
        int count;
        T* array;
    
    public:
        Queue(int size){
            this->front = 0;
            this->rear = size - 1; // handles initial problem when they set to -1
            this->size = size;
            this->array = (T*) malloc( size * sizeof(T) );
        }

        bool isEmpty(){    
            return count == 0;
        }

        bool isFull(){
            return count == size;
        }

        void enqueue(T value){
            if (isFull()){
                std::cout << "~~ can't enqueue: queue is full" << std::endl;
                return;
            }

            rear = (rear + 1) % size;
            array[rear] = value;
            count++;
        }

        T dequeue(){
            if (isEmpty()){
                std::cout << "~~ can't dequeue: queue is empty" << std::endl;
                return NULL;
            }

            T item = array[front];
            front = (front + 1) % size;
            count--;

            return item;
        }

        void display(){
            std::cout << "queue: ";

            if (isEmpty()){
                std::cout << "is empty" << std::endl << std::endl;
                return;
            }

            for (int i=0; i < count; i++){
                int current = (front + i) % size;
                std::cout << array[current] << ", "; 
            }
            std::cout << std::endl << std::endl;
        }
};

