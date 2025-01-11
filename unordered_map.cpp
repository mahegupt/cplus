#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    // Declare an unordered_map
    unordered_map<string, int> umap;

    // Insert key-value pairs
    umap["apple"] = 5;
    umap["banana"] = 10;
    umap["orange"] = 7;

    // Access elements using keys
    cout << "apple: " << umap["apple"] << endl;  // Output: apple: 5

    // Check if a key exists
    if (umap.find("banana") != umap.end()) {
        cout << "banana is in the map!" << endl;
    }

    // Iterate through the unordered_map
    for (const auto &pair : umap) {
        cout << pair.first << ": " << pair.second << endl;
    }

    // Erase a key
    umap.erase("orange");

    // Check size of the map
    cout << "Size: " << umap.size() << endl;

    return 0;
}
