class Solution {
    public:
        bool helper(vector<vector<char>>& board, vector<vector<int>>& visited, int i, int j, int idx, string& word){
            if (idx == word.size()){
                return true;}
            if (!(i > board.size() - 1 || j > board[0].size() - 1 || i < 0 || j < 0)){
                if (!visited[i][j] && board[i][j] == word[idx]){
                        visited[i][j] = true;
                        bool ans = helper(board, visited, i + 1, j, idx + 1, word) || helper(board, visited, i, j + 1, idx + 1, word) || helper(board, visited, i - 1, j, idx + 1, word) || helper(board, visited, i, j - 1, idx + 1, word);
                        visited[i][j] = false;
                        return ans;
                } else {return false;}
            }
            else {return false;}
        }
        bool exist(vector<vector<char>>& board, string word) {
            vector<vector<int>> visited(board.size(), vector<int>(board[0].size(), false));
            for (int i = 0; i < board.size(); ++i){
                for (int j = 0; j < board[0].size(); ++j){
                    if (board[i][j] == word[0]){
                        visited[i][j] = true;
                        if (helper(board, visited, i + 1, j, 1, word) || helper(board, visited, i, j + 1, 1, word) || helper(board, visited, i - 1, j, 1, word) || helper(board, visited, i, j - 1, 1, word)){
                            return true;
                        }
                        visited[i][j] = false;
                    }
                }
            }
            return false;
        }
    };