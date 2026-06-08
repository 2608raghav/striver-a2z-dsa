/*
Problem: Asteroid Collision
Platform: Leetcode
Topic: Recursion

Approach:
1. We can use a stack to keep track of the asteroids that are currently moving.
2. We will iterate through the list of asteroids:
   - If the current asteroid is moving to the right (positive), we will simply push it onto the stack.
   - If the current asteroid is moving to the left (negative), we will check for collisions with the asteroids on the stack:
     - We will pop asteroids from the stack until we find an asteroid that is moving to the right (positive) or the stack becomes empty.
     - If we find a positive asteroid, we will compare their sizes:
       - If the current asteroid is larger, we will pop the positive asteroid and continue checking for collisions.
       - If they are of equal size, we will pop the positive asteroid and discard the current asteroid.
       - If the positive asteroid is larger, we will discard the current asteroid and stop checking for collisions.
     - If the stack becomes empty, it means there are no more asteroids to collide with, so we will push the current asteroid onto the stack.
Time Complexity: O(n) where n is the number of asteroids, since we will process each asteroid once.
Space Complexity: O(n) in the worst case for the stack, if all asteroids are moving in the same direction.

*/  

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st; // Stack to hold asteroids
        
        for (int asteroid : asteroids) {
            bool destroyed = false; // Flag to check if the current asteroid is destroyed
            
            while (!st.empty() && asteroid < 0 && st.top() > 0) {
                if (abs(asteroid) > st.top()) {
                    st.pop(); // Pop the smaller positive asteroid
                } else if (abs(asteroid) == st.top()) {
                    st.pop(); // Both asteroids destroy each other
                    destroyed = true;
                    break;
                } else {
                    destroyed = true; // Current asteroid is destroyed
                    break;
                }
            }
            
            if (!destroyed) {
                st.push(asteroid); // Push the current asteroid onto the stack
            }
        }
        
        // Convert stack to vector
        vector<int> result(st.size());
        for (int i = st.size() - 1; i >= 0; i--) {
            result[i] = st.top();
            st.pop();
        }
        
        return result;
    }
};
