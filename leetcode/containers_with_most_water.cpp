#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0, right = n - 1;
        int area = 0;
        while (left < right) {
            area = max(area, (right - left) * min(height[left], height[right]));
            height[left] < height[right] ? left++ : right--;
        }
        return area;
    }
};