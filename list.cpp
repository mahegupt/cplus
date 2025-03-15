#include <iostream>
using namespace std;

// Definition for a singly-linked list node
class ListNode {
public:
    int val;
    ListNode* next;
    
    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};


ListNode *create_list(int *array, int size) {
    if (size==0) {
        return nullptr;
    }
    ListNode *head = new ListNode(array[0]);
    ListNode * current = head;
    for(int i=1; i<size; i++) {
        current->next = new ListNode(array[i]);
        current = current->next;
    }
    return head;
}

ListNode *reverse_list(ListNode *head) {
    ListNode * current = head;
    ListNode *prev = nullptr;
    if (!head or !head->next) {
        return head;
    }
    ListNode *next =  current->next;
    while(current) {        
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

//This takes 0(n) and space 0(n)
ListNode *recursive_reverse_list(ListNode *head) {
    if (!head || !head->next) {
        return head;
    } 
    ListNode *rest = recursive_reverse_list(head->next);
    head->next->next = head;
    head->next = nullptr;
    return rest;
}
//Given the head of a linked list, rotate the list to the right by k places.
ListNode* rotateRight(ListNode* head, int k) {
    if (!head || !head->next || k==0) {
        return head;
    }
    //Find length of linklist, Make the list a circuler, find the new head position after adjusting k, disconnect it.
    int length = 1;
    ListNode *current = head;
    while(current->next) {
        ++length;
        current = current->next;
    }
    //Make the circuler list
    current->next = head;

    //Find new position of head;
    k  = k % length;
    int newHeadPosition = length - k - 1;
    current = head;
    for(int i=0; i<newHeadPosition; ++i) {
        current = current->next;
    }
    // Disconnect the head;
    ListNode *newHead = current->next;
    current->next = nullptr;
    return newHead;
}

void print_list(ListNode *head) {
    if (head) {
        while(head->next) {
            cout << head->val << " ->";
            head = head ->next;
        }
        cout << head->val << "\n";
    }
}
int main() {
    int array[] = {2,1,4,5,6,7,11,22};
    int size = sizeof(array)/sizeof(array[0]);
    ListNode *head = create_list(array, size);
    print_list(head);
    head = reverse_list(head);
    print_list(head);
    head = recursive_reverse_list(head);
    print_list(head);
    int k=3;
    head = rotateRight(head, k);
    print_list(head);
}