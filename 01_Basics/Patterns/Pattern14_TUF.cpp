/*
Problem: Print the following pattern for a given N:
Platform: TUF
Topic: Basic Math

Approach:
1. We will use two nested loops to generate the pattern. The outer loop will iterate from 0 to N-1 for the upper half of the pattern and from N-1 to 0 for the lower half.
2. The inner loop will iterate from 0 to N-1 and will print either a space or an asterisk based on the condition j + i >= N - 1.
3. We will maintain a count of the number of asterisks printed in each row and use that count to print the additional asterisks needed to complete the pattern.

Time Complexity: O(N^2) - We have two nested loops, each running N times.
Space Complexity: O(1) - We are using a constant amount of space to store the count variable and the loop variables.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void pattern14(int n) {
        int count = 65;
        for(int i=0;i<n;i++){
            count =  65;
            for(int j=0;j<=i;j++){
                cout<<char(count);
                count++;
            }
            cout<<endl;
        }
    }
};