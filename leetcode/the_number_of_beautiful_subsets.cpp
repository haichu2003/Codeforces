#include <bits/stdc++.h>
using namespace std;

class Solution {
   private:
    char cnt[1001] = {0};
    void backtrack(int i, int& ans, int k, vector<int>& nums) {
        if (i == nums.size()) {
            ans++;
            return;
        }
        backtrack(i + 1, ans, k, nums);
        int x = nums[i];
        if ((x - k < 0 || cnt[x-k] == 0) && (x + k > 1000 || cnt[x + k] == 0)) {
            cnt[x]++;
            backtrack(i + 1, ans, k, nums);
            cnt[x]--;
        }
    }

   public:
    int beautifulSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 0;
        backtrack(0, ans, k, nums);
        return --ans;
    }
};


int main() {
    vector<pair<vector<int>, int>> cases = {
        {{2, 4, 6}, 2},
        {{1}, 1},
        {{10, 4, 5, 7, 2, 1}, 3},
        {{84,35,65,12,74,30,95,46,23,81,53,64,76,54,94}, 90},
        {{300,180,90,165,255,30,60,240,45,120,135,270,75,150,210,195,105,15,225,285}, 15},
        {{16,1,18,12,11,5,17,15,14,8,20,2,4,6,19,7,13,10,9,3}, 1}
    };
    Solution sol;
    for (auto a : cases) {
        auto nums = a.first;
        auto k = a.second;
        int n = sol.beautifulSubsets(nums, k);
        cout << "count: " << n << endl
             << endl;
    }
}