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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* ptr = head;
        while (ptr != NULL) {
            if (!ptr->next) break;
            int div = gcd(ptr->val, ptr->next->val);
            ListNode* node = new ListNode(div, ptr->next);
            ptr->next = node;
            ptr = ptr->next->next;
        }
        return head;
    }
};