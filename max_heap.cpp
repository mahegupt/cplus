// C++ Program for Implementing Max Heap
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Template for MaxHeap
template <typename T>
// Class for MaxHeap
class MaxHeap {
private:
    vector<T> array;  
    int size;
    int capacity;     

public:
    // Constructor to initialize the heap with a given capacity
     MaxHeap(int capacity) {
        this->size = 0;
        this->capacity = capacity;
        this->array.resize(capacity);
    }
    
    // Function to heapify the node at index i
    void heapify(int i) {
        int largest = i;           
        int left = 2 * i + 1;      
        int right = 2 * i + 2;     
        
        if (left < size && array[left] > array[largest])
            largest = left;

        
        if (right < size && array[right] > array[largest])
            largest = right;

        
        if (largest != i) {
            swap(array[i], array[largest]);  
            heapify(largest);               
        }
    }

    // Function to build a max heap from a given array
    void buildHeap(const vector<T>& arr) {
        capacity = arr.size();
        size = capacity;
        array = arr;

        // Build heap (rearrange array)
        for (int i = (size - 1) / 2; i >= 0; i--) {
            heapify(i);
        }
    }

    // Function to insert a new value into the heap
    void insert(T value) {
        if (size == capacity) {
            // Resize the heap if necessary
            capacity *= 2;
            array.resize(capacity);
        }

        size++;
        int i = size - 1;
        array[i] = value;

        // Fix the max heap property if it is violated
        while (i != 0 && array[(i - 1) / 2] < array[i]) {
            swap(array[i], array[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

  // Function to get the value of the root node of the max heap
    T top() {
        if (size <= 0)
        // Indicates that the heap is empty
            return -1; 

        return array[0];
    }

    // Function to remove and return the maximum value from the heap
    T pop() {
        if (size <= 0)
            return -1; 
        if (size == 1) {
            size--;
            return array[0];
        }

        // Store the maximum value, and remove it
        T root = array[0];
        array[0] = array[size - 1];
        size--;
        // Heapify the root node after deletion
        heapify(0);  
        return root;
    }

    // Function to delete a specific key from the heap
    void deleteKey(T key) {
        // Find the index of the key
        int index = -1;
        for (int i = 0; i < size; ++i) {
            if (array[i] == key) {
                index = i;
                break;
            }
        }
        // If key is not found, return
        if (index == -1) {
            cout << "Key not found" << endl;
            return;
        }

        // If the key is found, delete it
        // If it's the last element, simply reduce the size
        if (index == size - 1) {
            size--;
            return;
        }

        // Move the last element to the index of the key to be deleted
        array[index] = array[size - 1];
        size--;

        // Heapify down to maintain heap property
        heapify(index);
    }

    // Function to print the heap
    void print() const {
        cout << "Max Heap: ";
        for (int i = 0; i < size; ++i)
            cout << array[i] << " ";
        cout << endl;
    }
};

  int main() {
      // Create a MaxHeap with initial capacity of 6
      MaxHeap<int> maxHeap(6);
      vector<int> arr = {2, 3, 4, 5, 10, 15};

      // Build the heap from the array
      maxHeap.buildHeap(arr);

      // Print the max heap
      maxHeap.print();

      // Insert a node into the heap
      maxHeap.insert(9);
      cout << "After inserting 9: " << endl;
      maxHeap.print();

      // Get the maximum value from the max heap
      cout << "Top value: " << maxHeap.top() << endl;

      // Delete the root node of the max heap
      cout << "Popped value: " << maxHeap.pop() << endl;
      cout << "After popping: ";
      maxHeap.print();

      // Delete a specific value from the max heap
      maxHeap.deleteKey(5);
      cout << "After deleting the node 5: ";
      maxHeap.print();

      return 0;
  }