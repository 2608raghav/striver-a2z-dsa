/*
Problem: Count Good Numbers
Platform: Leetcode
Topic: Recursion

Approach:
1. We can determine the number of even and odd positions in the string based on the length n.
2. For even positions, we have 5 choices (0, 2, 4, 6, 8) and for odd positions, we have 4 choices (2, 3, 5, 7).
3. We can calculate the total number of good digit strings by raising the number of choices for even and odd positions to the respective counts of even and odd positions.
4. We will use a helper function to perform modular exponentiation to efficiently calculate the powers while keeping the results within the bounds of the modulus.

Time Complexity: O(log n) due to the recursive modular exponentiation.
Space Complexity: O(log n) due to the recursive call stack in the modular exponentiation function

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countGoodNumbers(int n) {
        const int MOD = 1000000007;
        long long evenPositions = (n + 1LL) / 2LL;
        long long oddPositions = n / 2LL;
        long long evens = powMod(5, evenPositions, MOD);
        long long odds = powMod(4, oddPositions, MOD);
        return (int)((evens * odds) % MOD);
    }

private:
    long long powMod(long long base, long long exp, int MOD) {
        if (exp == 0) {
            return 1;
        }
        long long half = powMod(base, exp / 2, MOD);
        long long result = (half * half) % MOD;
        if (exp % 2 == 1) {
            result = (result * base) % MOD;
        }
        return result;
    }
};
