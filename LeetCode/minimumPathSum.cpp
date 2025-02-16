#include <bits/stdc++.h>
class Solution {
    public:
        void helper(vector<vector<int>>& grid, vector<vector<int>>& accumulator, int i, int j){
            int m = grid.size();
            int n = grid[0].size();
            int down;
            int right;
            if (j < n - 1){
                if (accumulator[i][j+1] < 0){ // right
                    helper(grid, accumulator, i, j + 1);
                }
                right = accumulator[i][j+1];
            } else {
                right = INT_MAX;
            }
            if (i < m - 1){
                if (accumulator[i+1][j] < 0){ // down
                    helper(grid, accumulator, i + 1, j);
                } 
                down = accumulator[i+1][j];
            } else {
                down = INT_MAX;
            }
            if (right == INT_MAX && down == INT_MAX){
                accumulator[i][j] = grid[i][j];
                return;
            }
            accumulator[i][j] = grid[i][j] + min(down, right);
        }
        int minPathSum(vector<vector<int>>& grid) {
            // DFS
            int m = grid.size();
            int n = grid[0].size();
            vector<vector<int>> accumulator(m, vector<int>(n, -1));
            accumulator[m-1][n-1] = grid[m-1][n-1];
            helper(grid, accumulator, 0, 0);
            return accumulator[0][0];
        }
    };
