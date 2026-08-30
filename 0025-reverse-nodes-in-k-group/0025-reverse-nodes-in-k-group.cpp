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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;
        int count = 0;
        ListNode* curr = head;
        while (curr) {
            count++;
            curr = curr->next;
        }
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev_group_tail = &dummy;
        curr = head;
        while (count >= k) {
            ListNode* prev = nullptr;
            ListNode* next = nullptr;
            ListNode* group_head = curr; 
            for (int i = 0; i < k; ++i) {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            prev_group_tail->next = prev;
            group_head->next = curr;
            prev_group_tail = group_head;
            count -= k;
        }
        return dummy.next;
    }
};