/*
Problem: Implement Min Stack
Platform: Leetcode
Topic: Stack

Approach:
1. We can use two stacks: one for storing all elements and another for storing the minimum elements.
2. When pushing an element, we also push the current minimum to the minimum stack.
3. When popping an element, we pop from both stacks.
4. The top of the minimum stack will always contain the minimum element.

Time Complexity: O(1) for all operations.
Space Complexity: O(n) where n is the number of elements in the stack.

*/

#include <bits/stdc++.h>
using namespace std;
class MinStack {
public:
    stack<int> mainStack;
    stack<int> minStack;
    
    MinStack() {
        
    }
    
    void push(int x) {
        mainStack.push(x);
        if (minStack.empty() || x <= minStack.top()) {
            minStack.push(x);
        }
    }
    
    void pop() {
        if (mainStack.top() == minStack.top()) {
            minStack.pop();
        }
        mainStack.pop();
    }
    
    int top() {
        return mainStack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};