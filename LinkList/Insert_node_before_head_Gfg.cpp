/*
Problem: Insert a node before the head of the linked list
Platform: GeeksforGeeks
Topic: Linked List

Approach:
1. We will create a new node with the given value.
2. We will set the next pointer of the new node to point to the current head of the linked list.
3. Finally, we will update the head of the linked list to be the new node.

Time Complexity: O(1) since we are only inserting a new node at the beginning of the linked list.
Space Complexity: O(1) since we are using a constant amount of space to store the new node.

*/

#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};  
Node* insertBeforeHead(Node* head, int val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    return newNode; // The new node is now the head of the linked list
}