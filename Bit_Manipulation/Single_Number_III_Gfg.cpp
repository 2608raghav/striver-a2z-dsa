/*
Problem: Single Number III
Platform: Greedy For Geeks
Topic: Bit Manipulation

Approach:
1. The problem is to find the two single numbers in an array where every other number appears twice. We can use the XOR operator to solve this problem efficiently.
2. First, we XOR all the numbers in the array. The result will be the XOR of the two single numbers (let's call them a and b), since the pairs of duplicate numbers will cancel each other out.
3. Next, we need to find a bit that is set in the XOR result (which means that the two single numbers differ at that bit). We can use the expression `xor & -xor` to isolate the rightmost set bit.
4. We can then partition the numbers in the array into two groups based on whether they have that bit set or not. This will ensure that one of the single numbers is in one group and the other single number is in the other group.
5. Finally, we can XOR the numbers in each group to find the two single numbers.


Time Complexity: O(n) where n is the number of elements in the array, since we need to iterate through the array a few times (for XOR and partitioning).
Space Complexity: O(1) since we are using a constant amount of space to store the results and intermediate variables.

*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorResult = 0;
        // Step 1: XOR all numbers to get the XOR of the two single numbers
        for (int num : nums) {
            xorResult ^= num;
        }
        
        // Step 2: Find a set bit in the XOR result (rightmost set bit)
        int setBit = xorResult & -xorResult;
        
        int num1 = 0, num2 = 0;
        // Step 3: Partition the numbers into two groups and XOR them
        for (int num : nums) {
            if (num & setBit) {
                num1 ^= num; // Group with the set bit
            } else {
                num2 ^= num; // Group without the set bit
            }
        }
        
        return {num1, num2}; // Return the two single numbers
    }
};