/*
Problem: Print GFG
Platform: GeeksforGeeks
Topic: Recursion

Approach:
1. Base Case: If n is 0, return (stop recursion).
2. Recursive Case: Print "GFG" and then call the function with n-1

Time Complexity: O(n) since we are making n recursive calls.
Space Complexity: O(n) due to the recursive call stack, which can go up to n levels deep.

*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
 
    void printGfg(int N) {
        // Code here
        if(N<=0){
          return ;
      }
      else{
          cout<<"GFG"<<" ";
          printGfg(N-1);
      }
        
    }
};
