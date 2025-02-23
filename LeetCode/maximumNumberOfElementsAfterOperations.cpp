class Solution {
    public:
        int maxDistinctElements(vector<int>& nums, int k) {
            sort(nums.begin(), nums.end());
            int curr = -k;
            int counter = 0;
            for (int i = 0; i < nums.size(); ++i){
                if (i == 0){
                    nums[i] += curr;
                    ++counter;
                } else {
                    if (nums[i] - nums[i-1] > k){
                        curr = -k; // reset
                        nums[i] += curr;
                        ++counter;
                    }
                    else if (nums[i] + curr <= nums[i-1] && curr < k){
                        ++curr;
                        nums[i] += curr;
                        ++counter;
                    } else if (nums[i] - nums[i-1] <= k && nums[i] - nums[i-1] >= -k) {
                        curr = min(nums[i - 1] - nums[i] + 1, curr);
                        nums[i] += curr;
                        if (nums[i] > nums[i-1]){
                            ++counter;
                        }
                    }
                }
            }
            return counter;
        }
    };
    
    