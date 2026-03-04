/*
Problem: Insertion Sort
Platform: GeeksforGeeks
Topic: Sorting

Approach:
1. Iterate through the array from the second element to the end of the array.
2. For each element, store it as the "key" and compare it with the elements in the sorted portion of the array (to its left).
3. Shift the elements in the sorted portion that are greater than the key to one position ahead of their current position.
4. Insert the key into its correct position in the sorted portion of the array.



Time Complexity: O(n^2) in the worst and average cases, as we have two nested loops. In the best case (when the array is already sorted), the time complexity is O(n) because we only compare each element once.
Space Complexity: O(1) as we are sorting the array in-place and using only a constant amount of extra space.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    void insertionSort(vector<int>& arr) {
        // code here
        for(int i=1;i<arr.size();i++){
            for(int j=i;j>0;j--){
                if(arr[j-1]>arr[j]){
                    swap(arr[j-1],arr[j]);
                }
                else{
                    break;
                }
            }
        }
    }
};
