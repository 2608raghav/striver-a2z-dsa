/*
Problem: Remove N-th node from the end of the Linked List
Platform: Leetcode
Topic: Linked List

Approach:
1. We will use a two-pointer approach to find the N-th node from the end of the linked list.
2. We will initialize two pointers, fast and slow, both starting at the head of the linked list.
3. We will move the fast pointer N steps ahead in the linked list. If the fast pointer reaches the end of the linked list before moving N steps, it means that N is greater than the length of the linked list, and we can return the head of the linked list without making any changes.
4. If the fast pointer successfully moves N steps ahead, we will then move both the fast and slow pointers one step at a time until the fast pointer reaches the end of the linked list. At this point, the slow pointer will be pointing to the node just before the N-th node from the end.
5. We will then update the next pointer of the slow pointer to skip the N-th node from the end, effectively removing it from the linked list.

Time Complexity: O(n) since we may need to traverse the linked list twice, which takes linear time.
Space Complexity: O(1) since we are using a constant amount of space to store the pointers for traversal and the temporary variable for the node to be removed.

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0); // Create a dummy node to handle edge cases
        dummy->next = head; // Point the dummy node to the head of the linked list
        ListNode* fast = dummy; // Initialize fast pointer to the dummy node
        ListNode* slow = dummy; // Initialize slow pointer to the dummy node

        // Move the fast pointer n steps ahead
        for (int i = 0; i < n; i++) {
            if (fast->next == nullptr) {
                return head; // If n is greater than the length of the linked list, return the original head
            }
            fast = fast->next;
        }

        // Move both pointers until fast reaches the end of the linked list
        while (fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        // Skip the N-th node from the end
        ListNode* nodeToRemove = slow->next; // Store the node to be removed
        slow->next = slow->next->next; // Update the next pointer to skip the node to be removed
        delete nodeToRemove; // Free up memory used by the removed node

        return dummy->next; // Return the head of the modified linked list
    }
};