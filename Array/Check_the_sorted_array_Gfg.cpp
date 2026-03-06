/*
Problem: Check if the array is sorted
Platform: GeeksforGeeks
Topic: Sorting_In_Array

Approach:
1. Iterate through the array from the first element to the second last element.
2. For each element, compare it with the next element. If the current element is greater than the next element, it means the array is not sorted in non-decreasing order. In this case, return false.
3. If we finish iterating through the array without finding any such case, it means the array is sorted in non-decreasing order. In this case, return true.


Time Complexity: O(n) since we need to iterate through the array once to check if it is sorted.
Space Complexity: O(1) as we are using only a constant amount of extra space to store the loop variable and perform comparisons.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    bool isSorted(vector<int>& arr) {
        // code here
        for(int i=0;i<arr.size()-1;i++){
            if(arr[i]>arr[i+1]){
                return false;
            }
        }
        return true;
    }
};