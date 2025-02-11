#include <bits/stdc++.h>
class Solution {
public:
    
    int countSubstrings(string s) {
        vector<vector<bool>> subs(s.size(), vector<bool>(s.size(), false));
        for (int i = 0; i < subs.size(); ++i){
            subs[i][i] = true;
        }
        int count = s.size();
        for (int i = 1; i < s.size(); ++i){ // i is the length of the substring
            for (int begin = 0; begin + i < s.size(); ++begin){
                if (i == 1 || (subs[begin+1][begin+i-1])){
                    if (s[begin] == s[begin + i]){
                        ++count;
                        subs[begin][begin + i] = true;
                    }
                }
            }
        }
        return count;
    }
};
