#include<iostream>
#include<cstdlib>
#include <queue>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode *next;
    public:
    TreeNode(int x): data(x), left(NULL), right(NULL), next(NULL) {}
};

TreeNode* insert(TreeNode *root, int val) {
    TreeNode *node = new TreeNode(val);
    if (!root) return node;
    TreeNode *tmp = root;
    TreeNode *parent = NULL;
    while(tmp) {
        parent = tmp;
        if (val < tmp->data) {
            tmp = tmp->left;
        } else {
            tmp = tmp ->right;
        }
    }
    if (val < parent->data) {
        parent->left = node;
    } else {
        parent->right = node;
    }
    return root;
}

void print_inorder(TreeNode *root) {
    if (root) {
        print_inorder(root->left);
        cout << root->data << " ";
        print_inorder(root->right);        
    } 
}

void print_level_by_level_bst(TreeNode *root) {
    if (!root) return ;

    queue<TreeNode*> q;

    q.push(root);
    while(!q.empty()) {
        int levelSize = q.size(); // Number of node at any given level;

        for(int i=0; i<levelSize; ++i) {
            TreeNode *current = q.front();
            q.pop();

            cout << current->data << " ";
            
            if (current->left) {
                q.push(current->left);
            } 
            if (current->right) {
                q.push(current->right);
            }             
        }
        cout << endl;
    }
}


// Connect nodes at the same level using BFS
void connectNextPointers(TreeNode* root) {
    if (!root) return;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();
        TreeNode* prev = NULL;  // Track the previous node at the level

        for (int i = 0; i < levelSize; i++) {
            TreeNode* cur = q.front();
            q.pop();

            if (prev) {
                prev->next = cur; // Link previous node to current
            }
            prev = cur;

            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }

        prev->next = NULL; // Last node in the level points to NULL
    }
}

void printNextPointers(TreeNode *root) {    
    TreeNode *start = root;
    while(start) {
        TreeNode *temp = start;
        while(temp) {
            cout << temp->data <<" -> ";
            temp = temp->next;
        }
        cout << "NULL \n";

        if (start->left) {
            start = start->left;
        } else if (start->right) {
            start = start->right;
        } else {
            break;
        }
    }
}
int main() {
    TreeNode *root = NULL;
    cout << "Creating tree dynomically with values\n" ;
    srand((unsigned) time(NULL));
    for (int i=0; i<10; ++i) {
        int val = rand()%200;
        cout << val << " ";
        root = insert(root, val);
    }
    cout << endl;
    print_inorder(root);
    cout << endl;
    cout << "Level by level print 1"<<endl;
    print_level_by_level_bst(root);
    connectNextPointers(root);
    cout << "Level by level print 2"<<endl;
    printNextPointers(root);
}