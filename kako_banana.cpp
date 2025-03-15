#include <iostream>
#include <vector>
#include <cmath>  // For ceil()
#include <algorithm> // For max_element

using namespace std;

// Function to check if Koko can eat all bananas within h hours at speed k
bool canEatAll(vector<int>& piles, int h, int k) {
    long long  hours = 0;
    for (int bananas : piles) {
        hours += ceil((double)bananas / k);  // Each pile takes ceil(pile/k) hours
    }
    return hours <= h;
}

// Function to find the minimum k using binary search
int minEatingSpeed(vector<int>& piles, int h) {
    int left = 1, right = *max_element(piles.begin(), piles.end());
    int result = right;  // Maximum possible speed initially

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (canEatAll(piles, h, mid)) {
            result = mid;  // Store the minimum valid speed
            right = mid - 1;  // Try a smaller speed
        } else {
            left = mid + 1;  // Increase speed
        }
    }

    return result;
}

// Driver Code
int main() {
    vector<int> piles = {805306368,805306368,805306368};
    int h = 1000000000;
    cout << "Minimum eating speed: " << minEatingSpeed(piles, h) << endl;
    return 0;
}
