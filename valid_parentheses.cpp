#include <iostream>
#include <vector>
#include <string>
#include <stack>
class Solution {
public:
    char getParenthesis(char c) {
        if (c == ')') return '(';
        else if (c == '}') return '{';
        else if (c == ']') return '[';
        else return ' ';
    }
    bool isValid(std::string s) {
        std::stack<char> sta;
        sta.push(s[0]);
        for (int i = 1; i < s.length(); ++i) {
            if (sta.empty() || (!sta.empty() && (sta.top() != getParenthesis(s[i])))) {
                sta.push(s[i]);
            }
            else sta.pop();
        }
        return sta.empty();
    }
};

int main() {
    std::vector<std::string> q = {
        "()",
        "()[]{}",
        "(]"
    };
    Solution sol;
    for (auto s : q) {
        std::cout << s << "\t" << (sol.isValid(s) ? "yes" : "no") << std::endl;
    }
}