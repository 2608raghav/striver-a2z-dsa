/*
Problem: Reverse a Linked List
Platform: Leetcode
Topic: Linked List

Approach:
1. We can initialize three pointers: prev, current, and next. We will set prev to null and current to the head of the linked list.
2. We will then iterate through the linked list until current becomes null.
3. In each iteration, we will store the next node of current in the next pointer.
4. We will then reverse the next pointer of current to point to prev.
5. Finally, we will update prev to be current and current to be next.

Time Complexity: O(n) since we are iterating through the linked list once, where n is the number of nodes in the linked list.
Space Complexity: O(1) since we are using a constant amount of space to store the three pointers.

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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* current = head;
        ListNode* next = nullptr;
        
        while (current != nullptr) {
            next = current->next; 
            current->next = prev; 
            prev = current; 
            current = next; 
        }
        
        return prev; 
    }
};