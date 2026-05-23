/*
Problem:  M Coloring Problem
Platform: GeeksforGeeks
Topic: Recursion

Approach:
1. We will use backtracking to solve the M Coloring Problem, which involves coloring a graph with at most M colors such that no two adjacent vertices share the same color.
2. We will define a helper function that takes the current vertex, the graph, the number of colors, and a vector to store the colors assigned to each vertex.
3. The helper function will iterate through the possible colors for the current vertex and check if it is safe to assign that color (i.e., it does not conflict with adjacent vertices). If it is safe, we will assign the color and recursively call the helper function for the next vertex.
4. If we successfully assign colors to all vertices, we will return true. If we exhaust all color options for a vertex and cannot assign a valid color, we will backtrack and try a different color for the previous vertex.    

Time Complexity: O(M^V) in the worst case, where M is the number of colors and V is the number of vertices in the graph. This is because in the worst case, we may have to try all M colors for each of the V vertices.
Space Complexity: O(V) due to the recursive call stack, which can go up to V levels deep in the worst case. Additionally, we use O(V) space to store the colors assigned to each vertex.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isSafe(int vertex, int color, const vector<vector<int>>& graph, const vector<int>& colors) {
        for (int adjacent : graph[vertex]) {
            if (colors[adjacent] == color) {
                return false;
            }
        }
        return true;
    }
    
    bool backtrack(int vertex, const vector<vector<int>>& graph, int m, vector<int>& colors) {
        if (vertex == graph.size()) {
            return true; // All vertices are colored successfully
        }
        
        for (int color = 1; color <= m; color++) {
            if (isSafe(vertex, color, graph, colors)) {
                colors[vertex] = color; // Assign the color
                
                if (backtrack(vertex + 1, graph, m, colors)) {
                    return true; // Move to the next vertex
                }
                
                colors[vertex] = 0; // Backtrack
            }
        }
        
        return false; // No valid color found for this vertex
    }
    
    bool graphColoring(vector<vector<int>>& graph, int m) {
        int V = graph.size();
        vector<int> colors(V, 0); // Initialize all vertices with no color
        
        return backtrack(0, graph, m, colors);
    }
};