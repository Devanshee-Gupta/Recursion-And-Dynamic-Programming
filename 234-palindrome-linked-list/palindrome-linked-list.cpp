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
    ListNode* reverselinkedlist(ListNode *prev,ListNode* curr){
        
        if(curr==NULL){
            return prev;
        }
        ListNode *temp=curr->next;
        curr->next=prev;
        return reverselinkedlist(curr,temp);

    }

    bool isPalindrome(ListNode* head) {
        if(head==NULL or head->next==NULL) return 1;

        ListNode *fast=head,*slow=head,*prev;

        while(fast!=NULL && fast->next!=NULL){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        prev->next=NULL;
        prev=head; // assigning head to prev pointer
        // two linkedlists one having head pointer as prev and other as slow
        // reversing linkedlist which is pointed by slow pointer
   
        ListNode *temp=reverselinkedlist(NULL,slow);
      
        while(temp!=NULL && prev!=NULL){
            if(temp->val!=prev->val) return 0;
            temp=temp->next;
            prev=prev->next;
        }

        return 1;
    }
};