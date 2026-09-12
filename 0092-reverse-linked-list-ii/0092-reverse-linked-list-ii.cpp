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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* temp=head;
        for(int i=0;i<left-1;i++){
            temp=temp->next;
            prev=curr;
            curr=curr->next;
        }
        ListNode* beforeleft=prev;
        ListNode* leftnode=curr;
        for(int i=left;i<=right;i++){
            temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        if(beforeleft!=NULL){
            beforeleft->next=prev;
            leftnode->next=curr;
        }else{
            head=prev;
            leftnode->next=curr;
        }
        return head;
    }
};