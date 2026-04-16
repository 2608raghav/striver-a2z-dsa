/*
Problem: Longest Palindromic Substring
Platform: LeetCode
Topic: Strings

Approach:
1. We can use the "expand around center" technique to find the longest palindromic substring.
2. We will iterate through each character in the string and treat it as the center of a potential palindrome.
3. For each center, we will expand outwards in both directions (left and right) to check for palindromic substrings.
4. We will keep track of the longest palindrome found during this process and return it at the end.

Time Complexity: O(n^2) since we are expanding around each character and in the worst case, we may have to expand through the entire string for each character.
Space Complexity: O(1) since we are using a constant amount of space to store the start and end indices of the longest palindrome found.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
 int expand(int left,int right,string &s){
    while(left>=0 && right<s.size() && s[left]==s[right]){
        left--;
        right++;
    }
    return (right-left-1);
 }
    string longestPalindrome(string s) {
        if(s.size()<=1){
            return s;
        }
        int len1 =0;
        int len2 = 0;
        int len = 0;
        int start = 0;
        int end =0;
        for(int i=0;i<s.size();i++){
            int len1 = expand(i,i,s);
            int len2 = expand(i,i+1,s);
            int len = max(len1,len2);
              if (len > end - start) {
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }
        return s.substr(start,end-start+1);
    }
};