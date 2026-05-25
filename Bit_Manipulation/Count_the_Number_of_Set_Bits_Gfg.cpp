/*
Problem: Count the Number of Set Bits
Platform: Greeksfor Greeks
Topic: Bit Manipulation

Approach:
1. To count the number of set bits (1s) in the binary representation of a number n, we can use Brian Kernighan's algorithm. This algorithm works by repeatedly flipping the least significant set bit of n to 0 and counting how many times this operation can be performed until n becomes 0.
2. The operation n & (n - 1) will flip the least significant set bit of n to 0. For example, if n is 6 (110 in binary), n - 1 will be 5 (101 in binary), and n & (n - 1) will be 4 (100 in binary). This effectively removes the least significant set bit from n.
3. We will initialize a count variable to 0 and repeatedly apply the operation n & (n - 1) while incrementing the count until n becomes 0. The final value of count will be the number of set bits in n.
4. The function will return the count of set bits in n.

Time Complexity: O(k), where k is the number of set bits in n. In the worst case, when n has all bits set (e.g., n = 2^m - 1), the time complexity will be O(log n) since there can be at most log n set bits.
Space Complexity: O(1) since we are using a constant amount of space to store the count and perform the operations.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countSetBits(int n) {
        int count = 0;
        while (n > 0) {
            n &= (n - 1); // Flip the least significant set bit to 0
            count++;
        }
        return count;
    }
};