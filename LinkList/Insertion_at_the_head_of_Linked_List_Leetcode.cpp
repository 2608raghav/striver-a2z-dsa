/*
Problem: Insertion at the head of Linked List
Platform: LeetCode
Topic: Linked List

Approach:
1. We can create a new node with the given value.
2. We will set the next pointer of the new node to point to the current head of the linked list.
3. Finally, we will update the head of the linked list to be the new node.

Time Complexity: O(1) since we are inserting the new node at the head of the linked list, which takes constant time.
Space Complexity: O(1) since we are using a constant amount of space to create the new node and update the head pointer.

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