/*
Problem: Remove duplicates from a sorted doubly linked list
Platform: GeeksforGeeks
Topic: Linked List

Approach:
1. We will traverse the linked list and compare the current node's value with the next node's value.
2. If they are the same, we will update the next pointer of the current node to point to the next node's next node and update the previous pointer of the next node's next node to point to the current node.
3. We will continue traversing the linked list until we reach the end.


Time Complexity: O(n) since we need to traverse the linked list once to remove duplicates.
Space Complexity: O(1) since we are using a constant amount of space to store the temporary variables and update the pointers.
*/

#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node *next;
    Node *prev;
    Node() : data(0), next(nullptr), prev(nullptr) {}
    Node(int x) : data(x), next(nullptr), prev(nullptr) {}
    Node(int x, Node *next, Node *prev) : data(x), next(next), prev(prev) {}
};

class Solution {
public:
    Node* removeDuplicates(Node* head) {
        if(head==NULL){
            return NULL;
        }
        else{
            Node* curr = head;
            while(curr->next!=NULL){
                if(curr->data==curr->next->data){
                    curr->next = curr->next->next;
                    if(curr->next!=NULL){
                        curr->next->prev = curr;
                    }
                }
                else{
                    curr = curr->next;
                }
            }
        }
        return head;
    }
};
