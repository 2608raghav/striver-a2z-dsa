/*
Problem: Find pairs in a sorted doubly linked list whose sum is equal to a given value
Platform: GeeksforGeeks
Topic: Linked List

Approach:
1. We will use two pointers, one starting from the head of the linked list and the other starting from the tail of the linked list.
2. We will calculate the sum of the values at the two pointers.
3. If the sum is equal to the given value, we will add the pair to our result list and move both pointers towards the center (i.e., move the left pointer to the right and the right pointer to the left).
4. If the sum is less than the given value, we will move the left pointer to the right to increase the sum.
5. If the sum is greater than the given value, we will move the right pointer to the left to decrease the sum.

Time Complexity: O(n) since we are traversing the linked list at most once with the two pointers.
Space Complexity: O(1) since we are using only a constant amount of extra space for the two pointers and the result list.
*/

#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int x) : data(x), next(nullptr), prev(nullptr) {}
};
class Solution {
public:
vector<pair<int, int>> findPairs(Node* head, int k) {
    vector<pair<int, int>> result;
    if (head == nullptr) {
        return result; // Return empty vector if the list is empty
    }

    Node* left = head; // Start from the head
    Node* right = head; // Start from the head to find the tail

    // Move right pointer to the end of the list
    while (right->next != nullptr) {
        right = right->next;
    }

    // Use two pointers to find pairs
    while (left != right && left->prev != right) {
        int sum = left->data + right->data;
        if (sum == k) {
            result.emplace_back(left->data, right->data); // Add pair to result
            left = left->next; // Move left pointer to the right
            right = right->prev; // Move right pointer to the left
        } else if (sum < k) {
            left = left->next; // Move left pointer to increase sum
        } else {
            right = right->prev; // Move right pointer to decrease sum
        }
    }

    return result;
}
};