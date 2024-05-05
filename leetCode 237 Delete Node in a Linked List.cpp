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
    void deleteNode(ListNode* node) {
        ListNode * a = node;
        while(a  != NULL){
            // cout << a->val << "\n";
            ListNode * b = a->next;
            if(a -> next != NULL){
                a->val = b -> val;
            }
            if(a -> next -> next == NULL){
                a -> next = NULL;
                break;
            }
            a = b;
        }
    }
};