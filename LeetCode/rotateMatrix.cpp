#include <bits/stdc++.h>
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int newVal;
        for (int i = 0; i < n; ++i){
            for (int j = i; j < n - i - 1; ++j){
                int x = i;
                int y = j;
                newVal = matrix[x][y];
                for (int k = 0; k < 4; ++k){
                    // Do the rotation, based on the x, y coordinate
                    if (k == 0){
                        int tempX = x;
                        x = y;
                        y = n - tempX - 1;

                    } else if (k == 1){
                        int tempX = x;
                        x = y;
                        y = n - tempX - 1;
                        
                    } else if (k == 2){
                        int tempX = x;
                        x = y;
                        y = n - tempX - 1;
                    } else if (k == 3){
                        int tempX = x;
                        x = y;
                        y = n - tempX - 1;
                    }
                    int tempVal = newVal;
                    newVal = matrix[x][y];
                    matrix[x][y] = tempVal;
                }
            }
        }
    }
};