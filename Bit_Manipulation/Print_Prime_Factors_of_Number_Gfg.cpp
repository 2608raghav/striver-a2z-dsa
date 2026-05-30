/*
Problem: Print Prime Factors of a Number
Platform: Greedy For Geeks
Topic: Bit Manipulation

Approach:
1. To find the prime factors of a number, we can start by checking for the smallest prime factor, which is 2. We can keep dividing the number by 2 until it is no longer divisible by 2.
2. After checking for 2, we can check for odd factors starting from 3 up to the square root of the number. For each odd factor, we can keep dividing the number by that factor until it is no longer divisible.
3. If the number is greater than 2 after the loop, then it means that the number itself is a prime factor and we can add it to the list of prime factors.

Time Complexity: O(sqrt(n)) where n is the number for which we are finding the prime factors, since we only need to check up to the square root of n.
Space Complexity: O(1) since we are using a constant amount of space to store the prime factors and intermediate variables.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> primeFactors(int n) {
        vector<int> factors;
        
        // Check for number of 2s that divide n
        while (n % 2 == 0) {
            factors.push_back(2);
            n /= 2;
        }
        
        // n must be odd at this point, so we can skip even numbers
        for (int i = 3; i <= sqrt(n); i += 2) {
            // While i divides n, add i and divide n
            while (n % i == 0) {
                factors.push_back(i);
                n /= i;
            }
        }
        
        // This condition is to check if n is a prime number greater than 2
        if (n > 2) {
            factors.push_back(n);
        }
        
        return factors;
    }
};  
