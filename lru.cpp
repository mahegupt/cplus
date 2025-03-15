// C++ program to implement LRU Least Recently Used)
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    int value;
    Node *next;
    Node *prev;

    Node(int k, int v) {
        key = k;
        value = v;
        next = nullptr;
        prev = nullptr;
    }
};

// LRU Cache class
class LRUCache
{
  public:
  
    // Constructor to initialize the cache with a given capacity
    int capacity;
    unordered_map<int, Node *> cacheMap;
    Node *head;
    Node *tail;
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    // Function to get the value for a given key
    int get(int key) {
      
        if (cacheMap.find(key) == cacheMap.end())
            return -1;
  

        Node *node = cacheMap[key];
        remove(node);
        add(node);
        return node->value;
    }

    // Function to put a key-value pair into the cache
    void put(int key, int value) {
        if (cacheMap.find(key) != cacheMap.end()) {
            Node *oldNode = cacheMap[key];
            remove(oldNode);
              delete oldNode;
          
        }

        Node *node = new Node(key, value);
        cacheMap[key] = node;
        add(node);
       
       
        if (cacheMap.size() > capacity) {
            Node *nodeToDelete = tail->prev;
            remove(nodeToDelete);
            cacheMap.erase(nodeToDelete->key);
              delete nodeToDelete;
        }
    }

    // Add a node right after the head 
      // (most recently used position)
    void add(Node *node) {
        Node *nextNode = head->next;
        head->next = node;
        node->prev = head;
        node->next = nextNode;
        nextNode->prev = node;
    }

    // Remove a node from the list
    void remove(Node *node) {
        Node *prevNode = node->prev;
        Node *nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }
};

int main(){
    LRUCache cache(4);
  
    cache.put(1, 1); 
    cache.put(2, 2);
    cout << cache.get(1) << endl;
    cache.put(3, 3);
    cout  << cache.get(2) << endl;
    cache.put(4, 4);
    cout << cache.get(1) << endl;
    cout << cache.get(3) << endl;
    cout << cache.get(4) << endl;

    return 0;
}
