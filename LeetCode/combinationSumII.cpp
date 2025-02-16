#include <bits/stdc++.h>
class Solution {
    public:
        vector<vector<int>> result;
        void helper(vector<int>& candidates, int target, int curr, vector<int> currArr, int idx){
            if (curr < target && idx < candidates.size()){
                for (int i = idx; i < candidates.size(); ++i){
                    if (i == idx || candidates[i] != candidates[i-1]){
                        vector<int> newCurrArr = currArr;
                        newCurrArr.push_back(candidates[i]);
                        int newCurr = curr + candidates[i];
                        helper(candidates, target, newCurr, newCurrArr, i + 1);
                    }
                }
            } else if (curr == target){
                result.push_back(currArr);
            }
        }
        vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
            sort(candidates.begin(), candidates.end());
            for (int i = 0; i < candidates.size(); ++i){
                if (i == 0 || candidates[i] != candidates[i-1]){
                    helper(candidates, target, candidates[i], vector<int>{candidates[i]}, i+1);
                }            
            }
            return result;
        }
    };
