/*
Problem: Fruits Into Baskets
Platform: GeeksforGeeks
Topic: Array, Sliding Window, Two Pointers, Hash Map

Approach:
1. Use two pointers:
      l = 0  -> Left boundary of the window
      i = 0  -> Right boundary of the window

2. Use an unordered_map to store the frequency of each
   fruit type present in the current window.

3. Traverse the fruits array using the right pointer i.

4. Add the current fruit to the map:
      mp[fruits[i]]++

5. Check whether the window contains more than two
   distinct fruit types.

   If mp.size() > 2:
      - Shrink the window from the left.
      - Decrease the frequency of fruits[l].
      - If its frequency becomes zero, erase it from
        the map.
      - Increment l.
      - Continue until at most two distinct types remain.

6. Once the window becomes valid:
      - Calculate its length:

            length = i - l + 1

      - Update the maximum length:

            max_length = max(max_length, length)

7. Continue until the entire array is traversed.

8. Return max_length.

Time Complexity: O(n) average
- Each element enters and leaves the window at most once.
- Unordered_map operations take O(1) average time.

Space Complexity: O(1)
- The map stores at most three distinct fruit types
  temporarily before the window is shrunk.
*/

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int totalFruits(vector<int>& fruits) {

        unordered_map<int, int> mp;

        int l = 0;
        int max_length = 0;

        for (int i = 0; i < fruits.size(); i++) {

            // Add the current fruit to the window
            mp[fruits[i]]++;

            // Shrink the window if more than two
            // distinct fruit types are present
            while (mp.size() > 2) {

                mp[fruits[l]]--;

                // Remove the fruit if its frequency becomes zero
                if (mp[fruits[l]] == 0) {
                    mp.erase(fruits[l]);
                }

                l++;
            }

            // Update the maximum valid window length
            max_length = max(max_length, i - l + 1);
        }

        return max_length;
    }
};