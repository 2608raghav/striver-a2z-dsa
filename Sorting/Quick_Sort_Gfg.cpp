/*
Problem: Quick Sort
Platform: GeeksforGeeks
Topic: Sorting

Approach:
1. Choose a pivot element from the array (commonly the last element).
2. Partition the array such that all elements less than the pivot are on the left side and all elements greater than the pivot are on the right side.
3. Recursively apply the above steps to the left and right subarrays until the base case (subarray of size one or zero) is reached.

Time Complexity: O(n log n) in the average and best cases, as the array is divided into two halves at each step. However, in the worst case (when the smallest or largest element is always chosen as the pivot), the time complexity can degrade to O(n^2).
Space Complexity: O(log n) on average due to recursive stack space, but can go up to O(n) in the worst case if the partitioning is unbalanced.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
 
    int partition(vector<int>& arr, int low, int high) {
        
        int pivot = arr[high];
        int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    
    swap(arr[i + 1], arr[high]);  
    return i + 1;
    }
    
    public:
    
    void quickSort(vector<int>& arr, int low, int high) {

         if (low < high) {
      
        int position = partition(arr, low, high);
        quickSort(arr, low, position - 1);
        quickSort(arr, position + 1, high);
       
    }
    }
};