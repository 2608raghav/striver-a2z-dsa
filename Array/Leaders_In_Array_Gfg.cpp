/*
Problem: Leaders in an Array
Platform: GeeksforGeeks
Topic: Array

Approach:
1. Initialize a variable "mx" with the value of the last element of the array, as the last element is always a leader.
2. Create an empty vector "res" to store the leaders found in the array.
3. Iterate through the array in reverse order starting from the second last element:
   - For each element, compare it with the current "mx". If the current element is greater than or equal to "mx", it means it is a leader. Push it into the "res" vector and update "mx" with the value of the current element.
4. After iterating through the entire array, the "res" vector will contain the leaders in reverse order. Reverse the "res" vector to get the leaders in the correct order and return it.

Time Complexity: O(n) since we need to iterate through the array once to find the leaders.
Space Complexity: O(n) as we are using an additional vector to store the leaders found in the array.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> leaders(vector<int>& arr) {
        // code here
        int n = arr.size();
        int mx = arr[n-1];
        vector<int>res;
        res.push_back(arr[n-1]);
        for(int i=n-2;i>=0;i--){
            if(arr[i]>=mx){
                res.push_back(arr[i]);
                mx = arr[i];
            }
        }
        int start =0;
        int end = res.size()-1;
        while(start<=end){
            swap(res[start],res[end]);
            start++;
            end--;
        }
        return res;
    }
};