#include <bits/stdc++.h>
using namespace std;

class Solution {
   private:
    vector<vector<bool>> dp;
    bool isPalindrome(string& s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }

    void computeDP(string& s) {
        for (int i = 0; i < s.length(); ++i) {
            for (int j = i; j < s.length(); ++j) {
                dp[i][j] = isPalindrome(s, i, j);
            }
        }
    }

   public:
    string longestPalindrome(string s) {
        cout << s << endl;
        dp.clear();
        dp.assign(s.length(), vector<bool>(s.length(), false));
        computeDP(s);
        int start = 0, len = 0;
        for (int i = 0; i < dp.size(); ++i) {
            for (int j = 0; j < dp[i].size(); ++j) {
                cout << dp[i][j] << " ";
                if (dp[i][j]) {
                    if (j - i + 1 > len) {
                        start = i;
                        len = j - i + 1;
                    }
                }
            }
            cout << endl;
        }
        return s.substr(start, len);
    }
};

int main() {
    vector<string> q = {"babad", "cbbc", "aba"};
    Solution sol;
    for (auto s : q) {
        auto ans = sol.longestPalindrome(s);
        cout << ans << endl;
    }
}