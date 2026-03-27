/*
Problem: Number of Occurrence
Platform: GeeksforGeeks
Topic: Binary Search

Approach:
1. Initialize two pointers, one at the beginning and one at the end of the array.
2. Calculate the middle index.
3. For finding the first occurrence, if the element at the middle index is equal to the target, update the index of the first occurrence and search in the left half. If the element at the middle index is less than the target, search in the right half. If it is greater than the target, search in the left half.
4. For finding the last occurrence, if the element at the middle index is equal to the target, update the index of the last occurrence and search in the right half. If the element at the middle index is less than the target, search in the right half. If it is greater than the target, search in the left half.
5. Repeat steps 2-4 until the pointers cross each other.



Time Complexity: O(log n) in the worst and average cases, as we are dividing the search space in half at each step. In the best case (when the array is already sorted), the time complexity is O(log n).
Space Complexity: O(1) as we are using only a constant amount of extra space.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int countFreq(vector<int>& nums, int target) {
        // code here
       
        
        int first = nums.size();
        int start =0;
        int end = nums.size()-1;
        // for finding the first ocurence
        while(start<=end){
            int mid = (start+end)/2;
            if(nums[mid]==target){
                first = min(first,mid);
                end = mid-1;
            }
            else if(nums[mid]<target){
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }

        // for last occurenace

        
       int last = -1;
        start =0;
        end = nums.size()-1;

         while(start<=end){
            int mid = (start+end)/2;
            if(nums[mid]==target){
                last = max(last,mid);
                start = mid+1;
            }
            else if(nums[mid]<target){
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        int result =0;
        if((nums.size() && last==-1) or nums.size()==0 ){
            return result;
        }
        result = (last-first)+1;
        return result;
    }
};
