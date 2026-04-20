/*
Problem: Reverse a doubly linked list
Platform: GeeksforGeeks
Topic: Linked List

Approach:
1. We can initialize three pointers: prev, current, and next. We will set prev to null and current to the head of the linked list.
2. We will then iterate through the linked list until current becomes null.
3. In each iteration, we will store the next node of current in the next pointer.
4. We will then reverse the next pointer of current to point to prev.
5. We will also reverse the previous pointer of current to point to next.
6. Finally, we will update prev to be current and current to be next.

Time Complexity: O(n) since we are iterating through the linked list once, where n is the number of nodes in the linked list.
Space Complexity: O(1) since we are using a constant amount of space to store the three pointers.

*/

#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

Node* reverse(Node* head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;
    
    while (current != nullptr) {
        next = current->next; 
        current->next = prev; 
        current->prev = next; 
        prev = current; 
        current = next; 
    }
    
    return prev; 
}