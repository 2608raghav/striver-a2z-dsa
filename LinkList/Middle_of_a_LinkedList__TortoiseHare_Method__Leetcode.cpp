/*
Problem: Middle Of a LinkedList
Platform: Leetcode
Topic: Linked List

Approach:
1. We use a two-pass approach to find the middle node of the linked list.
2. First, we traverse the entire list to count the total number of nodes.
3. Then, we calculate the middle index as count/2 (integer division for 0-based indexing).
4. Finally, we traverse the list again from the head, moving 'mid' steps to reach the middle node and return it.

Time Complexity: O(n), where n is the number of nodes in the linked list, since we traverse the list twice.
Space Complexity: O(1), as we use only a constant amount of extra space for variables like temp, count, and mid.

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
    ListNode* middleNode(ListNode* head) {
        ListNode* temp = head;
        int count =0;
        while(temp!=NULL){
            count++;
            temp = temp->next;
        }
        int mid = count/2;
        temp = head;
        count =1;
        while(count<=mid){
            count++;
            temp = temp->next;

        }
        return temp;

    }
};