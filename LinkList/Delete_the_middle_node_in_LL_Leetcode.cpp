/*
Problem: Delete the middle node in a Linked List
Platform: Leetcode
Topic: Linked List

Approach:
1. We will use the two-pointer technique to find the middle node of the linked list. We will initialize two pointers, slow and fast, to point to the head of the linked list.
2. We will move the fast pointer two steps at a time and the slow pointer one step at a time until the fast pointer reaches the end of the linked list or has no next node.
3. At this point, the slow pointer will be pointing to the middle node of the linked list.
4. We will then delete the middle node by updating the next pointer of the node before the middle node to point to the node after the middle node.

Time Complexity: O(n) since we are traversing the linked list once to find the middle node and delete it.
Space Complexity: O(1) since we are using a constant amount of space to store the pointers for traversal and deletion.

*/

#include <bits/stdc++.h>
using namespace std;
    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return nullptr; // If the list is empty or has only one node, return null
        }

        ListNode* slow = head; // Slow pointer to find the middle node
        ListNode* fast = head; // Fast pointer to traverse the list
        ListNode* prev = nullptr; // Pointer to keep track of the node before the middle node

        while (fast != nullptr && fast->next != nullptr) {
            prev = slow; // Update prev to the current slow node
            slow = slow->next; // Move slow pointer one step
            fast = fast->next->next; // Move fast pointer two steps
        }

        prev->next = slow->next; // Delete the middle node by updating the next pointer of the previous node
        delete slow; // Free up memory used by the middle node

        return head; // Return the head of the modified linked list
    }
};
