#include <bits/stdc++.h>
using namespace std;

class Solution {
   private:
    vector<vector<int>> ans;
    void swap(int& x, int& y) {
        int temp = x;
        x = y;
        y = temp;
    }

    void backtrack(vector<int> nums, int i) {
        if (i == nums.size() - 1) {
            ans.push_back(nums);
            return;
        }
        for (int l = i; l < nums.size(); ++l) {
            swap(nums[l], nums[i]);
            backtrack(nums, i + 1);
            swap(nums[l], nums[i]);
        }
    }

   public:
    vector<vector<int>> permute(vector<int>& nums) {
        backtrack(nums, 0);
        return ans;
    }
};
