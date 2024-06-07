#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {
    vector<string> cases = { "dvdf", "abcabcbb", "bbbbb", "pwwkew", "abba" };
    for (string s : cases) {
        unordered_set<char> c;

        int max_length = 0;
        int temp = 0;
        int start = 0; int end = 0;

        for (end = 0; end < s.length(); end++) {
            if (c.find(s[end]) == c.end()) {
                max_length = max(max_length, end - start + 1);
                c.insert(s[end]);
            }
            else {
                while (s[start] != s[end]) {
                    c.erase(c.find(s[start]));
                    start++;
                }
                c.erase(c.find(s[start])); start++;
                c.insert(s[end]);
            }
        }
        cout << s << endl;
        cout << max_length << endl << endl;
    }
}