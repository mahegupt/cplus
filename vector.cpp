#include<iostream>
#include <vector>
#include <stack>
 
using std::vector;

using namespace::std;
using std::vector;

int main() {
    vector<string> articles = {"a", "an", "the"};
    for (string item : articles){
        cout << item << endl;
    }

    vector<string> cars = {"Volvo", "BMW", "Ford", "Mazda"};
    // Get the first element
    cout << cars[0] << endl;
    // Get the last element
    cout << cars[1] << endl;    
    cout << cars.size();  
    cars.push_back("Lambogini");
    cout << cars.size() <<endl;  
    cout << cars.empty() <<endl;  


    stack<string> mycars;
    mycars.push("M1");
    mycars.push("M2");
    cout << mycars.top() <<endl;
    mycars.push("Tesla");
    cout << mycars.top() <<endl;
    mycars.pop();
    cout << mycars.top() <<endl;


    // Create a vector called cars that will store strings
    // vector<string> cars = {"Volvo", "BMW", "Ford", "Mazda"};

    // Create a vector iterator called it
    vector<string>::iterator it;

    // Loop through the vector with the iterator
    for (it = cars.begin(); it != cars.end(); ++it) {
    cout << *it << "\n";
    }    
}