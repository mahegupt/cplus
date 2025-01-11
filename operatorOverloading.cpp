#include<iostream>
using namespace std;
class Complex {
public:
    int real, imag;

    // Constructor to initialize the object's values
    Complex(int r = 0, int i = 0) : real(r), imag(i) {}

    // Overload the + operator
    Complex operator + (const Complex& obj) {
        return Complex(real + obj.real, imag + obj.imag);
    }
    void print() {
       cout << real <<"."<<imag << endl; 
    }
};

int main() {
    Complex c1(10, 5), c2(2, 4);
    Complex c3 = c1 + c2;
    c1.print();
    c2.print();
    c3.print();
    auto add = [](int a, int b) -> int { return a + b; };
    cout << add(2,4) << endl;
}