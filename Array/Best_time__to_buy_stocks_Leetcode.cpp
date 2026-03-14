/*
Problem: Best Time to Buy and Sell Stock
Platform: LeetCode
Topic: Array

Approach:
1. Initialize two variables, "buy" to store the minimum price encountered so far and "profit" to store the maximum profit found so far.
2. Iterate through the input vector "prices":
   - Update "buy" to be the minimum of the current "buy" and the current price, which represents the lowest price at which we can buy the stock.
   - Update "profit" to be the maximum of the current "profit" and the difference between the current price and "buy", which represents the profit we would make if we sold the stock at the current price after buying it at the lowest price.
3. After the loop, return the value of "profit" which contains the maximum profit that can be achieved.

Time Complexity: O(n) since we need to iterate through the input vector once to find the minimum price and maximum profit.
Space Complexity: O(1) as we are using only a constant amount of extra space to store the "buy" and "profit" variables.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = INT_MAX;
        int profit = INT_MIN;
        for(int i=0;i<prices.size();i++){
            buy = min(buy,prices[i]);
            profit = max(profit,abs(prices[i]-buy));
        }
        return profit;
    }
};