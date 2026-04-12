/*
Problem: Isomorphic Strings
Platform: LeetCode
Topic: Strings

Approach:
1. We can use two hash maps to keep track of the character mappings from s to t and from t to s.
2. We will iterate through the characters of both strings simultaneously and check the mappings:
   - If the current character of s is already mapped to a different character in t, return false.
   - If the current character of t is already mapped to a different character in s, return false.
   - Otherwise, we will create the mapping in both hash maps.
   
Time Complexity: O(n) since we are iterating through the strings once.
Space Complexity: O(1) as we are using a constant amount of extra space for the
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) return false;
        
        unordered_map<char, char> s_to_t;
        unordered_map<char, char> t_to_s;
        
        for(int i = 0; i < s.size(); i++) {
            char c1 = s[i];
            char c2 = t[i];
            
            if(s_to_t.count(c1) && s_to_t[c1] != c2) {
                return false; // c1 is already mapped to a different character
            }
            if(t_to_s.count(c2) && t_to_s[c2] != c1) {
                return false; // c2 is already mapped to a different character
            }
            
            s_to_t[c1] = c2; // Create mapping from s to t
            t_to_s[c2] = c1; // Create mapping from t to s
        }
        
        return true;
    }
};