/*
Problem: Sum of n numbers
Platform: GeeksforGeeks
Topic: Recursion

Approach:
1. Base Case: If n is less than or equal to 0, return 0 (since the sum of non-positive numbers is considered 0).
2. Recursive Case: Return n plus the result of the function called with n-1, which will add all numbers from n down to 1.


Time Complexity: O(n) since we are making n recursive calls.
Space Complexity: O(n) due to the recursive call stack, which can go up to n levels deep.

*/


#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
 
    long long nSum(long long n) {
    if (n <= 0)
        return 0;
    return n + nSum(n - 1);
}
};