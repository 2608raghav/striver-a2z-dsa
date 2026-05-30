/*
Problem: Divisors of a Number
Platform: Greedy For Geeks
Topic: Bit Manipulation

Approach:
1. To find the divisors of a number, we can iterate from 1 to the square root of the number. For each integer i in this range, if i divides the number (i.e., n % i == 0), then we can add both i and n/i to the list of divisors.
2. We need to be careful when n is a perfect square, as in that case, we should only add the square root once to avoid duplicates.

Time Complexity: O(sqrt(n)) where n is the number for which we are finding the divisors, since we only need to check up to the square root of n.
Space Complexity: O(d) where d is the number of divisors, since we are storing the divisors in a vector.

*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> divisors(int n) {
        vector<int> divs;
        for (int i = 1; i <= sqrt(n); i++) {
            if (n % i == 0) {
                divs.push_back(i);
                if (i != n / i) { // Avoid adding the square root twice
                    divs.push_back(n / i);
                }
            }
        }
        sort(divs.begin(), divs.end()); // Sort the divisors in ascending order
        return divs;
    }
};
