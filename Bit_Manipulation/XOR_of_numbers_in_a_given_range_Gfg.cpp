/*
Problem: XOR of numbers in a given range
Platform: Greedy For Geeks
Topic: Bit Manipulation

Approach:
1. To find the XOR of numbers in a given range [L, R], we can use the property that XOR of a range can be computed using the XOR of two prefixes: XOR(0 to R) and XOR(0 to L-1).
2. We can define a helper function that computes the XOR of all numbers from 0 to n. This function can be implemented using the following pattern based on n mod 4:
   - If n % 4 == 0, then XOR(0 to n) = n
   - If n % 4 == 1, then XOR(0 to n) = 1
   - If n % 4 == 2, then XOR(0 to n) = n + 1
   - If n % 4 == 3, then XOR(0 to n) = 0
3. Finally, we can compute the XOR for the range [L, R] using the formula: XOR(L to R) = XOR(0 to R) ^ XOR(0 to L-1).


Time Complexity: O(1) for the helper function and O(1) for the final XOR computation, resulting in O(1) overall.
Space Complexity: O(1) since we are using a constant amount of space to store the results and intermediate variables.

*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int xorFromZeroToN(int n) {
        if (n % 4 == 0) {
            return n;
        } else if (n % 4 == 1) {
            return 1;
        } else if (n % 4 == 2) {
            return n + 1;
        } else {
            return 0;
        }
    }
    
    int xorInRange(int L, int R) {
        return xorFromZeroToN(R) ^ xorFromZeroToN(L - 1);
    }
};