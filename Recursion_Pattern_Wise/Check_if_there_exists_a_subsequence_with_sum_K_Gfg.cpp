/*
Problem: Check if there exists a subsequence with sum K
Platform: GeeksforGeeks
Topic: Recursion

Approach:
1. We will use recursion to explore all possible subsequences of the given array and check if any non-empty subsequence has a sum equal to K.
2. We will define a helper function that takes the current index, the current sum of the subsequence, and a boolean to track if at least one element has been included.
3. The helper function will have two choices at each step: include the current element in the subsequence or exclude it. We will recursively call the helper function for both choices.
4. We will use a boolean reference to indicate if a valid subsequence has been found.

Time Complexity: O(2^n) in the worst case, where n is the number of elements in the array. This is because each element can either be included or excluded from the subsequence, leading to 2^n possible subsequences.
Space Complexity: O(n) due to the recursive call stack, which can go up to n levels deep in the worst case.

Note: This considers only non-empty subsequences. If empty subsequences are allowed (e.g., for K=0), modify the base case accordingly.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void checkSubsequences(vector<int>& arr, int index, int currentSum, int K, bool included, bool& found) {
        if (found) return; // Early return if already found
        if (index == arr.size()) {
            if (currentSum == K && included) {
                found = true;
            }
            return;
        }
        
        // Include the current element in the subsequence
        checkSubsequences(arr, index + 1, currentSum + arr[index], K, true, found);
        
        // Exclude the current element from the subsequence
        checkSubsequences(arr, index + 1, currentSum, K, included, found);
    }
    
    bool isSubsequenceWithSumK(vector<int>& arr, int K) {
        bool found = false;
        checkSubsequences(arr, 0, 0, K, false, found);
        return found;
    }
};