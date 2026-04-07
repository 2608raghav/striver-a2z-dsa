/*
Problem: Kth element of 2 sorted arrays
Platform: GeeksforGeeks
Topic: Binary Search

Approach:
1. We can use binary search to find the kth element of the two sorted arrays.
2. We will use two pointers, one for each array, to keep track of the current index in each array.
3. We will calculate the middle index of both arrays and compare the elements at those indices.
4. If the element at the middle index of the first array is less than the element at the middle index of the second array, it means that the kth element must be in the right half of the first array and the left half of the second array. Therefore, we will update the pointers accordingly.
5. If the element at the middle index of the first array is greater than the element at the middle index of the second array, it means that the kth element must be in the left half of the first array and the right half of the second array. Therefore, we will update the pointers accordingly.
6. We will continue this process until we have found the kth element.

Time Complexity: O(log(min(n, m))) where n and m are the sizes of the two arrays. We are performing a binary search on the smaller array.
Space Complexity: O(1) as we are using only a constant amount of extra space.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        // code here
        if(n>m){
            return kthElement(arr2,arr1,m,n,k);
        }
        int low = max(0,k-m);
        int high = min(k,n);
        
        while(low<=high){
            int cut1 = (low+high)/2;
            int cut2 = k - cut1;
            
            int left1 = cut1==0?INT_MIN:arr1[cut1-1];
            int left2 = cut2==0?INT_MIN:arr2[cut2-1];
            
            int right1 = cut1==n?INT_MAX:arr1[cut1];
            int right2 = cut2==m?INT_MAX:arr2[cut2];
            
            if(left1<=right2 && left2<=right1){
                return max(left1,left2);
            }
            else if(left1>right2){
                high = cut1-1;
            }
            else{
                low = cut1+1;
            }
        }
        return 0;
    }
};
