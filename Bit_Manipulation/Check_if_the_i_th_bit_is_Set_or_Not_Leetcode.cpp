/*
Problem: Check if the i-th bit is Set or Not
Platform: Leetcode
Topic: Bit Manipulation

Approach:
1. To check if the i-th bit of a number n is set (i.e., is 1), we can use a bitwise AND operation with a mask that has only the i-th bit set.
2. The mask can be created by left-shifting the number 1 by i positions (1 << i). This will give us a number where only the i-th bit is 1 and all other bits are 0.
3. We then perform a bitwise AND operation between n and the mask. If the result is not zero, it means the i-th bit in n is set; otherwise, it is not set.
4. The function will return true if the i-th bit is set and false otherwise.
Time Complexity: O(1) since we are performing a constant number of operations.
Space Complexity: O(1) since we are using a constant amount of space.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isIthBitSet(int n, int i) {
        return (n & (1 << i)) != 0;
    }
};

