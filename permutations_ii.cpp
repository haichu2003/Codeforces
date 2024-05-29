#include <bits/stdc++.h>
using namespace std;

class Solution {
   private:
    set<vector<int>> ans;
    void swap(int& x, int& y) {
        int temp = x;
        x = y;
        y = temp;
    }

    void backtrack(vector<int> nums, int i) {
        if (i == nums.size() - 1) {
            ans.insert(nums);
            return;
        }
        for (int l = i; l < nums.size(); ++l) {
            if (l != i && nums[l] == nums[l - 1]) continue;
            swap(nums[l], nums[i]);
            backtrack(nums, i + 1);
            swap(nums[l], nums[i]);
        }
    }

   public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        backtrack(nums, 0);
        return vector<vector<int>>(ans.begin(), ans.end());
    }
};

int main() {
    vector<vector<int>> questions = {
        {1, 1, 2}
    };
    Solution sol;
    for (auto q: questions) {
        auto ans = sol.permuteUnique(q);
        for (auto i: ans) {
            cout<<"[ ";
            for (auto j: i) {
                cout<<j<<" ";
            }
            cout<<"], ";
        }
        cout<<endl;
    }
}