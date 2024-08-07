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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*,bool> mp;

        ListNode* curr1=headA;
        while(curr1!=NULL)
        {
            mp[curr1]=true;
            curr1=curr1->next;
        }

        ListNode* curr2=headB;
        while(curr2!=NULL)
        {
            if(mp.find(curr2)!=mp.end())
                return curr2;

            mp[curr2]=true;
            curr2=curr2->next;
        }
        return NULL;
    }
};
