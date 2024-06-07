#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int strStr(string haystack, string needle) {
        size_t f = haystack.find(needle);
        if (f != string::npos)
            return (int)f;
        return -1;
    }
};