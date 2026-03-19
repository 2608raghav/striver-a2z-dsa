/*
Problem: Majority Element II
Platform: LeetCode
Topic: Array

Approach:
1. We can use a modified version of the Boyer-Moore Voting Algorithm to find the majority elements in linear time and constant space.
2. Initialize four variables: "ele1" and "ele2" to store the two potential majority elements, and "cnf1" and "cnf2" to keep track of their counts.
3. Iterate through the input vector "nums":
    - If the current element is equal to "ele1" and not equal to "ele2", increment "cnf1".
    - Else if the current element is equal to "ele2" and not equal to "ele1", increment "cnf2".
    - Else if "cnf1" is 0, update "ele1" to the current element and set "cnf1" to 1.
    - Else if "cnf2" is 0, update "ele2" to the current element and set "cnf2" to 1.
    - Otherwise, decrement both "cnf1" and "cnf2".
4. After the first pass, "ele1" and "ele2" will hold the two potential majority elements. However, we need to verify that they are indeed the majority elements by counting their occurrences in a second pass.
5. If the count of "ele1" is greater than n/3, add "ele1" to the result vector. If the count of "ele2" is greater than n/3, add "ele2" to the result vector.
6. Sort the result vector and return it.

Time Complexity: O(n) since we need to iterate through the input vector twice (once to find the candidates and once to verify them).
Space Complexity: O(1) as we are using only a constant amount of extra space to store the candidate elements and their counts, and the result vector will contain at most 2 elements.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int ele1 =0;
        int ele2 = 0;
        int cnf1 =0;
        int cnf2 =0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==ele1 && nums[i]!=ele2){
                cnf1++;
            }
            else if(nums[i]==ele2 && nums[i]!=ele1){
                cnf2++;
            }
           else if(cnf1==0){
            ele1 = nums[i];
            cnf1=1;
           }
           else if(cnf2==0){
            ele2 = nums[i];
            cnf2 =1;
           }
           else{
            cnf1--;
            cnf2--;
           }
        }
        cnf1 =0;
        cnf2=0;
        vector<int>res;
        for(int i=0;i<nums.size();i++){
           if(nums[i]==ele1){
            cnf1++;
           }
           else if(nums[i]==ele2){
            cnf2++;
           }
        }
        int n = nums.size();
        
        if(cnf1>n/3){
            res.push_back(ele1);
        }
        if(cnf2>n/3){
            res.push_back(ele2);
        }
        sort(res.begin(),res.end());
        return res;
    }
};