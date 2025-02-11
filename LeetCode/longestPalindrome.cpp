#include <bits/stdc++.h>
class Solution {
public:
    int longestPalindrome(string s) {
       map<char, int> m;
       for (int i = 0; i < s.size(); ++i){
        if (m.count(s[i])){
            ++m[s[i]];
        } else {
            m[s[i]] = 1;
        }
       }
    bool hasOdd = false;
    int len = 0; 
    for (auto const& [key, val] : m){
        if (val % 2 == 1){
            hasOdd = true;
            len += val - 1;
        } else {
            len += val;
        }
    }
    return len + hasOdd;
    }
};
