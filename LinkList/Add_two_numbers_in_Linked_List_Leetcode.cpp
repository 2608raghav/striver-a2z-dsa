/*
Problem: Add two numbers represented by linked lists
Platform: Leetcode
Topic: Linked List

Approach:
1. We will initialize a dummy node to help us build the resulting linked list and a current pointer to keep track of the last node in the result list.
2. We will also initialize a carry variable to keep track of any carry that may occur during the addition of two digits.
3. We will iterate through both linked lists until we reach the end of both lists and there is no carry left.
4. In each iteration, we will calculate the sum of the current digits from both linked lists and the carry.
5. We will create a new node with the value of the sum modulo 10 and set the next pointer of the current node to this new node.
6. We will update the carry to be the sum divided by 10 (integer division).
7. Finally, we will return the next pointer of the dummy node, which will be the head of the resulting linked list.

Time Complexity: O(max(m, n)) where m and n are the lengths of the two linked lists, since we need to traverse both lists once.
Space Complexity: O(max(m, n)) since we are creating a new linked list to store the result, which in the worst case can have a length equal to the maximum of the two input lists plus one additional node for any carry that may occur.

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* current = dummyHead;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = carry;
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }

            current->next = new ListNode(sum % 10);
            current = current->next;
            carry = sum / 10;
        }

        return dummyHead->next; // Return the head of the resulting linked list
    }
};

