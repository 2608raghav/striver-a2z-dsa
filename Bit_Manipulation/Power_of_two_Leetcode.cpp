/*
Problem: Power of Two
Platform: Leetcode
Topic: Bit Manipulation

Approach:
1. A number n is a power of two if it has exactly one bit set in its binary representation. For example, 1 (2^0), 2 (2^1), 4 (2^2), 8 (2^3), etc. are powers of two.
2. To check if n is a power of two, we can use the property that n & (n - 1) will be 0 if n is a power of two. This is because n - 1 will have all the bits flipped after the rightmost set bit of n, and when we perform a bitwise AND with n, it will result in 0.
3. Additionally, we need to ensure that n is greater than 0, as negative numbers and zero cannot be powers of two.
4. The function will return true if n is a power of two and false otherwise.

Time Complexity: O(1) since we are performing a constant number of operations.
Space Complexity: O(1) since we are using a constant amount of space.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0){
            return false;
        }
         double temp = log2(n);
        if(temp==int(temp)){
            return true;
        }
        return false;
    }
};
