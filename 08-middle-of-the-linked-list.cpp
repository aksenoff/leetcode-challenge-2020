// https://leetcode.com/problems/middle-of-the-linked-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* current = 0;
        int num_elem = 0;
        current = head;
        while (current != NULL)
        {
            current = current->next;
            num_elem++;
        }
        if (num_elem == 1)
        {
            return head;
        }
        int num_skips = num_elem / 2;
        current = head;
        for (int i = 0; i < num_skips; i++)
        {
            current = current->next;
        }
        return current;
    }
};