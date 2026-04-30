/*
Problem: Reverse a linked list in groups of given size K
Platform: Leetcode
Topic: Linked List

Approach:
1. We will use three pointers: prev, curr, and next to reverse the linked list in groups of size K.
2. We will first reverse the first K nodes of the linked list and keep track of the next pointer of the last node in the reversed group.
3. We will then recursively call the function to reverse the remaining linked list starting from the next pointer of the last node in the reversed group.
4. Finally, we will connect the last node of the reversed group to the head of the next reversed group and return the new head of the linked list.

Time Complexity: O(n) since we need to traverse the linked list once to reverse it in groups of size K.
Space Complexity: O(n/k) since we are using a recursive approach and the maximum depth of the recursion will be n/k when we reverse the linked list in groups of size K.
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL){
            return NULL;
        }
        else{
            ListNode* prev = NULL;
            ListNode* curr = head;
            ListNode* next = NULL;
            int count = 0;
            while(curr!=NULL && count<k){
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
                count++;
            }
            if(next!=NULL){
                head->next = reverseKGroup(next,k);
            }
            return prev;
        }
    }
};