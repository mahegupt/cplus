#include<iostream>
#include<vector>
#include <sstream>

using namespace std;
class Solution {
    public:
        string reverseWords(string s) {
            vector <string> words;
            stringstream ss(s);
            string word, result;
    
            //Extract the words from String s
            while(ss>>word) {
                words.push_back(word);
            }
            
            //Nos start from end of list of words and constuct the result.
            for(int i=words.size()-1; i>=0; --i) {
                result +=  words[i];
                //Add space between words except last one.
                if (i>0) {
                    result += " ";
                }
            }
            return result;
        }
    };

int main() {
        string s = "  hello   world  ";
        Solution S;
        cout << "\"" << S.reverseWords(s) << "\"" << endl; // Output: "world hello"
        cout << "\"" << S.reverseWords("I am Mahesh Gupta") << "\"" << endl; // Output: "world hello"
        return 0;
}