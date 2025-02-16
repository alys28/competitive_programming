#include <bits/stdc++.h>
class Solution {
    public:
        vector<int> findSubstring(string s, vector<string>& words) {
            vector<int> result;
            if (s.size() >= words[0].size() * words.size()){
                map<string, int> wordCounter;
            for (const string& word : words) {
                wordCounter[word]++;
            }
            vector<map<string, int>> subProblems(words[0].size());
            for (int i = 0; i < s.size() - words[0].size() * words.size() + 1; ++i){
                bool isPossible = true;
                string subs = s.substr(i, words.size() * words[0].size());
                map<string, int>& curr = subProblems[i % words[0].size()];
                if (curr.empty()){
                    string first_word = subs.substr(0, words[0].size());
                    for (int j = 0; j < subs.size(); j += words[0].size()){
                        string word = subs.substr(j, words[0].size());
                        if (!curr.count(word)){
                            curr[word] = 1;
                        } else {
                            ++curr[word];
                        }
                        if (!wordCounter.count(word) || wordCounter[word] < curr[word]){
                            isPossible = false;
                        }
                    }
                    if (isPossible){
                        result.push_back(i);
                    }
                    --curr[first_word];
                }
                else {
                    bool isPossible = true;
                    string last_word = s.substr(i + (words.size() - 1) * words[0].size(), words[0].size());
                    string first_word = subs.substr(0, words[0].size());
                    map<string, int>& curr = subProblems[i % words[0].size()];
                    
                    
                    if (!curr.count(last_word)){
                        curr[last_word] = 1;
                    } else {
                        ++curr[last_word];
                    }
                    for (auto const& [key, val] : curr){
                        if ((!wordCounter[key] && curr[key] > 0) || curr[key] > wordCounter[key]){
                            isPossible = false;
                            break;
                        }
                    }
                    if (isPossible){
                        result.push_back(i);
                    }
                    --curr[first_word];
                }
            }
            }
        return result;
        }
    };