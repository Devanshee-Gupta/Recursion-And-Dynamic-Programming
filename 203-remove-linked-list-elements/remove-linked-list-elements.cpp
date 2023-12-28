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
    void f(ListNode* prev,ListNode* curr,ListNode** head,int val){
        if(curr==NULL) return;

        if(curr->val==val){
            if(prev!=NULL){
                prev->next=curr->next;
                curr=curr->next;
            }
            else{
                *head=curr->next;
                prev=NULL;
                curr=*head;
            }
        }
        else{
            prev=curr;
            curr=curr->next;
        }
        
        f(prev,curr,head,val);

    }
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *prev = NULL;
        f(prev,head,&head,val);
        return head;
    }
};