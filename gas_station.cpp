#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int ArrayChallenge(vector<string> strArr) {
    // Step 1: Parse the number of gas stations
    int N = stoi(strArr[0]);
    
    // Step 2: Parse the gas and cost at each station
    vector<int> gas(N);
    vector<int> cost(N);
    
    for (int i = 1; i <= N; ++i) {
        int colonPos = strArr[i].find(':'); // Find the position of ':'
        gas[i - 1] = stoi(strArr[i].substr(0, colonPos)); // Extract fuel before ':'
        cost[i - 1] = stoi(strArr[i].substr(colonPos + 1)); // Extract cost after ':'        
    }
    
    // Step 3: Check if total gas >= total cost
    int total_gas = 0, total_cost = 0;
    for (int i = 0; i < N; ++i) {
        total_gas += gas[i];
        total_cost += cost[i];
    }
    
    if (total_gas < total_cost) {
        return -1;  // Not possible to complete the circuit
    }
    
    // Step 4: Find the start station index
    int start_index = 0;
    int current_gas = 0;
    
    for (int i = 0; i < N; ++i) {
        current_gas += gas[i] - cost[i];
        
        // If current_gas goes negative, reset start_index to the next station
        if (current_gas < 0) {
            start_index = i + 1;
            current_gas = 0;
        }
    }
    
    return start_index;
}

int main() {
    vector<string> strArr = {"4", "4:5", "2:4", "3:3", "5:2"};
    int result = ArrayChallenge(strArr);
    if (result != -1) {
        cout << "Start at station " << result << endl;
    } else {
        cout << "Not possible to complete the circuit" << endl;
    }
    return 0;
}
