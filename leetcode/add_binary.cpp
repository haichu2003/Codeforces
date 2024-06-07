#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    string addBinary(string a, string b) {
        if (a.length() < b.length())
            swap(a, b);
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int res = 0;
        string ans = "";
        for (int i = 0; i < a.length(); ++i) {
            int ia = a[i] - '0';
            int ib = 0;
            if (i < b.length())
                ib = b[i] - '0';
            char v = ((ia ^ ib) ^ res) + '0';
            res = (ia + ib + res) / 2;
            ans += v;
        }
        if (res != 0)
            ans += (res + '0');
        reverse(ans.begin(), ans.end());
        return ans;
    }
};