#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int pivot = -1;
        for (int i = nums.size() - 1; i > 0; --i){
            if (nums[i-1] < nums[i]){
                pivot = i - 1;
                break;
            }
        }
        if (pivot == -1){
            std::reverse(nums.begin(), nums.end());
        }
        else {
            for (int j = nums.size() - 1; j > pivot; --j){
            if (nums[j] > nums[pivot]){
                int temp = nums[j];
                nums[j] = nums[pivot];
                nums[pivot] = temp;
                // cout << pivot << endl;
                std::reverse(nums.begin() + pivot + 1, nums.end());
                break;
            }
        }
        }

    }
};
