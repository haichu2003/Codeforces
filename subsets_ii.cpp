#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void go(vector<int>& v, int start, int end, vector<int> temp, vector<vector<int>>& ans) {
        ans.push_back(temp);
        for (int i = start; i < end; ++i) {
            if (i != start && v[i] == v[i - 1]) continue;
            temp.push_back(v[i]);
            go(v, i + 1, end, temp, ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        sort (nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        go(nums, 0, n, temp, ans);
        return ans;
    }
};