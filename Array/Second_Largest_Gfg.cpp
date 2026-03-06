/*
Problem: Find Second Largest Element
Platform: GeeksforGeeks
Topic: Sorting_In_Array

Approach:
1. First, find the largest element in the array by iterating through it once.
2. Initialize a variable "s_max" to store the second largest element, and set it to -1 (or any value that indicates no second largest element found).
3. Iterate through the array again, and for each element:
   - If the current element is greater than "s_max" and not equal to the largest element, update "s_max" with the value of the current element.
4. After iterating through the entire array, "s_max" will hold the second largest element in the array. Return "s_max".





Time Complexity: O(n) since we need to iterate through the array twice (once to find the largest element and once to find the second largest element).
Space Complexity: O(1) as we are using only a constant amount of extra space to store the "max" and "s_max" variables.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
         int max =arr[0];
        for(int i=1;i<arr.size();i++){
            if(arr[i]>max){
                max = arr[i];
            }
        }
        int s_max =-1;
        for(int i=0;i<arr.size();i++){
            if(arr[i]>s_max and arr[i]!=max){
                s_max = arr[i];
        }
    }
    return s_max;
    }
};