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
    int size = 0;
    ListNode* list;

    Solution(ListNode* head) {
        list = head;
        ListNode* ptr = list;
        while (ptr != NULL) {
            size++;
            ptr = ptr->next;
        }
    }
    
    int getRandom() {
        int num = rand() % size;
        ListNode* ptr = list;
        for (int i = 0; i < num; i++) {
            ptr = ptr->next;
        }
        return ptr->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */