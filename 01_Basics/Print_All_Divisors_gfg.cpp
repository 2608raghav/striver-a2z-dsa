/*
Problem: Print All Divisors of a Number
Platform: GeeksforGeeks
Topic: Basic Math

Approach:
1. Iterate from 1 to sqrt(n) and check if the number is a divisor.
2. If it is a divisor, print it.
3. If the divisor is not the square root of n, also print n/divisor to get the complementary divisor.

Time Complexity: O(sqrt(n)) since we only iterate up to the square root of n.

Space Complexity: O(sqrt(n)) since we are storing the larger divisors in a vector.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void print_divisors(int n) {

        vector<int> largeDivisors;

        int root = sqrt(n);

        for (int i = 1; i <= root; i++) {
            if (n % i == 0) {

                cout << i << " ";

                if (i != n / i) {
                    largeDivisors.push_back(n / i);
                }
            }
        }

        // Print larger divisors in reverse order
        for (int i = largeDivisors.size() - 1; i >= 0; i--) {
            cout << largeDivisors[i] << " ";
        }
    }
};