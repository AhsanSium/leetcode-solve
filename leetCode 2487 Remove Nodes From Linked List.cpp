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
    ListNode* removeNodes(ListNode* head) {
        ListNode * a = head;
        ListNode * b = head;
        ListNode * target = new ListNode(-1);
        ListNode * ans = head;
        stack<ListNode*> stack;

        while(b != NULL){
            while(a != NULL){
                // ListNode * b = a -> next;
                if(a -> val > target->val){
                    target = a;
                }
                a = a -> next;
            }
            cout << target -> val << "  nxt:" << target -> next << "\n";
            stack.push(target);
            // ans = target;
            // if(ans -> val == -1){
            //     ListNode * tmp = new ListNode(target -> val, NULL);
            //     ans = tmp;
            // }
            // else{
            //     ListNode * tmp = new ListNode(target -> val, NULL);
            //     ListNode * tmp2 =
            //     ans -> next = tmp;
            //     // ans = ans -> next;
            // }
            target -> val = 0;
            if(target-> next == NULL){break;}
            a = head;
            b = b -> next;
        }

        ListNode* nxt = nullptr;
        while (!stack.empty()) {
            ans = stack.top();
            stack.pop();
            cout << ans -> val << "  "
            ans -> next = nxt;
            nxt = ans;
        }

        return ans;
    }
};







class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        ListNode* cur = head;
        stack<ListNode*> stack;
        
        while (cur != nullptr) {
            while (!stack.empty() && stack.top()->val < cur->val) {
                stack.pop();
            }
            stack.push(cur);
            cur = cur->next;
        }
        
        ListNode* nxt = nullptr;
        while (!stack.empty()) {
            cur = stack.top();
            stack.pop();
            cur->next = nxt;
            nxt = cur;
        }
        
        return cur;
    }
};