/*
Problem: Count all subsequences with sum K
Platform: GeeksforGeeks
Topic: Recursion

Approach:
1. We will use recursion to explore all possible subsequences of the given array and count those whose sum equals K.
2. We will define a helper function that takes the current index, the current sum of the subsequence, and the count of valid subsequences found so far.
3. The helper function will have two choices at each step: include the current element in the subsequence or exclude it. We will recursively call the helper function for both choices.

Time Complexity: O(2^n) in the worst case, where n is the number of elements in the array. This is because each element can either be included or excluded from the subsequence, leading to 2^n possible subsequences.
Space Complexity: O(n) due to the recursive call stack, which can go up to n levels deep in the worst case.

*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void countSubsequences(vector<int>& arr, int index, int currentSum, int K, int& count) {
        if (index == arr.size()) {
            if (currentSum == K) {
                count++;
            }
            return;
        }
        
        // Include the current element in the subsequence
        countSubsequences(arr, index + 1, currentSum + arr[index], K, count);
        
        // Exclude the current element from the subsequence
        countSubsequences(arr, index + 1, currentSum, K, count);
    }
    
    int countSubsequencesWithSumK(vector<int>& arr, int K) {
        int count = 0;
        countSubsequences(arr, 0, 0, K, count);
        return count;
    }
};