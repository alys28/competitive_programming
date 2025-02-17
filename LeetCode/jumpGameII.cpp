#include <bits/stdc++.h>
class Solution {
    public:
        int jump(vector<int>& nums) {
            // NOT THE MOST OPTIMIZED SOLUTION
            vector<int> visited(nums.size(), INT_MAX);
            visited[nums.size() - 1] = 0;
            for (int i = nums.size() - 2; i >= 0; --i){
                int curr_min = INT_MAX;
                for (int j = 1; i + j < nums.size() && j <= nums[i]; ++j){
                    if (curr_min == INT_MAX){
                        if (visited[i + j] != INT_MAX){
                            curr_min = 1 + visited[i+j];
                        }
                    } else if (visited[i + j] != INT_MAX) {
                        curr_min = min(1 + visited[i+j], curr_min);
                    }
                        
                }
                visited[i] = curr_min;
            }
            return visited[0];
        }
    };