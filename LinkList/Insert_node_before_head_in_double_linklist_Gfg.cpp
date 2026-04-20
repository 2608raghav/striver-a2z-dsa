/*
Problem: Insert a node before the head in a double linked list
Platform: GeeksforGeeks
Topic: Linked List

Approach:
1. We can create a new node with the given value.
2. We will set the next pointer of the new node to point to the current head of the linked list.
3. We will also set the previous pointer of the current head to point to the new node.
4. Finally, we will update the head of the linked list to be the new node.

Time Complexity: O(1) since we are inserting the new node at the head of the linked list, which takes constant time.
Space Complexity: O(1) since we are using a constant amount of space to create the new node and update the head pointer.

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
Node* insertBeforeHead(Node* head, int val) {
    Node* newNode = new Node(val);
    if (head == nullptr) {
        return newNode; 
    }
    newNode->next = head; 
    head->prev = newNode; 
    return newNode; 
}