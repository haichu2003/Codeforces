#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        while (node->next != nullptr) {
            node->val = node->next->val;
            if (node->next->next != nullptr) node = node->next;
            else node->next = nullptr;
        }
    }
};

int main() {
    std::vector<std::pair<std::vector<int>, int>> q = {
        {{4, 5, 1, 9}, 5},
        {{4, 5, 1, 9}, 1}
    };
    Solution sol;
    for (auto p : q) {
        auto l = p.first;
        auto n = p.second;
        ListNode* head = new ListNode(l[0]);
        ListNode* temp = head;
        ListNode* to_be_del;
        if (l[0] == n) to_be_del = head;
        for (int i = 1; i < l.size(); ++i) {
            temp->next = new ListNode(l[i]);
            temp = temp->next;
            if (l[i] == n) to_be_del = temp;
        }
        sol.deleteNode(to_be_del);
        while (head != nullptr) {
            std::cout << head->val << " ";
            head = head->next;
        }
        std::cout << std::endl;
    }
}