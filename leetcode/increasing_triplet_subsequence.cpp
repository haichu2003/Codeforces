#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool increasingTriplet(vector<int>& nums) {
        int a = INT_MAX, b = INT_MAX;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] <= a)
                a = nums[i];
            else if (nums[i] <= b)
                b = nums[i];
            else
                return true;
        }
        return false;
    }
};

int main() {
    vector<vector<int>> questions = {
        {1, 2, 3, 4, 5},
        {5, 4, 3, 2, 1},
        {2, 1, 5, 0, 4, 6}};
    Solution sol;
    for (auto nums : questions) {
        auto ans = sol.increasingTriplet(nums);
        cout << (ans ? "True" : "False") << endl;
    }
}