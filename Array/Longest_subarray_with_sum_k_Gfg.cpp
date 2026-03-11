/*
Problem: Longest subarray with sum k
Platform: GeeksforGeeks
Topic: Array

Approach:
1. We can use a hash map to store the prefix sums and their corresponding indices.
2. Initialize a variable "sum" to keep track of the current prefix sum and a variable "len" to keep track of the length of the longest subarray found so far.
3. Iterate through the array and for each element:
    - Add the current element to "sum".
    - Check if "sum" is equal to "k". If it is, update "len" with the maximum of "len" and the current index + 1 (since the subarray starts from index 0).
    - Calculate the remaining sum "rem" by subtracting "k" from "sum". If "rem" exists in the hash map, it means there is a subarray that sums up to "k" between the index stored in the hash map and the current index. Update "len" with the maximum of "len" and the difference between the current index and the index stored in the hash map for "rem".
    - If "sum" does not exist in the hash map, store it along with the current index.

Time Complexity: O(n) since we need to iterate through the array once to find the longest subarray with sum k.
Space Complexity: O(n) as we are using a hash map to store the prefix sums and their indices.
*/

#include <bits/stdc++.h>
using namespace std;
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& arr, int k) {

        unordered_map<int,int> mp;

        int sum = 0;
        int len = 0;

        for(int i = 0; i < arr.size(); i++){
            sum += arr[i];

          
            if(sum == k){
                len = max(len, i + 1);
            }

           
            int rem = sum - k;
            if(mp.find(rem) != mp.end()){
                len = max(len, i - mp[rem]);
            }

            
            if(mp.find(sum) == mp.end()){
                mp[sum] = i;
            }
        }

        return len;
    }
};
