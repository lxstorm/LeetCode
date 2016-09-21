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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL)
            return head;

        ListNode* tail = head;
        ListNode* p = head;
        int cnt = 1;
        while(tail->next != NULL){
            tail = tail->next;
            ++cnt;
        }
        int shift = k % cnt;
        if(shift == 0)
            return head;
        for(int i = 0;i < cnt - shift - 1;++i){
            p = p->next;
        }
        ListNode * res = p->next;
        tail->next = head;
        p->next = NULL;
        return res;
    }
};
// another methode use circle
/*
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL)
            return head;

        ListNode* tail = head;

        int cnt = 1;
        while(tail->next != NULL){
            tail = tail->next;
            ++cnt;
        }
        tail->next = head;
        if(k %= cnt){
            for(int i = 0;i < cnt - k;++i)  tail = tail->next;
        }
        ListNode* newHead = tail->next;
        tail->next = NULL;

        return newHead;
    }
};
*/
