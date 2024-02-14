#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> numbers = { 2, 5 };
    for (auto n : numbers) {
        vector<int> ans(n + 1);
        for (int i = 0; i <= n; ++i) {
            int c;
            int v = i;
            for (c = 0; v; v >>= 1) {
                c += v & 1;
            }
            ans[i] = c;
        }
        for (auto c : ans) {
            cout << c << " ";
        }
        cout << "\n";
    }
}