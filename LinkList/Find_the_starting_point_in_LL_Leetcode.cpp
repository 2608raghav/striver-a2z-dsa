/*
Problem: Find the starting point of the loop in a linked list
Platform: Leetcode
Topic: Linked List

Approach:
1. We will use the Floyd’s Cycle Detection Algorithm, also known as the Tortoise and Hare algorithm.
2. We will initialize two pointers, slow and fast, both starting at the head of the linked list.
3. We will move the slow pointer one step at a time and the fast pointer two steps at a time.
4. If there is a loop in the linked list, the fast pointer will eventually meet the slow pointer.
5. Once the fast and slow pointers meet, we will initialize another pointer, say 'start', at the head of the linked list.
6. We will then move both the 'start' pointer and the 'slow' pointer one step at a time until they meet. The point at which they meet will be the starting point of the loop.

Time Complexity: O(n) in the worst case, where n is the number of nodes in the linked list, since we may need to traverse the entire list to detect a loop and find its starting point.
Space Complexity: O(1) since we are using only a constant amount of extra space for the three pointers (slow, fast, and start).

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
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL){
            return NULL;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                ListNode* start = head;
                while(start!=slow){
                    start = start->next;
                    slow = slow->next;
                }
                return start;
            }
        }
        return NULL;

    }
};



