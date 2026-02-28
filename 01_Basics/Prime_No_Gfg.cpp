/*
Problem: Prime Number
Platform: GeeksforGeeks
Topic: Basic Math
Approach: 1. Handle the case for 1, which is not a prime number.
            2. Check for divisibility from 2 to sqrt(n). If n is divisible by any of these numbers, it is not prime.
            3. If n is not divisible by any number in that range, it is prime.              

Time Complexity: O(sqrt(n)) since we are checking divisibility up to the square root of n.
Space Complexity: O(1)
*/
#include <bits/stdc++.h>
using namespace std;
    
class Solution {
  public:
    bool isPrime(int n) {
        // code here
        if(n==1){
            return false;
        }
        for(int i=2;i<=sqrt(n);i++){
            if(n%i==0){
                return false;
            }
        }
        return true;
    }
};