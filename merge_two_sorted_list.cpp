#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // recursion approach
        if (!list1) return list2;
        if (!list2) return list1;
        if (list1->val < list2->val) {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }
        list2->next = mergeTwoLists(list1, list2->next);
        return list2;
        // if (list1 == nullptr && list2 == nullptr) return nullptr;
        // if (list1 == nullptr) return list2;
        // else if (list2 == nullptr) return list1;
        // ListNode* head = new ListNode();
        // ListNode* temp = head;
        // while (list1 != nullptr && list2 != nullptr) {
        //     if (list1->val < list2->val) {
        //         temp->val = list1->val;
        //         list1 = list1->next;
        //     }
        //     else {
        //         temp->val = list2->val;
        //         list2 = list2->next;
        //     }
        //     if (list1 != nullptr && list2 != nullptr) {
        //         temp->next = new ListNode();
        //         temp = temp->next;
        //     }
        // }
        // if (list1 != nullptr) temp->next = list1;
        // if (list2 != nullptr) temp->next = list2;
        // return head;
    }
};

int main() {
    std::vector<std::pair<std::vector<int>, std::vector<int>>> q = {
        {{1, 2, 4}, {1, 3, 4}},
        {{}, {}},
        {{}, {0}}
    };
    for (auto p : q) {
        Solution sol;
        std::vector<int> s1 = p.first;
        std::vector<int> s2 = p.second;
        ListNode* head1 = nullptr;
        ListNode* head2 = nullptr;
        if (!s1.empty()) {
            ListNode* temp1 = new ListNode(s1[0]);
            head1 = temp1;
            for (int i = 1; i < s1.size(); ++i) {
                temp1->next = new ListNode(s1[i]);
                temp1 = temp1->next;
            }
        }
        if (!s2.empty()) {
            ListNode* temp2 = new ListNode(s2[0]);
            head2 = temp2;
            for (int i = 1; i < s2.size(); ++i) {
                temp2->next = new ListNode(s2[i]);
                temp2 = temp2->next;
            }
        }
        ListNode* ans = sol.mergeTwoLists(head1, head2);
        while (ans != nullptr) {
            std::cout << ans->val << " ";
            ans = ans->next;
        }
        std::cout << std::endl;
        delete head1;
        delete head2;
        delete ans;
    }
    return 0;
}