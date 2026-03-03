/*
Problem: Fibonacci Number
Platform: LeetCode
Topic: Recursion

Approach:
1. Base Cases: If n is 0, return 0. If n is 1, return 1.
2. Recursive Case: For n greater than 1, return the sum of the function called with n-1 and n-2, which will calculate the Fibonacci number by summing the two preceding Fibonacci numbers.


Time Complexity: O(2^n) since each call to fib(n) results in two additional calls to fib(n-1) and fib(n-2), leading to an exponential growth in the number of calls.
Space Complexity: O(n) due to the recursive call stack, which can go up to n levels deep in the worst case when n is large.

*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int fib(int n) {
        if(n==0){
            return 0;
        }
        else if(n==1){
            return 1;
        }
        
            return fib(n-1)+fib(n-2);
        
    }
};