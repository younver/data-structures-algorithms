#include "queue.h"
#include <iostream>
#include <stdlib.h>

template <typename T>
Queue<T>::Queue(int size){
    this->front = 0;
    this->rear = size - 1; // handles initial problem when they set to -1
    this->size = size;
    this->array = (T*) malloc( size * sizeof(T) );
}

template <typename T>
bool Queue<T>::isEmpty(){
    return count == 0;
}

template <typename T>
bool Queue<T>::isFull(){
    return count == size;
}

template <typename T>
void Queue<T>::enqueue(T value){

    if (isFull()){
        std::cout << "~~ can't enqueue: queue is full" << std::endl;
        return;
    }
    
    rear = (rear + 1) % size;
    array[rear] = value;
    count++;
}

template <typename T>
T Queue<T>::dequeue(){

    if (isEmpty()){
        std::cout << "~~ can't dequeue: queue is empty" << std::endl;
        return NULL;
    }

    T item = array[front];
    front = (front + 1) % size;
    count--;

    return item;
}
        
template <typename T>
void Queue<T>::display(){
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


int main(){

    Queue<int>* queue = new Queue<int>(5);
 
    std::cout << "dequeue ~ empty case: " << queue->dequeue() << std::endl;
    queue->display();

    std::cout << "enqueue ~ empty case" << std::endl;
    queue->enqueue(1);
    queue->display();

    std::cout << "dequeue ~ single case: " << queue->dequeue() << std::endl;
    queue->display();
    std::cout << "enqueue ~ default case" << std::endl;
    queue->enqueue(2);
    queue->enqueue(3);
    queue->enqueue(4);
    queue->display();
   
    std::cout << "dequeue ~ default case: " << queue->dequeue() << std::endl;
    queue->display();

    std::cout << "enqueue ~ hit full case" << std::endl;
    queue->enqueue(5);
    queue->enqueue(6);
    queue->enqueue(7);
    queue->display();

    std::cout << "enqueue ~ full case" << std::endl;
    queue->enqueue(8);
    queue->display();

    std::cout << "dequeue ~ default case: " << queue->dequeue() << std::endl;
    std::cout << "dequeue ~ default case: " << queue->dequeue() << std::endl;
    std::cout << "dequeue ~ default case: " << queue->dequeue() << std::endl;
    std::cout << "dequeue ~ default case: " << queue->dequeue() << std::endl;
    std::cout << "dequeue ~ hit empty case: " << queue->dequeue() << std::endl;
    queue->display();
    
    std::cout << "dequeue ~ empty case: " << queue->dequeue() << std::endl;
    queue->display();

    std::cout << "enqueue ~ after hit empty case" << std::endl;
    queue->enqueue(9);
    queue->display();

    return 0;
}
