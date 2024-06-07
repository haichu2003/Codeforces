#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize)
            return false;
        sort(hand.begin(), hand.end());
        unordered_map<int, int> hash;
        for (int i = 0; i < hand.size(); ++i)
            hash[hand[i]]++;
        for (int i = 0; i < hand.size(); ++i) {
            int curr = hand[i];
            if (!hash[curr])
                continue;  // not available
            hash[curr]--;
            for (int j = 1; j < groupSize; ++j) {
                if (hash[curr + j])
                    hash[curr + j]--;
                else
                    return false;
            }
        }
        return true;
    }
};