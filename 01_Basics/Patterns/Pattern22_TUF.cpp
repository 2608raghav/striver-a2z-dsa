/*
Problem: Print the following pattern for a given N:
Platform: TUF
Topic: Basic Math

Approach:
1. We will use two nested loops to generate the pattern. The outer loop will iterate from 0 to N-1 for the upper half of the pattern and from N-1 to 0 for the lower half.
2. The inner loop will iterate from 0 to N-1 and will print either a space or a star based on the condition j <= i for the first half and (k <= i) for the second half.

Time Complexity: O(N^2) - We have two nested loops, each running N times.
Space Complexity: O(1) - We are using a constant amount of space to store the loop variables.


*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void pattern22(int n) {
      
      int size = 2 * n - 1;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int top = i;
            int left = j;
            int bottom = size - 1 - i;
            int right = size - 1 - j;
            cout<< (n - min({top, left, bottom, right})) << " ";
        }
        cout<<endl;
    }
    }
};