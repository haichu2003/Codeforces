#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    vector<string> v = { "MCMXCIV" };
    for (auto s : v) {
        int to_return = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == 'V') to_return += 5;
            else if (s[i] == 'L') to_return += 50;
            else if (s[i] == 'D') to_return += 500;
            else if (s[i] == 'M') to_return += 1000;
            else if (s[i] == 'I') {
                if (i + 1 < s.length()) {
                    if (s[i + 1] == 'V') { to_return += 4; i++; }
                    else if (s[i + 1] == 'X') { to_return += 9; i++; }
                    else to_return += 1;
                }
                else to_return += 1;
            }
            else if (s[i] == 'X') {
                if (i + 1 < s.length()) {
                    if (s[i + 1] == 'L') { to_return += 40; i += 1; }
                    else if (s[i + 1] == 'C') { to_return += 90; i += 1; }
                    else to_return += 10;
                }
                else to_return += 10;
            }
            else if (s[i] == 'C') {
                if (i + 1 < s.length()) {
                    if (s[i + 1] == 'D') { to_return += 400; i += 1; }
                    else if (s[i + 1] == 'M') { to_return += 900; i += 1; }
                    else to_return += 100;
                }
                else to_return += 100;
            }
        }
        cout << to_return << endl;
    }
}