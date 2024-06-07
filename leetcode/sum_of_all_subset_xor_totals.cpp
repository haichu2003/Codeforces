#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        // go from 1 (e.g. 0001) to 2^n (e.g. 1111)
        // to get all combination (e.g. 0001, 0010, 0100, etc)
        for (int i = 1; i < (1 << n); ++i) {
            int current = 0;
            for (int j = 0; j < n; ++j) {
                // if the current index matches the combination (e.g. 0001 and 1 or 0011 and 2)
                if (i & (1 << j))
                    current ^= nums[j];
            }
            total += current;
        }
        return total;
    }
};

int main() {
    cout << (0 ^ 0) << endl;
}