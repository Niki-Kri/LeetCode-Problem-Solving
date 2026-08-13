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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;
        ListNode d(0);
        d.next = head;
        ListNode* p = &d;
        for (int i = 1; i < left; i++) {
            p = p->next;
        }
        ListNode* c = p->next;
        for (int i = 0; i < right - left; i++) {
            ListNode* n = c->next;
            c->next = n->next;
            n->next = p->next;
            p->next = n;
        }
        return d.next;
    }
};