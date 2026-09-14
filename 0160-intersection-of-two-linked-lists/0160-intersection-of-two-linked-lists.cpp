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
    int cnt(ListNode* head){
        int count=0;
        ListNode* temp=head;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        return count;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL||headB==NULL){
            return NULL;
        }
        ListNode* temp1=headA;
        ListNode* temp2=headB;
        int count1=cnt(headA);
        int count2=cnt(headB);
        int count=0;
        if(count1>count2){
            count=count1-count2;
            for(int i=1;i<=count&&temp1!=NULL;i++){
                temp1=temp1->next;
            }
        }else{
            count=count2-count1;
            for(int i=1;i<=count&&temp2!=NULL;i++){
                temp2=temp2->next;
            }
        }
        while(temp1!=NULL&&temp2!=NULL){
            if(temp1==temp2){
                return temp1;
            }
            temp1=temp1->next;
            temp2=temp2->next;
        }
        return  NULL;
    }
};