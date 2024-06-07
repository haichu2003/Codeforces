#include <iostream>
#include <vector>

class Solution {
public:
    int hIndex(std::vector<int>& citations) {
        int left = 0;
        int n = citations.size();
        int right = citations.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (citations[mid] >= n - mid) right = mid - 1;
            else left = mid + 1;
        }
        return n - left;
    }
};

int main() {
    std::vector<std::vector<int>> q = {
        {0,1,3,5,6},
        {1, 2, 100}
    };
    Solution sol;
    for (auto s : q) {
        for (auto i : s) { std::cout << i << " "; }
        std::cout << sol.hIndex(s) << std::endl;
    }
}