#include <bits/stdc++.h>
class Solution {
    public:
        bool canJump(vector<int>& nums) {
            int prev = nums.size() - 1;
            for (int i = nums.size() - 1; i >= 0; --i){
                if (prev - i <= nums[i]){
                    prev = i;
                }
            }
            if (prev == 0){
                return true;
            }
            return false;
        }
    };