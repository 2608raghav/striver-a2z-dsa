/*
Problem: Merge Overlapping SubIntervals
Platform: LeetCode
Topic: Array

Approach:
1. We first sort the input vector "intervals" based on the starting times of the intervals. Sorting helps us to easily identify overlapping intervals.
2. We initialize an empty vector of vectors "ans" to store the resulting merged intervals.

Time Complexity: O(n log n) due to sorting, where n is the number of intervals.
Space Complexity: O(1) if we don't consider the space required for the output vector.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
     vector<vector<int>>ans;
     sort(intervals.begin(),intervals.end());
     for(int i=0;i<intervals.size();i++){
        if(ans.empty() || ans.back()[1]<intervals[i][0]){
            ans.push_back(intervals[i]);
        }
        else{
            ans.back()[1] = max(ans.back()[1],intervals[i][1]);
        }
     }   
     return ans;
    }
};