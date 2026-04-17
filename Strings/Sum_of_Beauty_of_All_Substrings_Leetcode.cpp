/*
Problem: Sum of Beauty of All Substrings
Platform: LeetCode
Topic: Strings

Approach:
1. We can iterate through all possible substrings of the given string.
2. For each substring, we can calculate the frequency of each character.
3. We can then determine the beauty of the substring by finding the difference between the maximum and minimum frequency of characters.
4. We will keep a running total of the beauty values for all substrings and return the final sum at the end.

Time Complexity: O(n^3) where n is the length of the string, as we are generating all possible substrings (O(n^2)) and calculating the frequency for each substring (O(n)).
Space Complexity: O(1) since we are using a fixed amount of space to store the frequency counts and the beauty sum.

*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int beautySum = 0;
        
        for (int i = 0; i < n; i++) {
            vector<int> freq(26, 0);
            for (int j = i; j < n; j++) {
                freq[s[j] - 'a']++;
                int maxFreq = 0;
                int minFreq = INT_MAX;
                for (int f : freq) {
                    if (f > 0) {
                        maxFreq = max(maxFreq, f);
                        minFreq = min(minFreq, f);
                    }
                }
                beautySum += (maxFreq - minFreq);
            }
        }
        
        return beautySum;
    }
};