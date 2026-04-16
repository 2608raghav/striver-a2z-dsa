/*
Problem: Count Number of Substrings
Platform: GeeksforGeeks
Topic: Strings

Approach:
1. We can use a hash set to keep track of the unique substrings we encounter.
2. We will iterate through all possible starting and ending indices of the substrings and add them to the hash set.
3. Finally, the size of the hash set will give us the count of unique substrings.

Time Complexity: O(n^2) since we are generating all possible substrings, where n is the length of the string.
Space Complexity: O(n^2) as we are storing all unique substrings in the hash set.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
      int countDistinct(string s) {
         unordered_set<string> uniqueSubstrings;
         
         for (int i = 0; i < s.size(); i++) {
               for (int j = i; j < s.size(); j++) {
                  uniqueSubstrings.insert(s.substr(i, j - i + 1));
               }
         }
         
         return uniqueSubstrings.size();
      }
   };
