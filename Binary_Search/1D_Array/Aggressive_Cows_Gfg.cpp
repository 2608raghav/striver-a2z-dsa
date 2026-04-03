/*
Problem: Aggressive Cows
Platform: Gfg
Topic: Binary Search

Approach:
1. Sort the array of stall positions.
2. Initialize two pointers, one at the minimum distance (1) and one at the maximum distance (the difference between the last and first stall positions).
3. Calculate the middle distance.
4. Count the number of cows that can be placed in the stalls with at least the middle distance apart.
5. If the count of cows is greater than or equal to the given number of cows (C), update the index of the minimum distance and search in the right half (higher distances).
6. If the count of cows is less than the given number of cows (C), search in the left half (lower distances).
7. Repeat steps 3-6 until the pointers cross each other. The index of the maximum minimum distance will be returned.


Time Complexity: O(n log n) for sorting the stall positions and O(log m) for the binary search, where n is the number of stalls and m is the maximum distance between the first and last stall. The overall time complexity is O(n log n + log m).
Space Complexity: O(1) as we are using only a constant amount of extra space.
*/

#include <bits/stdc++.h>
using namespace std;
// User function Template for C++

class Solution {
  public:

    int aggressiveCows(vector<int> &stalls, int k) {

        // Write your code here
        sort(stalls.begin(),stalls.end()); 

    int n = stalls.size();

    int start = 0; 
    
    int end = (stalls[n-1] - stalls[0]); 

    int mid = 0;
    int ans = 0;
    
    
    int lastChosenElement = 0; 
    int count = 0;

    while(start <= end){
        mid = start + (end - start) / 2; 

        lastChosenElement = stalls[0]; 
        count = 1; 

        for(int i = 1; i < n; i++){
          
            int required_value = lastChosenElement + mid; 
            
            if(stalls[i] >= required_value){
                lastChosenElement = stalls[i]; 
                count++;
            }
        }
        
       if(count >= k){
            ans = mid;         
            start = mid + 1;
        } else {
            end = mid - 1;     
        }
    }
    
    
    return ans;
    }
};
    