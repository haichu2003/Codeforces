#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    int myAtoi(std::string s) {
        long int ans = 0;
        bool has_sign = false;
        int i = 0;
        while (i < s.length()) {
            if (s[i] == ' ') {
                i++;
                continue;
            }
            else if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) return ans;
            else break;
            i++;
        }
        if (s[i] == '+' || s[i] == '-') {
            if (s[i] == '-') has_sign = true;
            i++;
        }
        int count_num = 0;
        bool is_zero_lead = true;
        while (i < s.length() && count_num <= 10) {
            if (is_zero_lead && s[i] != '0') is_zero_lead = false;
            if (!(s[i] >= '0' && s[i] <= '9')) break;
            else {
                ans *= 10;
                ans += s[i] - '0';
            }
            if (s[i] != '0' && is_zero_lead) count_num ++;
            i++;
        }
        ans *= (has_sign ? -1 : 1);
        if (ans > INT32_MAX || (!has_sign & count_num > 10)) return INT32_MAX;
        else if (ans < INT32_MIN || (has_sign & count_num > 10)) return INT32_MIN;
        return (int) ans;
    }
};

int main() {
    std::vector<std::string> q = { "42", "  -042", "1337c0d3", "0-1", "words and 987", "00000000000012345678", "20000000000000000000" };
    Solution sol;
    for (auto s : q) {
        std::cout << sol.myAtoi(s) << std::endl;
    }
    return 0;
}