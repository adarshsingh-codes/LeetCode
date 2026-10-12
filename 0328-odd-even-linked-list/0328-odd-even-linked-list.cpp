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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL||head->next==NULL){
            return head;
        }
        ListNode* node1=new ListNode(0);
        ListNode* node2=new ListNode(0);
    
        ListNode* temp1=node1;
        ListNode* temp2=node2;
        ListNode* temp=head;

        for(int i=1;temp!=NULL;i++){
            if(i%2!=0){
                node1->next=temp;
                node1=node1->next;
            }else{
                node2->next=temp;
                node2=node2->next;
            }
            temp=temp->next;
        }
        node2->next=NULL;
        node1->next=temp2->next;
        return temp1->next;
    }
};