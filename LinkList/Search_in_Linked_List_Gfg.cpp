/*
Problem: Search in Linked List
Platform: GeeksforGeeks
Topic: Linked List

Approach:
1. We will check if the head of the linked list is null. If it is null, we can simply return false since there are no nodes in the list to search.
2. If the head is not null, we will initialize a pointer to the head of the linked list.
3. We will traverse the linked list from the head node to the last node, comparing the data of each node with the target value we are searching for.
4. If we find a node with the data equal to the target value, we can return true since we have found the target in the linked list.
5. If we reach the end of the linked list without finding the target value, we will return false since the target value is not present in the linked list.

Time Complexity: O(n) since we may need to traverse the entire linked list in the worst case to find the target value or determine that it is not present.
Space Complexity: O(1) since we are using a constant amount of space to store the pointer for traversal and the target value.

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

bool search(Node* head, int target) {
    if (head == nullptr) {
        return false;
    }
    Node* current = head;
    while (current != nullptr) {
        if (current->data == target) {
            return true;
        }
        current = current->next;
    }
    return false;
}

