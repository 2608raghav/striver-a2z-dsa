/*
Problem: Linear Search
Platform: GeeksforGeeks
Topic: Array

Approach:
1. Iterate through the array and compare each element with the target value.
2. If a match is found, return the index of the element.
3. If the loop ends and the target value is not found, return -1 to indicate that the element is not present in the array.


Time Complexity: O(n) since we may need to check each element in the worst case.
Space Complexity: O(1) as we are using only a constant amount of extra space to store the index and the target value.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int search(vector<int>& arr, int x) {
        // code here
        for(int i=0;i<arr.size();i++){
            if(arr[i]==x){
                return i;
            }
        }
        return -1;
    }
};