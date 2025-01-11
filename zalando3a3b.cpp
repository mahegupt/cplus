#include <iostream>
#include <string>
using namespace std;

string generateString(int a, int b) {
    string result = "";
    
    while (a > 0 || b > 0) {
        if (a > b) {
            if (a >= 2) {
                result += "aa";
                a -= 2;
            } else {
                result += "a";
                a -= 1;
            }
            if (b > 0) {
                result += "b";
                b -= 1;
            }
        } else if (b > a) {
            if (b >= 2) {
                result += "bb";
                b -= 2;
            } else {
                result += "b";
                b -= 1;
            }
            if (a > 0) {
                result += "a";
                a -= 1;
            }
        } else {
            if (a > 0) {
                result += "a";
                a -= 1;
            }
            if (b > 0) {
                result += "b";
                b -= 1;
            }
        }
    }
    
    return result;
}

int main() {
    // Example usage
    cout << generateString(4, 1) << endl;  // Output could be "aabab" or similar
    cout << generateString(1, 3) << endl;  // Output could be "bbab" or similar
    cout << generateString(2, 5) << endl;  // Output could be "bbabbab" or similar
    return 0;
}
