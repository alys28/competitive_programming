class Solution {
    public:
        vector<int> spiralOrder(vector<vector<int>>& matrix) {
            int minHorizontal = 0;
            int maxHorizontal = matrix[0].size() - 1;
            int minVertical = 0;
            int maxVertical = matrix.size() - 1;
            int currX = 0;
            int currY = 0;
            int direction = 0; // 0 = right, 1 = down, 2 = left, 3 = up
            vector<int> output;
            int totalLength = (maxHorizontal + 1) * (maxVertical + 1);
            while (output.size() < totalLength){
                output.push_back(matrix[currY][currX]);
                if (direction == 0){
                    if (currX == maxHorizontal){
                        ++direction;
                        ++currY;
                        --maxHorizontal;
                    } else {
                        ++currX;
                    }
                } else if (direction == 1){
                    if (currY == maxVertical){
                        ++direction;
                        --currX;
                        --maxVertical;
                        ++minVertical;
                    } else {
                        ++currY;
                    }
                } else if (direction == 2){
                    if (currX == minHorizontal){
                        ++direction;
                        --currY;
                        ++minHorizontal;
                    } else {
                        --currX;
                    }
                } else {
                    if (currY == minVertical){
                        ++direction;
                        ++currX;
                    } else {
                        --currY;
                    }
                }
                direction %= 4;
            }
            return output;
        }
    };