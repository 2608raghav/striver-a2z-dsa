/*
Problem: Union of Two Sorted Arrays
Platform: GeeksforGeeks
Topic: Array

Approach:
1. Initialize two pointers, "i" and "j", to the beginning of the two input arrays "arr1" and "arr2" respectively.
2. Create an empty vector "result" to store the union of the two arrays.
3. While both pointers are within the bounds of their respective arrays:
   - If the elements at both pointers are equal, add the element to the "result" vector and move both pointers forward.
   - If the element at pointer "i" is smaller than the element at pointer "j", add the element at pointer "i" to the "result" vector and move pointer "i" forward.
   - If the element at pointer "j" is smaller than the element at pointer "i", add the element at pointer "j" to the "result" vector and move pointer "j" forward.
4. After the loop, if there are remaining elements in either array, add them to the "result" vector.
5. Finally, return the "result" vector which contains the union of the two sorted arrays


Time Complexity: O(m + n) where m and n are the sizes of the two input arrays.
Space Complexity: O(m + n) for the "result" vector.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> findUnion(vector<int> &nums1, vector<int> &nums2) {
        // code 
    int i = 0, j = 0;
    vector<int> ans;

    while (i < nums1.size() && j < nums2.size()) {
        if (nums1[i] <= nums2[j]) {
            if (ans.empty() || ans.back() != nums1[i])
                ans.push_back(nums1[i]);
            i++;
        } else {
            if (ans.empty() || ans.back() != nums2[j])
                ans.push_back(nums2[j]);
            j++;
        }
    }

    while (i < nums1.size()) {
        if (ans.empty() || ans.back() != nums1[i])
            ans.push_back(nums1[i]);
        i++;
    }

    while (j < nums2.size()) {
        if (ans.empty() || ans.back() != nums2[j])
            ans.push_back(nums2[j]);
        j++;
    }

    return ans;
}

        
    };
