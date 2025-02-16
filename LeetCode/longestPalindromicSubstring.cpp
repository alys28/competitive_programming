#include <bits/stdc++.h>
class Solution {
    public:
        string longestPalindrome(string s) {
            string longest = s.substr(0, 1);
            vector<vector<bool>> table(s.size(), vector<bool>(s.size(), false));
            for (int i = 0; i < s.size(); ++i){
                table[i][i] = true;
            }
            for (int i = 1; i < s.size(); ++i){
                for (int j = 0; j + i < s.size(); ++j){
                    if (j+1 > j+i-1 || table[j+1][j+i-1]){
                        if (s[j] == s[j+i]){
                            table[j][j+i] = true;
                            longest = s.substr(j, i + 1);
                        }
                    }
                }
            }
            return longest;
        }   
    };