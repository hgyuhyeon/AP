/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans(2);
        ans[0] = INT_MAX;
        vector<int> cr;
        ListNode* ptr = head->next, *prev = head;
        int i = 2;
        while (ptr->next != NULL) {
            if (prev->val > ptr->val && ptr->next->val > ptr->val) cr.push_back(i);
            if (prev->val < ptr->val && ptr->next->val < ptr->val) cr.push_back(i);
            prev = ptr;
            ptr = ptr->next;
            i++;
        }

        if (!cr.size() || cr.size() == 1) return vector<int>(2, -1);

        for (int i = 1; i < cr.size(); i++) ans[0] = min(ans[0], cr[i] - cr[i-1]);
        ans[1] = max(ans[1], cr.back() - cr[0]);
        return ans;
    }
};