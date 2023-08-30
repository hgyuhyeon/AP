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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* construct(ListNode* left, ListNode* right) {
        if (left == right) return nullptr;
        ListNode* sl = left, *fa = left;
        while (fa != right && fa->next != right) {
            sl = sl->next;
            fa = fa->next->next;
        }
        TreeNode* node = new TreeNode(sl->val);
        node->left = construct(left, sl);
        node->right = construct(sl->next, right);
        return node;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        if (head == nullptr) return nullptr;
        else if (head->next == nullptr) return new TreeNode(head->val);
        else return construct(head, nullptr);
    }
};