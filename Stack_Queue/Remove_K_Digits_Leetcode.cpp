/*

Problem: Remove K Digits
Platform: Leetcode
Topic: Greedy, Stack, String

Approach:
1. We want to obtain the smallest possible number after removing exactly k digits.
2. Traverse the given number digit by digit.
3. Maintain a stack (or string used as a stack) to store the digits of the resulting number.
4. For each digit:
   - While the stack is not empty,
   - k > 0,
   - and the top digit of the stack is greater than the current digit,
     remove the top digit from the stack.
   This helps place smaller digits at more significant positions.
5. Push the current digit into the stack.
6. If k is still greater than 0 after processing all digits,
   remove the remaining digits from the end of the stack since they are the largest available.
7. Remove all leading zeros from the resulting number.
8. If the resulting string becomes empty, return "0".
9. Otherwise, return the final string.

Time Complexity: O(n)
- Each digit is pushed and popped at most once.

Space Complexity: O(n)
- Extra space is used to store the stack/result string.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        string st;

        for (char digit : num) {
            while (!st.empty() && k > 0 && st.back() > digit) {
                st.pop_back();
                k--;
            }

            st.push_back(digit);
        }

        while (!st.empty() && k > 0) {
            st.pop_back();
            k--;
        }

        int idx = 0;
        while (idx < st.size() && st[idx] == '0') {
            idx++;
        }

        string result = st.substr(idx);

        return result.empty() ? "0" : result;
    }
};