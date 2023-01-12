#include <iostream>

#define MAX 1000

template <typename T>
class Stack
{
private:
    int top;
public:
    T array[MAX];

    Stack()
    {
        this->top = -1;
    }

    bool isEmpty()
    {
        return top == -1;
    }

    bool isFull()
    {
        return top == (MAX-1);
    }

    void push(T value)
    {
        // Handle full stack
        if (this->isFull()) {
            std::cout << "~~ stack is full" << std::endl;
            return;
        }

        // Push to top
        array[++top] = value;
    }

    T pop()
    {
        // Handle empty stack
        if (this->isEmpty()) {
            return NULL;
        }
        
        // Pop from top
        return array[top--];
    }

    T peek()
    {
        // Handle empty stack
        if (this->isEmpty()) {
            return NULL;
        }

        // Peek the top
        return array[top];
    }

    void display()
    {
        // Handle empty stack
        if (this->isEmpty()) {
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

int main(){

    Stack<int> stack;

    std::cout << "* pop ~ empty case: " << stack.pop() << std::endl;
    stack.display();

    std::cout << "* push ~ empty case" << std::endl;
    stack.push(3);
    stack.display();

    std::cout << "* pop ~ single case: " << stack.pop() << std::endl;
    stack.display();

    std::cout << "* peek ~ empty case: " << stack.peek() << std::endl;
    stack.display();
    
    stack.push(4);
    std::cout << "* peek ~ single case: " << stack.peek() << std::endl;
    stack.display();

    stack.push(5);
    stack.push(6);
    stack.push(7);
    std::cout << "* peek ~ multiple case: " << stack.peek() << std::endl;
    stack.display();


    std::cout << "* pop ~ empty case: " << stack.pop() << std::endl;
    stack.display();

    return 0;
}