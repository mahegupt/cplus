#include <iostream>
using namespace std;
class Dog {
    int age;
    string name;
    public:
        Dog() {
            age = 0;
            name = "Dummy";
        }
        void setAge(const int &input) {
            age = input;
            cout << "Const Args Doc Age = " << age << endl;
        }
        void setAge(int &input) {
            age = input;
            cout << "Non-Const Arg Doc Age = " << age << endl;
        }
        void setAge(int &input) const{
            // age = input;
            cout << "Non-Const Doc Const fun Age = " << age << endl;
        }
        const string& getName() {
            return name;
        }
};

int main() {
    Dog d;
    int i=10;
    //Calling with non-const arg.
    d.setAge(i);
    cout << " i = " << i << endl;

    //Calling with const argument.
    int const a=100;
    d.setAge(i);

    //Calling const function with const object.
    const Dog d1;
    d1.setAge(i);

    const string n = d.getName();
    cout << " name = " << n << endl;
}