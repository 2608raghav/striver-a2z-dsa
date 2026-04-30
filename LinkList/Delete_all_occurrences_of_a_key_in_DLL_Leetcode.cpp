/*
Problem: Delete all occurrences of a key in a doubly linked list
Platform: Leetcode
Topic: Linked List

Approach:
1. We will traverse the linked list and check if the current node's value matches the key we want to delete.
2. If it matches, we will update the next pointer of the previous node to point to the next node and update the previous pointer of the next node to point to the previous node.
3. We will also check if the current node is the head of the linked list, in which case we will update the head to be the next node.
4. We will continue traversing the linked list until we reach the end.

Time Complexity: O(n) since we need to traverse the linked list once to delete all occurrences of the key.
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
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL){
            return NULL;
        }
        else{
            ListNode* succ = head;
            ListNode* prev = NULL;
            ListNode* curr = head;
            while(succ->next!=NULL){
                succ = curr->next;
                if(succ->val==val){
                    curr->next = succ->next;
                }
                else{
                    prev = curr;
                    curr = succ;
                }
            }
        }
        if(head->val==val){
            head = head->next;
        }
        return head;
    }
};


