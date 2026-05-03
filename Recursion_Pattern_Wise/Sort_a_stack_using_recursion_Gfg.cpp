/*
Problem: Sort a Stack using Recursion
Platform: GFG
Topic: Recursion

Approach:
1. We will use a recursive approach to sort the stack. The idea is to pop all elements from the stack until it is empty, and then insert each element back into the stack in sorted order.
2. We will define a helper function `insertSorted` that takes an element and inserts it into the correct position in the stack while maintaining the sorted order.
3. The main function `sortStack` will pop elements from the stack until it is empty, and then call `insertSorted` for each popped element to insert it back into the stack in sorted order.


Time Complexity: O(n^2) in the worst case, where n is the number of elements in the stack. This is because each element may need to be compared with every other element in the stack to find its correct position.
Space Complexity: O(n) due to the recursive call stack, which can go up to n levels deep in the worst case when all elements are in reverse order.

*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void insertSorted(stack<int>& s, int element) {
        // Base case: If stack is empty or top element is less than or equal to the current element
        if (s.empty() || s.top() <= element) {
            s.push(element);
            return;
        }
        
        // Pop the top element and recursively call insertSorted for the remaining stack
        int temp = s.top();
        s.pop();
        insertSorted(s, element);
        
        // Push the popped element back to the stack
        s.push(temp);
    }
    
    void sortStack(stack<int>& s) {
        // Base case: If stack is empty, return
        if (s.empty()) {
            return;
        }
        
        // Pop the top element and recursively call sortStack for the remaining stack
        int temp = s.top();
        s.pop();
        sortStack(s);
        
        // Insert the popped element back to the sorted stack
        insertSorted(s, temp);
    }
};