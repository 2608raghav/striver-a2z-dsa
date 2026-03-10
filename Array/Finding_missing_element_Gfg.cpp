/*
Problem: Finding Missing Element
Platform: GeeksforGeeks
Topic: Array

Approach:
1. Calculate the total number of elements "no" in the array, which is the size of the input vector plus one (since one element is missing).
2. Calculate the sum of the first "no" natural numbers using the formula: sum = (no * (no + 1)) / 2.
3. Initialize a variable "s" to store the sum of the elements in the input array
4. Iterate through the input array and add each element to "s".
5. Finally, return the difference between the total sum of the first "no" natural numbers and the sum of the elements in the input array, which will give us the missing element.


Time Complexity: O(n) since we need to iterate through the input array once to calculate the sum of its elements.
Space Complexity: O(1) as we are only using a constant amount of extra space.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int missingNum(vector<int>& arr) {
        // code here
        long long no = arr.size()+1;
        long sum = (no*(no+1))/2;
        long long s =0;
        for(int i=0;i<arr.size();i++){
            s+=arr[i];
        }
        return (sum-s);
        
    }
};