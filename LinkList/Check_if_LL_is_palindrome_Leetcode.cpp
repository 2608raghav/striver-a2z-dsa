/*
Problem: Check if a Linked List is a palindrome
Platform: Leetcode
Topic: Linked List

Approach:
1. We will use a two-pointer approach to find the middle of the linked list.
2. We will initialize two pointers, slow and fast, both starting at the head of the linked list.
3. We will move the slow pointer one step at a time and the fast pointer two steps at a time until the fast pointer reaches the end of the linked list. This way, the slow pointer will be at the middle of the linked list.
4. We will then reverse the second half of the linked list starting from the slow pointer.
5. We will compare the first half and the reversed second half node by node. If all nodes match, the linked list is a palindrome.

Time Complexity: O(n) since we are traversing the linked list twice, which takes linear time.
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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* current = head;
        while (current != nullptr) {
            ListNode* nextTemp = current->next; // Store the next node
            current->next = prev; // Reverse the current node's pointer
            prev = current; // Move prev to the current node
            current = nextTemp; // Move to the next node
        }
        return prev; // New head of the reversed list
    }

    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return true; // A single node or empty list is a palindrome
        }

        
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* secondHalfHead = reverseList(slow);

      
        ListNode* firstHalfHead = head;
        while (secondHalfHead != nullptr) {
            if (firstHalfHead->val != secondHalfHead->val) {
                return false; // Not a palindrome
            }
            firstHalfHead = firstHalfHead->next;
            secondHalfHead = secondHalfHead->next;
        }

        return true; // The linked list is a palindrome
    }
};