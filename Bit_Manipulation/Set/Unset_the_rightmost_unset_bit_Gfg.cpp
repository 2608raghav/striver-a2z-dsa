/*
Problem: Set/Unset the rightmost unset bit
Platform: GrreksforGreeks
Topic: Bit Manipulation

Approach:
1. To set the rightmost unset bit of a number n, we can use the expression n | (n + 1). This works because n + 1 will flip all the bits after the rightmost unset bit to 0 and set the rightmost unset bit to 1. When we perform a bitwise OR with n, it will set the rightmost unset bit in n.
2. To unset the rightmost unset bit of a number n, we can use the expression n & (n + 1). This works because n + 1 will flip all the bits after the rightmost unset bit to 0 and set the rightmost unset bit to 1. When we perform a bitwise AND with n, it will unset the rightmost unset bit in n.
3. The function will return the modified number after setting or unsetting the rightmost unset bit based on the input parameters.

Time Complexity: O(1) since we are performing a constant number of operations.
Space Complexity: O(1) since we are using a constant amount of space.

*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int setRightmostUnsetBit(int n) {
        return n | (n + 1); // Set the rightmost unset bit
    }
    
    int unsetRightmostUnsetBit(int n) {
        return n & (n + 1); // Unset the rightmost unset bit
    }
};