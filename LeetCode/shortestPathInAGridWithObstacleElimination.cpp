#include <bits/stdc++.h>
class Solution {
    public:
        struct entry {
            int i;
            int j;
            int k;
            int currSteps;
        };
        struct visitedEntry {
            int i;
            int j;
            int k;
        };
        int shortestPath(vector<vector<int>>& grid, int k) {
            int m = grid.size();
            int n = grid[0].size();
            queue<entry> q;
            vector<vector<vector<bool>>> visited(m, vector<vector<bool>>(n, vector<bool>(k + 1, false)));
            q.push(entry{0, 0, 0, 0});
            while (!q.empty()){
                entry elt = q.front();
                q.pop();
                if (elt.i == m - 1 && elt.j == n - 1){
                    return elt.currSteps;
                }
                int i = elt.i;
                int j = elt.j;
                int currSteps = elt.currSteps;
                if (i < m - 1){
                    int newK = elt.k + grid[i+1][j];
                    if (newK <= k && !visited[i+1][j][newK]){
                        q.push(entry{i+1, j, newK, currSteps + 1});
                        visited[i + 1][j][newK] = true;
                    }
                }
                if (j < n - 1){
                    int newK = elt.k + grid[i][j + 1];
                    if (newK <= k && !visited[i][j + 1][newK]){
                        q.push(entry{i, j + 1, newK, currSteps + 1});
                        visited[i][j + 1][newK] = true;
                    }
                }
                if (i > 0){
                    int newK = elt.k + grid[i - 1][j];
                    if (newK <= k && !visited[i-1][j][newK]){
                        q.push(entry{i - 1, j, newK, currSteps + 1});
                        visited[i-1][j][newK] = true;
                    }
                }
                if (j > 0){
                    int newK = elt.k + grid[i][j - 1];
                    if (newK <= k && !visited[i][j - 1][newK]){
                        q.push(entry{i, j - 1, newK, currSteps + 1});
                        visited[i][j-1][newK] = true;
                    }
                }
                
    
            }
            return -1;
        }
    };
