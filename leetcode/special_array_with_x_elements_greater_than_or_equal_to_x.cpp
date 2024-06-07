#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int x = -1;
        for (int i = 0; i <= nums.size(); ++i) {
            int cnt = 0;
            for (int j = 0; j < nums.size(); ++j) {
                if (nums[j] >= i) cnt++;
            }
            if (cnt == i) x = cnt;
        }
        return x;
    }
};