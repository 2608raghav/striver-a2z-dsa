/*
Problem: Reverse a stack
Platform: GeeksforGeeks
Topic: Recursion

Approach:
1. We will use recursion to reverse the stack. The idea is to pop all elements from the stack until it becomes empty, and then insert the popped elements back into the stack in reverse order.
2. We will define a helper function to insert an element at the bottom of the stack.
3. The main function will pop the top element of the stack, call itself recursively to reverse the remaining stack, and then call the helper function to insert the popped element at the bottom of the stack.

Time Complexity: O(n^2) in the worst case, where n is the number of elements in the stack. This is because for each element, we may need to insert it at the bottom of the stack, which takes O(n) time.
Space Complexity: O(n) due to the recursive call stack, which can go up to n levels deep in the worst case.

*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void insertAtBottom(stack<int>& st, int element) {
        if (st.empty()) {
            st.push(element);
            return;
        }
        
        int topElement = st.top();
        st.pop();
        
        insertAtBottom(st, element);
        
        st.push(topElement);
    }
    
    void reverseStack(stack<int>& st) {
        if (st.empty()) {
            return;
        }
        
        int topElement = st.top();
        st.pop();
        
        reverseStack(st);
        
        insertAtBottom(st, topElement);
    }
};  