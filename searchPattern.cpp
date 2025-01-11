#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

string SearchingChallenge(string str) {
    int max_len = 0;
    string longest_pattern = "null";

    // Start from patterns of length 2 up to length of half the string
    for (int len = 2; len <= str.size() / 2; ++len) { // Loop of patter size
        for (int i = 0; i <= str.size() - len; ++i) { //Loop on remaing part of string
            string pattern = str.substr(i, len); //First Extact pattern

            // Check if the pattern repeats at least once onward sub-string
            size_t next_occurrence = str.find(pattern, i + len);
            //If next sub string with matching patterr found, update the global variable.
            if (next_occurrence != string::npos) {
                // If we find a longer pattern, update max_len and longest_pattern
                if (len > max_len) {
                    max_len = len;
                    longest_pattern = pattern;
                }
            }
        }
    }

    // Check if we found any repeating pattern
    if (longest_pattern != "null") {
        return "yes " + longest_pattern;
    } else {
        return "no null";
    }
}

int main() {
    cout << SearchingChallenge("aabejiabkfabed") << endl; // Output: "yes abe"
    cout << SearchingChallenge("123224") << endl;         // Output: "no null"
    cout << SearchingChallenge("aa2bbbaacbbb") << endl;   // Output: "yes bbb"
    return 0;
}
