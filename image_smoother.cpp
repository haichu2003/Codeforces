#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size();
        if (m == 0)
            return {{}};
        int n = img[0].size();
        vector<vector<int>> ans(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int cnt = 0, total = 0;
                for (int u = i - 1; u <= i + 1; ++u) {
                    for (int v = j - 1; v <= j + 1; ++v) {
                        if (u < 0 || u >= m)
                            continue;
                        if (v < 0 || v >= n)
                            continue;
                        cnt++;
                        total += img[u][v];
                    }
                }
                ans[i][j] = total / cnt;
            }
        }
        return ans;
    }
};