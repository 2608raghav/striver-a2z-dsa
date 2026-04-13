/*
Problem: Rotate String
Platform: LeetCode
Topic: Strings

Approach:
1. We can concatenate the string s with itself to get a new string s + s.
2. If the string t is a substring of the new string s + s, then we can conclude that t is a rotation of s.

Time Complexity: O(n) since we are checking if t is a substring of s + s, which takes O(n) time.
Space Complexity: O(n) as we are creating a new string s + s which takes O(n) space.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool rotateString(string s, string t) {
        if(s.size() != t.size()) return false;
        
        string temp = s + s;
        
        return temp.find(t) != string::npos; 
    }
};
