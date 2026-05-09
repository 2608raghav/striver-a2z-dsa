/*
Problem: Print the following pattern for a given N:
Platform: TUF
Topic: Basic Math

Approach:
1. We will use two nested loops to print the pattern.
2. The outer loop will run from N down to 1, which will represent the number of rows.
3. The inner loop will run from i down to 1, which will represent the number of columns in each row (decreasing by one each row).
4. In each iteration of the inner loop, we will print an asterisk (*).
5. After the inner loop completes for each row, we will print a newline character to move to the next line.

Time Complexity: O(N^2) because we have two nested loops, where the inner loop runs i times for each iteration of the outer loop, leading to a total of N + (N-1) + ... + 1 = O(N^2) iterations.
Space Complexity: O(1) since we are only using a constant amount of extra space for variables.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void pattern5(int n) {
       for(int i=n;i>0;i--){
        for(int j=i;j>0;j--){
            cout<<"*";
        }
        cout<<endl;
       }
    }
};