#include <bits/stdc++.h>
using namespace std;

class Solution {
   private:
    struct Node {
        Node* arr[26];
        bool flag = false;
    };

    Node* root;

    void insert(string word) {
        int n = word.length();
        Node* node = root;
        for (int i = 0; i < n; ++i) {
            if (node->arr[word[i] - 'a'] == nullptr)
                node->arr[word[i] - 'a'] = new Node();
            node = node->arr[word[i] - 'a'];
        }
        node->flag = true;
    }

   public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        root = new Node();
        for (string word : dictionary) {
            insert(word);
        }
        int n = sentence.length();
        string ans = "";
        Node* node = root;
        bool contains = true;
        for (int i = 0; i < n; ++i) {
            ans += sentence[i];
            if (sentence[i] == ' ') {
                node = root;  // reset search
                contains = true;
                continue;
            }
            if (contains && node->arr[sentence[i] - 'a'] != nullptr) {
                node = node->arr[sentence[i] - 'a'];
                if (node->flag) {
                    while (i < n && sentence[i] != ' ')
                        i++;
                    if (i < n)
                        ans += ' ';
                    node = root;
                }
            } else {
                contains = false;
            }
        }
        // delete root;
        return ans;
    }
};

int main() {
    cout<<"Hello World"<<endl;
}