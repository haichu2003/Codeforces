#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // my solution
    string multiply1(string num1, string num2) {
        if (num1 == "0" || num2 == "0")
            return "0";
        else if (num1 == "1")
            return num2;
        else if (num2 == "1")
            return num1;
        string ans;
        vector<string> sub;
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        for (int i = 0; i < num1.length(); ++i) {
            int a = num1[i] - '0';
            string temp = "";
            int remain = 0;
            for (int j = 0; j < num2.length(); ++j) {
                int b = num2[j] - '0';
                int t = a * b + remain;
                int l = t % 10;
                remain = t / 10;
                temp += (l + '0');
            }
            while (remain > 0) {
                temp += (remain % 10 + '0');
                remain /= 10;
            }
            for (int k = 0; k < i; ++k) {
                temp = "0" + temp;
            }
            reverse(temp.begin(), temp.end());
            sub.push_back(temp);
        }
        ans = sub[0];
        for (int i = 1; i < sub.size(); ++i) {
            string temp = sub[i];
            string temp_ans = "";
            if (temp.length() < ans.length())
                swap(temp, ans);
            reverse(temp.begin(), temp.end());
            reverse(ans.begin(), ans.end());
            int j = 0;
            int remain = 0;
            for (j; j < ans.length(); ++j) {
                int t = (temp[j] - '0') + (ans[j] - '0') + remain;
                temp_ans += (t % 10) + '0';
                remain = t / 10;
            }
            for (j; j < temp.length(); ++j) {
                int t = temp[j] - '0' + remain;
                temp_ans += (t % 10) + '0';
                remain = t / 10;
            }
            while (remain > 0) {
                temp_ans += (remain % 10) + '0';
                remain /= 10;
            }
            reverse(temp_ans.begin(), temp_ans.end());
            ans = temp_ans;
        }
        return ans;
    }

    // best solution
    string multiply(string num1, string num2) {
        vector<int> res(num1.size() + num2.size());

        for (int i = num2.size() - 1; i >= 0; i--) {
            for (int j = num1.size() - 1; j >= 0; j--) {
                res[i + j + 1] += (num2[i] - '0') * (num1[j] - '0');
                int carry = res[i + j + 1] / 10;
                res[i + j + 1] %= 10;
                res[i + j] += carry;
            }
        }

        for (int i = res.size() - 1; i > 1; i--) {
            int carry = res[i] / 10;
            res[i] %= 10;
            res[i - 1] += carry;
        }

        int start = 0;
        while (start < res.size() && res[start] == 0)
            start++;
        string ans;
        while (start < res.size())
            ans.push_back(res[start] + '0'), start++;

        return ans.empty() ? "0" : ans;
    }
};