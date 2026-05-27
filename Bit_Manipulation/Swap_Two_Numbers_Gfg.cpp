/*
Problem: Swap Two Numbers
Platform: GrreksforGreeks
Topic: Bit Manipulation

Approach:
1. To swap two numbers a and b without using a temporary variable, we can use the XOR bitwise operator. The XOR operator has a property that if we XOR a number with itself, the result is 0, and if we XOR a number with 0, the result is the number itself.
2. We can perform the following steps to swap a and b:
   - Step 1: a = a XOR b
   - Step 2: b = a XOR b (which is (a XOR b) XOR b = a)
   - Step 3: a = a XOR b (which is (a XOR b) XOR a = b)
3. After these three steps, the values of a and b will be swapped without using any extra space for a temporary variable.

Time Complexity: O(1) since we are performing a constant number of operations.
Space Complexity: O(1) since we are using a constant amount of space.

*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void swap(int &a, int &b) {
        a = a ^ b; // Step 1: a now holds the result of a XOR b
        b = a ^ b; // Step 2: b now holds the original value of a
        a = a ^ b; // Step 3: a now holds the original value of b
    }
};

