/*
Problem: Upper Bound
Platform: GeeksforGeeks
Topic: Binary Search

Approach:
1. Initialize two pointers, one at the beginning and one at the end of the array.
2. Calculate the middle index.
3. Compare the target with the element at the middle index.
4. If the element at the middle index is greater than the target, update the index of the upper bound and search in the left half.
5. If the element at the middle index is less than or equal to the target, search in the right half.
6. Repeat steps 2-6 until the pointers cross each other.



Time Complexity: O(log n) in the worst and average cases, as we are dividing the search space in half at each step. In the best case (when the array is already sorted), the time complexity is O(log n).
Space Complexity: O(1) as we are using only a constant amount of extra space.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int upperBound(vector<int>& arr, int target) {
        // code here
          int start =0;
        int end = arr.size()-1;
        int index = end+1;
        while(start<=end){
            int mid = (start+end)/2;
            if(arr[mid]>target){
                 index = min(index,mid);
                 end--;
            }
            else if(arr[mid]>target){
                end--;
            }
            else{
                start++;
            }
        }
        return index;
    }
};
