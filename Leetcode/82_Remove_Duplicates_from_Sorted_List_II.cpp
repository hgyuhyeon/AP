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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* ptr = head, *nh = new ListNode(0, head), *prev = nh;
        while (ptr != NULL) {
            if (ptr->next != NULL && ptr->val == ptr->next->val) {
                while (ptr->next != NULL && ptr->val == ptr->next->val) ptr = ptr->next;
                prev->next = ptr->next;
                if (ptr != NULL) ptr = ptr->next;
            }
            else {
                prev = ptr;
                ptr = ptr->next;
            }
        }
        return nh->next;
    }
};