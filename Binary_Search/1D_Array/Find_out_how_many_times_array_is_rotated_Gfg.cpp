/*
Problem: Find out how many times an array is rotated
Platform: GeeksforGeeks
Topic: Binary Search

Approach:
1. Initialize two pointers, one at the beginning and one at the end of the array.
2. Calculate the middle index.
3. If the element at the middle index is less than the element at the end index, it means the minimum element is in the left half of the array. Therefore, update the end pointer to mid.
4. If the element at the middle index is greater than the element at the end index,
it means the minimum element is in the right half of the array. Therefore, update the start pointer to mid + 1.
5. Repeat steps 2-4 until the start pointer is equal to the end pointer. The index of the minimum element will give us the number of times the array has been rotated.

Time Complexity: O(log n) in the worst and average cases, as we are dividing the search space in half at each step. In the best case (when the array is already sorted), the time complexity is O(1) as we can directly return 0.
Space Complexity: O(1) as we are using only a constant amount of extra space.

*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findKRotation(int arr[], int n) {
        // code here
        int start =0;
        int end = n-1;
        while(start<end){
            int mid = (start+end)/2;
            if(arr[mid]<arr[end]){
                end=mid;
            }
            else{
                start=mid+1;
            }
        }
        return start;
    }
};
