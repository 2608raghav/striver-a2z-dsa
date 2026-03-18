/*
Problem: Pascal's Triangle
Platform: LeetCode
Topic:  Array

Approach:
1. To generate the first "numRows" of Pascal's Triangle, we can use a nested loop structure.
2. The outer loop will iterate from 1 to "numRows", representing the current row we are generating.
3. For each row, we can initialize a vector "res" to store the values of that row. The first and last element of each row will always be 1, so we can push back 1 at the beginning of the "res" vector.
4. For the elements in between the first and last element, we can calculate their values using the values from the previous row. Specifically, the value at index "j" in the current row can be calculated as the sum of the values at indices "j-1" and "j" from the previous row.
5. After calculating the values for the current row, we can push back 1 at the end of the "res" vector and then add the "res" vector to the final answer vector "ans".

Time Complexity: O(numRows^2) since we need to generate each row and calculate the values for each element in the row.
Space Complexity: O(numRows^2) since we are storing the values of all rows in

*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
vector<int>generate_row(int r){
    vector<int>res;
    res.push_back(1);
    long long ans =1;
    for(int col = 1;col<r;col++){
     ans = ans*(r-col);
     ans =  ans/col;
     res.push_back(ans);
    }
    return res;
}
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        
        for(int i=1;i<=numRows;i++){
            
            ans.push_back(generate_row(i));
        }
        return ans;

    }
};