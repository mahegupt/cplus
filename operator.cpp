#include<iostream>
using namespace std;

class Num {
    int data;
    public:
        Num(int val): data(val) {}
        
        // Num(Num &n): data(n.data){
        //  }

        Num operator+(const Num& input) {
            return Num(data + input.data);
        }

        void display() {
            cout << data << endl;
        }
};

int main() {
    Num a = Num(10);
    Num b = Num(20);
    Num c = a+b;
    a.display();
    b.display();
    c.display();
    auto lambda = [](int x, int y) { return x + y; };
    cout << lambda(3,5) << endl;
    return 0;
}