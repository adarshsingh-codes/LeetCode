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
    int cnt(ListNode* head){
        int count=0;
        ListNode* temp=head;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        return count;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL||head->next==NULL){
            return head;
        }
        k=k%cnt(head);
        if(k == 0) {
            return head;
        }
        int pos=cnt(head)-k;
        ListNode* temp=head;
        for(int i=1;i<pos;i++){
            temp=temp->next;
        }
        if(temp==NULL){
            return head;
        }
        ListNode* newlist=temp->next;
        ListNode* tail = newlist;
        while(tail->next != NULL) {
            tail = tail->next;
        }
        temp->next=NULL;
        tail->next=head;
        head=newlist;
        return head;
    }
};