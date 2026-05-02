/*
Problem: Pow(x, n)
Platform: Leetcode
Topic: Recursion

Approach:
1. Base Case: If n is 0, return 1 (since any number to the power of 0 is 1).
2. If n is negative, we can convert it to a positive exponent by taking the reciprocal of x and negating n.
3. If n is even, we can use the property that x^n = (x^(n/2))^2 to reduce the number of multiplications.
4. If n is odd, we can use the property that x^n = x * (x^(n-1)) to reduce the problem to a smaller exponent.

Time Complexity: O(log n) since we are halving the exponent in each step.
Space Complexity: O(log n) due to the recursive call stack, which can go up to log n levels deep.

*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    double myPow(double x, int n) {
        return myPowHelper(x, (long long)n);
    }
    
private:
    double myPowHelper(double x, long long n) {
        if (n == 0) {
            return 1.0; // Base case: x^0 is 1
        }
        
        if (n < 0) {
            x = 1 / x; // If n is negative, take the reciprocal of x
            n = -n; // Make n positive
        }
        
        if (n % 2 == 0) {
            double half = myPowHelper(x, n / 2); // Calculate x^(n/2)
            return half * half; // Return (x^(n/2))^2
        } else {
            return x * myPowHelper(x, n - 1); // Return x * (x^(n-1))
        }
    }
};