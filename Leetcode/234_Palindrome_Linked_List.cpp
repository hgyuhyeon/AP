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
    bool isPalindrome(ListNode* head) {
        ListNode* ptr = head;
        vector<int> v;
        while (ptr != nullptr) {
            v.push_back(ptr->val);
            ptr = ptr->next;
        }

        int lo = 0, hi = v.size() - 1;
        while (lo < hi) if (v[lo++] != v[hi--]) return false;
        return true;
    }
};