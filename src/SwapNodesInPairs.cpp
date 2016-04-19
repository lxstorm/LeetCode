/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 /* my first AC solution
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        if(head == NULL || head->next == NULL)
            return head;
        ListNode* p = dummy;
        ListNode* p1 = p->next;
        ListNode* p2 = p1->next;
        ListNode* p3 = p2->next;

        while(1){
            cout<<p2->val<<endl;
            p->next = p2;
            p2->next = p1;
            p1->next = p3;

            p = p1;
            p1 = p->next;
            if(p1)
            p2 = p1->next;
            else
            break;
            if(p2)
            p3 = p2->next;
            else
            break;
        }
        return dummy->next;
    }
};
*/
// recursive solution
// try to connect the next element that is head->next->next, then try to swap
class Solution{
public:
    ListNode* swapPairs(ListNode* head){
        ListNode* p = head;
        if(p && p->next){
            p = p->next;
            head->next = swapPairs(p->next);
            p->next = head;

        }
        return p;
    }
};
