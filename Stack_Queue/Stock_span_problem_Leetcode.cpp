/*
Problem: Online Stock Span
Platform: Leetcode
Topic: Stack, Monotonic Stack

Approach:
1. Maintain a monotonic decreasing stack storing:
      {stock price, span}
2. For each incoming stock price:
   - Initialize span = 1.
3. While the stack is not empty and the top stock price is less than or equal
   to the current price:
   - Add the span stored at the top to the current span.
   - Remove the top element from the stack.
4. Push the current price along with its calculated span into the stack.
5. Return the calculated span.
6. The stored span allows us to skip multiple previous days at once,
   making the solution efficient.

Time Complexity: O(1) Amortized
- Each price is pushed and popped at most once.

Space Complexity: O(n)
- In the worst case, all prices may remain in the stack.

*/

#include <bits/stdc++.h>
using namespace std;

class StockSpanner {
public:
    stack<pair<int, int>> st;

    StockSpanner() {
    }

    int next(int price) {
        int span = 1;

        while (!st.empty() && st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }

        st.push({price, span});

        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */