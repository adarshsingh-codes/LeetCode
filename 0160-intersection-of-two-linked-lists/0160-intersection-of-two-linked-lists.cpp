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
        int count1=cnt(headA);
        int count2=cnt(headB);
        int diff=0;
        ListNode* temp1=headA;
        ListNode* temp2=headB;
        if(count2>count1){
            diff=count2-count1;
            while(diff>0){
                temp2=temp2->next;
                diff--;
            }
            while(temp1!=NULL&&temp2!=NULL){
                if(temp1==temp2){
                    return temp1;
                }
                temp1=temp1->next;
                temp2=temp2->next;            }
        }
        else if(count1>count2){
            diff=count1-count2;
            while(diff>0){
                temp1=temp1->next;
                diff--;
            }
            while(temp1!=NULL&&temp2!=NULL){
                if(temp1==temp2){
                    return temp1;
                }
                temp1=temp1->next;
                temp2=temp2->next;            
            }
        }else{
            while(temp1!=NULL&&temp2!=NULL){
                if(temp1==temp2){
                    return temp1;
                }
                temp1=temp1->next;
                temp2=temp2->next;
            }
        }
        return NULL;
    }
};