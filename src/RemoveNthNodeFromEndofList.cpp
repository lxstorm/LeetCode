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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* tmp = NULL;
        //get the (n+1)th node
        for(int i = 0;i < n;++i){
            fast = fast->next;
        }
        if(fast == NULL)
            return head->next;
        while(fast->next != NULL){
            fast = fast->next;
            slow = slow->next;
        }
        cout<<slow->val<<endl;
        tmp = slow->next;
        slow->next = tmp->next;
        delete tmp;
        tmp = NULL;
        return head;
    }
};
