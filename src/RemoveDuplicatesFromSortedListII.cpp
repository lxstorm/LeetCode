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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head)   return NULL;
        if(!head->next) return head;

        ListNode *p = head->next;
        int dup = head->val;
        while(p && p->val == dup){
            p = p->next;
        }
        if(p == head->next){
            head->next = deleteDuplicates(p);
            return head;
        }
        else{
            return deleteDuplicates(p);
        }
    }
};
