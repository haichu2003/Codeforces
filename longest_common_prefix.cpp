#include <iostream>
#include <string>
#include <vector>
class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string> strs) {
        int last = 0;
        int min_length = INT32_MAX;
        for (auto s: strs) {
            if (s.length() < min_length) min_length = s.length();
        }
        while (last < min_length) {
            char c = strs[0][last];
            int i = 1;
            for (i = 1; i < strs.size(); ++i) {
                if (strs[i][last] != c) break;
            }
            if (i < strs.size()) break;
            last++;
        }
        std::string ans = "";
        for (int i = 0; i < last; ++i) {
            ans += strs[0][i];
        }
        return ans;
    }
};

int main() {
    std::vector<std::vector<std::string>> q = {
        { "flower","flow","flight"},
        {"dog","racecar","car"}
    };
    Solution sol;
    for (auto strs: q) {
        std::cout<<sol.longestCommonPrefix(strs)<<std::endl;
    }
}