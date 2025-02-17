#include <bits/stdc++.h>
class Solution {
    public:
        void helper(vector<vector<int>> &grid, int i, int j, int m, int n){
            if (i == m - 1 && j == n - 1){
                grid[i][j] = 1;
            } else {
                int total = 0;
                if (j < n - 1){
                    if (grid[i][j + 1] < 0){
                        helper(grid, i, j + 1, m, n);
                    }
                    total += grid[i][j + 1];
                }
                if (i < m - 1){
                    if (grid[i + 1][j] < 0){
                        helper(grid, i + 1, j, m, n);
                    }
                    total += grid[i + 1][j];
                }
                grid[i][j] = total;
            }
        }
        int uniquePaths(int m, int n) {
            vector<vector<int>> grid(m, vector<int>(n, -1));
            helper(grid, 0, 0, m, n);
            return grid[0][0];
        }
    };
    