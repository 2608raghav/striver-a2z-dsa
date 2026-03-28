/*
Problem: Natural Sort
Platform: GeeksforGeeks
Topic: Sorting

Approach:
1. Use a custom comparator function to compare two strings based on their natural order.
2. The comparator function should split the strings into segments of digits and non-digits.
3. Compare the segments of the two strings:
   - If both segments are digits, compare them as integers.
   - If both segments are non-digits, compare them lexicographically.
   - If one segment is a digit and the other is a non-digit, the digit segment should come before the non-digit segment.

Time Complexity: O(n log n) for sorting the array of strings, where n is the number of strings. The comparison of two strings takes O(m) time, where m is the length of the longer string.
Space Complexity: O(n) for storing the sorted array of strings, and O(m) for the temporary segments used in the comparator function.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    static bool compare(const string &a, const string &b) {
        int i = 0, j = 0;
        while (i < a.size() && j < b.size()) {
            if (isdigit(a[i]) && isdigit(b[j])) {
                // Extract the number from both strings
                int numA = 0, numB = 0;
                while (i < a.size() && isdigit(a[i])) {
                    numA = numA * 10 + (a[i] - '0');
                    i++;
                }
                while (j < b.size() && isdigit(b[j])) {
                    numB = numB * 10 + (b[j] - '0');
                    j++;
                }
                if (numA != numB) {
                    return numA < numB; // Compare as integers
                }
            } else if (!isdigit(a[i]) && !isdigit(b[j])) {
                if (a[i] != b[j]) {
                    return a[i] < b[j]; // Compare lexicographically
                }
                i++;
                j++;
            } else {
                return isdigit(a[i]) ? true : false; // Digits come before non-digits
            }
        }
        return a.size() < b.size(); // If all segments are equal, shorter string comes first
    }

    vector<string> naturalSort(vector<string> arr) {
        sort(arr.begin(), arr.end(), compare);
        return arr;
    }
};
