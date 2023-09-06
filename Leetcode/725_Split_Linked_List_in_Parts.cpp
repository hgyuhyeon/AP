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
        vector<ListNode*> ans;
        queue<ListNode*> q;
        int len = 0;
        ListNode* ptr = head;
        while (ptr != NULL) {
            len++;
            ptr = ptr->next;
        }

        int num = len / k, plus = len % k;
        ptr = head;
        while (k > 0 && ptr != NULL) {
            ans.push_back(ptr);
            for (int i = 0; i < num + (plus > 0) - 1; i++) ptr = ptr->next;
            ListNode* temp = ptr->next;
            ptr->next = NULL;
            ptr = temp;
            plus = plus - 1 > 0 ? plus - 1 : 0;
            k--;
        }

        while (k-- > 0) ans.push_back(NULL);

        return ans;
    }
};