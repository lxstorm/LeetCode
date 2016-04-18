/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
// former solution
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
*/

/*
//not use dummy
class Solution{
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
        if(!l1) return l2;
        if(!l2) return l1;

        ListNode *head = NULL;

        if(l1->val < l2->val) {head = l1;l1 = l1->next;}
        else                  {head = l2;l2 = l2->next;}
        cout<<head->val<<endl;
        ListNode *p = head;

        while(l1 && l2){
            if(l1->val < l2->val){
                p->next = l1;
                l1 = l1->next;
            }
            else{
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        if(l1)  p->next = l1;
        else    p->next = l2;

        return head;
    }
};
*/
// use dummy
class Solution{
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        while(l1 && l2){
            if(l1->val < l2->val){
                tail->next = l1;
                l1 = l1->next;
            }
            else{
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        if(l1) tail->next = l1;
        else   tail->next = l2;

        return dummy->next;
    }
};
