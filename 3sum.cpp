#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int j, k;
        for (int i = 0; i < n; ++i) {
            int a = nums[i];
            if (i > 0 && a == nums[i - 1])
                continue;
            j = i + 1;
            k = n - 1;
            while (j < k) {
                vector<int> r;
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    j++;
                    continue;
                }
                // if (nums[k] == nums[k + 1]) k--; continue;
                if (nums[j] + nums[k] + a == 0) {
                    r.push_back(a);
                    r.push_back(nums[j]);
                    r.push_back(nums[k]);
                    result.push_back(r);
                    j++;
                    k--;
                    // break;
                } else {
                    if (nums[j] + nums[k] > -a)
                        k--;
                    else
                        j++;
                }
            }
        }
        return result;
    }
};