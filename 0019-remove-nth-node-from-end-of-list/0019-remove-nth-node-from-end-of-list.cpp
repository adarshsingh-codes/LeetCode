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
        ListNode* prev=NULL;
        ListNode* temp=head;
        while(temp!=NULL){
            temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL || n<=0){
            return NULL;
        }
        head=rev(head);
        if(n==1){
            ListNode* del=head;
            head=head->next;
            delete del;
            return rev(head);
        }
        ListNode* temp=head;
        for(int i=1;i<n-1&&temp!=NULL;i++){
            temp=temp->next;
        }
        if(temp==NULL||temp->next==NULL){
            return rev(head);
        }
        ListNode* del=temp->next;
        temp->next=del->next;
        delete del;
        head=rev(head);
        return head;
    }
};