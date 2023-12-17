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
    ListNode* rev(ListNode* l, ListNode* r){
        if(r==NULL){
            l->next=NULL;
            return l;
        }

        if(r->next==NULL){
            r->next=l;
            l->next=NULL;
            return r;
        }

        ListNode * swapped= rev(r->next,r->next->next);
        r->next=l;
        l->next=swapped;
        return r;

    }
    ListNode* swapPairs(ListNode* head) {

        if(!head) return NULL;
        
        ListNode *curr=head->next;
        if(curr==NULL) return head;

        return rev(head,curr);  
    }
};