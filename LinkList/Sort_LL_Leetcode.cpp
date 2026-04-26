/*
Problem: Sort a linked list in O(n log n) time using constant space complexity.
Platform: Leetcode
Topic: Linked List

Approach:
1. We will use the merge sort algorithm to sort the linked list. Merge sort is a divide-and-conquer algorithm that divides the list into two halves, sorts each half recursively, and then merges the sorted halves back together.
2. We will implement a helper function to find the middle of the linked list using the slow and fast pointer technique.
3. We will implement a helper function to merge two sorted linked lists into one sorted linked list
4. In the main function, we will recursively split the linked list until we reach base cases (lists of length 0 or 1), and then merge the sorted halves back together.

Time Complexity: O(n log n) since we are dividing the list into halves log n times and merging takes O(n) time.
Space Complexity: O(1) since we are using a constant amount of space for the pointers

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
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head; // Base case: if the list is empty or has only one node, it's already sorted
        }

        // Step 1: Split the linked list into halves
        ListNode* mid = getMiddle(head); // Get the middle node
        ListNode* leftHalf = head; // Left half starts from head
        ListNode* rightHalf = mid->next; // Right half starts from the node after the middle
        mid->next = nullptr; // Split the linked list into two halves

        // Step 2: Recursively sort both halves
        leftHalf = sortList(leftHalf); // Sort the left half
        rightHalf = sortList(rightHalf); // Sort the right half

        // Step 3: Merge the sorted halves
        return merge(leftHalf, rightHalf); // Merge and return the sorted list
    }
private:
    ListNode* getMiddle(ListNode* head) {
        ListNode* slow = head; // Slow pointer to find the middle node
        ListNode* fast = head; // Fast pointer to traverse the list

        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next; // Move slow pointer one step
            fast = fast->next->next; // Move fast pointer two steps
        }

        return slow; // Slow pointer will be at the middle node
    }   
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode dummy; // Dummy node to help with merging
        ListNode* tail = &dummy; // Tail pointer to build the merged list

        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                tail->next = l1; // Append l1 to the merged list
                l1 = l1->next; // Move l1 pointer
            } else {
                tail->next = l2; // Append l2 to the merged list
                l2 = l2->next; // Move l2 pointer
            }
            tail = tail->next; // Move the tail pointer
        }

        // If there are remaining nodes in either list, append them
        if (l1 != nullptr) {
            tail->next = l1;
        } else {
            tail->next = l2;
        }

        return dummy.next; // Return the head of the merged list
    }
};