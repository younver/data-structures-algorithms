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
            return this->count == 0;
        }

        bool isFull(){
            return this->count == this->size;
        }

        void enqueue(T value){
            
            // Handle full case
            if (this->isFull()){
                std::cout << "~~ can't enqueue: queue is full" << std::endl;
                return;
            }

            this->rear = (this->rear + 1) % this->size;
            this->array[rear] = value;
            this->count++;
        }

        T dequeue(){
            // Handle empty case
            if (this->isEmpty()){
                std::cout << "~~ can't dequeue: queue is empty" << std::endl;
                return NULL;
            }

            T item = this->array[this->front];
            this->front = (this->front + 1) % this->size;
            this->count--;
            
            return item;
        }
        
        void display(){
             std::cout << "queue: ";
             
             // Handle empty case
             if (this->isEmpty()){
                 std::cout << "is empty" << std::endl << std::endl;
                 return;
             }

             for (int i=0; i < this->count; i++){
                 int current = (this->front + i) % this->size;
                 std::cout << this->array[current] << ", "; 
             }
             std::cout << std::endl << std::endl;
        }
};


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
