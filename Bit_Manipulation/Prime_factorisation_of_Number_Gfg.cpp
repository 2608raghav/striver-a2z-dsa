/*
Problem: Find the prime factorization of a number N.
Platform: Greedy For Geeks
Topic: Bit Manipulation

Approach:
1. To find the prime factorization of a number N, we can start by checking for the smallest prime factor, which is 2. We can divide N by 2 repeatedly until it is no longer divisible by 2, and we can keep track of the count of how many times we divided by 2.
2. After we have handled the factor of 2, we can move on to the next odd numbers starting from 3. For each odd number, we can repeat the same process: divide N by the odd number repeatedly until it is no longer divisible, and keep track of the count.
3. We can continue this process until we have checked all numbers up to the square root of N. If N is still greater than 1 after the loop, it means that N itself is a prime factor and we can add it to our result.


Time Complexity: O(sqrt(N)) in the worst case, when N is a prime number. In general, the time complexity is O(log N) for numbers with small prime factors.
Space Complexity: O(1) since we are using a constant amount of space to store the prime factors and their counts.

*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<pair<int, int>> primeFactorization(int N) {
        vector<pair<int, int>> factors;
        
        // Check for the number of 2s that divide N
        int count = 0;
        while (N % 2 == 0) {
            count++;
            N /= 2;
        }
        if (count > 0) {
            factors.push_back({2, count});
        }

        // Check for odd factors from 3 to sqrt(N)
        for (int i = 3; i * i <= N; i += 2) {
            count = 0;
            while (N % i == 0) {
                count++;
                N /= i;
            }
            if (count > 0) {
                factors.push_back({i, count});
            }
        }

        // If N is a prime number greater than 2
        if (N > 2) {
            factors.push_back({N, 1});
        }

        return factors;
    }
};


