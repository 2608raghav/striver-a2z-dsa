/*
Problem: Clone a linked list with random and next pointers
Platform: Leetcode
Topic: Linked List

Approach:
1. We will use a hash map to store the mapping of the original nodes to the cloned nodes.
2. We will first create a copy of the original linked list and store the mapping of the original nodes to the cloned nodes in the hash map.
3. We will then iterate through the original linked list again and update the next and random pointers of the cloned nodes using the hash map.

Time Complexity: O(n) since we need to traverse the linked list twice, where n is the number of nodes in the linked list.
Space Complexity: O(n) since we are using a hash map to store the mapping of the original nodes to the cloned nodes, where n is the number of nodes in the linked list.
*/


#include <bits/stdc++.h>
using namespace std;

  struct Node {
      int val;
      Node *next;
      Node *random;
      Node(int _val) {
          val = _val;
          next = NULL;
          random = NULL;
      }
  };

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL){
            return NULL;
        }
        else{
            unordered_map<Node*,Node*> mp;
            Node* curr = head;
            while(curr!=NULL){
                mp[curr] = new Node(curr->val);
                curr = curr->next;
            }
            curr = head;
            while(curr!=NULL){
                mp[curr]->next = mp[curr->next];
                mp[curr]->random = mp[curr->random];
                curr = curr->next;
            }
            return mp[head];
        }
    }
};