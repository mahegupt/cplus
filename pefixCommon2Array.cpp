/*
You are given two 0-indexed integer permutations A and B of length n.
A prefix common array of A and B is an array C such that C[i] is equal to the count of numbers that are present at or before the index i in both A and B.
Return the prefix common array of A and B.
A sequence of n integers is called a permutation if it contains all integers from 1 to n exactly once.

Example 1:
Input: A = [1,3,2,4], B = [3,1,2,4]
Output: [0,2,3,4]
Explanation: At i = 0: no number is common, so C[0] = 0.
At i = 1: 1 and 3 are common in A and B, so C[1] = 2.
At i = 2: 1, 2, and 3 are common in A and B, so C[2] = 3.
At i = 3: 1, 2, 3, and 4 are common in A and B, so C[3] = 4.
*/
#include<iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        auto n = A.size();
        auto common = 0;
        vector<int> C(n, 0);
        //Create 2 sets.
        unordered_set<int> uSetA;
        unordered_set<int> uSetB;

        for (auto i=0;i<n;i++) {
            //Add elements to of each input vector to respective set.
            uSetA.insert(A[i]);
            uSetB.insert(B[i]);

            // A[i] is common if it's already in Set_B
            if (uSetB.find(A[i]) != uSetB.end()) {
                ++common;
            }
            // B[i] is common if it's already in Set_A
            if (uSetA.find(B[i]) != uSetA.end()) {
                ++common;
            }
            // Avoid double-counting when A[i] == B[i]
            if (A[i] == B[i]) {
                --common;
            }

            //  Update the prefix common count at index i
            C[i] = common;
        }
        return C;
    }
};
int main() {
    Solution c;
    vector<int> A = {1, 3, 2, 4};
    vector<int> B = {3, 1, 2, 4};
    
    vector<int> result = c.findThePrefixCommonArray(A, B);

    // Print the result
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

}