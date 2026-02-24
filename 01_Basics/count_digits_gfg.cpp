/*
Problem: Count Digits
Platform: GeeksforGeeks
Topic: Basic Math
Approach: Divide by 10 repeatedly
Time Complexity: O(log10(n))
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countDigits(int n) {
        if(n==0){
            return 1;
        }

        n = abs(n); 
        int count = 0;

        while(n > 0){
            count++;
            n /= 10;
        }

        return count;
    }
};