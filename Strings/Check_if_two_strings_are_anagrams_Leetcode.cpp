/*
Problem: Check if two strings are anagrams
Platform: LeetCode
Topic: Strings

Approach:
1. Sort both strings and compare them.
2. If the sorted strings are equal, then the original strings are anagrams.

Time Complexity: O(n log n) due to sorting the strings.
Space Complexity: O(n) as we are creating new strings to store the sorted versions.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        
        return s == t; 
    }
};

