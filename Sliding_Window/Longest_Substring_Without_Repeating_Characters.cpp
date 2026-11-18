/*
Problem: Longest Substring Without Repeating Characters
Platform: GeeksforGeeks
Topic: String, Sliding Window, Two Pointers, Hash Map

Approach:
1. Use two pointers:
      l = 0  -> Left pointer of the window
      r = 0  -> Right pointer of the window

2. Maintain a map to store the frequency of characters
   present in the current window.

3. Expand the window by moving the right pointer r.

4. Check whether the current character s[r] is already
   present in the window.

   Case 1: Character is already present:
      - Shrink the window from the left.
      - Decrease the frequency of s[l].
      - Increment l.
      - Continue until the duplicate character is removed.

   Case 2: Character is not present:
      - Add the current character to the map.
      - Increase its frequency.

5. After removing duplicates, calculate the current
   window length:

      length = r - l + 1

6. Update the maximum length:

      mx_length = max(mx_length, length)

7. Increment r and continue until the entire string
   has been traversed.

8. Return mx_length.

Time Complexity: O(n log k)
- Each character enters and leaves the window at most once.
- Map operations take O(log k), where k is the number
  of distinct characters.

Space Complexity: O(k)
- The map stores at most k distinct characters.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestNonRepeatingSubstring(string& s) {

        // Map stores the frequency of characters
        // present in the current window
        map<char, int> mp;

        int l = 0;
        int r = 0;

        int mx_length = 0;

        while (r < s.size()) {

            // Remove characters from the left until
            // the duplicate character is removed
            while (mp[s[r]] > 0) {
                mp[s[l]]--;
                l++;
            }

            // Include the current character in the window
            mp[s[r]]++;

            // Calculate the current window length
            mx_length = max(mx_length, r - l + 1);

            // Expand the window
            r++;
        }

        return mx_length;
    }
};