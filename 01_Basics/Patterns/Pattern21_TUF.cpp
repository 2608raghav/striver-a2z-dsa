/*
Problem: Print the following pattern for a given N:
Platform: TUF
Topic: Basic Math

Approach:
1. We will use two nested loops to generate the pattern. The outer loop will iterate from 0 to N-1 for the upper half of the pattern and from N-1 to 0 for the lower half.
2. The inner loop will iterate from 0 to N-1 and will print either a space or a star based on the condition j == 0 || j == n-1 for the first and last rows, and for the other rows, it will print a star only at the first and last column.

Time Complexity: O(N^2) - We have two nested loops, each running N times.
Space Complexity: O(1) - We are using a constant amount of space to store the loop variables.


*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void pattern21(int n) {
       
       for(int i=0;i<n;i++){
         if(i==0 || i==n-1){
            for(int j=0;j<n;j++){
                cout<<"*";
            }
            cout<<endl;
         }
         else{
         for(int j=0;j<n;j++){
            if(j==0 || j==n-1){
                cout<<"*";
            }
            else{
                cout<<" ";
            }
         }
         cout<<endl;
         }
       }
    }
};