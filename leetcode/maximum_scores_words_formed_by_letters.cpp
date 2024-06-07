#include <bits/stdc++.h>
using namespace std;

class Solution {
   private:
    int a[26] = {0}, b[26] = {0}, ans = 0;

    void backtrack(int i, vector<string>& words, vector<int>& scores) {
        if (i == words.size()) {
            int sc = 0;
            for (int j = 0; j < 26; ++j) {
                if (b[j] > a[j])
                    return;  // a letter is used mor than it is given
                sc += scores[j] * b[j];
            }
            ans = max(ans, sc);
            return;
        }
        backtrack(i + 1, words, scores);  // skip current case
        for (auto x : words[i])
            b[x - 'a']++;                 // add current word's letters to b
        backtrack(i + 1, words, scores);  // call next case
        for (auto x : words[i])
            b[x - 'a']--;  // remove current word's letters from b
    }

   public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        for (auto l : letters)
            a[l - 'a']++;  // count number of each letter given
        backtrack(0, words, score);
        return ans;
    }
};

int main() {
    vector<pair<pair<vector<string>, vector<char>>, vector<int>>> questions = {
        {{{"dog", "cat", "dad", "good"}, {'a', 'a', 'c', 'd', 'd', 'd', 'g', 'o', 'o'}}, {1, 0, 9, 5, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}},
        {{{"xxxz", "ax", "bx", "cx"}, {'z', 'a', 'b', 'c', 'x', 'x', 'x'}}, {4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 10}},
        {{{"leetcode"}, {'l', 'e', 't', 'c', 'o', 'd'}}, {0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0}}};
    Solution sol;
    for (auto q : questions) {
        auto words = q.first.first;
        auto letters = q.first.second;
        auto score = q.second;
        int ans = sol.maxScoreWords(words, letters, score);
        cout << ans << endl
             << endl;
    }
}