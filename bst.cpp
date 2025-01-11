#include<iostream>
using namespace std;

struct  Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val): data(val), left(nullptr), right(nullptr) { 

       }
};

class BST{
    private:
        Node *root;

        Node *insert(Node *node, int val) {
            if (node == nullptr) {
                return new Node(val);
            }
            if (val < node->data) {
                node->left = insert(node->left, val);
            } else {
                node->right = insert(node->right, val);
            }
            return node;
        }
        bool search(Node*node, int val) {
            if (node == nullptr) {
                return false;
            } else if (val == node->data) {
                return true;
            } else if (val < node->data) {
                return search(node->left, val);
            } else {
                return search(node->right, val);
            }
        }
        void inorder(Node *node) {
            if (node != nullptr) {
                inorder(node->left);
                cout << node->data << " ";
                inorder(node->right);
            }
        }
        
    public:
        //Define the Constructor
        BST():root(nullptr) {}

        //Insert value in Tree
        void insert(int val) {
            root = insert(root, val);
        }

        //Search opeation
        bool search(int val) {
            return search(root, val);
        }

        //Display data from Tree in-order.
        void display() {
            inorder(root);
            cout << endl;
        }
};


int main() {
    BST b;
    b.insert(100);
    b.insert(10);
    b.insert(120);
    b.insert(88);
    b.insert(111);
    b.display();
    cout << "is found 100 in BST "<< b.search(100) << endl;
    cout << "is found 300 in BST "<< b.search(300) << endl;
    return 0;
}