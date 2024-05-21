#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        vector<int> temp;
        for (int i = 0; i < n; ++i) {
            if (nums[i] != val)
                temp.push_back(nums[i]);
        }
        // sort(temp.begin(), temp.end());
        nums = temp;
        return nums.size();
    }
};
