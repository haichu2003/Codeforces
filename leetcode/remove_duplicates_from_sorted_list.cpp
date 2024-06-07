#include <bits/stdc++.h>
using namespace std;

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

// class Solution {
//    public:
//     ListNode* deleteDuplicates(ListNode* head) {
//         if (head == nullptr)
//             return head;
//         vector<int> check(300, 0);
//         auto ans = head;
//         check[ans->val + 100] = 1;
//         while (ans != nullptr) {
//             auto temp = ans->next;
//             if (temp != nullptr && check[temp->val + 100]) {
//                 ans->next = temp->next;
//             } else {
//                 if (temp != nullptr) {
//                     check[temp->val + 100] = 1;
//                     ans = ans->next;
//                 } else
//                     break;
//             }
//         }
//         if (ans != nullptr) {
//             if (check[ans->val + 100])
//                 ans = nullptr;
//         }
//         return head;
//     }
// };

class Solution {
   public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        auto a = head;
        auto b = a->next;
        while (b != nullptr) {
            while (b != nullptr && a->val == b->val)
                b = b->next;
            a->next = b;
            a = b;
            if (b != nullptr)
                b = b->next;
        }
        return head;
    }
};