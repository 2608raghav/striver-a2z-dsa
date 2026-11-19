/*
Problem: Longest K Unique Characters Substring
Platform: GeeksforGeeks
Topic: String, Sliding Window, Two Pointers, Hash Map

Approach:
1. Use two pointers:
      l = 0  -> Left boundary of the window
      r = 0  -> Right boundary of the window

2. Maintain an unordered_map to store the frequency
   of characters present in the current window.

3. Expand the window by moving the right pointer r.

4. Add the current character to the map:
      mp[s[r]]++

5. Check whether the window contains more than K
   distinct characters.

   If mp.size() > k:
      - Shrink the window from the left.
      - Decrease the frequency of s[l].
      - If its frequency becomes zero, erase it
        from the map.
      - Increment l.
      - Continue until at most K distinct characters
        remain.

6. Check whether the window contains exactly K
   distinct characters.

   If mp.size() == k:
      - Calculate the current window length:

            length = r - l + 1

      - Update the maximum length:

            mx = max(mx, length)

7. Increment r and continue until the entire string
   has been traversed.

8. Return mx.
   If no substring contains exactly K distinct
   characters, return -1.

Time Complexity: O(n) average
- Each character enters and leaves the window at most once.
- Unordered_map operations take O(1) average time.

Space Complexity: O(k)
- The map stores at most K distinct characters
  after the window is adjusted.
*/

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int longestKSubstr(string &s, int k) {

        int l = 0;
        int r = 0;

        int mx = -1;

        unordered_map<char, int> mp;

        while (r < s.size()) {

            // Add the current character to the window
            mp[s[r]]++;

            // Shrink the window if distinct characters
            // become greater than K
            while (mp.size() > k) {

                mp[s[l]]--;

                // Remove the character if its frequency is zero
                if (mp[s[l]] == 0) {
                    mp.erase(s[l]);
                }

                l++;
            }

            // Update answer only when exactly K
            // distinct characters are present
            if (mp.size() == k) {
                mx = max(mx, r - l + 1);
            }

            // Expand the window
            r++;
        }

        return mx;
    }
};