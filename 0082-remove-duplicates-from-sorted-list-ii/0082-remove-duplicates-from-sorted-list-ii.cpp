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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL||head->next==NULL){
            return head;
        }
        ListNode* dummy=new ListNode(0);
        ListNode* temp1=dummy;

        ListNode* temp=head;

        while(temp!=NULL&&temp->next!=NULL){
            if(temp->val==temp->next->val){
                int x=temp->val;
                while(temp!=NULL&&temp->val==x){
                    temp=temp->next;
                }
            }
            else{
                temp1->next=temp;
                temp1=temp1->next;
                temp=temp->next;
           }
        }
        if(temp!=NULL){
            temp1->next=temp;
            temp1=temp1->next;
        }
        temp1->next=NULL;
        return dummy->next;
    }
};