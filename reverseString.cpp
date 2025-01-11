#include<iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string str;
    cout << "Enter the sting to reverse"<<endl;
    cin>>str;
    // reverse(inStr.begin(), inStr.end());
    int n = str.length();
    for (int i = 0; i < n / 2; ++i) {
        std::swap(str[i], str[n - i - 1]);
    }
    cout << "Reversed output is :" << str << endl;
    return 0;
}