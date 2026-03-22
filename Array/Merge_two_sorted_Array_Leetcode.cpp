/*
Problem: Merge Two Sorted Array
Platform: LeetCode
Topic: Array

Approach:
1. Store the sizes of both arrays (n1 and n2).
2. Append all elements of array b into array a.
3. Sort the combined array a.
4. Copy the last n2 elements of sorted array a into array b.
5. Remove the extra elements from array a so that it again contains only n1 elements.
6. Now both arrays a and b contain sorted elements in correct order.

Time Complexity: O((n1 + n2) log(n1 + n2))
- Appending elements → O(n2)
- Sorting combined array → O((n1+n2) log(n1+n2))
- Copying elements back → O(n2)
- Removing extra elements → O(n2)
Overall complexity dominated by sorting.

Space Complexity: O(1)
- No extra data structure is used.
- Sorting is done in-place (ignoring internal recursion stack).
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    void mergeArrays(vector<int>& a, vector<int>& b) {
        // code here
        int n1 = a.size();
        int n2 = b.size();
        for(int i=0;i<b.size();i++){
            a.push_back(b[i]);
        }
        sort(a.begin(),a.end());
        int j=0;
        for(int i=n1;i<a.size();i++){
            b[j]=a[i];
            j++;
        }
        for(int i=a.size();i>n1;i--){
            a.pop_back();
        }
    }
};