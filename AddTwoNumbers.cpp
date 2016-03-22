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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* sumList = new ListNode(0);
        ListNode* p;
        p = sumList;
        int val1 = 0;
        int carry = 0;
        int lval1 = l1->val;
        int lval2 = l2->val;

        while(l1 != NULL || l2 != NULL){
            val1 = (lval1 + lval2 + carry) % 10;
            carry = (lval1 + lval2 + carry) / 10;
            Insert(p, val1);

            if(l1 != NULL){
                l1 = l1->next;
                if(l1 != NULL)
                    lval1 = l1->val;
                else
                    lval1 = 0;
            }
            else{
                val1 = 0;
            }

            if(l2 != NULL){
                l2 = l2->next;
                if(l2 != NULL)
                    lval2 = l2->val;
                else
                    lval2 = 0;
            }
            else{
                lval2 = 0;
            }
            p = p->next;
            if(l1 == NULL && l2 == NULL && carry !=0)
                Insert(p,carry);

        }
        return sumList->next;
    }

    void Insert(ListNode* lNode, int value){
        ListNode *tmp = new ListNode(0);
        tmp->val = value;
        tmp->next = lNode->next;
        lNode->next = tmp;
    }

};
