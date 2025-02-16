#include <bits/stdc++.h>
class Solution {
    public:
        int search(vector<int>& nums, int target) {
            int left = 0;
            int right = nums.size() - 1;
            while (left <= right){
                int middle = (left + right) / 2;
                if (nums[middle] == target){
                    return middle;
                }
                // cout << middle << endl;
                if (nums[left] < nums[right]){ // regular binary search
                    if (target > nums[middle]){
                        left = middle + 1;
                    } else {
                        right = middle - 1;
                    }
                } else { // nums[left] > nums[right]
                    if (target >= nums[left]){ // that means that it's in the pivoted range
                        if ((target < nums[middle] && nums[middle] > nums[left]) || (target > nums[middle] && nums[middle] < nums[right])){
                            right = middle - 1;
                        } else {
                            left = middle + 1;
                        }
                    } else {
                        if ((target < nums[middle] && nums[middle] > nums[right]) || (target > nums[middle] && nums[middle] < nums[right])){
                            left = middle + 1;
                        } else {
                            right = middle - 1;
                        }
                    }
                }
            }
            return -1;
        }
    };