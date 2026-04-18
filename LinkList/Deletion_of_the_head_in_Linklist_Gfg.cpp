/*
Problem: Deletion of the head in Linked List
Platform: GeeksforGeeks
Topic: Linked List

Approach:
1. We will check if the head of the linked list is null. If it is null, we can simply return null since there is nothing to delete.
2. If the head is not null, we will store the current head in a temporary variable.
3. We will then update the head of the linked list to point to the next node in the list.
4. Finally, we will delete the temporary variable to free up the memory used by the old head node.

Time Complexity: O(1) since we are only updating the head pointer and deleting one node, which takes constant time.
Space Complexity: O(1) since we are using a constant amount of space to store the temporary variable and update the head pointer.

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
Node* deleteHead(Node* head) {
    if (head == nullptr) {
        return nullptr;
    }
    Node* temp = head; // Store the current head in a temporary variable
    head = head->next; // Update the head to point to the next node
    delete temp; // Delete the old head node to free up memory
    return head; // Return the new head of the linked list
}