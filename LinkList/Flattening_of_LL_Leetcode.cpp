/*
Problem: Flattening of a multilevel linked list
Platform: Leetcode
Topic: Linked List

Approach:
1. We will use a stack to keep track of the nodes that we need to visit.
2. We will start from the head of the linked list and push it onto the stack.
3. We will then pop a node from the stack and add it to the flattened linked list.
4. If the popped node has a next pointer, we will push the next node onto the stack.
5. If the popped node has a child pointer, we will push the child node onto the stack.
6. We will continue this process until the stack is empty.

Time Complexity: O(n) since we need to traverse the linked list twice, where n is the number of nodes in the linked list.
Space Complexity: O(n) since we are using a stack to store the nodes, where n is the number of nodes in the linked list.

*/

#include <bits/stdc++.h>
using namespace std;

  struct Node {
      int val;
      Node *prev;
      Node *next;
      Node *child;
  };

class Solution {
public:
    Node* flatten(Node* head) {
        if(head==NULL){
            return NULL;
        }
        else{
            stack<Node*> st;
            st.push(head);
            Node* prev = NULL;
            Node* curr = NULL;
            while(!st.empty()){
                curr = st.top();
                st.pop();
                if(prev!=NULL){
                    prev->next = curr;
                    curr->prev = prev;
                }
                if(curr->next!=NULL){
                    st.push(curr->next);
                }
                if(curr->child!=NULL){
                    st.push(curr->child);
                    curr->child = NULL;
                }
                prev = curr;
            }
            return head;
        }
    }
};

