/*
Problem: Painter's Partition Problem
Platform: GeeksforGeeks
Topic: Binary Search

Approach:
1. Initialize two pointers, one at the maximum length of a single board (the minimum time) and one at the sum of all board lengths (the maximum time).
2. Calculate the middle time.
3. Calculate the total number of painters required to paint all boards with the middle time.
4. If the total number of painters required is less than or equal to the given number of painters (k), update the index of the minimum time and search in the left half (lower times).
5. If the total number of painters required is greater than the given number of painters (k), search in the right half (higher times).
6. Repeat steps 2-5 until the pointers cross each other.

Time Complexity: O(n log m) where n is the number of boards and m is the sum of all board lengths. The binary search takes O(log m) time and calculating the total painters takes O(n) time.
Space Complexity: O(1) as we are using only a constant amount of extra space.
*/

#include <bits/stdc++.h>
using namespace std;
// User function template for C++

class Solution {
  public:
    int minTime(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
    
    int sum =0;
    int start = 0;
    for(int i=0;i<n;i++){
        sum = sum+arr[i];
        start = max(start,arr[i]);
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
           pages = pages + arr[i];
           if(pages>mid){
            count++;
            pages = arr[i];
           }
           
        }
        if(count<=k){
          ans = mid;
          end = mid-1;
        }
        else{
            start = mid+1;
        }

        
    }
    return ans;
        // return minimum time
    }
};