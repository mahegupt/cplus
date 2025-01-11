#include <iostream>
using namespace std;

class Base {
public:
    void nonVirtualFunc() {
        std::cout << "Base class non-virtual function." << std::endl;
    }
    virtual void virtualFunc() {
        std::cout << "Base class virtual function." << std::endl;
    }
};

class Derived : public Base {
public:
    void nonVirtualFunc() {
        std::cout << "Derived class non-virtual function." << std::endl;
    }
    void virtualFunc() override {
        std::cout << "Derived class virtual function." << std::endl;
    }
};

int main() {
    Base* basePtr;
    Derived derivedObj;

    basePtr = &derivedObj;

    basePtr->nonVirtualFunc();  // Output: Base class non-virtual function.
    basePtr->virtualFunc();     // Output: Derived class virtual function.

    return 0;
}
