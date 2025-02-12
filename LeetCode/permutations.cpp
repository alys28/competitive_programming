#include <bits/stdc++.h>
class Solution {
public:

    void helper(vector<vector<int>> &results, int idx, vector<int>nums) {
        if (idx < nums.size()){
            for (int i = idx; i < nums.size(); ++i){
                vector<int> new_nums = nums;
                int tmp = new_nums[idx];
                new_nums[idx] = new_nums[i];
                new_nums[i] = tmp;
                helper(results, idx + 1, new_nums);
            }
        } else {
            results.push_back(nums);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> results;
        helper(results, 0, nums);
        return results;    
    }
};
