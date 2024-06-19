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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        vector<ListNode*> v;
        ListNode* ptr = head;
        while (ptr != NULL) {
            v.push_back(ptr);
            ptr = ptr->next;
        }
        sort(v.begin(), v.end(), [](ListNode* a, ListNode* b) {
            return a->val < b->val;
        });
        int n = v.size();
        for (int i = 0; i < n - 1; i++) v[i]->next = v[i+1];
        v[n-1]->next = NULL;
        return v[0];
    }
};