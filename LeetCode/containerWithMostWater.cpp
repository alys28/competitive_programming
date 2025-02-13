#include <bits/stdc++.h>
class Solution {
    public:
        int maxArea(vector<int>& height) {
            int pt1 = 0;
            int pt2 = height.size() - 1;
            int maxCount = 0;
            while (pt1 < pt2){
                int curr = min(height[pt1], height[pt2]) * (pt2 - pt1);
                maxCount = curr > maxCount ? curr : maxCount;
                if (height[pt1] > height[pt2]){
                    --pt2;
                } else {
                    ++pt1;
                }
            }
            return maxCount;
        }
    };
    