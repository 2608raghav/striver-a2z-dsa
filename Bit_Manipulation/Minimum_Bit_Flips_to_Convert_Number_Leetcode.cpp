/*
Problem: Minimum Bit Flips to Convert Number
Platform: Leetcode
Topic: Bit Manipulation

Approach:
1. To find the minimum number of bit flips required to convert one number (start) to another (goal), we can use the XOR bitwise operator. The XOR operator will give us a number where each bit is set to 1 if the corresponding bits of the two numbers are different, and 0 if they are the same.
2. Once we have the result of the XOR operation, we need to count the number of set bits (1s) in the result, which will give us the number of bit flips required.
3. We can count the number of set bits using a simple loop or by using built-in functions.

Time Complexity: O(log n) where n is the maximum of start and goal, since we need to count the bits in the XOR result.
Space Complexity: O(1) since we are using a constant amount of space.

*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minBitFlips(int start, int goal) {
        int xorResult = start ^ goal; 
        int count = 0; // 
        while (xorResult) { 
            count += xorResult & 1; 
            xorResult >>= 1; 
        }
        return count; // 
    }
};


