#include <iostream>
#include <stdexcept> // For exceptions

class Stack {
private:
    int* data;       // Dynamic array to hold stack elements
    int topIndex;    // Index of the top element
    int capacity;    // Maximum capacity of the stack

public:
    // Constructor to initialize the stack
    Stack(int size) : capacity(size), topIndex(-1) {
        data = new int[capacity]; // Allocate memory
    }

    // Destructor to release memory
    ~Stack() {
        delete[] data;
    }

    // Push an element onto the stack
    void push(int value) {
        if (topIndex == capacity - 1) {
            throw std::overflow_error("Stack overflow: Cannot push onto a full stack");
        }
        data[++topIndex] = value; // Increment topIndex and insert the value
    }

    // Pop an element from the stack
    void pop() {
        if (isEmpty()) {
            throw std::underflow_error("Stack underflow: Cannot pop from an empty stack");
        }
        --topIndex; // Decrement topIndex to remove the top element
    }

    // Get the top element of the stack
    int top() const {
        if (isEmpty()) {
            throw std::underflow_error("Stack is empty: No top element");
        }
        return data[topIndex];
    }

    // Check if the stack is empty
    bool isEmpty() const {
        return topIndex == -1;
    }

    // Check the size of the stack
    int size() const {
        return topIndex + 1;
    }
};

int main() {
    Stack stack(5); // Create a stack with a capacity of 5

    // Push elements onto the stack
    stack.push(10);
    stack.push(20);
    stack.push(30);

    // Display and pop elements
    while (!stack.isEmpty()) {
        std::cout << "Top: " << stack.top() << std::endl;
        stack.pop();
    }
    
    return 0;
}
