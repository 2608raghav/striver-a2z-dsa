/*
Problem: Selection Sort
Platform: GeeksforGeeks
Topic: Sorting

Approach:
1. Iterate through the array from the first element to the second last element.
2. For each element, find the minimum element in the unsorted portion of the array (
    starting from the current element to the end of the array).
3. Swap the current element with the minimum element found in the unsorted portion.



Time Complexity: O(n^2) since we have two nested loops, each iterating up to n elements.
Space Complexity: O(1) as we are sorting the array in-place and using only a constant amount of extra space.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    // Function to perform selection sort on the given array.
    void selectionSort(vector<int> &arr) {
        // code here
        int n = arr.size();
        for(int i=0;i<n-1;i++){
            int index = i;
            for(int j=i+1;j<n;j++){
                if(arr[j]<arr[index]){
                    index = j;
                }
            }
            swap(arr[i],arr[index]);
        }
    }
};