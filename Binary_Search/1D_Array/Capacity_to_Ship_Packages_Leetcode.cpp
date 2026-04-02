/*
Problem: Capacity to Ship Packages Within D Days
Platform: Leetcode
Topic: Binary Search

Approach:
1. Initialize two pointers, one at the maximum weight of a single package (the minimum capacity) and one at the sum of all package weights (the maximum capacity).
2. Calculate the middle capacity.
3. Calculate the total number of days required to ship all packages with the middle capacity.
4. If the total number of days required is less than or equal to the given days (D), update the index of the minimum capacity and search in the left half (lower capacities).
5. If the total number of days required is greater than the given days (D), search in the right half (higher capacities).
6. Repeat steps 2-5 until the pointers cross each other.

Time Complexity: O(n log m) where n is the number of packages and m is the sum of all package weights. The binary search takes O(log m) time and calculating the total days takes O(n) time.
Space Complexity: O(1) as we are using only a constant amount of extra space.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
       int n = weights.size();
    if(days>n){
        return -1;
    }
    int sum =0;
    int start = 0;
    for(int i=0;i<n;i++){
        sum = sum+weights[i];
        start = max(start,weights[i]);
    }
    
    int end = sum;
    int count =1;
    int pages =0;
    int ans =0;
    int mid =0;
    while(start<=end){
        mid = (start+end)/2;
        pages =0;
        count =1;
        for(int i=0;i<n;i++){
           pages = pages + weights[i];
           if(pages>mid){
            count++;
            pages = weights[i];
           }
           
        }
        if(count<=days){
          ans = mid;
          end = mid-1;
        }
        else{
            start = mid+1;
        }

        
    }
    return ans;
       
    }
};
