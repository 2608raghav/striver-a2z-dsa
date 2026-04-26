/*
Problem: Add one to a number represented by a linked list
Platform: GeeksforGeeks
Topic: Linked List

Approach:
1. We will first reverse the linked list to make it easier to add one to the number represented by the linked list.
2. We will initialize a carry variable to 1 since we want to add one to the number.
3. We will then traverse the reversed linked list and add the carry to the value of each
    node. If the sum is less than 10, we will update the value of the node and set the carry to 0 since we don't need to add anything to the next node. If the sum is 10 or greater, we will update the value of the node to sum % 10 and keep the carry as 1 to add to the next node.
4. After we have traversed the entire linked list, if there is still a carry of 1, we will create a new node with value 1 and add it to the end of the linked list.
5. Finally, we will reverse the linked list again to restore the original order and return the head of the modified linked list.

Time Complexity: O(n) since we are traversing the linked list three times (reversing, adding one, and reversing again), where n is the number of nodes in the linked list.
Space Complexity: O(1) since we are using a constant amount of space to store the carry variable and temporary pointers for traversal and reversal.

*/

#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
class Solution {
public:
    Node* reverseList(Node* head) {
        Node* prev = nullptr;
        Node* current = head;
        while (current != nullptr) {
            Node* nextTemp = current->next; // Store the next node
            current->next = prev; // Reverse the current node's pointer
            prev = current; // Move prev to the current node
            current = nextTemp; // Move to the next node
        }
        return prev; // New head of the reversed list
    }

    Node* addOne(Node* head) {
        head = reverseList(head); // Step 1: Reverse the linked list

        Node* current = head;
        int carry = 1; // Initialize carry to 1 since we want to add one

        while (current != nullptr && carry > 0) {
            int sum = current->data + carry; // Add carry to the current node's value
            current->data = sum % 10; // Update the node's value to sum % 10
            carry = sum / 10; // Update carry to sum / 10

            if (current->next == nullptr && carry > 0) {
                current->next = new Node(carry); // If we are at the end and still have a carry, add a new node
                carry = 0; // Reset carry after adding the new node
            }
            current = current->next; // Move to the next node
        }

        return reverseList(head); // Step 5: Reverse the linked list again to restore original order
    }
};
