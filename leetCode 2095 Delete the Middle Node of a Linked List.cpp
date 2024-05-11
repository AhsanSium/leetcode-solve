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
    ListNode* deleteMiddle(ListNode* head) {
        int sz = 0;
        ListNode * a = head;
        while(a != NULL){
            sz ++;
            a = a -> next;
        }
        if(sz == 1){
            head = NULL;
            return head;
        }
        int mid = sz / 2;
        cout << mid << "\n";
        ListNode * b = head;
        for(int i = 0; i < mid - 1; i++){
            b = b -> next;
        }
        b -> next = b -> next -> next;
        cout << b->val << "\n";

        return head;
    }
};