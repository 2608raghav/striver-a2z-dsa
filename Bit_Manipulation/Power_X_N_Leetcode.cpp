/*
Problem: Implement pow(x, n), which calculates x raised to the power n (i.e., x^n).
Platform: Leetcode
Topic: Bit Manipulation

Approach:
1. We can use the method of exponentiation by squaring to efficiently calculate x^n. This method reduces the number of multiplications needed, making it more efficient than a naive approach.
2. If n is negative, we can compute the positive power and then take the reciprocal to get the result for negative powers.
3. We can use bit manipulation to check if n is odd or even. If n is odd, we multiply the result by x and then square x. If n is even, we simply square x. We can repeat this process until n becomes zero.
    

Time Complexity: O(log n) where n is the exponent, since we are halving the exponent in each iteration.
Space Complexity: O(1) since we are using a constant amount of extra space.

*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    double myPow(double x, int n) {
        if (n < 0) {
            x = 1 / x; // Handle negative powers
            n = -n;
        }
        
        double result = 1.0;
        double current_product = x;
        
        while (n > 0) {
            if (n % 2 == 1) { // If n is odd
                result *= current_product;
            }
            current_product *= current_product; // Square the base
            n /= 2; // Halve the exponent
        }
        
        return result;
    }
};