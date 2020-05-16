// https://leetcode.com/problems/odd-even-linked-list/

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

// TLE
//class Solution {
//public:
//    ListNode* oddEvenList(ListNode* head) {
//        if (!head->next || !head->next->next) return head;
//        ListNode* evencurrent = head->next, * oddcurrent = head, * current = head->next->next, * evenroot = head->next;
//        int i = 3;
//        while (true)
//        {
//            if (i % 2)
//            {
//                oddcurrent->next = current;
//                oddcurrent = current;
//            }
//            else
//            {
//                evencurrent->next = current;
//                evencurrent = current;
//            }
//            if (!current->next) break;
//            current = current->next;
//        }
//        oddcurrent->next = evenroot;
//        return head;
//    }
//};

//TLE2
//class Solution {
//public:
//    ListNode* oddEvenList(ListNode* head) {
//        if (!head->next || !head->next->next) return head;
//        ListNode* evencurrent = head->next, * oddcurrent = head, * evenroot = head->next;
//        while (true)
//        {
//            if (!evencurrent->next) break;
//            oddcurrent->next = evencurrent->next;
//            oddcurrent = oddcurrent->next;
//            if (!oddcurrent->next) break;
//            evencurrent->next = oddcurrent->next;
//            evencurrent = evencurrent->next;
//            cout << '.';
//        }
//        oddcurrent->next = evenroot;
//        return head;
//    }
//};


class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next || !head->next->next) return head;
        ListNode* evencurrent = head->next, * oddcurrent = head, * evenroot = head->next;
        while (evencurrent->next && evencurrent->next->next)
        {
            oddcurrent->next = evencurrent->next;
            oddcurrent = oddcurrent->next;
            evencurrent->next = oddcurrent->next;
            evencurrent = evencurrent->next;
        }
        oddcurrent->next = evenroot;
        return head;
    }
};