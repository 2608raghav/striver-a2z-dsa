/*
Problem: Divide two numbers without using multiplication, division and mod operator.
Platform: Leetcode
Topic: Bit Manipulation

Approach:
1. The idea is to use bit manipulation to perform division. We can subtract the divisor from the dividend repeatedly until the dividend becomes smaller than the divisor.
2. To optimize this, we can use bit shifting to find the largest multiple of the divisor that is less than or equal to the dividend.
3. We keep track of the quotient and update it with each iteration.

Time Complexity: O(log n) where n is the dividend.
Space Complexity: O(1) since we are using a constant amount of space.

*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle edge cases
        if (divisor == 0) return INT_MAX; // Division by zero case
        if (dividend == INT_MIN && divisor == -1) return INT_MAX; // Overflow case

        // Determine the sign of the result
        bool isNegative = (dividend < 0) ^ (divisor < 0);

        // Convert to positive
        long long absDividend = abs((long long)dividend);
        long long absDivisor = abs((long long)divisor);

        long long quotient = 0;
        while (absDividend >= absDivisor) {
            long long temp = absDivisor, multiple = 1;
            while (absDividend >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }
            absDividend -= temp;
            quotient += multiple;
        }

        return isNegative ? -quotient : quotient;
    }
};

