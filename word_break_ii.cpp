#include <bits/stdc++.h>
using namespace std;

class Solution {
   private:
    vector<string> backtrack(string& s, int start, unordered_set<string> dict) {
        vector<string> ans;
        if (start == s.length())
            ans.push_back("");
        for (int end = start + 1; end <= s.length(); ++end) {
            string pref = s.substr(start, end - start);
            if (dict.find(pref) != dict.end()) {
                auto temp = backtrack(s, end, dict);
                for (auto t : temp) {
                    ans.push_back(pref + (t.empty() ? "" : " ") + t);
                }
            }
        }
        return ans;
    }

   public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        return backtrack(s, 0, dict);
    }
};

int main() {
    vector<pair<string, vector<string>>> questions = {
        {"catsanddog", {"cat", "cats", "and", "sand", "dog"}},
        {"pineapplepenapple", {"apple", "pen", "applepen", "pine", "pineapple"}},
        {"catsandog", {"cats", "dog", "sand", "and", "cat"}}};
    Solution sol;
    for (auto q : questions) {
        auto s = q.first;
        auto wordDict = q.second;
        auto ans = sol.wordBreak(s, wordDict);
        for (auto a : ans) {
            cout << a << endl;
        }
        cout << endl;
    }
}