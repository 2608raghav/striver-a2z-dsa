/*
Problem: Find the length of the Linked List
Platform: GeeksforGeeks
Topic: Linked List

Approach:
1. We will check if the head of the linked list is null. If it is null, we can simply return 0 since there are no nodes in the list.
2. If the head is not null, we will initialize a counter to 0.
3. We will traverse the linked list from the head node to the last node, incrementing the counter for each node we visit.
4. Finally, we will return the counter value, which represents the length of the linked list.

Time Complexity: O(n) since we need to traverse the entire linked list to count the number of nodes.
Space Complexity: O(1) since we are using a constant amount of space to store the

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

int getLength(Node* head) {
    if (head == nullptr) {
        return 0;
    }
    int length = 0;
    Node* current = head;
    while (current != nullptr) {
        length++;
        current = current->next;
    }
    return length;
}
