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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next){
          return head;
        }
        ListNode* t=head;
        int l=1;
        while(t->next!=NULL){
          l++;
          t=t->next;
        }
        k%=l;
        if(k==0){
          return head;
        }

        t->next=head;
        ListNode* temp=head;
        for(int i=1;i<l-k;i++){
          temp=temp->next;
        }
        ListNode* newH=temp->next;
        temp->next=NULL;

        return newH;
    }
};