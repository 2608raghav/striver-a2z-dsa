/*
Problem: Sort a linked list of 0s, 1s and 2s
Platform: GeeksforGeeks
Topic: Linked List

Approach:
1. We will count the number of 0s, 1s and 2s in the linked list by traversing it once.
2. We will then traverse the linked list again and update the values of the nodes based on the count of 0s, 1s and 2s. We will first update the nodes with 0s, then with 1s and finally with 2s.

Time Complexity: O(n) since we need to traverse the linked list twice, where n is the number of nodes in the linked list.
Space Complexity: O(1) since we are using a constant amount of space to store the count of 0s, 1s and 2s and update the values of the nodes.
*/

#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node *next;
    Node() : data(0), next(nullptr) {}
    Node(int x) : data(x), next(nullptr) {}
    Node(int x, Node *next) : data(x), next(next) {}
};
class Solution {
public:
    Node* segregate(Node *head) {
        int count0 = 0, count1 = 0, count2 = 0; // Counters for 0s, 1s and 2s
        Node* curr = head; // Pointer to traverse the linked list

        // Step 1: Count the number of 0s, 1s and 2s in the linked list
        while (curr != nullptr) {
            if (curr->data == 0) {
                count0++;
            } else if (curr->data == 1) {
                count1++;
            } else if (curr->data == 2) {
                count2++;
            }
            curr = curr->next; // Move to the next node
        }

        curr = head; // Reset the pointer to the head of the linked list

        // Step 2: Update the values of the nodes based on the count of 0s, 1s and 2s
        while (curr != nullptr) {
            if (count0 > 0) {
                curr->data = 0; // Update node value to 0
                count0--;
            } else if (count1 > 0) {
                curr->data = 1; // Update node value to 1
                count1--;
            } else if (count2 > 0) {
                curr->data = 2; // Update node value to 2
                count2--;
            }
            curr = curr->next; // Move to the next node
        }

        return head; // Return the head of the modified linked list
    }
};