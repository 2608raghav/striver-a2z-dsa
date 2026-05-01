/*
Problem: Rotate a linked list to the right by k places
Platform: Leetcode
Topic: Linked List

Approach:
1. We will first find the length of the linked list and the last node of the linked list.
2. We will then connect the last node to the head of the linked list to make it a circular linked list.
3. We will then find the new head of the linked list by moving (length - k % length) steps from the last node.
4. Finally, we will break the circular linked list by setting the next pointer of the new tail node to NULL and return the new head of the linked list.

Time Complexity: O(n) since we need to traverse the linked list once to find its length and the last node, and then we need to traverse the linked list again to find the new head and break the circular linked list.
Space Complexity: O(1) since we are using a constant amount of space to store the temporary variables and update the pointers.
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL || k==0){
            return head;
        }
        else{
            ListNode* curr = head;
            int length = 1;
            while(curr->next!=NULL){
                curr = curr->next;
                length++;
            }
            curr->next = head; // Connect the last node to the head to make it a circular linked list
            int newHeadPos = length - k % length; // Find the new head position
            for(int i=0;i<newHeadPos;i++){
                curr = curr->next; // Move to the new head position
            }
            ListNode* newHead = curr->next; // The new head of the linked list
            curr->next = NULL; // Break the circular linked list
            return newHead; // Return the new head of the linked list
        }
    }
};
