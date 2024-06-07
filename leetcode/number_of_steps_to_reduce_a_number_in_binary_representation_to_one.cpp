#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int numSteps(string s) {
        int cnt = 0;
        while (s.length() > 1) {
            if (s[s.length() - 1] == '0')
                s.pop_back();
            else {
                int i = s.length() - 1;
                while (i >= 0 && s[i] == '1') {
                    s[i] = '0';
                    i--;
                }
                if (i < 0) {
                    s = "1" + s;
                } else
                    s[i] = '1';
            }
            cnt++;
        }
        return cnt;
    }
};