/*
Problem: Factorial
Platform: GeeksforGeeks
Topic: Recursion

Approach:
1. Base Case: If n is less than or equal to 0, return 1 (since the factorial of 0 is defined as 1).
2. Recursive Case: Return n multiplied by the result of the function called with n-1, which will calculate the factorial of n by multiplying n with the factorial of (n-1).

Time Complexity: O(n) since we are making n recursive calls.
Space Complexity: O(n) due to the recursive call stack, which can go up to n levels deep.

*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    long long factorial(int n) {
        // code here
        if(n==0 || n==1){
            return 1;
        }
        else{
            return 1LL * n * factorial(n-1); // Use 1LL to ensure the multiplication is done in long long to prevent overflow for larger values of n.
        }
    }
};