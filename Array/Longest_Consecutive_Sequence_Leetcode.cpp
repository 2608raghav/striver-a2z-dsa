/*
Problem: Longest Consecutive Sequence
Platform: LeetCode
Topic: Array

Approach: 
  1. First, we check if the input vector "nums" is empty. If it is, we return 0 since there are no numbers to form a consecutive sequence.
  2. We sort the input vector "nums" in ascending order. Sorting helps us to easily identify consecutive numbers.
  3. We initialize two variables, "count" and "mx", to keep track of the current length of the consecutive sequence and the maximum length found so far, respectively. Both are initialized to 1 since a single number is considered a consecutive sequence of length 1.
  4. We iterate through the sorted vector "nums" from the first element to the second last element. For each element, we compare it with the next element:
     - If the difference between the next element and the current element is 1, it means they are consecutive, so we increment the "count" variable.
     - If the next element is equal to the current element, we skip it since it does not contribute to a longer consecutive sequence.
     - If neither of the above conditions is true, it means we have reached the end of a consecutive sequence. We update "mx" with the maximum of "mx" and "count", and reset "count" to 1 for the next potential sequence.
    5. After the loop, we return the maximum of "mx" and "count" to account for the case where the longest consecutive sequence ends at the last element of the vector.

 
Time Complexity: O(N) since we need to iterate through the input vector once to find the longest consecutive sequence.
Space Complexity: O(1) as we are using only a constant amount of extra space to store the "count" and "mx" variables, and the sorting is done in-place.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        if(nums.size() == 0) return 0;

        sort(nums.begin(), nums.end());

        int count = 1;
        int mx = 1;

        for(int i = 0; i < nums.size()-1; i++){

            if(nums[i+1] - nums[i] == 1){
                count++;
            }

            else if(nums[i+1] == nums[i]){
                continue;
            }

            else{
                mx = max(mx, count);
                count = 1;
            }
        }

        return max(mx, count);
    }
};