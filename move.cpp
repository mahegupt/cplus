#include <iostream>
#include <memory>

class MyClass {
private:
    int* data;

public:
    // Constructor
    MyClass(int value) : data(new int(value)) {
        std::cout << "Constructor: Allocating memory." << std::endl;
    }

    // Move constructor
    MyClass(MyClass&& other) noexcept : data(other.data) {
        other.data = nullptr;  // Leave the other object in a safe state
        std::cout << "Move constructor: Transferring ownership." << std::endl;
    }

    // Destructor
    ~MyClass() {
        if (data) {
            delete data;  // Deallocate memory
            std::cout << "Destructor: Deallocating memory." << std::endl;
        }
        std::cout << "Destructed object." << std::endl;
    }

    void display() const {
        std::cout << "Data: " << (data ? *data : 0) << std::endl;
    }
};

int main() {
    MyClass obj1(10);  // Regular constructor
    obj1.display();  // Output: Data: 10

    MyClass obj2 = std::move(obj1);  // Move constructor is called
    obj2.display();  // Output: Data: 10
    obj1.display();  // Output: Data: 0 (or nothing, because obj1 is in a valid but unspecified state)

    return 0;
}
