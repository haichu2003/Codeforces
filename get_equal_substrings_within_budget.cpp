#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int equalSubstring(string s, string t, int maxCost) {
        int left = 0, right = 0;
        int total = 0;
        int len = 0;
        int al = 0, ar = 0;
        for (right = 0; right < s.length(); ++right) {
            int current = (abs(s[right] - t[right]));
            cout << "right: " << right << "\tleft: " << left << endl;
            cout << s[right] << " - " << t[right] << " = " << current << endl;
            if (total + current <= maxCost) {
                total += current;
                ar += 1;
            } else {
                len = max(len, ar - al);
                ar += 1;
                al += 1;
                total += current;
                total -= abs(s[left] - t[left]);
                left++;
            }
        }

        len = max(len, min(ar - al, right - left));
        return len;
    }
};