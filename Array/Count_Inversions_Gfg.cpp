/*
Problem: Count Inversions
Platform: GeeksforGeeks
Topic: Array

Approach:
1. Use Merge Sort to divide the array into two halves recursively.
2. Count inversions in the left half using mergeSort.
3. Count inversions in the right half using mergeSort.
4. While merging both halves:
   - If element in left array is smaller, place it in the original array.
   - If element in right array is smaller, then all remaining elements in left array
     form inversions with this element.
   - Add (n1 - i) to inversion count.
5. Merge both halves into a sorted array.
6. Return the total inversion count.

Key Idea:
Whenever L[i] > R[j], it means all remaining elements from L[i] to L[n1-1]
are greater than R[j], so they form inversions.

Time Complexity: O(n log n)
- Merge sort divides the array into log n levels.
- At each level, merging takes O(n).
- Total complexity = O(n log n)

Space Complexity: O(n)
- Temporary arrays L and R are used during merging.
- Recursive stack space also contributes.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
  int merge(vector<int> &arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Temporary arrays
    vector<int> L(n1), R(n2);
    

    // Copy data
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    int count =0;

    // Merge the temp arrays back
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
           count += (n1 - i);
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    return count;
}

int mergeSort(vector<int> &arr, int left, int right) {
    int count =0;
    if (left >= right)
        return count;

    int mid = left + (right - left) / 2;
    
    count+=mergeSort(arr, left, mid);
   count+= mergeSort(arr, mid + 1, right);
   count+=merge(arr, left, mid, right);
   return count;
}
    int inversionCount(vector<int> &arr) {
        // Code Here
      return  mergeSort(arr,0,arr.size()-1);
        
        
    }
};
