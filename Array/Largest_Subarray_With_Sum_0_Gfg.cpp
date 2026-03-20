/*
Problem: Largest Subarray With Sum 0
Platform: GeeksforGeeks
Topic: Array

Approach:
1. We initialize an unordered map "mp" to store the cumulative sum and its corresponding index. We also initialize two variables "sum" to keep track of the cumulative sum and "mx" to keep track of the maximum length of the subarray with sum 0.
2. We iterate through the array using a for loop. For each element at index "i":
   - We add the current element to "sum" to update the cumulative sum.
   - If "sum" is equal to 0, it means we have found a subarray from the beginning of the array to the current index "i" that sums up to 0. We update "mx" with the maximum of its current value and "i + 1" (the length of this subarray).
   - If "sum" is already present in the map "mp", it means we have found a subarray that sums up to 0 between the previous index where this sum was seen and the current index "i". We calculate the length of this subarray as "i - prevIndex" and update "mx" with the maximum of its current value and this length.
   - If "sum" is not present in the map, we add it to the map with its corresponding index "i".
3. After iterating through the entire array, "mx" will hold the length of the largest subarray with sum 0. We return "mx".


Time Complexity: O(n) since we need to iterate through the array once to find the largest subarray with sum 0.
Space Complexity: O(n) as we are using an unordered map to store the cumulative sum and its corresponding index.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxLength(int arr[], int n) {
        unordered_map<int, int> mp;
        int sum = 0;
        int mx = 0;

        for (int i = 0; i < n; i++) {
            sum += arr[i];

            if (sum == 0) {
                mx = max(mx, i + 1);
            }

            if (mp.find(sum) != mp.end()) {
                int prevIndex = mp[sum];
                mx = max(mx, i - prevIndex);
            } else {
                mp[sum] = i;
            }
        }

        return mx;
    }
};