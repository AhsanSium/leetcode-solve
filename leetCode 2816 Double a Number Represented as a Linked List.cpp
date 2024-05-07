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
    ListNode* doubleIt(ListNode* head) {
        ListNode * a = head;
        stack <int> total_st;
        int total1 = 0;
        while(a != NULL){
            total_st.push(a->val);
            a = a -> next;
        }

        int carry = 0;
        ListNode * ans = NULL;
        while(!total_st.empty()){
            ans = new ListNode(0, ans);
            int digit = total_st.top();
            total_st.pop();
            digit = digit * 2 + carry;
            carry = digit / 10;
            digit = digit % 10;
            ans -> val = digit;
            if(total_st.empty() && carry != 0){
                ans = new ListNode(0, ans);
                ans -> val = carry;
            }
        }

        return ans;
    }
};