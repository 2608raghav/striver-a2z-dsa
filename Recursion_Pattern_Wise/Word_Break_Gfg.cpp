/*
Problem: Word Break
Platform: GeeksforGeeks
Topic: Recursion

Approach:
1. We will use recursion to check if the given string can be segmented into a space-separated sequence of one or more dictionary words.
2. We will define a helper function `wordBreakUtil` that takes the current index in the string and checks if the substring from that index to the end of the string can be segmented.
3. The helper function will iterate through the dictionary and check if any word in the dictionary matches the substring starting from the current index. If a match is found, we will recursively call the helper function for the index immediately following the matched word.
4. If we reach the end of the string, it means we have successfully segmented the string, and we will return true. If we exhaust all possibilities without finding a valid segmentation, we will return false.

Time Complexity: O(n * m) in the worst case, where n is the length of the input string and m is the number of words in the dictionary. This is because for each index in the string, we may check all words in the dictionary for a match.
Space Complexity: O(n) due to the recursive call stack, which can go up to n levels deep in the worst case when we are checking each index of the string. Additionally, we use O(1) space for storing the dictionary and other variables.

*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool wordBreakUtil(string s, vector<string>& dict, int index) {
        if (index == s.size()) return true; // Reached the end of the string

        for (const string& word : dict) {
            int len = word.size();
            if (index + len <= s.size() && s.substr(index, len) == word) {
                if (wordBreakUtil(s, dict, index + len)) {
                    return true; // Found a valid segmentation
                }
            }
        }
        return false; // No valid segmentation found
    }

    bool wordBreak(string s, vector<string>& dict) {
        return wordBreakUtil(s, dict, 0);
    }
};
