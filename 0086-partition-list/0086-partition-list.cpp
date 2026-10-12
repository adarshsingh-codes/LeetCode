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
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL||head->next==NULL){
            return head;
        }
        ListNode* list1=new ListNode(0);
        ListNode* list2=new ListNode(0);
        ListNode* temp1=list1;
        ListNode* temp2=list2;
        ListNode* temp=head;

        while(temp!=NULL){
            if(temp->val<x){
                list1->next=temp;
                list1=list1->next;
            }else{
                list2->next=temp;
                list2=list2->next;
            }
            temp=temp->next;
        }
        list2->next=NULL;
        list1->next=temp2->next;
        return temp1->next;
    }
};