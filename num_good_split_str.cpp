/*
You are given a string s.
A split is called good if you can split s into two non-empty strings sleft and sright where their concatenation is equal to s 
(i.e., sleft + sright = s) and the number of distinct letters in sleft and sright is the same.
Return the number of good splits you can make in s.
Input: s = "aacaba"
Output: 2
explain - aac, aba is one split, aaca, ba is another split.
*/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int numSplits(string s) {
        int n = s.length();
        vector <int> left_count(n, 0);
        vector <int> right_count(n, 0);
        unordered_set<char> seen;
        for (auto i=0; i<n; ++i) {
            seen.insert(s[i]);
            left_count[i] = seen.size();
        }

        seen.clear();
        for(auto i=n-1; i>=0; --i) {
            seen.insert(s[i]);
            right_count[i] = seen.size();
        }
        int num_good_split = 0;
        for(auto i=0; i<n-1; ++i) {
            if (left_count[i] == right_count[i+1]) {
                ++num_good_split;
            }
        }
        return num_good_split;
    }
};



int main() {
    Solution S;
    string s = "aacaba";
    cout << "For String "<< s << " Number of good splits: " << S.numSplits(s) << endl;

    string s1 = "mpg";
    cout << "For String "<< s1 << " Number of good splits: " << S.numSplits(s1) << endl;

    return 0;
}