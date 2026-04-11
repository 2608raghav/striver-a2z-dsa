/*
Problem: Reverse Words in a String
Platform: LeetCode
Topic: Strings

Approach:
1. We can use two pointers to reverse the words in the string.
2. We will first reverse the entire string to get the words in the correct order but with reversed characters.
3. Then we will reverse each word in the reversed string to get the final result.

Time Complexity: O(n) since we are iterating through the string a few times (reversing the entire string and then reversing each word).
Space Complexity: O(n) as we are using an additional string to store the result.
*/

#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        
        string result = "";
        string temp = "";

        for(int i = s.size() - 1; i >= 0; i--) {

            if(s[i] == ' ') {
                if(temp != "") {
                    reverse(temp.begin(), temp.end());
                    result += temp;
                    result += ' ';
                    temp = "";
                }
            }
            else {
                temp.push_back(s[i]);
            }
        }

        // last word
        if(temp != "") {
            reverse(temp.begin(), temp.end());
            result += temp;
        }

        // remove last space if exists
        if(result.back() == ' ')
            result.pop_back();

        return result;
    }
};
