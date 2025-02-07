#include <bits/stdc++.h>
class Solution {
public:
    vector<vector<int>> solutions;
    int obj;
    void combinationSumHelper(vector<int>& candidates, int curr, vector<int> currMembers = vector<int>()){
        if (curr < obj){
            for (int i = 0; i < candidates.size(); ++i){
                if (curr + candidates[i] <= obj){
                    vector<int> newCurrMembers = currMembers;
                    newCurrMembers.push_back(candidates[i]);
                    combinationSumHelper(candidates, curr + candidates[i], newCurrMembers);
                }
            }
        } else if (curr == obj){
            solutions.push_back(currMembers);
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        obj = target;
        combinationSumHelper(candidates, 0);
        for (int i = 0; i < solutions.size(); ++i){
            std::sort(solutions[i].begin(), solutions[i].end());
        }
        std::set<std::vector<int>> s(solutions.begin(), solutions.end());
        std::vector<std::vector<int>> sols(s.begin(), s.end());
        return sols;
    }
};