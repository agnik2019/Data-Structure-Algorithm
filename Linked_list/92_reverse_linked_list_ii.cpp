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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* current = head, *prev = nullptr;
        // after skipping m-1 nodes current will pe pointing to mth node
        for(int i = 0; current && i<m-1; i++)
        {
            prev = current;
            current = current->next;
        }
        ListNode* lastnodeoffirstpart = prev; // points to the node at index m-1
        ListNode* next = nullptr;
        ListNode* lastnodeofsublist = current; // after reversing current will be the last node of sublist
        for(int i = 0; current && i<n-m+1; i++)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        //connect with the first part
        if(lastnodeoffirstpart) lastnodeoffirstpart->next = prev;
        else head = prev;
        
        //connect with last part
        
        lastnodeofsublist->next = current;
        return head;
    }
};