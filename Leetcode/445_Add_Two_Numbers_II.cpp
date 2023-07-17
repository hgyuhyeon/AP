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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<ListNode*> s1, s2;
        ListNode* ans, *next = NULL, *ptr1 = l1, *ptr2 = l2;
        while (ptr1 != NULL) {
            s1.push(ptr1);
            ptr1 = ptr1->next;
        }

        while (ptr2 != NULL) {
            s2.push(ptr2);
            ptr2 = ptr2->next;
        }

        int flag = 0, size = s1.size() < s2.size() ? s1.size() : s2.size();
        for (int i = 0; i < size; i++) {
            int sum = s1.top()->val + s2.top()->val + flag;
            s1.pop();
            s2.pop();
            if (sum >= 10) {
                flag = 1;
                sum %= 10;
            }
            else flag = 0;
            ans = new ListNode(sum, next);
            next = ans;
        }

        if (!s1.empty()) {
            if (flag == 1) {
                while (!s1.empty() && flag == 1) {
                    int sum = s1.top()->val + flag;
                    s1.pop();
                    if (sum >= 10) sum %= 10;
                    else flag = 0;
                    ans = new ListNode(sum, next);
                    next = ans;
                }
            }
            if (!s1.empty()) {
                s1.top()->next = ans;
                ans = l1;
            }
        }
        else if (!s2.empty()) {
            if (flag == 1) {
                while (!s2.empty() && flag == 1) {
                    int sum = s2.top()->val + flag;
                    s2.pop();
                    if (sum >= 10) sum %= 10;
                    else flag = 0;
                    ans = new ListNode(sum, next);
                    next = ans;
                }
            }
            if (!s2.empty()) {
                s2.top()->next = ans;
                ans = l2;
            }
        }

        if (flag == 1) ans = new ListNode(1, next);
        return ans;
    }
};