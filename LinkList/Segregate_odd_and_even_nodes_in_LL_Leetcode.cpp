/*
Problem: Segregate odd and even nodes in a Linked List
Platform: Leetcode
Topic: Linked List

Approach:
1. We will create two dummy nodes, one for odd and one for even, to help us build the two separate lists.
2. We will initialize two pointers, odd and even, to point to the dummy nodes.
3. We will traverse the original linked list using a pointer called current. For each node, we will check if its value is odd or even.
4. If the value is odd, we will append it to the odd list by setting odd->next to current and moving the odd pointer to the next node.
5. If the value is even, we will append it to the even list by setting even->next to current and moving the even pointer to the next node.
6. After we have traversed the entire linked list, we will connect the odd list to the even list by setting odd->next to evenDummy->next.
7. Finally, we will set even->next to nullptr to terminate the even list and return the head of the odd list, which is oddDummy->next.

Time Complexity: O(n) since we are traversing the linked list once to segregate the odd and even nodes.
Space Complexity: O(1) since we are using a constant amount of space to store the dummy nodes and pointers for traversal.

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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }

        ListNode* oddDummy = new ListNode(0); // Dummy node for odd positions
        ListNode* evenDummy = new ListNode(0); // Dummy node for even positions
        ListNode* odd = oddDummy; // Pointer to build the odd position list
        ListNode* even = evenDummy; // Pointer to build the even position list
        ListNode* current = head; // Pointer to traverse the original list
        int position = 1; // Track the position (1-indexed)

        while (current != nullptr) {
            if (position % 2 != 0) { // If the position is odd (1st, 3rd, 5th, ...)
                odd->next = current; // Append to odd position list
                odd = odd->next; // Move the odd pointer
            } else { // If the position is even (2nd, 4th, 6th, ...)
                even->next = current; // Append to even position list
                even = even->next; // Move the even pointer
            }
            current = current->next; // Move to the next node in the original list
            position++; // Increment position
        }

        odd->next = evenDummy->next; // Connect odd position list to even position list
        even->next = nullptr; // Terminate the even position list

        return oddDummy->next; // Return the head of the odd position list
    }
};