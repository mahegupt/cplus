#include <iostream>
#include <unordered_map>
using namespace std;

// Use the sliding window between left index to right index of unique chars. Keep moving right index unless repeted char not occured to find window size.
// Once you notice repeated character, keep moving left index unless you find bigger window.
int largestUniqueSubString(string s) {
    int left = 0; 
    int n = s.length();
    int max_len = 0;
    unordered_map<char, int> charIndex; 
    for(int right=0; right<n; ++right) {
        // If the char found in charIndex, repeated, move the left
        if (charIndex.find(s[right]) != charIndex.end()) {
            left = max(left, charIndex[s[right]]+1);
        }
        charIndex[s[right]] = right; //Store index of char s[right] to charIndex table
        max_len = max(max_len, right - left + 1); // Keep updating the max length
    }
    return max_len;
}

int main() {
    string input = "abcabcdeabcea";
    cout << "Input is :" << input << endl;
    cout << "Largest unique substring is : " << largestUniqueSubString(input) << endl; 
    return 0;
}