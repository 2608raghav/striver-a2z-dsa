/*
Problem: Koko Eating Bananas
Platform: Leetcode
Topic: Binary Search

Approach:
1. Initialize two pointers, one at the minimum eating speed (1) and one at the maximum eating speed (the maximum number of bananas in any pile).
2. Calculate the middle eating speed.
3. Calculate the total hours required for Koko to eat all the bananas at the middle eating speed.
4. If the total hours required is less than or equal to the given hours (h), update the index of the minimum eating speed and search in the left half (lower eating speeds).
5. If the total hours required is greater than the given hours (h), search in the right half (higher eating speeds).
6. Repeat steps 2-5 until the pointers cross each other.


Time Complexity: O(n log m) where n is the number of piles and m is the maximum number of bananas in any pile. The binary search takes O(log m) time and calculating the total hours takes O(n) time.
Space Complexity: O(1) as we are using only a constant amount of extra space.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(),piles.end());
        int n  = piles.size();
        int start = 1;
        int end = piles[n-1];
        int mid =0;
        float base =0;
        double time =0.0;
        int ans =0;
        
        while(start<=end){
            mid = (start+end)/2;
            
            time =0;
            for(int i=0;i<n;i++){
               
                time = time + ceil(static_cast<double>(piles[i]) / mid);
                
            }
            cout<<time<<endl;
            if(time<=h){
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
    
