/*
Problem: Move Zeroes to End
Platform: LeetCode
Topic: Array

Approach:
1. Create an empty vector "result" to store the non-zero elements.
2. Initialize a variable "count" to keep track of the number of non-zero elements found
3. Iterate through the input vector "nums" and for each element:
   - If the current element is not zero, push it into the "result" vector and increment the "count".
4. After iterating through the entire input vector, calculate the number of zeroes by subtracting the count of non-zero elements from the total size of the input vector.
5. Append the calculated number of zeroes to the "result" vector.
6. Finally, assign the "result" vector back to the input vector "nums" to reflect the changes.



Time Complexity: O(n) since we need to iterate through the input vector once to find the non-zero elements and then append the zeroes.
Space Complexity: O(n) as we are using an additional vector to store the result.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
      
    vector<int> result;
    int count =0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]!=0){
          result.push_back(nums[i]);
        
            
        }
    }
    int size = nums.size()-result.size();
    for(int i=0;i<size;i++){
        result.push_back(0);
    }
    nums = result;
    }
};