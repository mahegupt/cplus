#include <iostream>
#include <memory>

using namespace std;
class Dog {
    public:
    Dog() {
        cout << "Crreate Base class Dog" << endl;
    }
    ~Dog() {
        cout << "Base Dog deleted"<< endl;
    }
};

class YelloDog : public Dog {
    public:
    YelloDog() {
        cout << "Crreate Yellow class Dog" << endl;
    }
    ~YelloDog() {
        cout << "Yellow Dog deleted" << endl;
    }
};

class dogFactory {
    public:
    static shared_ptr<Dog> createYellowDog() { 
        return shared_ptr<YelloDog>(new YelloDog());
    }
    
};

int main() {
    shared_ptr<Dog> d = dogFactory::createYellowDog();
    // delete d;
    return 0;
}
//If a class derive from base class, the base class must have a virtual distructor for clean memory cleanup.
//A clean object deletion can  be achieved using shared function. std::shared_ptr is a smart pointer that retains shared ownership of an object through a pointer.