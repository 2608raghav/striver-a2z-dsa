/*
Problem: Find Largest Element
Platform: GeeksforGeeks
Topic: Sorting_In_Array

Approach:
1. Initialize a variable "max" with the value of the first element of the array.
2. Iterate through the array starting from the second element.
3. For each element, compare it with the current "max". If the current element is greater than "max", update "max" with the value of the current element.
4. After iterating through the entire array, "max" will hold the largest element in the array. Return "max".




Time Complexity: O(n) since we need to iterate through the array once to find the largest element.
Space Complexity: O(1) as we are using only a constant amount of extra space to store the "max" variable.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int largest(vector<int> &arr) {
        // code here
        int max =arr[0];
        for(int i=1;i<arr.size();i++){
            if(arr[i]>max){
                max = arr[i];
            }
        }
        return max;
    }
};
