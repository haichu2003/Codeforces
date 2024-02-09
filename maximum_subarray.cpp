#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<int>> numbers = { {-2,1,-3,4,-1,2,1,-5,4}, {1}, {5,4,-1,7,8} };
    for (auto nums : numbers) {
        int max_sum = 0;
        int temp = 0;
        for (int i = 0; i < nums.size(); ++i) {
            temp = max(nums[i], temp + nums[i]);
            max_sum = max(max_sum, temp);
        }
        cout << max_sum << endl;
    }
}