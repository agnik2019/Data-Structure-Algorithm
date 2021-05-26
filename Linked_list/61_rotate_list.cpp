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
        if(!head || k<0)
            return NULL;
        ListNode* lastnode = head;
        int length = 1;
        while(lastnode->next){
            lastnode = lastnode->next;
            length++;
        }
        lastnode->next = head;
        k = k %length; // if k>length
        int skiplength = length-k;
        ListNode* lastnodePrev = head;
        for(int i = 0; i<skiplength-1; i++){
            lastnodePrev = lastnodePrev->next;
        }
        head = lastnodePrev->next;
        lastnodePrev->next = nullptr;
        return head;
    }
};