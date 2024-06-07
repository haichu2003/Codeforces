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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr) return head;
        if (head->next == nullptr) return head;
        ListNode* t = head->next;
        head->next = t->next;
        t->next = head;
        ListNode* temp = head;
        head = t;
        while (temp->next != nullptr && temp->next->next != nullptr) {
            ListNode* t1 = temp->next;
            ListNode* t2 = t1->next;
            temp->next = t2;
            t1->next = t2->next;
            t2->next = t1;
            temp = temp->next->next;
        }
        return head;
    }
};