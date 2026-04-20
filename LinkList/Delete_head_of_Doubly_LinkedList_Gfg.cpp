/*
Problem: Delete head of a doubly linked list
Platform: GeeksforGeeks
Topic: Linked List

Approach:
1. We can check if the head of the linked list is null. If it is null, we can simply return null since there is nothing to delete.
2. If the head is not null, we can store the current head in a temporary variable.
3. We will then update the head of the linked list to be the next node of the current head.
4. If the new head is not null, we will set its previous pointer to null since it will become the new head of the linked list.
5. Finally, we will delete the temporary variable that stored the old head to free up memory

Time Complexity: O(1) since we are deleting the head of the linked list, which takes constant time.
Space Complexity: O(1) since we are using a constant amount of space to store the temporary variable and update the head pointer.

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

Node* deleteHead(Node* head) {
    if (head == nullptr) {
        return nullptr; 
    }
    Node* temp = head; 
    head = head->next; 
    if (head != nullptr) {
        head->prev = nullptr; 
    }
    delete temp; 
    return head; 
}