#include <bits/stdc++.h>
class Solution {
    public:
        int firstMissingPositive(vector<int>& nums) {
            for (int i = 0; i < nums.size();++i){
                if (nums[i] <= 0 || nums[i] > nums.size()){
                    nums[i] = -1;
                }
            }
            for (int i = 0; i < nums.size(); ++i){
                if (nums[i] > 0){
                    int idx = nums[i] - 1;
                    int temp = nums[idx];
                    nums[idx] = nums[i];
                    nums[i] = temp;
                    while (nums[i] > 0 && nums[i] < i + 1){
                        int idx = nums[i] - 1;
                        int temp = nums[idx];
                        nums[idx] = nums[i];
                        nums[i] = temp;
                        if (nums[i] == nums[idx]){
                            break;
                        }
                    }
                }
            }
            for (int i = 0; i < nums.size(); ++i){
                if (nums[i] != i + 1){
                    return i + 1;
                };
            }
            return nums.size() + 1;
        }
    };
    