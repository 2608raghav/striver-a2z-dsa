/*
Problem: Single Number I
Platform: Leetcode
Topic: Bit Manipulation

Approach:
1. The problem is to find the single number in an array where every other number appears twice. We can use the XOR operator to solve this problem efficiently.
2. The XOR operator has a property that a ^ a = 0 and a ^ 0 = a. This means that if we XOR all the numbers in the array, the pairs of duplicate numbers will cancel each other out, leaving us with the single number.
3. We can initialize a variable to store the result and XOR it with each number in the array. By the end of the loop, the variable will hold the single number.     

Time Complexity: O(n) where n is the number of elements in the array, since we need to iterate through the array once.
Space Complexity: O(1) since we are using a constant amount of space to store the result.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (int num : nums) {
            result ^= num; // XOR operation
        }
        return result; // The result will be the single number
    }   
};