/*
Problem: Find the Missing and Repeating Number
Platform: GeeksforGeeks
Topic: Array

Approach:
1. Create a frequency array (hp) of size n+2 initialized with 0.
2. Traverse the given array and store the frequency of each element in hp.
3. Traverse the frequency array from index 1 to n:
   - If frequency is greater than 1, that number is the repeating element.
4. Traverse the frequency array again:
   - If frequency is 0, that number is the missing element.
5. Store repeating and missing elements in the result vector and return it.

Time Complexity: O(n)
- First loop to count frequency → O(n)
- Second loop to find repeating → O(n)
- Third loop to find missing → O(n)
Overall complexity = O(3n) ≈ O(n)

Space Complexity: O(n)
- Frequency array of size n+2 is used.
- Result vector uses constant space.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
       
        vector<int>hp(arr.size()+2,0);
        vector<int>res;
        for(int i=0;i<arr.size();i++){
            hp[arr[i]]++;
        }
        for(int i=1;i<hp.size();i++){
            if(hp[i]>1){
                res.push_back(i);
                break;
            }
        }
        for(int i=1;i<hp.size();i++){
            if(hp[i]==0){
                res.push_back(i);
                break;
            }
        }
        return res;
    }
};