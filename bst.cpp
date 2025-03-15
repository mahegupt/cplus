#include<iostream>
#include<climits>
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

        void postorder(Node *node) {
            if (node != nullptr) {
                postorder(node->left);
                postorder(node->right);
                cout << node->data << " ";
            }
        }
        void preorder(Node *node) {
            if (node != nullptr) {
                cout << node->data << " ";
                postorder(node->left);
                postorder(node->right);                
            }
        }
        tuple<int, int>min_max_in_bst(Node *node) {
            int min = 0;
            int max = 0;
            Node *tNode = node;
            while (tNode->left) {
                tNode = tNode->left;
            }
            min = tNode->data;
            
            tNode = node;
            while (tNode->right) {
                tNode = tNode->right;
            }
            max = tNode->data;
            return {min, max};
        }
        //Inorder traversal (Left → Root → Right) of a BST gives the elements in sorted order, keep reducing k till it become 0.
        int kthSmallestElement(Node*node, int &k) {
            if (node == nullptr) {                
                return -1;
            }
            int left = kthSmallestElement(node->left, k);
            if (k == 0) return left;
            k--;
            if (k == 0) return node->data;
            return kthSmallestElement(node->right, k);
        }

        //Postorder traversal (Left → Root → Right) of a BST gives the elements in sorted order, keep reducing k till it become 0.
        int kthLargestElement(Node*node, int &k) {
            if (node == nullptr) {                
                return -1;
            }
            int right = kthLargestElement(node->right, k);
            if (k == 0) return right;
            k--;
            if (k == 0) return node->data;
            return kthLargestElement(node->left, k);
        }

        int lowestCommonAncestor(Node *node, int p, int q) {
            if (node == nullptr) {
                return -1;
            } else if (p<node->data && q>node->data) {
                return node->data;
            } else if (p>node->data && q>node->data) {
                return lowestCommonAncestor(node->right, p, q);
            } else {
                return lowestCommonAncestor(node->left, p, q);
            }
        }

        bool isBSThelper(Node *root, int min, int max) {
            if (root == nullptr) {
                return true;
            } else if (root->data>max || root->data<min) {
                return false;
            } else {
                return isBSThelper(root->left, min, root->data) || isBSThelper(root->right, root->data, max);
            }
        }

        bool isBST(Node *root){            
            return isBSThelper(root, INT_MIN, INT_MAX);
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
        void display_inorder() {
            inorder(root);
            cout << endl;
        }

        void display_postorder() {
            postorder(root);
            cout << endl;
        }
        void display_preorder() {
            preorder(root);
            cout << endl;
        }

        tuple<int, int> min_max_in_bst() {
            return min_max_in_bst(root);
        }

        int kthSmallestElement(int k) {
            //Find the kth smallest element in Tree.
            return kthSmallestElement(root, k);
        }
        int kthLargestElement(int k) {
            //Find the kth largest element in Tree.
            return kthLargestElement(root, k);
        }

        int lowestCommonAncestor(int p, int q) {
            //Find the lowest common ancestor of given value p and q.
            return lowestCommonAncestor(root, p, q);
        }

        bool isBST() {
            return isBST(root);
        }
};


int main() {
    BST b;
    b.insert(100);
    b.insert(10);
    b.insert(120);
    b.insert(88);
    b.insert(111);
    b.insert(101);
    b.insert(21);
    b.insert(28);
    b.insert(18);
    b.insert(98);
    cout << "The inorder display" << endl;
    b.display_inorder();
    cout << "The preorder display" << endl;
    b.display_postorder();
    cout << "The postorder display" << endl;    
    b.display_preorder();
    cout << "is found 100 in BST "<< b.search(100) << endl;
    cout << "is found 300 in BST "<< b.search(300) << endl;
    auto [min, max] = b.min_max_in_bst();
    cout << "In BST the min = "<< min <<" max = "<<max<<endl;
    
    cout << "4th smallest and largest elements are: "<<b.kthSmallestElement(4) << " and "
        << b.kthLargestElement(4) << endl;
    int p=88;
    int q=111;
    cout << "lowest common ancester of " << p << " and " << q << " are: "<< b.lowestCommonAncestor(p, q) << endl;
    cout << "IsBST " << b.isBST() << endl;
    return 0;
}