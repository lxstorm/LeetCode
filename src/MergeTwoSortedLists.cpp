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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        ListNode* resList = new ListNode(0);
        ListNode* np = resList;

        while(p1 != NULL && p2 != NULL)
        {
            ListNode* tmp = new ListNode(0);
            if(p1->val > p2->val){
                tmp->val = p2->val;
                p2 = p2->next;
            }
            else{
                tmp->val = p1->val;
                p1 = p1->next;
            }
            np->next = tmp;
            np = tmp;
        }
        while(p1 != NULL){
            ListNode* tmp = new ListNode(p1->val);
            np->next = tmp;
            np = tmp;
            p1 = p1->next;
        }
        while(p2 != NULL){
            ListNode* tmp = new ListNode(p2->val);
            np->next = tmp;
            np = tmp;
            p2 = p2->next;
        }
        return resList->next;
    }
};
