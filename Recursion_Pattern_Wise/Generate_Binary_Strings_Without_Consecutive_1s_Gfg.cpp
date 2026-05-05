/*
Problem: Generate Binary Strings Without Consecutive 1s
Platform: GeeksforGeeks
Topic: Recursion

Approach:
1. We will use recursion to generate binary strings without consecutive 1s. The idea is to build the string character by character, ensuring that we never place two 1s consecutively.
2. We will define a helper function to recursively build the binary string.
3. The main function will call the helper function with the initial parameters.

Time Complexity: O(2^n) in the worst case, where n is the length of the string. This is because for each position, we have two choices (0 or 1), and we need to avoid consecutive 1s.
Space Complexity: O(n) due to the recursive call stack, which can go up to n levels deep in the worst case.

*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void generateBinaryStrings(int n, string current, vector<string>& result) {
        if (current.length() == n) {
            result.push_back(current);
            return;
        }
        
        // Add '0' and continue recursion
        generateBinaryStrings(n, current + '0', result);
        
        // Add '1' only if the last character is not '1'
        if (current.empty() || current.back() != '1') {
            generateBinaryStrings(n, current + '1', result);
        }
    }
    
    vector<string> generateBinaryStrings(int n) {
        vector<string> result;
        generateBinaryStrings(n, "", result);
        return result;
    }
};