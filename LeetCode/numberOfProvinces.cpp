#include <bits/stdc++.h>
class Solution {
public:
    int provinces = 0;
    void helper(vector<vector<int>>& isConnected, int idx, vector<int> &visited){
        if (!visited[idx]){
            visited[idx] = true;
            for (int i = 0; i < isConnected[idx].size(); ++i){
                if (isConnected[idx][i]){
                    helper(isConnected, i, visited);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int> visited(isConnected.size(), 0);
        for (int i = 0; i < isConnected.size(); ++i){
            if (!visited[i]){
                helper(isConnected, i, visited);
                ++provinces;
            }
        }
        return provinces;
    }
};
