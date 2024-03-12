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
    ListNode* removeZeroSumSublists(ListNode* head) {
        vector<int> v;
        ListNode* ptr = head;
        while (ptr != NULL) {
            v.push_back(ptr->val);
            ptr = ptr->next;
        }
        int lo, hi = 0, sum = v[0], n = v.size();
        while (++hi < n) {
            sum += v[hi];
            lo = -1;
            int tmp = sum;
            while (++lo <= hi) {
                if (tmp == 0) {
                    for (int i = lo; i <= hi; i++) v[i] = 0;
                }
                tmp -= v[lo];
            }
        }
        ListNode* ans = new ListNode(0);
        ptr = ans;
        for (auto i: v) {
            if (i != 0) {
                ptr->next = new ListNode(i);
                ptr = ptr->next;
            }
        }
        return ans->next;
    }
};