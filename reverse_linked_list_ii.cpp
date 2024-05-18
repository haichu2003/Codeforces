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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* temp_left;
        ListNode* temp_right;
        ListNode* temp = head;
        int count = 1;
        list<int> val;
        while (count <= right) {
            if (count == left) {
                temp_left = temp;
            }
            if (count == right) {
                temp_right = temp;
            }
            if (count >= left)
                val.push_back(temp->val);
            temp = temp->next;
            count++;
        }
        temp = temp_left;
        while (temp != temp_right->next) {
            temp->val = val.back();
            val.pop_back();
            temp = temp->next;
        }
        return head;
    }
};