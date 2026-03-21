/*
Problem: Count SubArray with XOR k
Platform: GeeksforGeeks
Topic: Array

Approach:
1. Initialize a variable "count" to 0. This variable will be used to store the result.
2. Initialize a variable "XR" to 0. This variable will be used to store the cumulative XOR of the elements in the array.
3. Initialize a variable "x" to 0. This variable will be used to store the XOR of the cumulative XOR and k.
4. Use a HashMap to store the frequency of cumulative XOR values.

Time Complexity: O(n) since we need to iterate through the input array once to calculate the cumulative XOR and update the HashMap.
Space Complexity: O(n) in the worst case if all cumulative XOR values are unique and stored in the HashMap.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long subarrayXor(int arr[], int n, int k) {
        long count = 0;
        int XR = 0;
        int x = 0;

        unordered_map<int, int> mp;
        mp[0] = 1;

        for (int i = 0; i < n; i++) {
            XR = XR ^ arr[i];
            x = XR ^ k;   // left out part

            if (mp.find(x) != mp.end()) {
                count += mp[x];
            }

            mp[XR]++;
        }

        return count;
    }
};