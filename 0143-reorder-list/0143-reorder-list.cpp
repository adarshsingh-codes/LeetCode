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
    ListNode* rev(ListNode* head){
        ListNode* curr=head;
        ListNode* temp=head;
        ListNode* prev=NULL;
        while(temp!=NULL){
            temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }

    void reorderList(ListNode* head) {
        if(head==NULL||head->next==NULL){
            return;
        }
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL&&fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* first=head;
        ListNode* last=rev(slow->next);
        slow->next=NULL;
        while(first!=NULL&&last!=NULL){
            
            ListNode* temp1=first->next;
            ListNode* temp2=last->next;

            first->next=last;
            last->next=temp1;
            first=temp1;
            last=temp2;
        }
    }
};