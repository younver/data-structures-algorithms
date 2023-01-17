#include "queue.h"
#include <iostream>

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
