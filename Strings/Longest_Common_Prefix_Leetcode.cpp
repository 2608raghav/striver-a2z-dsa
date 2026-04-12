/*
Problem: Longest Common Prefix
Platform: LeetCode
Topic: Strings

Approach:
1. We can use a vertical scanning approach to find the longest common prefix.
2. We will iterate through the characters of the first string and compare them with the corresponding characters of the other strings.
3. If we find a mismatch or reach the end of any string, we will return the longest common prefix found so far.

Time Complexity: O(n*m) where n is the number of strings and m is the length of the longest common prefix.
Space Complexity: O(1) as we are using only a constant amount of extra space.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public: 
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        
        for(int i = 0; i < strs[0].size(); i++) {
            char c = strs[0][i];
            for(int j = 1; j < strs.size(); j++) {
                if(i >= strs[j].size() || strs[j][i] != c) {
                    return strs[0].substr(0, i);
                }
            }
        }
        return strs[0];
    }
};