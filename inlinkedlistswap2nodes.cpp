/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::swapPairs(ListNode* A) {

   ListNode *pt1=NULL,*pt2=NULL,*curr=A,*newhead=NULL,*prev=NULL;

   while(curr!=NULL){
       pt1=curr;
       pt2=curr->next;

       if(curr->next==NULL)
       break;

       pt1->next=pt2->next;
       if(prev!=NULL)
        prev->next=pt2;

        pt2->next=pt1;
       if(newhead==NULL)
         newhead=pt2;

       prev=pt1;
       curr=pt1->next;
   }
   if(newhead==NULL)
   return pt1;

   return newhead;
    // ListNode *curr=A;
    // while(curr!=NULL){
    //     int t=curr->val;
    //   if(curr->next!=NULL)
    //   { curr->val=curr->next->val;
    //      curr->next->val=t;
    //   }

    //     if(curr->next==NULL)
    //     break;

    //     curr=curr->next->next;

    // }
    // return A;
}

