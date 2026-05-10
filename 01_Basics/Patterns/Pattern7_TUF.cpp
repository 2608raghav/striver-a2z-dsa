/*
Problem: Print the following pattern for a given N:
Platform: TUF
Topic: Basic Math

Approach:
1. We will use two nested loops to print the pattern.
2. The outer loop will run from 0 to N-1, which will represent the number of rows.
3. The inner loop will run from 0 to N-1, which will represent the number of columns in each row.
4. In each iteration of the inner loop, we will check if the sum of the current row index (i) and column index (j) is greater than or equal to (N-1). If it is, we will print an asterisk (*), otherwise we will print a space.
5. After the inner loop completes for each row, we will print a newline character to move to the next line.

Time Complexity: O(N^2) because we have two nested loops, where the inner loop runs N times for each iteration of the outer loop, leading to a total of N * N = O(N^2) iterations.
Space Complexity: O(1) since we are only using a constant amount of extra space for variables.

*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void pattern7(int n) {
        int count =0;
         for(int i=0;i<n;i++){
            count =0;
            for(int j=0;j<n;j++){
                if(j+i>=(n-1)){
                    cout<<"*";
                    count++;
                }
                else{
                    cout<<" ";
                }
            }
            count--;
            while(count!=0){
                cout<<"*";
                count--;
            }
            cout<<endl;
         }
    }
};