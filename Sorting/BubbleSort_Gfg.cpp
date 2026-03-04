/*
Problem: Bubble Sort
Platform: GeeksforGeeks
Topic: Sorting

Approach:
1. Iterate through the array multiple times.
2. In each iteration, compare adjacent elements and swap them if they are in the wrong order
    (i.e., if the current element is greater than the next element).
3. Repeat this process until the array is sorted. The largest element will "bubble up"
    to the end of the array in each iteration, so we can reduce the number of comparisons
    in subsequent iterations.




Time Complexity: O(n^2) in the worst and average cases, as we have two nested loops. In the best case (when the array is already sorted), the time complexity is O(n) due to the optimization that checks if any swaps were made.
Space Complexity: O(1) as we are sorting the array in-place and using only a constant amount of extra space.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    void bubbleSort(vector<int>& arr) {
        // code here
        for(int i=0;i<arr.size()-1;i++){
            for(int j= 0;j<arr.size()-i-1;j++){
                if(arr[j]>arr[j+1]){
                    swap(arr[j],arr[j+1]);
                }
            }
        }
    }
};