/*
Problem: Book Allocation Problem
Platform: Gfg
Topic: Binary Search

Approach:
1. Initialize two pointers, one at the maximum number of pages in a single book (the minimum number of pages) and one at the sum of all pages (the maximum number of pages).
2. Calculate the middle number of pages.
3. Calculate the total number of students required to allocate all books with the middle number of pages.
4. If the total number of students required is less than or equal to the given number of students (k), update the index of the minimum number of pages and search in the left half (lower number of pages).
5. If the total number of students required is greater than the given number of students (k), search in the right half (higher number of pages).
6. Repeat steps 2-5 until the pointers cross each other.

Time Complexity: O(n log m) where n is the number of books and m is the sum of all pages. The binary search takes O(log m) time and calculating the total students takes O(n) time.
Space Complexity: O(1) as we are using only a constant amount of extra space.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int findPages(vector<int> &arr, int k) {
        // code here
        
    int n = arr.size();
    if(k>n){
        return -1;
    }
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
        
    }
};