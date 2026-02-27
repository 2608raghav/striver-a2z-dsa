/*
Problem: Armstrong Number
Platform: LeetCode
Topic: Basic Math

Approach:
1. Count the number of digits in the number.
2. Precompute digit^count for digits 0 to 9.
3. Traverse the digits once and sum the precomputed values.
4. Compare the sum with the original number.

Time Complexity: O(d)
- Counting digits: O(d)
- Precomputation: O(10) -> constant
- Summing digits: O(d)
Total = O(d)

Space Complexity: O(1)
- Only 10 extra values stored.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isArmstrong(int n) {

        if (n == 0) return true;

        int original = n;
        int temp = n;

        // Step 1: Count digits
        int count = 0;
        while (temp > 0) {
            count++;
            temp /= 10;
        }

        // Step 2: Precompute powers for digits 0-9
        long long powerDigit[10];

        for (int digit = 0; digit <= 9; digit++) {
            long long value = 1;
            for (int i = 0; i < count; i++) {
                value *= digit;
            }
            powerDigit[digit] = value;
        }

        // Step 3: Compute sum using lookup
        long long sum = 0;
        temp = n;

        while (temp > 0) {
            int digit = temp % 10;
            sum += powerDigit[digit];
            temp /= 10;
        }

        return sum == original;
    }
};