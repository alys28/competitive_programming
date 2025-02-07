#include <bits/stdc++.h>
class Solution {
public:
    vector<int> solution;
    void helper(vector<vector<int>> &graph, int idx, vector<int>& visited){
        if (visited[idx] == 0){
            visited[idx] = 2;
            for (int i = 0; i < graph[idx].size(); ++i){
                int newNodeIdx = graph[idx][i];
                helper(graph, newNodeIdx, visited);
                if (visited[newNodeIdx] == 2){
                    return;
                }
            }
            visited[idx] = 1;
        }
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> visited(graph.size(), 0); // 0, 1, 2
        for (int i = 0; i < graph.size(); ++i){
            helper(graph, i, visited);
        }
        for (int i = 0; i < visited.size(); ++i){
            if (visited[i] == 1){
                solution.push_back(i);
            }
        }
        return solution;
    }
};