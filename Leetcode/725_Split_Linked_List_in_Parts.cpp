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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = 0;
        ListNode* ptr = head;
        while (ptr != NULL) {
            n++;
            ptr = ptr->next;
        }
        ptr = head;
        int shr = n / k, rem = n % k, i = 0;
        vector<ListNode*> ans(k);
        while (ptr != NULL) {
            ans[i++] = ptr;
            int cnt = shr + (rem-- > 0 ? 1 : 0);
            while (cnt-- > 1) ptr = ptr->next;
            ListNode* prev = ptr;
            ptr = ptr->next;
            prev->next = NULL;
        }
        return ans;
    }
};