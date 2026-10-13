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
    bool isPalindrome(ListNode* head) {
        ListNode* temp=head;
        ListNode* list1=new ListNode(0);
        ListNode* temp1=list1;

        while(temp!=NULL){
            list1->next=new ListNode(temp->val);
            temp=temp->next;
            list1=list1->next;
        }
        head=rev(head);
        ListNode* temp2=head;
        while(temp1->next!=NULL&&temp2!=NULL){
            if(temp1->next->val==temp2->val){
                temp1=temp1->next;
                temp2=temp2->next;
            }else{
                return false;
            }
        }
        return true;
    }
};