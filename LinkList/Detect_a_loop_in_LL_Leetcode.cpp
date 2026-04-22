/*
Problem: Find the start of the cycle in Linked List (if exists)
Platform: Leetcode
Topic: Linked List

Approach:
1. We will use the Floyd’s Cycle Detection Algorithm, also known as the Tortoise and Hare algorithm.
2. We will initialize two pointers, slow and fast, both starting at the head of the linked list.
3. We will move the slow pointer one step at a time and the fast pointer two steps at a time.
4. If there is a loop in the linked list, the fast pointer will eventually meet the slow pointer.
5. If there is no loop, the fast pointer will reach the end of the linked list (null) before the slow pointer.
6. If a cycle is detected, reset slow to head and move both pointers one step at a time until they meet again. The meeting point is the start of the cycle.

Time Complexity: O(n) in the worst case, where n is the number of nodes in the linked list, since we may need to traverse the entire list to detect a loop.
Space Complexity: O(1) since we are using only a constant amount of extra space for the two pointers.
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
       ListNode* detectCycle(ListNode *head) {
        if(head == NULL){
            return nullptr;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                // Find the start of the cycle
                slow = head;
                while(slow != fast){
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return nullptr;

    }
};