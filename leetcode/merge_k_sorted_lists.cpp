#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode()
        : val(0), next(nullptr) {}
    ListNode(int x)
        : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next)
        : val(x), next(next) {}
};
class Solution {
   public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty())
            return nullptr;
        vector<int> n;
        for (auto l : lists) {
            while (l) {
                n.push_back(l->val);
                l = l->next;
            }
        }
        if (n.empty())
            return nullptr;
        sort(n.begin(), n.end());
        ListNode* head = new ListNode(n[0]);
        ListNode* temp = head;
        for (int i = 1; i < n.size(); ++i) {
            temp->next = new ListNode(n[i]);
            temp = temp->next;
        }
        return head;
    }
};