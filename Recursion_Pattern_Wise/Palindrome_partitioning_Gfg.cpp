/*
Problem: Palindrome Partitioning
Platform: Greedy For Geeks
Topic: Recursion

Approach:
1. We will use recursion to generate all possible palindrome partitions of the given string.
2. We will define a helper function that takes the current index in the string, the current partition being formed, and a vector to store the results.
3. The helper function will iterate through the possible substrings starting from the current index and check if they are palindromes. If a substring is a palindrome, we will recursively call the helper function to continue partitioning the remaining string.
4. The main function will call the helper function with the initial parameters.

Time Complexity: O(n * 2^n) in the worst case, where n is the length of the input string. This is because there are 2^(n-1) ways to partition a string of length n, and checking if a substring is a palindrome takes O(n) time.
Space Complexity: O(n) due to the recursive call stack, which can go up to n levels deep in the worst case. Additionally, the space used to store the partitions can also be O(2^n) in the worst case if all partitions are unique.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPalindrome(const string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    
    void backtrack(const string& s, int index, vector<string>& currentPartition, vector<vector<string>>& result) {
        if (index == s.size()) {
            result.push_back(currentPartition);
            return;
        }
        
        for (int i = index; i < s.size(); i++) {
            if (isPalindrome(s, index, i)) {
                currentPartition.push_back(s.substr(index, i - index + 1));
                backtrack(s, i + 1, currentPartition, result);
                currentPartition.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> currentPartition;
        backtrack(s, 0, currentPartition, result);
        return result;
    }
};

