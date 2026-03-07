/*
Problem: `Rotate Array By one
Platform: GeeksforGeeks
Topic: Array

Approach:
1. To rotate the array by one position to the right, we can follow these steps:
   - Store the last element of the array in a temporary variable.
   - Shift all elements of the array one position to the right, starting from the second last element down to the first element.
   - Place the temporary variable (the last element) at the first position of the array.


Time Complexity: O(n) since we need to iterate through the array once to shift the elements.
Space Complexity: O(1) as we are using only a constant amount of extra space to store the temporary variable.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  void reverse(vector<int> &arr,int start,int end){
      while(start<=end){
          swap(arr[start],arr[end]);
          start++;
          end--;
      }
  }
    void rotate(vector<int> &arr) {
        // code here
        int n = arr.size();
        reverse(arr,0,n-2);
        reverse(arr,0,n-1);
        
    }
};