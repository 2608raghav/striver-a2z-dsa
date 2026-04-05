/*
Problem: Minimum days to make M bouquets
Platform: Leetcode
Topic: Binary Search

Approach:
1. Initialize two pointers, one at the minimum bloom day and one at the maximum bloom day.
2. Calculate the middle day.
3. Count the number of bouquets that can be made by the middle day.
4. If the number of bouquets is greater than or equal to M, it means we can make the required bouquets by the middle day. Therefore, update the end pointer to mid.
5. If the number of bouquets is less than M, it means we cannot make the required bouquets by the middle day. Therefore, update the start pointer to mid + 1.
6. Repeat steps 2-5 until the start pointer is equal to the end pointer.

Time Complexity: O(n log d) where n is the number of flowers and d is the range of bloom days. The binary search takes O(log d) time and counting the bouquets takes O(n) time.
Space Complexity: O(1) as we are using only a constant amount of extra space.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if(m*k>n){
            return -1;
        }
        int start = *min_element(bloomDay.begin(),bloomDay.end());
        int end = *max_element(bloomDay.begin(),bloomDay.end());
        while(start<end){
            int mid = (start+end)/2;
            int bouquets = 0;
            int flowers = 0;
            for(int i=0;i<n;i++){
                if(bloomDay[i]<=mid){
                    flowers++;
                    if(flowers==k){
                        bouquets++;
                        flowers=0;
                    }
                }
                else{
                    flowers=0;
                }
            }
            if(bouquets>=m){
                end=mid;
            }
            else{
                start=mid+1;
            }
        }
        return start;
    }
};

