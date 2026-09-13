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
        ListNode* temp=head;

        ListNode* temp1= new ListNode(0);
        ListNode* temp2= new ListNode(0);

        ListNode* list1=temp1;
        ListNode* list2=temp2;

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