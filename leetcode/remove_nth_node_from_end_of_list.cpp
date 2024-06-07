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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count_node = 0;
        ListNode* temp = head;
        while (temp != nullptr) {
            count_node++;
            temp = temp->next;
        }
        int node_to_remove = count_node - n;
        if (node_to_remove < 0) return nullptr;
        else if (node_to_remove == 0) return head->next;
        node_to_remove--;
        temp = head;
        while (node_to_remove--) {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        return head;
    }
};

int main() {
    std::vector<std::pair<std::vector<int>, int>> q = {
        {{1, 2, 3, 4, 5}, 2},
        {{1}, 1},
        {{1, 2}, 1}
    };
    for (auto p : q) {
        Solution sol;
        std::vector<int> s = p.first;
        int n = p.second;
        ListNode* temp = new ListNode(s[0]);
        ListNode* head = temp;
        for (int i = 1; i < s.size(); ++i) {
            temp->next = new ListNode(s[i]);
            temp = temp->next;
        }
        ListNode* ans = sol.removeNthFromEnd(head, n);
        while (ans != nullptr) {
            std::cout << ans->val << " ";
            ans = ans->next;
        }
        std::cout << std::endl;
        delete head;
        delete ans;
    }
    return 0;
}
