/*
Problem: Reverse an array
Platform: GeeksforGeeks
Topic: Recursion

Approach: Use two pointers, one at the beginning and one at the end of the array. Swap elements at these pointers and move them towards each other until they meet in the middle.



Time Complexity: O(n) since we are traversing the array once to reverse it.
Space Complexity: O(1) since we are using only a constant amount of extra space for the left and right pointers.

*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    void reverseArray(vector<int> &arr) {
        // code here
        int left =0;
        int right = arr.size()-1;
        while(left<=right){
            swap(arr[left],arr[right]);
            left++;
            right--;
        }
    }
};