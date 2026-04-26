/*
Problem: Find the intersection point of Y shaped linked lists
Platform: Leetcode
Topic: Linked List

Approach:
1. We will first calculate the lengths of both linked lists by traversing them until we reach the end. We will keep a count of the number of nodes in each list.
2. After we have the lengths of both linked lists, we will find the difference in lengths. This will help us determine how many nodes we need to skip in the longer linked list to align both lists at the same starting point for comparison.
3. We will then move the pointer of the longer linked list ahead by the difference in lengths to align both pointers at the same distance from the end of the lists.
4. Finally, we will traverse both linked lists simultaneously, comparing the nodes at each step. If we find a node that is the same in both lists (i.e., they point to the same memory location), that node is the intersection point. If we reach the end of both lists without finding an intersection, we will return null.

Time Complexity: O(n) since we are traversing both linked lists to calculate their lengths and then traversing them again to find the intersection point.
Space Complexity: O(1) since we are using a constant amount of space to store the pointers and counters for traversal.

*/


#include <bits/stdc++.h>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;
        int ctr1 = 0;
        int ctr2 =0;
        while(temp1!=NULL){
              temp1 = temp1->next;
              ctr1++;
        }
        while(temp2!=NULL){
            temp2 = temp2->next;
            ctr2++;
        }
        temp1 = headA;
        temp2 = headB;
        while(ctr1!=ctr2){
            if(ctr1>ctr2){
                ctr1--;
                temp1 = temp1->next;
            }
            else{
                ctr2--;
                temp2 = temp2->next;
            }
        }
        while(ctr1!=0){
            if(temp1==temp2){
                return temp1;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
            ctr1--;
            
        }

        return NULL;
    }
};