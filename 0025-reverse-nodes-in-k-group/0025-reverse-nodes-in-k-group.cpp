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
        ListNode* temp=head;
        ListNode* curr=head;
        ListNode* prev=NULL;
        while(temp!=NULL){
            temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL||head->next==NULL){
            return head;
        }
        ListNode* temp=head;
        ListNode* prev=NULL;
        while(temp!=NULL){
            ListNode* ksize=temp;
            for(int i=1;i<k;i++){
                if(ksize==NULL) {
                    break;
                }
                ksize=ksize->next;
            }
            if(ksize==NULL){
                break;
            }

            ListNode* afterksize=ksize->next;
            ksize->next=NULL;
            ListNode* newhead=rev(temp);

            if(prev==NULL){
                head=newhead;
            }
            else{
                prev->next=newhead;
            }
            temp->next=afterksize;
            prev=temp;
            temp=afterksize;
        }
        return head;
    }
};