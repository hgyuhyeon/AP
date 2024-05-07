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
    ListNode* doubleIt(ListNode* head) {
        if (head->val == 0) return head;
        vector<ListNode*> v;
        ListNode* ptr = head;
        while (ptr != nullptr) {
            v.push_back(ptr);
            ptr = ptr->next;
        }
        int rnd = 0;
        for (int i = v.size()-1; i>=0; i--) {
            v[i]->val *= 2;
            if (rnd) v[i]->val += rnd;
            rnd = v[i]->val / 10;
            v[i]->val %= 10;
        }
        if (rnd) return new ListNode(rnd, head);
        return head;
    }
};