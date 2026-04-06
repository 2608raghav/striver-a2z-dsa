/*
Problem: Minimize Max Distance to Gas Station
Platform: Leetcode
Topic: Binary Search

Approach:
1. Initialize two pointers, one at 0 (the minimum possible distance) and one at the maximum distance between any two gas stations (the maximum possible distance).
2. Calculate the middle distance.
3. Calculate the number of additional gas stations needed to ensure that the distance between any two gas stations is less than or equal to the middle distance.
4. If the number of additional gas stations needed is less than or equal to the given number of additional gas stations (K), it means we can achieve the middle distance or a smaller distance. Therefore, update the end pointer to mid.
5. If the number of additional gas stations needed is greater than the given number of additional gas stations (K), it means we need to allow for a larger distance. Therefore, update the start pointer to mid.
6. Repeat steps 2-5 until the start pointer is equal to the end pointer.

Time Complexity: O(n log d) where n is the number of gas stations and d is the range of possible distances (from 0 to the maximum distance between any two gas stations). The binary search takes O(log d) time and calculating the number of additional gas stations needed takes O(n) time.
Space Complexity: O(1) as we are using only a constant amount of extra space.

*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    double minmaxGasDist(vector<int>& stations, int K) {
        int n = stations.size();
        double start = 0;
        double end = 0;
        for(int i=1;i<n;i++){
            end = max(end,(double)(stations[i]-stations[i-1]));
        }
        while(end-start>1e-6){ // We can use a small epsilon value to determine when to stop the binary search
            double mid = (start+end)/2;
            int count = 0;
            for(int i=1;i<n;i++){
                count += (int)((stations[i]-stations[i-1])/mid); // Calculate how many additional gas stations are needed for this distance
            }
            if(count<=K){
                end = mid; // We can try for a smaller distance
            }
            else{
                start = mid; // We need a larger distance
            }
        }
        return start; // or end, both are the same at this point
    }
};
