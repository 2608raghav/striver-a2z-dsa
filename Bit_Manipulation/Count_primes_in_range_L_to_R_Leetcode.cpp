/*
Problem: Count the number of prime numbers in the range [L, R].
Platform: Leetcode
Topic: Bit Manipulation

Approach:
1. We can use the Sieve of Eratosthenes algorithm to find all prime numbers up to R. This algorithm efficiently marks non-prime numbers in a boolean array.
2. After we have the list of prime numbers, we can iterate through the range [L, R] and count how many of those numbers are prime by checking our boolean array.



Time Complexity: O(n log log n) for the Sieve of Eratosthenes, where n is R. The counting step takes O(R - L + 1).
Space Complexity: O(n) for the boolean array used in the Sieve of Eratosthenes.

*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countPrimesInRange(int L, int R) {
        if (R < 2) return 0; // No primes less than 2
        vector<bool> isPrime(R + 1, true);
        isPrime[0] = isPrime[1] = false; // 0 and 1 are not prime

        for (int i = 2; i * i <= R; ++i) {
            if (isPrime[i]) {
                for (int j = i * i; j <= R; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        int count = 0;
        for (int i = max(L, 2); i <= R; ++i) {
            if (isPrime[i]) {
                count++;
            }
        }
        return count;
    }
};