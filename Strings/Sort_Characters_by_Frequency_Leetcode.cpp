/*
Problem: Sort Characters by Frequency
Platform: LeetCode
Topic: Strings

Approach:
1. We can use a hash map to count the frequency of each character in the string.
2. We can then create a vector of pairs to store the characters and their frequencies.
3. We can sort the vector of pairs based on the frequency in descending order.
4. Finally, we can construct the result string by repeating each character according to its frequency.

Time Complexity: O(n log n) due to sorting the vector of pairs based on frequency.
Space Complexity: O(n) as we are using a hash map to store the frequency of characters and a vector to store the pairs of characters and their frequencies.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        
        for(char c : s) {
            freq[c]++;
        }
        
        vector<pair<char, int>> charFreq(freq.begin(), freq.end());
        
        sort(charFreq.begin(), charFreq.end(), [](const pair<char, int>& a, const pair<char, int>& b) {
            return a.second > b.second; 
        });
        
        string result;
        for(const auto& p : charFreq) {
            result += string(p.second, p.first); 
        }
        
        return result;
    }
};

