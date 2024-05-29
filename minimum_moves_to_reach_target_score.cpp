#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int minMoves(int target, int maxDoubles) {
        int cnt = 0;
        while (target > 1) {
            if (target % 2 == 0 && maxDoubles > 0) {
                target /= 2;
                maxDoubles--;
            } else
                target -= 1;
            if (maxDoubles == 0)
                return target + cnt;
            cnt++;
        }
        return cnt;
    }
};