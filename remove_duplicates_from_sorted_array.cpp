#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> n1, n2;
        vector<int> check(300, 0);
        for (int i = 0; i < nums.size(); ++i) {
            int index = nums[i] + 100;
            if (check[index])
                n2.push_back(nums[i]);
            else {
                n1.push_back(nums[i]);
                check[index] = 1;
            }
        }
        nums.clear();
        nums.insert(nums.end(), n1.begin(), n1.end());
        nums.insert(nums.end(), n2.begin(), n2.end());
        return n1.size();
    }
};