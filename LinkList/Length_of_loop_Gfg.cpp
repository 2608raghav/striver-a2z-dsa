/*
Problem: Length of loop in Linked List
Platform: GeeksforGeeks
Topic: Linked List

Approach:
1. We will use the Floyd’s Cycle Detection Algorithm, also known as the Tortoise and Hare algorithm, to detect if there is a loop in the linked list.
2. We will initialize two pointers, slow and fast, both starting at the head of the linked list.
3. We will move the slow pointer one step at a time and the fast pointer two steps at a time.
4. If there is a loop in the linked list, the fast pointer will eventually meet the slow pointer.
5. Once a loop is detected, we will keep one pointer at the meeting point and move the other pointer one step at a time until they meet again. We will count the number of steps taken to meet again, which will give us the length of the loop.


Time Complexity: O(n) in the worst case, where n is the number of nodes in the linked list, since we may need to traverse the entire list to detect a loop and count its length.
Space Complexity: O(1) since we are using only a constant amount of extra space for the two pointers and the counter.

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

int countNodesinLoop(Node* head) {
    if (head == nullptr) {
        return 0;
    }
    Node* slow = head;
    Node* fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            // Loop detected, now count the number of nodes in the loop
            int count = 1; // Start counting from the meeting point
            Node* temp = slow;
            while (temp->next != slow) {
                count++;
                temp = temp->next;
            }
            return count; // Return the length of the loop
        }
    }
    return 0; // No loop found
}