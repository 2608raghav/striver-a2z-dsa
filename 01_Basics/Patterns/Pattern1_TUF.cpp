/*
Problem: Print the following pattern for a given N:
Platform: TUF
Topic: Basic Math

Approach:
1. We will use two nested loops to print the pattern.
2. The outer loop will run from 0 to N-1, which will represent the number of rows.
3. The inner loop will also run from 0 to N-1, which will represent the number of columns in each row.
4. In each iteration of the inner loop, we will print an asterisk (*).
5. After the inner loop completes for each row, we will print a newline character to move to the next line.

Time Complexity: O(N^2) because we have two nested loops, each running N times.
Space Complexity: O(1) since we are only using a constant amount of extra space for variables.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void pattern1(int n) {
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        cout<<"*";
    }
    cout<<endl;
}
    }
};