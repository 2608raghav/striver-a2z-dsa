/*
Problem: Merge Sort
Platform: GeeksforGeeks
Topic: Sorting

Approach:
1. Divide the array into two halves until we reach arrays of size one (base case).
2. Merge the sorted halves back together in a sorted manner.




Time Complexity: O(n log n) since we divide the array into two halves recursively and then merge them in linear time.
Space Complexity: O(n) as we are using an additional temporary array for merging.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    void merge(vector<int>&arr,int start,int mid,int end){
            
            int left = start;
            int right = mid+1;
            vector<int>temp;
            while(left<=mid && right<=end){
                if(arr[left]<=arr[right]){
                    temp.push_back(arr[left]);
                    left++;
                }
                else{
                    temp.push_back(arr[right]);
                    right++;
                }
            }
           
            while(left<=mid){
                temp.push_back(arr[left]);
                left++;
            }
            while(right<=end){
                temp.push_back(arr[right]);
                right++;
            }
            
            int index =0;
            for(int i=start;i<=end;i++){
                arr[i]= temp[index];
                index++;
            }
        }
        
    void mergeSort(vector<int>& arr, int l, int r) {
        // code here
      if(l>=r){
          return ;
      }
      int mid = l+(r-l)/2;
      mergeSort(arr,l,mid);
      mergeSort(arr,mid+1,r);
      merge(arr,l,mid,r);
    }
};